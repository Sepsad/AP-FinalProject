#include "Money.h"


Money::Money(User* _user, int _amount)
{
    user = _user; amount = _amount;
}

User* Money::get_user()
{
    return user;
}

Film* Money::get_film()
{
    return film;
}

int Money::get_amount()
{
    return amount;
}
