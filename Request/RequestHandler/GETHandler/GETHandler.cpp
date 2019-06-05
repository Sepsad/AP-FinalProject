#include "GETHandler.h"
#include "../../../Exceptions/Exceptions.h"
#include "../../../Tools/Tools.h"

#include <iostream>
#include <algorithm>




const std::string FILM_ID = "film_id";
const std::string LIMIT = "limit";
const std::string NAME = "name";
const std::string PRICE = "price";
const std::string DIRECTOR = "driector";
const std::string MAX_YEAR = "max_year";
const std::string MIN_YEAR = "min_year";
const std::string MIN_RATE = "min_rate";
const std::string ADMIN = "admin";

const std::string MONEY_URL = "money";



bool less_than_key_user( User*& user1,User*& user2)
{
    return (user1->get_id() < user2->get_id());
}

bool less_than_key_film(Film*& film1,Film* film2)
{
    return (film1->get_rate() < film2->get_rate());
}


void GETHandler::followers_handler(Request* req, DataBase* db, Network* network)
{
    User* user = network->get_online_user();
    if (!user)
    {
        throw PermissionEx();
        return ; 
    }
    if(!(user->is_publisher()))
    {
        throw  BadRequestEx();
        return ;
    }
    
    std::vector <User*> followers = user->get_followers();

    std::cout << "List of Followers\n" ;
    if(followers.size() == 0)
    {
        return;
    }
    std::sort(followers.begin(),followers.end(),less_than_key_user);
    std::cout << "#. User Id | User Username | User Email";

    for (int i = 0; i < followers.size(); i++)
    {
        std::cout << i << ". ";
        followers[i]->view_identity();
    }
}


void GETHandler::films_handler(Request* req, DataBase* db, Network* network)
{
    User* user = network->get_online_user();
    if (!user)
    {
        throw PermissionEx();
        return ; 
    }
    std::map <std::string, std::string> params = req->get_parameters();
    
    if (!(params[FILM_ID] == ""))
    {       
        Film* film = db->get_film(std::stoi(params[FILM_ID]));
        if(!film)
        {
            throw NotFoundEx();
            return;
        }
        film->view_details();
        std::cout << "\n" ;
        std::cout << "Comments\n";
        film->view_comments();

        std::vector <Film*> films = db->get_all_films();
        std::sort(films.begin(), films.end(), less_than_key_film);
        std::cout << "Recommendation Film\n";
        std::cout << "#. Film Id | Film Name | Film Length | Film Director\n";
        
        int cnt = 4;
        if(films.size() < 4)
        {
            cnt = films.size();
        }

        for (int i = 0; i < cnt; i++)
        {
            std::cout << (i+1) << ". ";
            films[i]->view_recom();
        }
    }
    if (params[FILM_ID] == "")
    {
        std::vector <Film*> films = db->get_all_films();
        std::cout << "#. Film Id | Film Name | Film Length | Film price | Rate | Production Year | Film Director\n";
        int cnt = 1;
        for (int i = 0; i < films.size(); i++)
        {
            if(films[i]->ok_for_view(params[NAME], params[MIN_RATE], params[MIN_YEAR], params[PRICE], params[MAX_YEAR], params[DIRECTOR]))
            {
                std::cout << cnt <<". ";
                films[i]->view();
                cnt++;
            }
        }
    }

}

void GETHandler::notification_handler(Request* req, DataBase* db, Network* network)
{
    User* user = network->get_online_user();
    if (!user )
    {
        throw PermissionEx();
        return ; 
    }
    std::cout <<"#. Notification Message\n";
    
    user->view_unread_notifications();
    
}

void GETHandler::notificationread_handler(Request* req, DataBase* db, Network* network)
{
    User* user = network->get_online_user();
    if (!user)
    {
        throw PermissionEx();
        return ; 
    }
    std::map <std::string, std::string> params = req->get_parameters();
    if(!(Tools::is_number(params[LIMIT])))
    {
        throw BadRequestEx();
        return; 
    }

    std::cout <<"#. Notification Message\n";
    user->view_all_notifications(std::stoi(params[LIMIT]));   
}

void GETHandler::purchased_handler(Request* req, DataBase* db, Network* network)
{
    User* user = network->get_online_user();
    if (!user)
    {
        throw PermissionEx();
        return ; 
    }
    if(user->is_publisher())
    {
        throw PermissionEx();
        return;
    }
    std::map <std::string, std::string> params = req->get_parameters();
    std::vector <Film*> films = (user)->get_films();

    std::cout << "#. Film Id | Film Name | Film Length | Film price | Rate | Production Year | Film Director\n";
    int cnt = 1;
    for (int i = 0; i < films.size(); i++)
    {
        if(films[i]->ok_for_view(params[NAME], params[MIN_RATE], params[MIN_YEAR], params[PRICE], params[MAX_YEAR], params[DIRECTOR]));
        {
            std::cout << cnt <<". ";
            films[i]->view();
            cnt++;
        }
    }
}

void GETHandler::published_handler(Request* req, DataBase* db, Network* network)
{
    User* user = network->get_online_user();
    if (!user)
    {
        throw PermissionEx();
        return ; 
    }
    if(!user->is_publisher())
    {
        throw PermissionEx();
        return;
    }
    std::map <std::string, std::string> params = req->get_parameters();
    std::vector <Film*> films = (user)->get_films();
    std::cout << "#. Film Id | Film Name | Film Length | Film price | Rate | Production Year | Film Director\n";
    int cnt = 1;
    for (int i = 0; i < films.size(); i++)
    {
        if(films[i]->ok_for_view(params[NAME], params[MIN_RATE], params[MIN_YEAR], params[PRICE], params[MAX_YEAR], params[DIRECTOR]))
        {
            std::cout << cnt <<". ";
            films[i]->view();
            cnt++;
        }
    }

    
}

void GETHandler:: money_handler(Request* req, DataBase* db, Network* network)
{  
    User* online_user = network->get_online_user();
    if (!online_user)
    {
        throw PermissionEx();
        return;
    }
    if(online_user->get_username() == ADMIN )
    {
        std::cout << network->get_money() << std::endl ;
        return;
    }
    
    std::cout << online_user->get_money() << std::endl ;
}


void GETHandler::handle(Request* req, DataBase* db, Network* network)
{
    if(req->get_url() == PUBLISHED_URL)
    {
        try
        {
            published_handler(req,db,network);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
        
    }
    else if (req -> get_url() == FOLLOWERS_URL)
    {
        try
        {
            followers_handler(req, db,network);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }   
    }
    else if(req->get_url() == FILMS_URL)
    {
        try
        {
            films_handler(req, db, network);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }
    else if(req->get_url() == PURCHASED_URL)
    {
        try
        {
            purchased_handler(req, db, network);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }
    else if(req->get_url() == NOTIFICATION_URL)
    {
        try
        {
            notification_handler(req, db, network);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }
    else if(req->get_url() == NOTIFICATIONREAD_URL)
    {
        try
        {
            notificationread_handler(req, db, network);
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