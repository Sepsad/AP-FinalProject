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
    std::string get_type();
    std::string get_url();
    int get_parameters_size();
    std::map <std::string, std::string> get_parameters();
    
private:
    std::string request_type;
    std::string url;
    std::map <std::string, std::string> parameters;
};


#endif