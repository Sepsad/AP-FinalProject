#ifndef _NOTIFICATION_H_ 
#define _NOTIFICATION_H_

#include <string>

class Notification
{
public:
    Notification(std::string _content);
    void view_content();
    bool is_read();
    void set_read();
private:
    std::string content;
    bool read;
};

#endif