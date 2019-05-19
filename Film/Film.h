#ifndef _FILM_H_ 
#define _FILM_H_

#include <string>
#include "../Comment/Comment.h"

class Publisher;

class Film 
{ 
public:
    Film(std::string _name, int _year, int _lentgh, int _price,
             std::string _summary ,std::string _dircetor, Publisher* publisher);
             
    void view();
    void view_details();
    void add_comment(std::string content);
    void rate(int score);

    double get_score(); 

protected:
    int id;
    std::string name;
    int year;
    int length;
    int price;
    std::string summary;
    std::string director;



    int scorer_numbers;
    int total_score;

    
    std::vector<Comment*> comments;




};

#endif