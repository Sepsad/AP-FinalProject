#ifndef _NETWORK_H_ 
#define _NETWORK_H_
#include "../User/User.h"
#include "../DataBase/DataBase.h"
class Network
{
    
public:
    Network();
    bool is_user_null();
    void login(User* user);
    User* get_online_user();

private:
    User* online_user;
    DataBase* database;
};




#endif
