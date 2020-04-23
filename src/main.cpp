/* Include curses headers
 *  -> used for TUI
 */
#include <curses.h>

/* Include class headers */
#include "Player.h"
#include "Board.h"

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

    /* Sets Terminal mode */
    cbreak();

    /* Print test message */
    printw("Hello World!");
    refresh();

    Sleep(t);

    clear();
    printw("Curses Started Successfully.");
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
     * Code Path for the basic Monte Carlo Simulation of a Standard 501 Darts game
     */

    Player Sid("Sid", 75);
    Player Joe("Joe", 75);

    Board Dart_Board;

    for (int i = 0; i < 10000; i++) {
        do {
            do {
                do {

                } while (Sid.Get_Score() != 0 and Joe.Get_Score() != 0);
            } while (Sid.Matches_Won < 3 and Joe.Matches_Won < 3);
        } while (Sid.Sets_Won < 7 and Joe.Sets_Won < 7);
    }
}