#ifndef _FILM_H_ 
#define _FILM_H_
#include <vector>
#include <string>
// #include "../User/User.h"
// #include "../Rate/Rate.h"
// #include "../Comment/Comment.h"
// #include "../Comment/Reply.h"
// #include "../User/Publisher.h"

class User;
class Rate;
class Comment;
class Reply;

class Film 
{ 
public:

    Film();
    Film(int _id, std::string _name, int _year, int _lentgh, int _price ,std::string _summary ,std::string _dircetor, User* _publisher);
             
    void view();
    void view_details();
    void view_comments();
    void view_recom();
    void add_comment(std::string content, User* user);
    void add_reply_to_comment(int comment_id, Reply* reply);
    void rate(Rate* rate);

    int get_id();
    double get_rate();
    int get_price();
    User* get_publisher();
    std::string get_name();
    Comment* get_comment(int id);



    void delete_comment(int id);
    

    void edit_film(std::string _name, std::string _year, std::string _lentgh,
         std::string _summary ,std::string _dircetor);
    bool ok_for_view(std::string _name, std::string min_rate , std::string min_year 
            ,std::string _price, std::string max_year, std::string director);

private:
    int id;
    std::string name;
    int year;
    int length;
    int price;
    std::string summary;
    std::string director;


    User* publisher;
    std::vector <Rate*> rates;

    double calculate_total_score();
    
    std::vector <Comment*> comments;




};

#endif