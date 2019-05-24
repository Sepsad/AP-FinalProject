#include "Money.h"


Money::Money(User* _user, Film* _film, int _amount)
{
    user = _user; amount = _amount; film = _film;
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
