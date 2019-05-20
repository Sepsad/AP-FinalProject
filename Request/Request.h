#ifndef _REQUEST_H_ 
#define _REQUEST_H_

#include <string>
#include <map>
#include <vector>

class Request
{
public:
    Request(std::string type, std::string _url, std::map<std::string, std::string> _parameters);
    Request(std::string type, std::string _url);
private:
    std::string request_type;
    std::string url;
    std::map <std::string, std::string> parameters;
};


#endif