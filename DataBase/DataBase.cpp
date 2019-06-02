#include "DataBase.h"
#include "../Exceptions/Exceptions.h"
// #include "../User/User.h"
// #include "../Film/Film.h"
#include <iostream>

DataBase::DataBase()
{
    std::vector <User*> _users; users = _users;
    std::vector <Film*> _films; films = _films;
    std::vector <Money*> _treasury; treasury = _treasury;
}



void DataBase::add_member(User* user)
{
    users.push_back(user);
}

void DataBase::add_film(Film* film)
{
    films.push_back(film);
}

void DataBase::add_money_to_tresury(Money* money)
{
    treasury.push_back(money);
}




Film* DataBase::get_film(int id)
{
    for (int i = 0; i < films.size(); i++)
    {
        if(films[i]->get_id() == id)
        {
            return films[i];
        }
    }
    throw NotFoundEx();
    return nullptr;
}
User* DataBase::get_user(int id)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i]->get_id() == id)
        {
            return users[i];
        }
    }
    return nullptr;
}

User* DataBase::get_last_user()
{
    if(users.size() != 0)
    {
        return users[users.size()-1];
    }
}

int DataBase::get_last_user_id()
{
    if (users.size() != 0)
    {
        return (users[users.size()-1]->get_id());
    }
    return 0;
}

int DataBase::get_last_film_id()
{
    if (films.size() != 0)
    {
        return (films[films.size()-1]->get_id());
    }
    return 0;
}

std::vector<User*> DataBase::get_all_users()
{
    return users;
}

std::vector<Film*>  DataBase::get_all_films()
{
    return films;
}

std::vector<Money*> DataBase::get_treasury()
{
    return treasury;
}


void DataBase::delete_money_of_user_from_treasury(User* user)
{
    std::vector<Money*>::iterator it;
    for (it = treasury.begin(); it != treasury.end(); it++)
    {
        if((*it)->get_user() == user)
        {
            delete * it;
            it = treasury.erase(it);
            return;
        }
    }
}






void DataBase::delete_film(int id)
{
    std::vector<Film*>::iterator it;
    for (it = films.begin(); it != films.end(); it++)
    {
        if((*it)->get_id() == id)
        {
            delete * it;
            it = films.erase(it);
            return;
        }
    }
    throw NotFoundEx();
}


User* DataBase::search_user_by_username(std::string username)
{
    for (int i = 0; i < users.size(); i++)
    {
        if(username == users[i]->get_username())
        {
            return users[i];
        }
    }

    return nullptr;    
}

