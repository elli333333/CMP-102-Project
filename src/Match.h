//
// Created by smacdonald on 06/05/2020.
//

#ifndef CMP102_WEEK6_MATCH_H
#define CMP102_WEEK6_MATCH_H

#include "Player.h"

class Match {
private:

public:
    Match();

    struct Score {
        int Score_P0 = 0;
        int Score_P1 = 0;
    };

    Score Run_Match(Player, Player);
    int Run_Set(Player, Player);
    int Run_Game(Player, Player);
};


#endif //CMP102_WEEK6_MATCH_H
