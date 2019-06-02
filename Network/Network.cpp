#include "Network.h"

Network::Network()
{
    database = new DataBase();
    online_user = nullptr;
}

bool Network::is_user_nullptr()
{
    if(!online_user)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Network::login(User* user)
{
    online_user = user;
}

User* Network::get_online_user()
{
    return online_user;
}
