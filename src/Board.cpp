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


    /*
     * Its like cstd random, only nicer
     * - experimental feature introduced in C++ 17
     */
    int rand = std::experimental::randint(0,100);

    /* Check if player hits target */
    if (rand >= Player_Accuracy_Clone) {
        return (Target * Multiplier);
    }
    else if (rand < Player_Accuracy_Clone and Target < 25) {
       /*
        * Find values neighbouring the target,
        * Loops through array and finds the values either side,
        * Used to determine missed dart score,
        * This is here because if we hit we don't need it,
        * There is no point in running this preemptively
        */
        int Target_Left;
        int Target_Right;
        for (int i = 0; i < 19; i++) {
            if (Dart_Board[i] == Target) {
                if (i != 0) {
                    Target_Left = Dart_Board[i--];
                }
                else {
                    Target_Left = Dart_Board[19];
                }
                Target_Right = Dart_Board[i++];
            }
            else {
                /*
                 * Should never reach this state,
                 * if it does there are bigger problems
                 */
            }
        }

        rand = std::experimental::randint(0, 3);
        switch (rand) {
            case 0:
                /* Hits Left */
                return Target_Left;
                break;
            case 1:
                /* Hits Right */
                return Target_Right;
                break;
            case 2:
                /* Hits High */
                switch (Multiplier) {
                    case 3:
                        return 0;
                        break;
                    case 2:
                        return Target;
                        break;
                    case 1:
                        if (rand == 0) {
                            return (Target * 3);
                        }
                        else {
                            return (Target * 2);
                        }
                        break;

                    default:
                        break;
                }
            case 3:
                /* Hits Low */
                switch (Multiplier) {
                    case 3:
                    case 2:
                        return Target;
                        break;
                    case 1:
                        if (rand == 0) {
                            return 25;
                        } else if (rand == 1) {
                            return 50;
                        } else {
                            return (Target * 2);
                        }
                        break;
                    default:
                        break;
                }
                break;
            default:
                /* Shouldn't happen */
                break;
        }
    }
    else if (rand < Player_Accuracy_Clone and Target >= 25) {
        /*
         * Special case if target is the bull
         */
        rand = std::experimental::randint(0, 20);
        if (Target == 50) {
            if (rand < 10) {
                return 25;
            }
            else {
                return Dart_Board[rand];
            }
        }
        else if (Target == 25) {
            if (rand < 5) {
                return 50;
            }
            else {
                return Dart_Board[rand];
            }
        }
    }
    else {
        /*
         * Catch all clause in case the above fall through
         */
        return 0;
    }

    /* Satisfy the clang-tidy */
    return 0;
}
