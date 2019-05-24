#include "PUTHandler.h"
#include "../../../Exceptions/Exceptions.h"
#include "../../../Tools/Tools.h"

#include <iostream>

const std::string   FILMS_URL = "films";

const std::string NAME = "name";
const std::string YEAR = "year";
const std::string LENGTH = "length";
const std::string PRICE = "price";
const std::string SUMMARY = "summary";
const std::string DIRECTOR = "director";

const std::string FILM_ID = "film_id";


void PUTHandler::films_handler(Request* req, DataBase* db, Network* network)
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




void PUTHandler::handle(Request* req, DataBase* db, Network* network)
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
    else
    {
        throw BadRequestEx();
    }
}