#include "Request.h"

Request::Request(std::string type, std::string _url)
{
    request_type = type; url = _url;
}