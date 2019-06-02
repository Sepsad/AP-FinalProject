
#include "RequestReader.h"
#include "../../Exceptions/Exceptions.h"
#include "../../Tools/Tools.h"
#include <iostream>

const std::string POST = "POST";
const std::string GET = "GET";
const std::string DELETE = "DELETE";
const std::string PUT = "PUT";

const std::string QUESTIONSIGNINDEX = "?";

int RequestReader::find_sign_index(std::vector <std::string> req, std::string sign)
{
	for (int i = 0; i < req.size(); i++)
	{
		if(req[i] == sign)
			return i;
	}
	return req.size();
}

std::string RequestReader::create_url(std::vector <std::string> req, int question_sign_index)
{
	std::string url="";
	for (int i = 1; i < question_sign_index; i++)
	{
		url+=req[i];
	}
	return url;
}

std::map <std::string, std::string> RequestReader::get_parameter(std::vector <std::string> req, int question_sign_index)
{
	std::map <std::string, std::string>  parameters;
	
	for (int i = question_sign_index+2 ; i < (req.size()); i +=2)
	{
		parameters[req[i-1]] = req[i];
		// std::cout << req[i] << std::endl;
	}
	return parameters;
}




Request* RequestReader::read(std::string raw_req)
{
    std::vector <std::string> tokenized_string = Tools::parse(raw_req);
	if(tokenized_string.size() < 1)
	{
		return nullptr;
	}
    if(tokenized_string[0] != POST && tokenized_string[0] != GET && 
            tokenized_string[0] != DELETE && tokenized_string[0] != PUT)
    {
        throw BadRequestEx();
        return nullptr;
    }
    std::string type = tokenized_string[0];
    int question_sign_index = RequestReader::find_sign_index(tokenized_string, QUESTIONSIGNINDEX);
    std::string url = RequestReader::create_url(tokenized_string, question_sign_index);
    if(question_sign_index == tokenized_string.size())
    {
        return(new Request(type,url));
    }
    std::map <std::string, std::string> parameters = RequestReader::get_parameter(tokenized_string, question_sign_index);
    
    return (new Request(type, url, parameters));    

}
