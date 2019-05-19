#include "User.h"

User::User(std::string _email, std::string _username, std::string _password, int _age)
{
    

}


bool is_email_valid(std::string& email)
{
    const std::regex pattern
            ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return std::regex_match(email,pattern);
}