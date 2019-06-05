#ifndef _GETHANDLER_H_ 
#define _GETHANDLER_H_

#include "../../../DataBase/DataBase.h"
#include "../../Request.h"
#include "../../../Network/Network.h"

const std::string   FILMS_URL = "films";
const std::string   FOLLOWERS_URL = "followers";
const std::string   PURCHASED_URL = "purchased";
const std::string   PUBLISHED_URL = "published";
const std::string   NOTIFICATION_URL = "notifications";
const std::string   NOTIFICATIONREAD_URL = "notificationread";



class GETHandler
{
    


public:
    
static void handle(Request* req, DataBase* db, Network* network);


private:


static void followers_handler(Request* req, DataBase* db, Network* network);
static void films_handler(Request* req, DataBase* db, Network* network);
static void notification_handler(Request* req, DataBase* db, Network* network);
static void notificationread_handler(Request* req, DataBase* db, Network* network);
static void published_handler(Request* req, DataBase* db, Network* network);
static void purchased_handler(Request* req, DataBase* db, Network* network);

static void money_handler(Request* req, DataBase* db, Network* network);




};

#endif