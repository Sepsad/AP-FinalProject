#ifndef _MONEY_H_ 
#define _MONEY_H_

#include "../User/User.h"
#include "../Film/Film.h"

class Money
{

public:
    Money(User* _user, Film* film, int _amount);

    User* get_user();
    Film* get_film();
    int get_amount();

private:
    User* user;
    Film* film;
    int amount;
};




#endif
