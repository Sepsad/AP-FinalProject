#ifndef _POSTHANDLETOOLS_H_ 
#define _POSTHANDLETOOLS_H_

#include <vector>
#include "../../../../DataBase/Money/Money.h"
#include "../../../../User/User.h"
#include "../../../../Notification/Notification.h"



class PostHandleTools
{
public:

    static int calculate(std::vector <Money*> tresury, User* user);
    static void send_notification_to_all(std::vector <User*> users, Notification* notif);
    static void send_notification_to_user(User*user, Notification* notif);
    static bool is_username_duplicate(std::string username, DataBase* db);
    

};




#endif  
