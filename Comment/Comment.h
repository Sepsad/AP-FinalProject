#ifndef _COMMENT_H_ 
#define _COMMENT_H_

#include <string>
#include <vector>
#include "Reply.h"
// #include "../User/User.h"
// #include "../Film/Film.h"
class User;

class Comment
{
public:
    Comment(int _id ,std::string _content,User* _user);
    // ~Comment();
    int get_id();
    User* get_user();

    void reply(Reply* _rep);
    void view();
    
private:
    int id;
    User* user;
    std::string content;
    std::vector <Reply*> replies;
};
#endif  