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


void Network::logout()
{
    online_user = nullptr;
}

void Network::login(User* user)
{
    online_user = user;
}

User* Network::get_online_user()
{
    return online_user;
}

int Network::get_money()
{
    std::vector<Money*> tres = database->get_treasury();
    int res = 0;
    for (int i = 0; i < tres.size(); i++)
    {
        res += tres[i] ->get_amount();
    }

    return res;
}
