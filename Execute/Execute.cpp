#include "Execute.h"
#include <iostream>
#include <string>
#include "../DataBase/DataBase.h"
#include "../Network/Network.h"
#include "../Request/Request.h"
#include "../Request/RequestHandler/RequestHandler.h"
#include "../Request/RequestReader/RequestReader.h"

void Execute::execute()
{
    DataBase* db = new DataBase();
    Network* net = new Network();
    std::string raw_req;




    while (getline(std::cin, raw_req))
    {   

        if(raw_req.size() == 0)
            continue;
        try
        {
            Request* req = RequestReader::read(raw_req);
            
            // std::map <std::string, std::string> params = req->get_parameters();
            
            // std::map <std::string, std::string>::const_iterator iter;

            // for (iter = params.begin() ; iter !=params.end() ; iter++)
            // {
                // std::cout << "key : " << iter->first << "\t"<< "value : " << iter->second << std::endl ;
            // }
                // std::cout << req->get_url()  << std::endl;
            RequestHandler::Handle(req, db, net);
            delete req;
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }
    delete db;
    delete net;
}

