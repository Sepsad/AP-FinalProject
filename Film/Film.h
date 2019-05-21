#ifndef _FILM_H_ 
#define _FILM_H_
#include <vector>
#include <string>
#include "../Comment/Comment.h"

class Publisher;

class Film 
{ 
public:
    Film(std::string _name, int _year, int _lentgh, int _price,
             std::string _summary ,std::string _dircetor, Publisher* _publisher);
             
    void view(int number);
    void view_details();
    void add_comment(std::string content);
    void rate(int score);

    bool is_ok_for_view(std::string _name, int min_rate , int min_year 
            ,int _price, int max_year, std::string director);

    int get_id();
    double get_score(); 

protected:
    int id;
    std::string name;
    int year;
    int length;
    int price;
    std::string summary;
    std::string director;
    Publisher* publisher;


    int scorer_numbers;
    int total_score;

    
    std::vector <Comment*> comments;




};

#endif