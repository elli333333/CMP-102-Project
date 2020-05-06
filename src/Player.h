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

    int Dart_Board[20] = {20, 1,  18, 4,  13, 6,  10, 15, 2,  17, 3,  19, 7,  16, 8,  11, 14, 9,  12, 5};

public:

    Player(std::string, int);
    Player();
    ~Player();

    std::string Get_Player_Name();
    void Set_Player_Name(std::string);

    int Get_Accuracy() const;
    void Set_Accuracy(int);

    int Get_Score() const;
    int Adjust_Score();
    void Reset_Score();

    void Throw_Dart();
};


#endif //CMP_102_PROJECT_PLAYER_H
