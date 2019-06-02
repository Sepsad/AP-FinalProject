#include "RequestHandler.h"
#include "../../Exceptions/Exceptions.h"
#include <iostream> 
#include "POSTHandler/POSTHandler.h"
#include "DELETEHandler/DELETEHandler.h"
#include "PUTHandler/PUTHandler.h"
#include "GETHandler/GETHandler.h"




void RequestHandler::Handle(Request* request, DataBase* db, Network* network)
{
    const std::string POST = "POST";
    const std::string PUT = "PUT";
    const std::string GET = "GET";
    const std::string DELETE = "DELETE";
    
    if(request->get_type() == POST)
    {
        try
        {
            POSTHandler::handle(request, db, network);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }
    else if (request->get_type() == GET)
    {
        try
        {
            GETHandler::handle(request, db, network);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }
    else if (request->get_type() == PUT)
    {
        try
        {
            PUTHandler::handle(request, db, network);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }
    else if (request->get_type() == DELETE)
    {
        try
        {
            DELETEHandler::handle(request, db, network);
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