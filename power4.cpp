//
// Created by tuxca on 18.10.2022.
//

#include <iostream>
#include <array>
#include <string>
#include "power4.h"

Power4::Power4(){

}


/**
 * Method that check if a player win the game (currently)
 *
 * @param player the player to check the win
 * @return true if the player as win
 */
bool Power4::checkWin(int player) {
    //iterate on each case of the array
    for (int x = 0; x < GAME_ARR.size(); x++) {
        for (int y = 0; y < GAME_ARR[0].size(); y++) {
            //if the case is checked by the user we want to win
            if (GAME_ARR[x][y] == player) {
                //check bounderies for have no error
                bool allowXplus1 = x + 1 - (int) GAME_ARR.size() < 0;
                bool allowXplus2 = x + 2 - (int) GAME_ARR.size() < 0;
                bool allowYplus1 = y + 1 - (int) GAME_ARR[x].size() < 0;
                bool allowYplus2 = y + 2 - (int) GAME_ARR[x].size() < 0;
                bool allowYsub2 = y - 2 >= 0;
                bool allowYsub1 = y - 1 >= 0;

                bool finalBool = false;
                if (allowXplus1 && allowXplus2) {
                    //check if a column of 3 case is checked
                    finalBool = (finalBool ||
                                 (GAME_ARR[x + 1][y] == player && GAME_ARR[x + 2][y] == player));
                    if (allowYplus1 && allowYplus2) {
                        //check if a diagonal of 3 case is checked
                        finalBool = (finalBool ||
                                     (GAME_ARR[x + 1][y + 1] == player &&
                                      GAME_ARR[x + 2][y + 2] == player));
                    }
                    if (allowYsub1 && allowYsub2) {
                        //check if a diagonal of 3 case is checked
                        finalBool = (finalBool ||
                                     (GAME_ARR[x + 1][y - 1] == player &&
                                      GAME_ARR[x + 2][y - 2] == player));
                    }
                }
                if (allowYplus1 && allowYplus2) {
                    //check if a line of 3 case is checked
                    finalBool = (finalBool ||
                                 (GAME_ARR[x][y + 1] == player && GAME_ARR[x][y + 2] == player));
                }
                if (finalBool) {
                    //if 3 case checked return true for win
                    return true;
                }
            }
        }
    }

    //if no 3 case is found not win so return false
    return false;
};

/**
 * This method ask the user to check a case and then save it on the array
 * @param user the current user
 * @param isComputer if true the case is asked by the computer
 * @return false if an error occurred
 */
bool Power4::addACase(int user, bool isComputer) {
    std::cout << "User " << user << " give some coordinate (format:x,y):";

    int xString = 0;
    int yString = 0;
    isComputer = true;
    if (isComputer) {
            //generate random coordinate
            xString = rand() % GAME_ARR.size();
        yString = rand() % GAME_ARR[0].size();
    } else {
        //ask user the coordinate of the case to check
        std::string caseToAdd;
        getline(std::cin, caseToAdd);

        //get single coordinate x or y
        //xString = caseToAdd;
    }

    //cast coordinate to int and get the asked case in the array
    //const std::string yString = "TO CALCULATE";
    int &askedCase = GAME_ARR[xString, nullptr, 10][yString, nullptr, 10];
    //check if the case hasn't been checked else return false
    if (askedCase == 0) {
        askedCase = user;
        return true;
    }
    std::cout << "An error occurred, please retry" << std::endl;
    return false;
}

/**
 * This method display as user-friendly as possible the array of the game
 */
void Power4::displayArray() {
    //iterate on each case of the array
    for (int x = 0; x < GAME_ARR.size(); x++) {
        for (int y = 0; y < GAME_ARR[0].size(); y++) {
            switch (GAME_ARR[x][y]) {
                case 2:
                    std::cout << "  X  ";
                    break;
                case 1:
                    std::cout << "  *  ";
                    break;
                case 0:
                default:
                    std::cout << " " << x << "," << y << " ";
            }
        }
        std::cout << std::endl;
    }
}

/**
 * This method create a new game and describe all the process of a game until someone win
 * @param isVsComputer if true user 2 is the computer
 */
void Power4::newGame(bool isVsComputer) {
    bool currentUser = false; //The current user is 1 if false else 2 (or computer)
    displayArray();
    while (!(checkWin(1) || checkWin(2))) {
        bool isPassed = false;
        while (!isPassed) {
            isPassed = addACase(currentUser ? 2 : 1, isVsComputer && currentUser);
        }
        displayArray();
        currentUser = !currentUser;
    }

    if (checkWin(1)) {
        if (isVsComputer) {
            std::cout << "Congratulation, you won !" << std::endl;
        } else {
            std::cout << "Congratulation, User 1 won !" << std::endl;
        }
    } else {
        if (isVsComputer) {
            std::cout << "What a reveal your IQ is less than mine, you lost !" << std::endl;
        } else {
            std::cout << "Congratulation, User 2 won !" << std::endl;
        }
    }
}