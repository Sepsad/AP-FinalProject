#ifndef _FILM_H_ 
#define _FILM_H_
#include <vector>
#include <string>
#include "../Rate/Rate.h"
#include "../Comment/Comment.h"
#include "../Comment/Reply.h"

class Publisher;

class Film 
{ 
public:
    Film(std::string _name, int _year, int _lentgh, int _price,
             std::string _summary ,std::string _dircetor, Publisher* _publisher);
             
    void view(int number);
    void view_details();
    void add_comment(Comment* comment);
    void add_reply_to_comment(int comment_id, Reply* reply);
    void rate(Rate* rate);




    void edit_film(std::string _name, int _year, int _lentgh,
         std::string _summary ,std::string _dircetor);
    // bool is_ok_for_view(std::string _name, int min_rate , int min_year 
            // ,int _price, int max_year, std::string director);

    int get_id();
private:
    int id;
    std::string name;
    int year;
    int length;
    int price;
    std::string summary;
    std::string director;


    Publisher* publisher;
    std::vector <Rate*> rates;

    double calculate_total_score();
    
    std::vector <Comment*> comments;




};

#endif