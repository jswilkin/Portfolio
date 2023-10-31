//
// Created by jswilkin on 4/17/22.
//

#include "Person.h"
#include <iostream>
#include <string>
#include <random>
using namespace std;

//Listing the attributes for each global function
const std::string Person::music_genre[5]{"world", "rock", "hiphop", "jazz", "classical"};
const std::string Person::movie_genre[4]{"documentary", "action", "adventure", "romance"};
const std::string Person::game_genre[4]{"adventure", "role play", "educational", "sports"};

//user select functions
std::string Person::select_music() {
    int mus = rand() % 5;
    return music_genre[mus];
}

std::string Person::select_movie() {
    int movie = rand() % 4;
    return movie_genre[movie];
}

std::string Person::select_game() {
    int game = rand() % 4;
    return game_genre[game];
}

    Person::Person(const string the_first, const string the_last)
    : first_name{the_first}, last_name{the_last}
    {}

    Person::Person(const string first, const string last, string movie, string music, string game)
    : first_name{first}, last_name{last}, fav_movie{movie}, fav_music{music}, fav_game{game}
    {}

    //Destructor
    Person::~Person() {}

    //getters

    string Person::get_first_name(){
        return this->first_name;
    }

    string Person::get_last_name(){
        return this->last_name;
    }

    string Person::get_fav_movie(){
        return this->fav_movie;
    }

    string Person::get_fav_music(){
        return this->fav_music;
    }

    string Person::get_fav_game(){
        return this->fav_game;
    }

    //setters

    void Person::set_fav_game(std::string new_game) {
        this->fav_game = new_game;
    }

    void Person::set_fav_movie(std::string new_movie) {
        this->fav_movie = new_movie;
    }

    void Person::set_fav_music(std::string new_music) {
        this->fav_music = new_music;
    }

    //Printouts for favorite genres of each global function
    void Person::to_string(){
        cout << "\n" << get_first_name() << ", " << get_last_name()
        << "\n\t favorite movie genre is, " << get_fav_movie()
        << "\n\t favorite music genre is, " << get_fav_music()
        << "\n\t favorite game genre is, " << get_fav_game() << endl;
    }