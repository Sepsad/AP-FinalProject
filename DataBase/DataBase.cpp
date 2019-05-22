#include "DataBase.h"
#include "../Exceptions/Exceptions.h"
#include "../User/User.h"
#include "../Film/Film.h"

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
    return NULL;
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
    throw NotFoundEx();
    return NULL;
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

std::vector<Film*>  DataBase::get_all_films()
{
    return films;
}

std::vector<Money*> DataBase::get_treasury()
{
    return treasury;
}

int DataBase::get_last_user_id()
{
    return users.size();
}
int DataBase::get_last_film_id()
{
    return films.size();
}

