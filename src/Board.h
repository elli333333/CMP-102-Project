//
// Created by smacdonald on 21/04/2020.
//

#ifndef CMP_102_PROJECT_BOARD_H
#define CMP_102_PROJECT_BOARD_H


class Board {
private:
    int Dart_Board[20] = {20, 1,  18, 4,  13, 6,  10, 15, 2,  17, 3,  19, 7,  16, 8,  11, 14, 9,  12, 5};

public:
    Board();
    ~Board();

    int Throw_Dart(int, int, int);
    /*
     * Target, Player_Accuracy
     * Returning throw score
     */
};

#endif //CMP_102_PROJECT_BOARD_H