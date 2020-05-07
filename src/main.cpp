/* Include class headers */
#include "Player.h"
#include "Match.h"

/* Standard Library C++ Library timing */
#include <chrono>
#include <thread>

/* iostream */
#include <iostream>

/* Function Prototypes */
void Simulation_501();

/* Main */
int main() {
    Simulation_501();
}

void Simulation_501() {
    /*
     * Basic Monte Carlo Simulation of a Standard 501 Darts game
     */

    Player Player_0("Sid", 75);
    Player Player_1("Joe", 80);

    int Win_Rates[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    Match Active_Match;
    Match::Score Match_Score;

    int Matches = 10;

    std::cout << "501 Simple Darts Simulation" << std::endl;
    std::cout << "Starting Simulation\n";

    for (int i = 0; i < Matches; i++) {
        std::cout << "Running Match: " << i << std::endl;
        Match_Score = Active_Match.Run_Match(Player_0, Player_1);
        if (Match_Score.Score_P0 == 7) {
            switch (Match_Score.Score_P1) {
                case 1:
                    Win_Rates[0] ++;
                    break;
                case 2:
                    Win_Rates[1] ++;
                    break;
                case 3:
                    Win_Rates[2] ++;
                    break;
                case 4:
                    Win_Rates[3] ++;
                    break;
                case 5:
                    Win_Rates[4] ++;
                    break;
                case 6:
                    Win_Rates[5] ++;
                    break;
                default:
                    break;
            }
        }
        else if (Match_Score.Score_P1 == 7) {
            switch (Match_Score.Score_P0) {
                case 1:
                    Win_Rates[6] ++;
                    break;
                case 2:
                    Win_Rates[7] ++;
                    break;
                case 3:
                    Win_Rates[8] ++;
                    break;
                case 4:
                    Win_Rates[9] ++;
                    break;
                case 5:
                    Win_Rates[10] ++;
                    break;
                case 6:
                    Win_Rates[11] ++;
                    break;
                default:
                    break;
            }
        }
    }

    std::cout << "\rSimulation Complete";

    /* Calculate percentage match result frequency */
    int Result_Frequencies[12];
    for (int i = 0; i < 12; i++) {
        Result_Frequencies[i] = (Win_Rates[i] / Matches) * 100;
    }

    /* Find most frequent result */
    int Most_Frequent =  0;
    for (int Result_Frequency : Result_Frequencies) {
        if (Result_Frequency > Most_Frequent) {
            Most_Frequent = Result_Frequency;
        }
    }

    /* Display Output */
    std::cout << "\rSimulation Results" << std::endl;

    std::cout << Player_0.Get_Player_Name() << " " << Player_1.Get_Player_Name() << std::endl;
    std::cout << "7:1\t" << Result_Frequencies[0] << std::endl;
    std::cout << "7:2\t" << Result_Frequencies[1] << std::endl;
    std::cout << "7:3\t" << Result_Frequencies[2] << std::endl;
    std::cout << "7:4\t" << Result_Frequencies[3] << std::endl;
    std::cout << "7:5\t" << Result_Frequencies[4] << std::endl;
    std::cout << "7:6\t" << Result_Frequencies[5] << std::endl;
    std::cout << "1:7\t" << Result_Frequencies[6] << std::endl;
    std::cout << "2:7\t" << Result_Frequencies[7] << std::endl;
    std::cout << "3:7\t" << Result_Frequencies[8] << std::endl;
    std::cout << "4:7\t" << Result_Frequencies[9] << std::endl;
    std::cout << "5:7\t" << Result_Frequencies[10] << std::endl;
    std::cout << "6:7\t" << Result_Frequencies[11] << std::endl;


    std::cout << "Most Common Result: " << Most_Frequent << std::endl;
}
