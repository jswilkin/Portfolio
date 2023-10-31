// Jacob Wilkin
// CPSC 306; Spring 2022
// Small Project 2 - main.cpp
// main driver for Person class.

//Code Summary: Implementing two file classes that have 3 global arrays with 3 corresponding global functions.

#include <iostream>
#include "Person.h"
#include "Friend.h"
using namespace std;

int main() {
    //printouts from rubric with the class functions
    Person agent_a ("Andrea", "Adams", Person::select_movie(), Person::select_music(), Person::select_game());
    Person agent_b ("Bernie", "Bates", Person::select_movie(), Person::select_music(), Person::select_game());
    Person agent_c ("Charlotte", "Caylorlie", Person::select_movie(), Person::select_music(), Person::select_game());
    Person agent_d ("Duayne", "Dramtoix", Person::select_movie(), Person::select_music(), Person::select_game());
    Person agent_e ("Edward", "Edmunds", Person::select_movie(), Person::select_music(), Person::select_game());

    Person agent_f ("Francous", "Frenchie");
    Person agent_g ("Gerald", "Gramatix");
    Person agent_h ("Hope", "Hjung");
    Person agent_i ("Ivan", "Issiac");
    Person agent_j ("Jessia", "Jones");

    //Building an array of people
    array<Person, 5> people_list{agent_a,agent_f,agent_g,agent_h,agent_i};
    Friend my_friends{people_list};

    my_friends.update_friends();
    my_friends.print_favs();
    cout << "check games" << endl;
    my_friends.friend_of_friend();

    return 0;
}
