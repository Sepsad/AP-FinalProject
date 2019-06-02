#include "Tools.h"
#include "../Exceptions/Exceptions.h"


std::vector<std::string> Tools::parse(std::string request)
{
    std::vector<std::string> tokens_of_line;
	int start = 0 ;
	std::string tmp;
	for (int i = 0 ;i < request.size() ; i++)
	{
		if(request[i] == ' ' || request[i] == '\t' )
		{
			if(start != i)
				tokens_of_line.push_back(request.substr(start,i-start ) );		
			start = i+1;
		}
	}	
	if(start != request.size())
		tokens_of_line.push_back(request.substr( start ,  request.size() - start ));
	return tokens_of_line ;
}

bool Tools::is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}