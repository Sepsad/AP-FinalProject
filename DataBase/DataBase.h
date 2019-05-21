#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <vector>

class User;
class Film;

class DataBase
{
public:
    void add_member(User* member);
    void add_film(Film* film);

    User* get_user(int id);
    Film* get_film(int id);
    std::vector<Film*> get_all_films();
    int get_last_user_id();
    int get_last_film_id();

    void delete_film(int id);
protected:

    std::vector <User*> users;
    std::vector <Film*> films;


};


#endif