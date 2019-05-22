#ifndef _RATE_H_ 
#define _RATE_H_

class User;

class Rate
{
public:
    Rate(int _score, User* _user);
    void set_score(int _score);
    int get_score();
private:
    int score;
    User* user;

};


#endif