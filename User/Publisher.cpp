#include "Publisher.h"

Publisher::Publisher(std::string _email, std::string _username, std::string _password, int _age)
        : User(_email,_username,_password,_age)     {}

void Publisher::add_film(Film* film)
{
        films.push_back(film);
}


