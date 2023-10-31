// Jacob Wilkin
// Created by jswilkin on 4/17/22.
// Person.h file

#include <iostream>
using namespace std;

#ifndef SMALLPROJECT2_PERSON_H
#define SMALLPROJECT2_PERSON_H


class Person {
public:

    //Constructors
    friend class Friends;

    Person(const std::string, const std::string);

    Person(const std::string, const std::string, std::string, std::string, std::string);

    //Destructor
    ~Person();

    //Stating the getters
    std::string get_first_name();
    std::string get_last_name();
    std::string get_fav_movie();
    std::string get_fav_music();
    std::string get_fav_game();
    void to_string();

    //Stating the setters
    void set_fav_movie(std::string);
    void set_fav_music(std::string);
    void set_fav_game(std::string);

    //Stating the user select functions
    static std::string select_music();
    static std::string select_movie();
    static std::string select_game();

private:
    //Creating variables in private
    std::string first_name;
    std::string last_name;
    std::string fav_movie = "none";
    std::string fav_music = "none";
    std::string fav_game = "none";

    const static std::string music_genre[5];
    const static std::string movie_genre[4];
    const static std::string game_genre[4];
};


#endif //SMALLPROJECT2_PERSON_H
