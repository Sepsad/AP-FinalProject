#ifndef _COMMENT_H_ 
#define _COMMENT_H_

#include <string>
#include <vector>

class Comment
{
public:
    Comment(std::string _content);
    void reply(Comment* _cm);
    void view();
    
private:
    int id;
    std::string content;
    std::vector <Comment*> replies;
};
#endif  