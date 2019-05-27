#ifndef _REQUESTHANDLER_H_ 
#define _REQUESTHANDLER_H_


#include "Request.h"
#include "../DataBase/DataBase.h"
#include "../Network/Network.h"


class RequestHandler
{
public:
    static void Handle(Request* request, DataBase* db, Network* network);
    
};






#endif