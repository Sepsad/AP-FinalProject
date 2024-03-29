#ifndef _PUBLISHER_H_ 
#define _PUBLISHER_H_

#include <string>
#include <vector>

#include "User.h"
// #include "../Film/Film.h"
// class User;

class Film;

class Publisher : public User
{
public:
    Publisher(int _id, std::string _email, std::string _username, std::string _password, int _age); 
    void add_film(Film* film);
    void delete_film(int id);
    std::string get_type();
    Film* get_film(int id);
    std::vector<Film*> get_films();    
    
    bool is_publisher();
private:
    std::vector <Film*> films;

  
};

#endif