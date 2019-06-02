#include "Rate.h"
#include "../User/User.h"


Rate::Rate(int _score, User* _user)
{
    score = _score; user = _user;
}

int Rate::get_score()
{
    return score;
}