#include "User.h"
#include "../Exceptions/Exceptions.h"

bool is_email_valid(std::string& email)
{
    const std::regex pattern
            ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return std::regex_match(email,pattern);
}



User::User(std::string _email, std::string _username, std::string _password, int _age)
{
    if (!is_email_valid(_email))
    {
        throw BadRequestEx();
    }
    email = _email; username = _username; password = _password; age = _age; 
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

void User::view_purchased_films()
{

}

void User::view_unread_notifications()
{

}
void User::view_all_notifications(int limit)
{

}
