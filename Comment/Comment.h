#ifndef _COMMENT_H_ 
#define _COMMENT_H_

#include <string>
#include <vector>
#include "Reply.h"

class Comment
{
public:
    Comment(std::string _content);
    ~Comment();
    int get_id();
    void reply(Reply* _rep);
    void view();
    
private:
    int id;
    std::string content;
    std::vector <Reply*> replies;
};
#endif  