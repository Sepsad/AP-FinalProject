#include "Publisher.h"
#include "../Exceptions/Exceptions.h"

Publisher::Publisher(std::string _email, std::string _username, std::string _password, int _age)
                : User(_email,_username,_password,_age)  {}

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


std::string Publisher::get_type()
{
        return "Publisher";
}