#ifndef _NOTIFICATION_H_ 
#define _NOTIFICATION_H_

#include <string>

class Notification
{
public:
    Notification(std::string _content);
    std::string get_content();
    bool is_read();

private:
    std::string content;
    bool read;
};

#endif