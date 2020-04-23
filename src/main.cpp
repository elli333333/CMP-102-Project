/* Include curses headers
 *  -> used for TUI
 */
#include <curses.h>

/* Include class headers */
#include "Game.h"
#include "Player.h"
#include "Board.h"

/* Define "Shorthand" for different game types */
const int INTERACTIVE = 1;
const int SIMULATION_501 = 2;
const int SIMULATION_301 = 3;

/* Boost C++ Library timing */
#include <boost/chrono.hpp>
#include <boost/thread.hpp>

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

//    if (* Game_Init_Type == SIMULATION_501) {
//        Simulation_501();
//    }
//    else if (* Game_Init_Type == INTERACTIVE) {
//        printw("Mode not Implemented");
//    }
//    else if (* Game_Init_Type == SIMULATION_301) {
//        printw("Mode Not Implemented");
//    }

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
     * Wrapper function for sleep using boost C++ thread and chrono.
     * parameter 't' is time in milliseconds
     */
    boost::this_thread::sleep_for (boost::chrono::milliseconds(t));
}

void Simulation_501() {
    /*
     * Code Path for the basic Monte Carlo Simulation of a Standard 501 Darts game
     */

    const int * Game_Init_Type = &SIMULATION_501;

    Player Sid(* Game_Init_Type, "Sid", 75);
    Player Joe(* Game_Init_Type, "Joe", 75);
}