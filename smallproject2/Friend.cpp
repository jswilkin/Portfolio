//
// Created by jswilkin on 4/17/22.
//

#include "Friend.h"
#include "Person.h"
#include <iostream>
#include <array>
using namespace std;

    Friend::Friend(std::array<Person, 5>& these_people)
        : friend_list(these_people) {
    }

    void Friend::update_friends(){
        for (int x = 0; x < 5; x++){
            if (this->friend_list[x].get_fav_movie() == "none"){ //If they don't have a favorite
                //Going through each genre
                this->friend_list[x].set_fav_movie(Person::select_movie());
                this->friend_list[x].set_fav_music(Person::select_music());
                this->friend_list[x].set_fav_game(Person::select_game());
            }
        }
    }

    void Friend::print_favs() {
        for (int x = 0; x < 5; x++){
            this->friend_list[x].to_string();
        }
    }

    //Printing out list of friends that share same interests
    void Friend::friend_of_friend() {
        for (int x = 0; x < 4; x++){
            string favmovie = this->friend_list[x].get_fav_movie();
            string favmusic = this->friend_list[x].get_fav_music();
            string favgame = this->friend_list[x].get_fav_game();
            for (int y = 1; y < 5; y++){
                string favmov= this->friend_list[y].get_fav_movie();
                string favmus = this->friend_list[y].get_fav_music();
                string favgam = this->friend_list[y].get_fav_game();
                if ((favmovie == favmov) && (friend_list[x].get_first_name() != friend_list[y].get_first_name())){
                    cout << "\n\t" << friend_list[x].get_first_name() << " and "
                    << friend_list[y].get_first_name() << " share an interest in movies."; }
                if ((favmusic == favmus) && (friend_list[x].get_first_name() != friend_list[y].get_first_name())){
                    cout << "\n\t" << friend_list[x].get_first_name() << " and "
                         << friend_list[y].get_first_name() << " share an interest in music."; }
                if ((favgame == favgam) && (friend_list[x].get_first_name() != friend_list[y].get_first_name())){
                    cout << "\n\t" << friend_list[x].get_first_name() << " and "
                         << friend_list[y].get_first_name() << " share an interest in games."; }
            }
        }
    }