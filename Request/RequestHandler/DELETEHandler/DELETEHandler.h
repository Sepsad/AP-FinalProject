#ifndef _DELETEHANDLER_H_
#define _DELETEHANDLER_H_

#include "../../../DataBase/DataBase.h"
#include "../../Request.h"
#include "../../../Network/Network.h"




class DELETEHandler
{
public:
    static void handle(Request* req, DataBase* db, Network* network);
private:
    static void films_handler(Request* req, DataBase* db, Network* network);
    static void comments_handler(Request* req, DataBase* db, Network* network);
    

};






#endif