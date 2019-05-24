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
    if (user == NULL)
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
    if(followers.size() == 0)
    {
        return;
    }
    std::sort(followers.begin(),followers.end(),less_than_key_user);
    std::cout << "List of Followers\n" ;
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

    if (user == NULL)
    {
        throw PermissionEx();
        return ; 
    }
    std::map <std::string, std::string> params = req->get_parameters();
    
    if (!(params[FILM_ID] == ""))
    {
        Film* film = db->get_film(std::stoi(params[FILM_ID]));
        if(film == NULL)
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
        for (int i = 0; i < 4; i++)
        {
            std::cout << (i+1) << ". ";
            films[i]->view_recom();
        }
    }
    



}

void GETHandler::notification_handler(Request* req, DataBase* db, Network* network)
{
    User* user = network->get_online_user();
    if (user == NULL)
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
    if (user == NULL)
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
    if (user == NULL)
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
    if (user == NULL)
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
