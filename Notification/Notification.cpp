#include "Notification.h"
#include <iostream>

Notification::Notification(std::string _content)
{
    content = content;
    read = false;
}

void Notification::view_content()
{
    std::cout << content << "\n" ;
}

bool Notification::is_read()
{
    return read;
}

void Notification::set_read()
{
    read = true;
}