#include "Comment.h"
#include <iostream>

Comment::Comment(std::string _content)
{
    content = _content;
}
// Comment::~Comment()
// {
//     for (int i = 0; i < replies.size(); i++)
//     {
//         delete replies[i];
//     }
// }


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