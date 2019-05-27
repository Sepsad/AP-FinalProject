#include "Execute.h"
#include <iostream>
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
    while (std::cin >> raw_req)
    {   
        if(raw_req.size() == 0)
            continue;
        try
        {
            Request* req = RequestReader::read(raw_req);
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

