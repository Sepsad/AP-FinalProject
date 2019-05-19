#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <vector>

class User;
class Film;

class DataBase
{
public:
    DataBase();
    void add_member(User* member);
    void add_film(Film* film);

    User* get_user(int id);
    Film* get_film(int id);
    std::vector<Film*> get_all_films();

    void delete_film(int id);
    


protected:

    std::vector <User*> members;
    std::vector <Film*> films;


};


#endif