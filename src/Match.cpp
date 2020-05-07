//
// Created by smacdonald on 06/05/2020.
//

#include "Match.h"
#include <iostream>

Match::Match() = default;

Match::Score Match::Run_Match(Player Player_0, Player Player_1) {
    int Set_Winner = 0;

    int Score_P0 = 0;
    int Score_P1 = 0;

    std::cout << "Player 0" << Player_0.Get_Score() << std::endl;
    std::cout << "Player 1" << Player_1.Get_Score() << std::endl;

    std::cout << "Starting sets\n";
    do {
        Set_Winner = Run_Set(Player_0, Player_1);
        switch (Set_Winner) {
            case 0:
                Score_P0 ++;
                break;
            case 1:
                Score_P1 ++;
                break;
            default:
                break;
        }
        std::cout << "Set Finished\n";
    } while ((Score_P0 != 7) and (Score_P1 != 7));

    Match::Score Return_Value;

    Return_Value.Score_P0 = Score_P0;
    Return_Value.Score_P1 = Score_P1;

    return Return_Value;
}

int Match::Run_Set(Player Player_0, Player Player_1) {
    int Game_Winner = 0;

    int Score_P0 = 0;
    int Score_P1 = 0;

    std::cout << "Starting Games\n";
    do {
        Game_Winner = Run_Game(Player_0, Player_1);
        switch (Game_Winner) {
            case 0:
                Score_P0 ++;
                break;
            case 1:
                Score_P1 ++;
                break;
            default:
                return 2;
        }

        std::cout << "Game Finished";
    } while ((Score_P0 != 7) and (Score_P1 != 7));

    if (Score_P0 == 3) {
        return 0;
    }
    else if (Score_P1 == 2) {
        return 1;
    }
    else {
        return 2;
    }
}

int Match::Run_Game(Player Player_0, Player Player_1) {
    Player_0.Reset_Score();
    Player_1.Reset_Score();

    int Score_P0 = 0;
    int Score_P1 = 0;

    do {
        do {
//            std::cout << "Throwing Darts\n";
            Player_0.Throw_Darts();
//            std::cout << "p0" << Player_0.Get_Score() << std::endl;
            Player_1.Throw_Darts();
//            std::cout << "p1" << Player_1.Get_Score() << std::endl;
        } while ((Player_0.Get_Score() != 0) and (Player_1.Get_Score() != 0));

        std::cout << "Winning Game\n";
        if ((Player_0.Get_Score() == 0) and (Player_1.Get_Score() != 0)) {
            Score_P0 ++;
        }
        else if ((Player_1.Get_Score() == 0) and (Player_0.Get_Score() != 0)) {
            Score_P1 ++;
        }

    } while ((Score_P0 != 3) and (Score_P1 != 3));

    if (Score_P0 == 3) {
        std::cout << "p0 won\n";
        return 0;
    }
    else {
        std::cout << "p1 won\n";
        return 1;
    }

}