#ifndef _PUTHANDLER_H_
#define _PUTHANDLER_H_

#include "../../../DataBase/DataBase.h"
#include "../../Request.h"
#include "../../../Network/Network.h"



class PUTHandler
{
public:

static void handle(Request* req, DataBase* db, Network* network);

private:

static void films_handler(Request* req, DataBase* db, Network* network);


};




#endif
