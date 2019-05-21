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

std::string Request::get_type()
{
    return request_type;
}

std::string Request::get_url()
{
    return url;
}

int Request::get_parameters_size()
{
    return parameters.size();
}

std::map <std::string, std::string> Request::get_parameters()
{
    return parameters;
}

