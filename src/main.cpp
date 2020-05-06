/* Include curses headers
 *  -> used for TUI
 */
#include <curses.h>

/* Include class headers */
#include "Player.h"
#include "Match.h"

/* Standard Library C++ Library timing */
#include <chrono>
#include <thread>

/* Function Prototypes */
void Curses_Init(int t);
void Curses_Destruct();

void Sleep(int);

void Simulation_501();

/* Main */
int main() {
    Curses_Init(50);

    Sleep(100);

    Simulation_501();

    Curses_Destruct();
}

void Curses_Init(int t) {
    /*
     * Function calls all curses Initialisation functions,
     * Sets up the window, and finally prints welcome message
     * takes int t - time(ms) to sleep after init
     * before clearing display
     */

    /* Starts curses */
    initscr();

    /* Suppresses character echos */
    noecho();

    /*
     * Sets Terminal mode,
     * Removes Input delay and need for Enter to be pressed
     */
    cbreak();

    /* Print test message */
    printw("Hello World!");
    refresh();

    Sleep(t);

    clear();
    refresh();
}

void Curses_Destruct() {
    /*
     * Cleanly exits Curses mode,
     * Without this the terminal may not function correctly after program exit,
     * Clears windows and exits, resetting the terminal.
     */

    clear();
    refresh();
    endwin();
}

void Sleep(int t) {
    /*
     * Wrapper function for sleep using Standard Library C++ thread and chrono.
     * parameter 't' is time in milliseconds
     */
    std::this_thread::sleep_for (std::chrono::milliseconds(t));
}

void Simulation_501() {
    /*
     * Basic Monte Carlo Simulation of a Standard 501 Darts game
     */

    Player Player_0("Sid", 75);
    Player Player_1("Joe", 75);


    struct Rounds_Won {
        /* Player_One/Player_Two */
        int seven_6 = 0,
            seven_5 = 0,
            seven_4 = 0,
            seven_3 = 0,
            seven_2 = 0,
            seven_1 = 0,
            six_7 = 0,
            five_7 = 0,
            four_7 = 0,
            three_7 = 0,
            two_7 = 0,
            one_7 = 0;
    };

    Rounds_Won Win_Rates;

    Match Active_Match;
    Match::Score Match_Score;

    /* Begin timer for simulation loop */
    std::chrono::steady_clock::time_point Timer_Start = std::chrono::steady_clock::now();

    for (int i = 0; i < 10000; i++) {
        Match_Score = Active_Match.Run_Match(Player_0, Player_1);
        if (Match_Score.Score_P0 == 7) {
            switch (Match_Score.Score_P1) {
                case 1:
                    Win_Rates.seven_1 ++;
                    break;
                case 2:
                    Win_Rates.seven_2 ++;
                    break;
                case 3:
                    Win_Rates.seven_3 ++;
                    break;
                case 4:
                    Win_Rates.seven_4 ++;
                    break;
                case 5:
                    Win_Rates.seven_5 ++;
                    break;
                case 6:
                    Win_Rates.seven_6 ++;
                    break;
                default:
                    break;
            }
        }
        else if (Match_Score.Score_P1 == 7) {
            switch (Match_Score.Score_P0) {
                case 1:
                    Win_Rates.one_7 ++;
                    break;
                case 2:
                    Win_Rates.two_7 ++;
                    break;
                case 3:
                    Win_Rates.three_7 ++;
                    break;
                case 4:
                    Win_Rates.four_7 ++;
                    break;
                case 5:
                    Win_Rates.five_7 ++;
                    break;
                case 6:
                    Win_Rates.six_7 ++;
                    break;
                default:
                    break;
            }
        }
        else {
            ;
        }
    }

    /* End timer for simulation loop */
    std::chrono::steady_clock::time_point Timer_End = std::chrono::steady_clock::now();

    std::chrono::duration_cast<std::chrono::microseconds>(Timer_End - Timer_Start)

}
