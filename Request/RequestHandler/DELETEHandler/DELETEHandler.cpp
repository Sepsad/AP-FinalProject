#include "DELETEHandler.h"
#include <iostream>
#include "../../../Exceptions/Exceptions.h"

const std::string   FILMS_URL = "films";
const std::string   COMMENTS_URL = "comments";

const std::string FILM_ID = "film_id";
const std::string COMMENT_ID = "comment_id";



void DELETEHandler::comments_handler(Request* req, DataBase* db, Network* network)
{
    User* user = network->get_online_user();
    if (user == NULL)
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

void DELETEHandler::films_handler(Request* req, DataBase* db, Network* network)
{
        User* user = network->get_online_user();
    if (user == NULL)
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




void DELETEHandler::handle(Request* req, DataBase* db, Network* network)
{
    if(req->get_url() == FILMS_URL)
    {
         try
        {
            films_handler(req, db, network);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
        std::cout << "OK\n";
    }

    if (req->get_url() == COMMENTS_URL)
    {
         try
        {
            comments_handler(req, db, network);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
        std::cout << "OK\n";

        
    }
    
}

