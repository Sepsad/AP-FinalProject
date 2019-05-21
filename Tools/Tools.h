#ifndef _TOOLS_H_
#define _TOOLS_H_

#include <string>
#include <vector>
#include <map>

class Tools
{
public:
    static std::vector<std::string> parse(std::string request);
    static std::string hash_password(std:: string);
};

#endif