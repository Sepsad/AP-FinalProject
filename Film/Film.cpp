#include "Film.h"
#include "../Exceptions/Exceptions.h"
#include "../Tools/Tools.h"
#include <iostream>

Film::Film(int _id,std::string _name, int _year, int _lentgh, int _price,
             std::string _summary ,std::string _dircetor, User* _publisher)
{
    id =_id;
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



void Film::view()
{
    std::cout << id << " | ";
    std::cout << name << " | ";
    std::cout << length << " | ";
    std::cout << price << " | ";
    std::cout << calculate_total_score() << " | ";
    std::cout <<  year << " | ";
    std::cout << director << std::endl;
}

void Film::view_recom()
{
    std::cout << id << " | ";
    std::cout << name << " | ";
    std::cout << length << " | ";
    std::cout << director << std::endl;

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


void Film::view_comments()
{
    for (int i = 0; i < comments.size(); i++)
    {
        comments[i]->view();
    }
}

void Film::add_comment(std::string content,User* user)
{   
    if(comments.size() == 0)
    {
        comments.push_back(new Comment(1, content, user));
    }
    else
    {
        comments.push_back(new Comment(comments.size()+1, content, user));
    }
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
int Film::get_price()
{
    return price;
}


double Film::get_rate()
{
    return calculate_total_score();
}

User* Film::get_publisher()
{
    return publisher;
}
std::string Film::get_name()
{
    return name;
}

Comment* Film::get_comment(int id)
{
    for (int i = 0; i < comments.size(); i++)
    {
        if(comments[i]->get_id() == id)
        {
            return comments[i];
        }
    }
    return NULL;
}



void Film::delete_comment(int id)
{
    std::vector<Comment*>::iterator it;
    for (it = comments.begin(); it != comments.end(); it++)
    {
        if((*it)->get_id() == id)
        {
            delete * it;
            it = comments.erase(it);
            return;
        }
    }
    throw NotFoundEx();
}




void Film::edit_film(std::string _name , std::string _year , std::string _lentgh ,
             std::string _summary, std::string _dircetor )
{
    if(_name != "")
    {
        name = _name;
    }
    if(_year != "" && Tools::is_number(_year))
    {
        year = std::stoi(_year);
    }
    if(_lentgh != "" && Tools::is_number(_lentgh))
    {
        year = std::stoi(_lentgh);
    }
    if(_summary != "")
    {
        summary = _summary;
    }
    if(_dircetor != "")
    {
        director = _dircetor;
    }
}

bool Film::ok_for_view(std::string _name , std::string min_rate , std::string min_year ,
        std::string _price, std::string max_year, std::string _director)
{
    int _min_rate = -1 ;
    int _min_year = 0 ;
    int _max_year = 10000;
    int __price = -1 ; 

    if( Tools::is_number(min_year))
    {
        _min_year = std::stoi(min_year);
    }
    if( Tools::is_number(max_year))
    {
        _max_year = std::stoi(max_year);
    }
    if( Tools::is_number(min_rate))
    {
        _min_rate = std::stoi(min_rate);
    }
    if( Tools::is_number(_price))
    {
        __price = std::stoi(_price);
    }
    return ((name == _name) & (director == _director) &  (price == __price) & 
            (calculate_total_score() > _min_rate) & (year > _min_year) & (year < _max_year))   ;
}


