#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <vector>
#include "Money/Money.h"

class User;
class Film;

class DataBase
{
public:
    void add_member(User* member);
    void add_film(Film* film);
    void add_money_to_tresury(Money* money);

    User* get_user(int id);
    Film* get_film(int id);

    std::vector<Film*> get_all_films();
    std::vector<Money*> get_treasury();


    int get_last_user_id();
    int get_last_film_id();

    void delete_money_of_user_from_treasury(User* user);
    void delete_film(int id);
    
protected:

    std::vector <User*> users;
    std::vector <Film*> films;
    std::vector <Money*> treasury;
};


#endif