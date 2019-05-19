#ifndef _NOTIFICATION_H_ 
#define _NOTIFICATION_H_

#include <string>

class Notification
{
public:
    Notification(std::string _content);
    void view_unread();
    void view();
    void read();

private:
    std::string content;
    bool read;
};

#endif