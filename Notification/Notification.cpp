#include "Notification.h"

Notification::Notification(std::string _content)
{
    content = content;
    read = false;
}

std::string Notification::get_content()
{
    read = true;
    return content;
}

bool Notification::is_read()
{
    return read;
}

void Notification::set_read()
{
    read = true;
}