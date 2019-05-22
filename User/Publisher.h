#ifndef _PUBLISHER_H_ 
#define _PUBLISHER_H_
#include "User.h"

class Publisher : public User
{
public:
    Publisher(std::string _email, std::string _username, std::string _password, int _age); 
    void add_film(Film* film);
    void delete_film(int id);

    void get_money_from_network();

    virtual std::string get_type(); 
    
private:
    std::vector <Film*> films;

  
};

#endif