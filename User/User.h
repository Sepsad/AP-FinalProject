#ifndef _USER_H_ 
#define _USER_H_

#include <string>
#include <regex>
// #include "../Film/Film.h"
// #include "../Notification/Notification.h"

class Film;
class Notification;

class User
{
public:
    User(int _id ,std::string _email, std::string _username, std::string _password, int _age);
    virtual void follow(User* user);
    virtual void increase_money(int amount);
    virtual void buy(Film* film);
    virtual void recieve_notifications(Notification* notification);
    virtual void add_follower(User* _user);

    virtual std::string get_type();
    virtual int get_id();
    virtual std::string get_username();
    virtual std::vector<Film*> get_films();

    virtual void view_identity();
    virtual void view_purchased_films();
    virtual void view_all_notifications(int limit);
    virtual void view_unread_notifications();

    virtual bool check_password(std::string _password);
    virtual bool is_publisher();


    virtual void add_film(Film* film);
    virtual void delete_film(int id);
    virtual Film* get_film(int id);
    virtual std::vector <User*>  get_followers();
    virtual int get_money();


protected:
    int id;
    std::string email;
    std::string username;
    std::string password;
    int age;
    int money_amount;

    std::vector<Film*> purchased_films;

    std::vector<User*> followings;
    std::vector<User*> followers;

    std::vector<Notification*> notifications;

    bool is_email_valid(std::string& email);
};



#endif