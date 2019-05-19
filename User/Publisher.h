#ifndef _PUBLISHER_H_ 
#define _PUBLISHER_H_
#include "User.h"

class Publisher : public User
{
public:
    Publisher(std::string _email, std::string _username, std::string _password, int _age); 
    void add_film(Film* film);
    void edit_film(int id);
    void delete_film(int id);

    void get_money_from_network();

    void reply(int film_id, int comment_id, std::string content);
    void delete_comment(int film_id, int comment_id);

    virtual void get_type(); 
private:
    std::vector <Film*> films;

  
};

#endif