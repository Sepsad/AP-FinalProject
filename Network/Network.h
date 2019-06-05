#ifndef _NETWORK_H_ 
#define _NETWORK_H_
#include "../User/User.h"
#include "../DataBase/DataBase.h"
class Network
{
    
public:
    Network();
    bool is_user_nullptr();
    void login(User* user);
    void logout();
    User* get_online_user();
    int get_money();

private:
    User* online_user;
    DataBase* database;
};




#endif
