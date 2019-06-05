#include "PostHandleTools.h"
#include"../../../../DataBase/DataBase.h"
#include <iostream>

int PostHandleTools::calculate(std::vector <Money*> tresury, User* user)
{
    int res = 0;
    for (int i = 0; i < tresury.size(); i++)
    {
        if(tresury[i]->get_user() == user)
        {
            double rate_of_film  = (tresury[i]->get_film())->get_rate();
            if(rate_of_film < 5)
            {
                res += (tresury[i]->get_amount()) * 0.80 ;
            }
            else if (rate_of_film < 8)
            {
                res += (tresury[i]->get_amount()) * 0.90 ;

            }
            else
            {
                res += (tresury[i]->get_amount()) * 0.95 ;
            }
        }
    }
    return res;
}


void PostHandleTools::send_notification_to_all(std::vector <User*> users, Notification* notif)
{
    for (int i = 0; i < users.size(); i++)
    {
        users[i]->recieve_notifications(notif);
    }
}


void PostHandleTools::send_notification_to_user(User*user, Notification* notif)
{
    user->recieve_notifications(notif);
}

bool PostHandleTools::is_username_duplicate(std::string username, DataBase* db)
{
   if(!(db->search_user_by_username(username)))
   {
       return false;
   }
   else
   {
       return true;
   }
   
}