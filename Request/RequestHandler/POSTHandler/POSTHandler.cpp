#include "POSTHandler.h"
#include <iostream>
#include "../../../Exceptions/Exceptions.h"
#include "../../../User/User.h"
#include "../../../User/Publisher.h"
#include "../../../Network/Network.h"
#include "../../../Film/Film.h"
#include "../../../Money/Money.h"
#include "../../../Comment/Comment.h"
#include "../../../Comment/Reply.h"
#include "../../../Notification/Notification.h"
#include "../../../Rate/Rate.h"
#include "../../../Tools/Tools.h"


#include "PostHandleTools/PostHandleTools.h"

#include <map>
#include <string>
#include <algorithm>

const std::string USERNAME = "username";
const std::string EMAIL = "email";
const std::string PASSWORD = "password";
const std::string AGE = "age";
const std::string PUBLISHER = "publisher";
const std::string TRUE_STR = "true";

const std::string NAME = "name";
const std::string YEAR = "year";
const std::string LENGTH = "length";
const std::string PRICE = "price";
const std::string SUMMARY = "summary";
const std::string DIRECTOR = "director";

const std::string AMOUNT = "amount";

const std::string FILM_ID = "film_id";
const std::string COMMENT_ID = "comment_id";
const std::string CONTENT = "content";
const std::string USER_ID = "user_id";
const std::string SCORE = "score";

const std::string PUT_FILMS = "put_films";
const std::string DELETE_FILMS = "delete_films";
const std::string DELETE_COMMENTS = "delete_comments";

const std::string LOGOUT_URL = "logout";

void POSTHandler::logout_handler(Request* req, DataBase* db, Network* network)
{
    network->logout();
}

void POSTHandler::sign_up_handler(Request* req, DataBase* db, Network* network)
{   
    
    std::map <std::string, std::string> params = req->get_parameters();
    if(params.size() < 4)
    {
        throw BadRequestEx();
    }
    if(PostHandleTools::is_username_duplicate(params[USERNAME], db) == true)
    {
        throw BadRequestEx();
        return;
    }
    if(params[PUBLISHER] == TRUE_STR)
    {
        db->add_member(new Publisher((db->get_last_user_id()+1), params[EMAIL],
                params[USERNAME], params[PASSWORD], std::stoi(params[AGE])));       
    }
    else
    {
        db->add_member(new User((db->get_last_user_id()+1), params[EMAIL], 
                params[USERNAME], params[PASSWORD], std::stoi(params[AGE])));  
    }
    
    // if(network->is_user_nullptr())
    {
        network->login(db->get_last_user());
    }
}




void POSTHandler::login_handler(Request* req, DataBase* db, Network* network)
{
    std::map <std::string, std::string> params = req->get_parameters();
    User* user = db->search_user_by_username(params[USERNAME]);
    if(params.size()  < 2)
    {
        throw BadRequestEx();
    }
    if (!user)
    {  
       throw NotFoundEx(); 
       return ;
    }
    if ( user->check_password(params[PASSWORD]) )
    {
        network->login(user);
        return;
    }
    
    throw BadRequestEx();
}




void POSTHandler::films_handler(Request* req, DataBase* db, Network* network)
{
    
    if(!network->get_online_user())
    {
        throw PermissionEx();
        return ;
    }
    if( !((network->get_online_user())->is_publisher()))
    {
        throw PermissionEx();
        return;
    }
    std::map <std::string, std::string> params = req->get_parameters();

    if(params.size() < 6)
    {
        throw BadRequestEx();
        return;
    }
    if(params[NAME] == "" || params[YEAR] == "" || params[LENGTH] == "" || params[PRICE] == "" ||
             params[SUMMARY] == "" || params[DIRECTOR] == "")
    {
        throw BadRequestEx();
        return;
    }

    db->add_film(new Film(db->get_last_film_id()+1, params[NAME], std::stoi(params[YEAR]), std::stoi(params[LENGTH]), 
            std::stoi(params[PRICE]), params[SUMMARY], params[DIRECTOR], network->get_online_user()));
    
    User* _user = network->get_online_user();
    _user->add_film(new Film(db->get_last_film_id(), params[NAME], std::stoi(params[YEAR]), std::stoi(params[LENGTH]), 
            std::stoi(params[PRICE]), params[SUMMARY], params[DIRECTOR], network->get_online_user()));

    std::string notif_content = "Publisher" + (network->get_online_user())->get_username() 
            + "with id" + std::to_string( (network->get_online_user())->get_id()) + "register new film."; 

    PostHandleTools::send_notification_to_all(db->get_all_users(),new Notification(notif_content));
}





void POSTHandler::money_handler(Request* req, DataBase* db, Network* network)
{
    
    User* user = network->get_online_user();
    if (!user)
    {
        throw PermissionEx();
        return ; 
    }
    if(!(user->is_publisher()))
    {
        throw PermissionEx();        
        return;
    }

    std::map <std::string, std::string> params = req->get_parameters();
    if(req->get_parameters_size() == 0)
    {
        if(!(network->get_online_user()->is_publisher()))
        {
            throw PermissionEx();
            return;
        }
       
        std::vector <Money*> tresury = db->get_treasury();
        int amount = PostHandleTools::calculate(db->get_treasury(), network->get_online_user());
        (network->get_online_user())->increase_money(amount);
        db->delete_money_of_user_from_treasury(network->get_online_user());
    }
    else
    {
        (network->get_online_user())->increase_money(std::stoi(params[AMOUNT]));
    }   
}





void POSTHandler::replies_handler(Request* req, DataBase* db, Network* network)
{
    if(!network->get_online_user())
    {
        throw PermissionEx();
        return ;
    }
    std::map <std::string, std::string> params = req->get_parameters();
    if(params.size() < 3)
    {
        throw BadRequestEx();
    }
    if(!(network->get_online_user())->get_film(std::stoi(params[FILM_ID])))
    {
        throw PermissionEx();
        return;
    }
    Film* film = db->get_film(std::stoi(params[FILM_ID]));
    (film)->add_reply_to_comment(std::stoi(params[COMMENT_ID]),new Reply(params[CONTENT]));
    std::string notif_content = "Publisher" + (network->get_online_user())->get_username() 
        + "with id" + std::to_string( (network->get_online_user())->get_id()) + "reply to your comment.";

    PostHandleTools::send_notification_to_user((film->get_comment(std::stoi(params[FILM_ID])))->get_user(),
            new Notification(notif_content));
}

void POSTHandler::followers_handler(Request* req, DataBase* db, Network* network)
{
    std::map <std::string, std::string> params = req->get_parameters();
    if(params.size() == 0)
    {
        throw BadRequestEx();
    }
    if(!network->get_online_user())
    {
        throw PermissionEx();
        return ;
    }
    if(!db->get_user(std::stoi(params[USER_ID])))
    {
        throw NotFoundEx();
        return;
    }


    (network->get_online_user())->follow(db->get_user(std::stoi(params[USER_ID])));
    std::string notif_content = "User" + (network->get_online_user())->get_username() 
        + "with id" + std::to_string( (network->get_online_user())->get_id()) + "follow you."; 


    PostHandleTools::send_notification_to_user(db->get_user(std::stoi(params[USER_ID])) ,new Notification(notif_content));
}





void POSTHandler::buy_handler(Request* req, DataBase* db, Network* network)
{
    std::map <std::string, std::string> params = req->get_parameters();
    if(!network->get_online_user())
    {
        throw PermissionEx();
        return ;
    }
    if(!db->get_film(std::stoi(params[FILM_ID])))
    {
        throw NotFoundEx();
        return;
    }
    Film* film = db->get_film(std::stoi(params[FILM_ID]));
    (network->get_online_user())->buy(film);
    Money* money = new Money(network->get_online_user(), film, film->get_price());
    db->add_money_to_tresury(money);

    std::string notif_content = "User" + (network->get_online_user())->get_username() 
    + "with id" + std::to_string( (network->get_online_user())->get_id()) + "buy your film " 
    + film->get_name() + " with id " + std::to_string(film->get_id()) + ".";

    PostHandleTools::send_notification_to_user(film->get_publisher(),new Notification(notif_content));


}
void POSTHandler::rate_handler(Request* req, DataBase* db, Network* network)
{
    std::map <std::string, std::string> params = req->get_parameters();
    if(!network->get_online_user())
    {
        throw PermissionEx();
        return ;
    }
    if(!db->get_film(std::stoi(params[FILM_ID])))
    {
        throw NotFoundEx();
        return;
    }

    Film* film = db->get_film(std::stoi(params[FILM_ID]));
    int score = std::stoi(params[SCORE]);
    film->rate(new Rate(score, network->get_online_user()));


    std::string notif_content = "User" + (network->get_online_user())->get_username() 
        + "with id" + std::to_string( (network->get_online_user())->get_id()) + "rate your film " 
        + film->get_name() + " with id " + std::to_string(film->get_id()) + ".";

    PostHandleTools::send_notification_to_user(film->get_publisher(),new Notification(notif_content));
}




void POSTHandler::comment_handler(Request* req, DataBase* db, Network* network)
{
    std::map <std::string, std::string> params = req->get_parameters();
    if(!network->get_online_user())
    {
        throw PermissionEx();
        return ;
    }
    if(!db->get_film(std::stoi(params[FILM_ID])))
    {
        throw NotFoundEx();
        return;
    }
    Film* film = db->get_film(std::stoi(params[FILM_ID]));
    film->add_comment(params[CONTENT], network->get_online_user());
    std::string notif_content = "User" + (network->get_online_user())->get_username() 
            + "with id" + std::to_string( (network->get_online_user())->get_id()) + "comment on your film " 
            + film->get_name() + " with id " + std::to_string(film->get_id()) + "."; 
    
    PostHandleTools::send_notification_to_user(film->get_publisher(),new Notification(notif_content));
}


void POSTHandler::put_film_handler(Request* req, DataBase* db, Network* network)
{
    std::map <std::string, std::string> params = req->get_parameters();
    if(!(Tools::is_number(params[FILM_ID])))
    {
        throw BadRequestEx();
        return ;
    }
    Film* film = db->get_film(std::stoi(params[FILM_ID]));
    if(!(film->get_publisher() == network->get_online_user()))
    {
        throw PermissionEx();
        return;
    }
    film->edit_film(params[NAME], params[YEAR], params[LENGTH], params[SUMMARY], params[DIRECTOR]);

}

void POSTHandler::delete_comments_handler(Request* req, DataBase* db, Network* network)
{
    User* user = network->get_online_user();
    if (!user)
    {
        throw PermissionEx();
        return ; 
    }
    if(!(user->is_publisher()))
    {
        throw PermissionEx();
        return;
    }


    std::map <std::string, std::string> params = req->get_parameters();
    if(params.size() < 2)
    {
        throw BadRequestEx();
    }
    Film* film = db->get_film(std::stoi(params[FILM_ID]));
    film->delete_comment(std::stoi(params[COMMENT_ID]));
}

 void POSTHandler::delete_films_handler(Request* req, DataBase* db, Network* network)
{
    User* user = network->get_online_user();
    if (!user)
    {
        throw PermissionEx();
        return ; 
    }
    if(!(user->is_publisher()))
    {
        throw PermissionEx();
        return;
    }

    std::map <std::string, std::string> params = req->get_parameters();
    if(params.size() == 0)
    {
        throw BadRequestEx();
    }
    db->delete_film(std::stoi(params[FILM_ID]));
}



void POSTHandler::handle(Request* req, DataBase* db, Network* network)
{

    const std::string   LOGIN_URL = "login";
    const std::string   SIGNUP_URL = "signup";
    const std::string   FILMS_URL = "films";
    const std::string   MONEY_URL = "money";
    const std::string   REPLIES_URL = "replies";
    const std::string   FOLLOWERS_URL = "followers";
    const std::string   BUY_URL  = "buy";
    const std::string   RATE_URL  = "rate";
    const std::string   COMMENTS_URL = "comments";

    
    // std::cout << req->get_url() << std::endl ;

    if(req->get_url() == SIGNUP_URL)
    {
        try
        {
            sign_up_handler(req, db, network);
            std::cout << "OK\n";
        }
        catch(const std::exception& e)
        {            
            std::cout << e.what()<<  '\n';
        }
        

    }
    else if(req->get_url() == LOGOUT_URL)
    {
        try
        {
            logout_handler(req, db, network);
            std::cout << "OK\n";
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }

    }
    else if(req->get_url() == LOGIN_URL)
    {
        try
        {
            login_handler(req, db, network);
            std::cout << "OK\n";
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }

    }
    else if(req->get_url() == FILMS_URL )
    {
        try
        {
            films_handler(req, db, network);
            std::cout << "OK\n";
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }

    }

    else if(req->get_url() == MONEY_URL)
    {
        try
        {
            money_handler(req, db, network);
            std::cout << "OK\n";
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }
    
    else if(req->get_url() == REPLIES_URL)
    {
        try
        {
            replies_handler(req, db, network);
            std::cout << "OK\n";

        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }

        
    }

    else if(req->get_url() == FOLLOWERS_URL)
    {
        try
        {
            followers_handler(req, db, network);
            std::cout << "OK\n";
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }

    }

    else if(req->get_url() == BUY_URL)
    {
        try
        {
            buy_handler(req, db, network);
            std::cout << "OK\n";

        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }
    else if(req->get_url() == RATE_URL)
    {
        try
        {
            rate_handler(req, db, network);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
        std::cout << "OK\n";
    }
    else if(req->get_url() == COMMENTS_URL)
    {
        try
        {
            comment_handler(req, db, network);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
        std::cout << "OK\n";
    }
    else if(req->get_url() == PUT_FILMS)
    {
        try
        {
            put_film_handler(req, db, network);
            std::cout << "OK\n";
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }
    else if(req->get_url() == DELETE_FILMS)
    {
         try
        {
            delete_films_handler(req, db, network);
            std::cout << "OK\n";
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }
    else if (req->get_url() == DELETE_COMMENTS)
    {
         try
        {
            delete_comments_handler(req, db, network);
            std::cout << "OK\n";
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }   
    }
    else
    {
        throw BadRequestEx();
    }
    

}