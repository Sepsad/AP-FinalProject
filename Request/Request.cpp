#include "Request.h"

Request::Request(std::string type, std::string _url)
{
    std::map <std::string, std::string> empty;

    request_type = type; url = _url; parameters = empty;
}

Request::Request(std::string type, std::string _url, std::map<std::string, std::string> _parameters)
{
    request_type = type; url = _url; parameters = _parameters;
}



