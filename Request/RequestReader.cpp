
#include "RequestReader.h"
#include "../Exceptions/Exceptions.h"
#include "../Tools/Tools.h"

const std::string POST = "POST";
const std::string GET = "GET";
const std::string DELETE = "DELETE";
const std::string PUT = "PUT";


Request* RequestReader::read_to_question_sign(std::string raw_req)
{
    std::vector <std::string> tokenized_string = Tools::parse(raw_req);
    
    if(tokenized_string[0] != POST || tokenized_string[0] != GET || 
            tokenized_string[0] != DELETE || tokenized_string[0] != PUT)
    {
        throw BadRequestEx();
        return NULL;
    }

    std::string type = tokenized_string[0];
    std::string url = "";
    int question_sign_index=1;

    while (tokenized_string[question_sign_index] != "?")
    {
        url += tokenized_string[question_sign_index];
        question_sign_index++;
    }

    if(question_sign_index == tokenized_string.size())
    {
        return(new Request(type,url));
    }

    std::map <std::string, std::string> parameters;

    
    

    
    
    
        
    

}