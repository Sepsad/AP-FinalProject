#ifndef _POSTHANDLER_H_
#define _POSTHANDLER_H_

#include "../../../DataBase/DataBase.h"
#include "../../Request.h"
#include "../../../Network/Network.h"

const std::string   LOGIN_URL = "login";
const std::string   SIGNUP_URL = "singup";
const std::string   FILMS_URL = "films";
const std::string   MONEY_URL = "money";
const std::string   REPLIES_URL = "replies";
const std::string   FOLLOWERS_URL = "followers";
const std::string   BUY_URL  = "buy";
const std::string   RATE_URL  = "rate";
const std::string   COMMENTS_URL = "comments";



class POSTHandler
{
public:

static void handle(Request* req, DataBase* db, Network* network);

private:


static void sign_up_handler(Request* req, DataBase* db, Network* network);
static void login_handler(Request* req, DataBase* db, Network* network);
static void films_handler(Request* req, DataBase* db, Network* network);
static void money_handler(Request* req, DataBase* db, Network* network);
static void replies_handler(Request* req, DataBase* db, Network* network);
static void followers_handler(Request* req, DataBase* db, Network* network);
static void buy_handler(Request* req, DataBase* db, Network* network);
static void rate_handler(Request* req, DataBase* db, Network* network);
static void comment_handler(Request* req, DataBase* db, Network* network);
};



#endif