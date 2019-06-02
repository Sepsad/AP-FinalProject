#include "Comment.h"
#include <iostream>
#include "../User/User.h"


Comment::Comment(int _id ,std::string _content, User* _user)
{
    id = _id;
    content = _content;
    user = _user;
}

User* Comment::get_user()
{
    return user;
}

int Comment::get_id()
{
    return id;
}

void Comment::reply(Reply* reply)
{
    replies.push_back(reply);
}

void Comment::view()
{
    std::cout << id << ". " ;
    std::cout << content << std::endl;
    for (int i = 0; i < replies.size(); i++)
    {
        std::cout << (i+1) << "." << id << ". " << replies[i]->get_content() << std::endl;
    }
}