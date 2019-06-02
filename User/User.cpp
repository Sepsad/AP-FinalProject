#include "User.h"
#include "../Exceptions/Exceptions.h"
#include <iostream>
#include "../Notification/Notification.h"


bool User::is_email_valid(std::string& email)
{
    const std::regex pattern
            ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return std::regex_match(email,pattern);
}



User::User(int _id ,std::string _email, std::string _username, std::string _password, int _age)
{
    if (!is_email_valid(_email))
    {
        throw BadRequestEx();
    }
    id = _id; email = _email; username = _username; password = _password; age = _age; 
}

void User::add_follower(User* _user)
{
    followers.push_back(_user);
}
std::vector <User*>  User::get_followers()
{
    return followers;
}




void User::follow(User* user)
{
    followings.push_back(user);
}

void User::increase_money(int amount)
{
    money_amount += amount;
}

void User::buy(Film* film)
{
    purchased_films.push_back(film);
}

void User::recieve_notifications(Notification* notification)
{
    notifications.push_back(notification);
}

int User::get_id()
{
    return id;
}

std::string User::get_type()
{
    return "User";
}

 std::string User::get_username()
 {
     return username;
 }


void User::view_purchased_films()
{

}

void User::view_unread_notifications()
{
    for (int i = 0; i < notifications.size(); i++)
    {
        if(!(notifications[i]->is_read()))
        {
            std::cout << i <<". " << notifications[i]->get_content() << "\n" ;
            notifications[i]->set_read();
        }
    }
}
void User::view_all_notifications(int limit)
{
    if(limit > notifications.size())
    {
        throw BadRequestEx();
        return;

    }
    for (int i = 0; i < limit ; i++)
    {
        std::cout << i <<". " << notifications[i]->get_content() << "\n" ;
    }
}

 void User::view_identity()
 {
    
    std::cout << id << " | ";
    std::cout << username << " | ";
    std::cout << email << std::endl;

 }

std::vector<Film*> User::get_films()
{
    return purchased_films;
}




bool User::check_password(std::string _password)
{
    if (password == _password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool User::is_publisher()
{
    return false;
}

void User::add_film(Film* film)
{}

void User::delete_film(int id)
{}

Film* User::get_film(int id)
{}