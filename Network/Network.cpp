#include "Network.h"

Network::Network()
{
    database = new DataBase();
    online_user = NULL;
}

bool Network::is_user_null()
{
    return (online_user == NULL);
}

void Network::login(User* user)
{
    online_user = user;
}

User* Network::get_online_user()
{
    return online_user;
}
