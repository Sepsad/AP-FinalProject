#ifndef _REQUESTREADER_H_
#define _REQUESTREADER_H_
#include "Request.h"

#include <string>
#include <vector>


class RequestReader
{
public:
    static Request* read(std::string raw_req);
private:
    static int find_sign_index(std::vector <std::string> req, std::string sign);
    static std::string create_url(std::vector <std::string> req, int question_sign_index);
    static std::map <std::string, std::string> get_parameter(std::vector <std::string> req, int question_sign_index);

};



#endif