#include "Publisher.h"
#include "../Exceptions/Exceptions.h"

Publisher::Publisher(int _id,std::string _email, std::string _username, std::string _password, int _age)
                : User(_id,_email,_username,_password,_age)  {}

void Publisher::add_film(Film* film)
{
        films.push_back(film);
}

void Publisher::delete_film(int id)
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

std::vector<Film*> Publisher::get_films()
{
    return films;
}

std::string Publisher::get_type()
{
        return "Publisher";
}

bool Publisher::is_publisher()
{
    return true;
}

Film* Publisher::get_film(int id)
{
    for (int i = 0; i < films.size(); i++)
    {
        if (films[i]->get_id() == id)
        {
            return films[i];
        }
    }
    return NULL;
    
}