//
// Created by jswilkin on 4/17/22.
//

#include "Person.h"
#include <iostream>
#include <array>
using namespace std;

#ifndef SMALLPROJECT2_FRIEND_H
#define SMALLPROJECT2_FRIEND_H


class Friend {
public:

    //Building array
    Friend(std::array<Person, 5>&);

    void update_friends();

    void print_favs();

    void friend_of_friend();

private:
    //connecting array to friend list
    std::array<Person, 5>& friend_list;
};


#endif //SMALLPROJECT2_FRIEND_H
