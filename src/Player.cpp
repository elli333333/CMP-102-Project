//
// Created by smacdonald on 21/04/2020.
//

#include "Player.h"
#include <experimental/random>
#include <iostream>

Player::Player() = default;

Player::Player(std::string name, int accuracy) {
    Player_Name = name;
    Player_Accuracy = accuracy;
    Turn_Score = 0;
    Player_Score = 501;
}

Player::~Player() = default;

void Player::Set_Player_Name(std::string name) {
    Player_Name = name;
}

std::string Player::Get_Player_Name() {
    return Player_Name;
}

void Player::Set_Accuracy(int accuracy) {
    Player_Accuracy = accuracy;
}

int Player::Get_Accuracy() const {
    return Player_Accuracy;
}

int Player::Get_Score() const {
    return Player_Score;
}

void Player::Reset_Score() {
    Player_Score = 501;
}

int Player::Adjust_Score() {
    if (Turn_Score < Player_Score) {
        Player_Score -= Turn_Score;
        Turn_Score = 0;
        return 0; //Success, Score Adjusted
    }
    else if (Turn_Score > Player_Score) {
        Turn_Score = 0;
        return 1; //Failure, Turn over scored
    }
    else {
        return 2;
    }
}


void Player::Throw_Darts() {
    /*
     * Throws set of three at a self determined target,
     * Target is Triple 20 until below score of 180
     */

    int Dart_Board[20] = {20, 1,  18, 4,  13, 6,  10, 15, 2,  17, 3,  19, 7,  16, 8,  11, 14, 9,  12, 5};

    int Round_Value = 0;

    int Target = 000;
    /*
     * Target Board location,
     * No.s 1 -> 20 are valid
     * as are 25 and 50 for bull
     * first digit is multiplier:
     *  - 1: single
     *  - 2: double
     *  - 3: triple
     */

        int Predicted_Score;

    for (int i = 0; i < 3; i++) {
        /*
         * Targeting logic
         * This is really bad
         */
        Predicted_Score = Player_Score;
//        std::cout << "Predicted Score" << Predicted_Score << std::endl;
//        std::cout << "Player Score" << Player_Score << std::endl;

        if (Predicted_Score >= 180) {
            Target = 320;
        }
        else if (Predicted_Score < 180 and Predicted_Score >= 150) {
            Target = 150;
        }
        else if (Predicted_Score < 150 and Predicted_Score >= 120) {
            Target = 220;
        }
        else if (Predicted_Score < 120 and Predicted_Score >= 75) {
            Target = 125;
        }
        else if (Predicted_Score < 75 and Predicted_Score >= 60) {
            Target = 120;
        }
        else if (Predicted_Score < 60 and Predicted_Score >= 45) {
            Target = 115;
        }
        else if (Predicted_Score < 45 and Predicted_Score >= 20) {
            Target = 110;
        }
        else if (Predicted_Score < 20 and Predicted_Score >= 5) {
            Target = 105;
        }
        else if (Predicted_Score < 5 and Predicted_Score >= 0) {
            Target = 101;
        }


        /*
         * Determine Multiplier and Accuracy Penalty
         */

        int Multiplier;

        if ((Target - 300) > 0) {
            Multiplier = 3;
        }
        else if ((Target - 200) > 0) {
            Multiplier = 2;
        }
        else {
            Multiplier = 1;
        }

        Target = Target - (Multiplier * 100);

        int Penalised_Accuracy = Player_Accuracy;

        switch (Multiplier) {
            case 2:
                Penalised_Accuracy -= 15;
                break;
            case 3:
                Penalised_Accuracy -= 20;
                break;
            case 1:
                break;
            default:
                Penalised_Accuracy --;
        }

        int Dart_Value = 0;

//        std::cout << "Target" << Target << std::endl;
//        std::cout << "Multiplier" << Multiplier << std::endl;

        /*
        * Its like cstd random, only nicer
        * - experimental feature introduced in C++ 17
        */
        int rand = std::experimental::randint(0,100);

        /* Check if player hits target */
        if (rand >= Penalised_Accuracy) {
            Dart_Value = (Target * Multiplier);
        }
        else if (rand < Penalised_Accuracy and Target < 25) {
            /*
             * Find values neighbouring the target,
             * Loops through array and finds the values either side,
             * Used to determine missed dart score,
             * This is here because if we hit we don't need it,
             * There is no point in running this preemptively
             */
            int Target_Left;
            int Target_Right;
            for (int i = 0; i <= 19; i++) {
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
                    Dart_Value = Target_Left;
                    break;
                case 1:
                    /* Hits Right */
                    Dart_Value = Target_Right;
                    break;
                case 2:
                    /* Hits High */
                    switch (Multiplier) {
                        case 3:
                            Dart_Value = 0;
                            break;
                        case 2:
                            Dart_Value = Target;
                            break;
                        case 1:
                            if (rand == 0) {
                                Dart_Value = (Target * 3);
                            }
                            else {
                                Dart_Value = (Target * 2);
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
                            Dart_Value = Target;
                            break;
                        case 1:
                            if (rand == 0) {
                                Dart_Value = 25;
                            } else if (rand == 1) {
                                Dart_Value = 50;
                            } else {
                                Dart_Value = (Target * 2);
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
        else if (rand < (Penalised_Accuracy - 15) and Target >= 25) {
            /* Special case if target is the bull */
            rand = std::experimental::randint(0, 20);
            if (Target == 50) {
                if (rand < 10) {
                    Dart_Value = 25;
                }
                else {
                    Dart_Value = Dart_Board[rand];
                }
            }
            else if (Target == 25) {
                if (rand < 5) {
                    Dart_Value = 50;
                }
                else {
                    Dart_Value = Dart_Board[rand];
                }
            }
        }

//        std::cout << "Dart Value" << Dart_Value << std::endl;
//        std::cout << "Predicted Score" << Predicted_Score << std::endl;
        Predicted_Score -= Dart_Value;

    }

    if (Predicted_Score < Player_Score) {
        Player_Score = Predicted_Score;
    }
}
