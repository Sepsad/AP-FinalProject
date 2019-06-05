#ifndef _POSTHANDLER_H_
#define _POSTHANDLER_H_

#include "../../../DataBase/DataBase.h"
#include "../../Request.h"
#include "../../../Network/Network.h"




class POSTHandler
{

public:

static void handle(Request* req, DataBase* db, Network* network);

private:


static void sign_up_handler(Request* req, DataBase* db, Network* network);
static void login_handler(Request* req, DataBase* db, Network* network);
static void logout_handler(Request* req, DataBase* db, Network* network);


static void films_handler(Request* req, DataBase* db, Network* network);
static void money_handler(Request* req, DataBase* db, Network* network);
static void replies_handler(Request* req, DataBase* db, Network* network);
static void followers_handler(Request* req, DataBase* db, Network* network);
static void buy_handler(Request* req, DataBase* db, Network* network);
static void rate_handler(Request* req, DataBase* db, Network* network);
static void comment_handler(Request* req, DataBase* db, Network* network);

static void put_film_handler(Request* req, DataBase* db, Network* network);
static void delete_films_handler(Request* req, DataBase* db, Network* network);
static void delete_comments_handler(Request* req, DataBase* db, Network* network);





};



#endif