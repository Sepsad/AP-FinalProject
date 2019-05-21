#ifndef _USER_H_ 
#define _USER_H_

#include <string>
#include <regex>
#include "../Film/Film.h"
#include "../Notification/Notification.h"

class User
{

public:
    User(std::string _email, std::string _username, std::string _password, int _age);
    void follow(User* user);
    void increase_money(int amount);
    void buy(Film* film);
    void recieve_notifications(Notification* notification);

    virtual std::string get_type();
    int get_id();
    
    void view_purchased_films();
    void view_all_notifications(int limit);
    void view_unread_notifications();
protected:
    int id;
    std::string email;
    std::string username;
    std::string password;
    int age;
    int money_amount;

    std::vector<Film*> purchased_films;

    std::vector<User*> followings; 

    std::vector<Notification*> notifications;

    bool is_email_valid(std::string& email);
};



#endif