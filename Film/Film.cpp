#include "Film.h"
#include "../Exceptions/Exceptions.h"
#include <iostream>

Film::Film(std::string _name, int _year, int _lentgh, int _price,
             std::string _summary ,std::string _dircetor, Publisher* _publisher)
{
    name = _name; year = _year; length = _lentgh; price = _price; 
    summary=_summary; director = _dircetor; publisher = _publisher;
    std::vector <Rate*> _rates; rates = _rates; 
}

double Film::calculate_total_score()
{
    if(rates.size() == 0)
    {
        return 0;
    }
    double total=0;
    for (int i = 0; i < rates.size(); i++)
    {
        total += rates[i]->get_score();
    }

    total = total / rates.size();
    return total;
}



void Film::view(int number)
{
    std::cout << number <<". ";
    std::cout << id << " | ";
    std::cout << name << " | ";
    std::cout << length << " | ";
    std::cout << price << " | ";
    std::cout << calculate_total_score() << " | ";
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
    std::cout << "rate = " << calculate_total_score() << std::endl;
    std::cout << "price = " << price << std::endl;
}

void Film::add_comment(Comment* comment)
{
    comments.push_back(comment);
}

void Film::add_reply_to_comment(int id, Reply* reply)
{
    for (int i = 0; i < comments.size(); i++)
    {
        if(comments[i]->get_id() == id)
        {
            comments[i]->reply(reply);
            return;
        }
    }

    throw NotFoundEx();
}


void Film::rate(Rate* rate)
{
    rates.push_back(rate);
}

int Film::get_id()
{
    return id;
}



void Film::edit_film(std::string _name = "", int _year = -1, int _lentgh = -1,
             std::string _summary = "", std::string _dircetor = "")
{

}

