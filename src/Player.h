//
// Created by smacdonald on 21/04/2020.
//

#ifndef CMP_102_PROJECT_PLAYER_H
#define CMP_102_PROJECT_PLAYER_H

#include <string>

class Player {
private:
    std::string Player_Name;
    int Player_Accuracy;

    int Player_Score;

    int Turn_Score;


public:
    int Rounds_Won = 0;
    int Matches_Won = 0;
    int Sets_Won = 0;
    int Games_Won = 0;

    Player(std::string, int);
    ~Player();

    std::string Get_Player_Name();
    void Set_Player_Name(std::string);

    int Get_Accuracy() const;
    void Set_Accuracy(int);

    int Get_Score() const;
    int Adjust_Score();

    void Adjust_Turn_Score(int);
};


#endif //CMP_102_PROJECT_PLAYER_H
