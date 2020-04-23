//
// Created by smacdonald on 21/04/2020.
//

#include "Board.h"

#include <experimental/random>

Board::Board() = default;
Board::~Board() = default;

int Board::Throw_Dart(int Target, int Player_Accuracy, int Multiplier) {
    /*
     *  Takes Target as base score of location,
     *  applies a penalty to the player accuracy depending on Multiplier
     *  then rolls against a random number
     *
     *  on a successful hit return the requested value (target*multiplier)
     *  on a failed hit return a random neighbour value
     *      50% chance for single neighbour
     *      20% for a double or triple
     *      30% for a bull
     */
    int Player_Accuracy_Clone = Player_Accuracy;
    switch (Multiplier){
        case 1:
            break;
        case 2:     /* Target is Double or Triple */
        case 3:
            Player_Accuracy_Clone -= 20;
            break;
        case 4:     /* Target is Bull */
            Player_Accuracy_Clone -= 30;
            break;
        default:
            break;
    }

    int rand = std::experimental::randint(0,100);

    /* Check if player hits target */
    if (rand >= Player_Accuracy_Clone) {
        return (Target * Multiplier);
    }
    else if (rand < Player_Accuracy_Clone) {
            /* return something else */
        }
    }
}