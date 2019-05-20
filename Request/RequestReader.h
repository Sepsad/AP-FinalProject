#ifndef _REQUESTREADER_H_
#define _REQUESTREADER_H_
#include "Request.h"

#include <string>
#include <vector>


class RequestReader
{
public:
    static Request* read_to_question_sign(std::string raw_req);
    
};



#endif