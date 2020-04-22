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

public:
    Player(int, std::string, int);
    ~Player();

    std::string Get_Player_Name();
    std::string Set_Player_Name(std::string);

    int Get_Accuracy();
    int Set_Accuracy(int);

    int Get_Score();
    int Adjust_Score(int);
};


#endif //CMP_102_PROJECT_PLAYER_H
