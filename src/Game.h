//
// Created by smacdonald on 21/04/2020.
//

#ifndef CMP_102_PROJECT_GAME_H
#define CMP_102_PROJECT_GAME_H

class Game {
private:
    int Matches_Played{};
    int Sets_Played{};
    int Games_Played{};

    int Init_Type{};

public:
    Game();
    ~Game();

    int Start_Match();
    int Start_Set();
    int Start_Game();

    int Set_Init_Type();
    int Get_Init_Type();

    int Get_Round();
    int Get_Average_rounds();

    int Get_Games_Played();
    int Get_Sets_Played();
    int Get_Matches_Played();
};


#endif //CMP_102_PROJECT_GAME_H