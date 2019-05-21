#include "Film.h"
#include <iostream>

Film::Film(std::string _name, int _year, int _lentgh, int _price,
             std::string _summary ,std::string _dircetor, Publisher* _publisher)
{
    name = _name; year = _year; length = _lentgh; price = _price; 
    summary=_summary; director = _dircetor; publisher = _publisher;
    total_score = 0; scorer_numbers = 0;
}

void Film::view(int number)
{
    std::cout << number <<". ";
    std::cout << id << " | ";
    std::cout << name << " | ";
    std::cout << length << " | ";
    std::cout << price << " | ";

    if(scorer_numbers == 0)
        std::cout << 0 << " | ";
    else
        std::cout << double(total_score/scorer_numbers) << " | ";
    
    std::cout <<  year << " | ";
    std::cout << director;
}

void Film::view_details()
{
    std::cout << "Details of Film " << name << std::endl;
    std::cout << "Id = " << id << std::endl;
    std::cout << "Director = " << director << std::endl;
    std::cout << "Length = " << length << std::endl;
    std::cout << "Year = " << year << std::endl;
    std::cout << "Summary = " << summary << std::endl;
    if(scorer_numbers == 0)
        std::cout << "rate = " << 0 << std::endl;
    else
        std::cout << "rate = " << double(total_score/scorer_numbers) << std::endl;
        std::cout << "price = " << price << std::endl;
}