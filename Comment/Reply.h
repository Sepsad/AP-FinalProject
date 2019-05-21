#ifndef _REPLY_H_ 
#define _REPLY_H_

#include <string>

class Reply
{
public:
    Reply(std::string _content) { content = _content; }
    std::string get_content() { return content; }
private:
    std::string content;
}; 

#endif