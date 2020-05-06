//
// Created by smacdonald on 21/04/2020.
//

#include "Player.h"

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


void Player::Throw_Dart() {
    /*
     * Throws dart at a self determined target,
     * Target is Triple 20 until below score of 180
     */

    int Target = 0;
    int Multiplier = 1;

    if (Player_Score > 180) {
        Target = 20;
        Multiplier = 3;
    }
    else if (Player_Score <= 180) {

    }
}


