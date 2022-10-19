//
// Created by tuxca on 18.10.2022.
//

#include <iostream>
#include <vector>
#include <string>
#include "power4.h"
#include "env.h"

Power4::Power4(int nLines, int nColumn) {
    this->gameArr.assign(nColumn, std::vector(nLines, POSSIBLE_VALUE::EMPTY));
}

/**
 * Method that check if a player win the game (currently)
 *
 * @param player the player to check the win
 * @return true if the player as win
 */
bool Power4::checkWin(int player) {
    //iterate on each case of the array
    for (int x = 0; x < gameArr.size(); x++) {
        for (int y = 0; y < gameArr[0].size(); y++) {
            //if the case is checked by the user we want to win
            if (gameArr[x][y] == player) {
                //check bounderies for have no error
                bool allowXplus1 = x + 1 - (int) gameArr.size() < 0;
                bool allowXplus2 = x + 2 - (int) gameArr.size() < 0;
                bool allowXplus3 = x + 3 - (int) gameArr.size() < 0;
                bool allowYplus1 = y + 1 - (int) gameArr[x].size() < 0;
                bool allowYplus2 = y + 2 - (int) gameArr[x].size() < 0;
                bool allowYplus3 = y + 3 - (int) gameArr[x].size() < 0;
                bool allowYsub3 = y - 3 >= 0;
                bool allowYsub2 = y - 2 >= 0;
                bool allowYsub1 = y - 1 >= 0;

                bool finalBool = false;
                if (allowXplus1 && allowXplus2 && allowXplus3) {
                    //check if a column of 3 case is checked
                    finalBool = (finalBool ||
                                 (gameArr[x + 1][y] == player
                                  && gameArr[x + 2][y] == player
                                  && gameArr[x + 3][y] == player));
                    if (allowYplus1 && allowYplus2 && allowYplus3) {
                        //check if a diagonal of 3 case is checked
                        finalBool = (finalBool ||
                                     (gameArr[x + 1][y + 1] == player
                                      && gameArr[x + 2][y + 2] == player
                                      && gameArr[x + 3][y + 3] == player));
                    }
                    if (allowYsub1 && allowYsub2 && allowYsub3) {
                        //check if a diagonal of 3 case is checked
                        finalBool = (finalBool ||
                                     (gameArr[x + 1][y - 1] == player
                                      && gameArr[x + 2][y - 2] == player
                                      && gameArr[x + 3][y - 3] == player));
                    }
                }
                if (allowYplus1 && allowYplus2 && allowYplus3) {
                    //check if a line of 3 case is checked
                    finalBool = (finalBool ||
                                 (gameArr[x][y + 1] == player
                                  && gameArr[x][y + 2] == player
                                  && gameArr[x][y + 3] == player));
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

int Power4::findX(int y) {
    for (int x = gameArr.size() - 1; x >= 0; x--) {
        if (gameArr[x][y] == 0) {
            return x;
        }
    }
    return -1;
}

/**
 * This method ask the user to check a case and then save it on the array
 * @param user the current user
 * @param isComputer if true the case is asked by the computer
 * @return false if an error occurred
 */
bool Power4::addACase(int user, bool isComputer) {
    std::cout << "User " << user << " give a number of column (in range: 0-6):" << std::endl;

    int y = 0;

    if (isComputer) {
        //generate random coordinate
        y = rand() % gameArr[0].size();
    } else {
        //ask user the coordinate of the case to check
        std::string caseToAdd;
        std::cin >> y;

        //get single coordinate x or y
        //xString = caseToAdd;
    }

    //cast coordinate to int and get the asked case in the array
    int x = findX(y);

    if (x == -1) {
        std::cout << "No place on this column please choose another one." << std::endl;
        return false;
    }

    POSSIBLE_VALUE &askedCase = gameArr[x][y];

    askedCase = user == 1 ? POSSIBLE_VALUE::USER_1 : POSSIBLE_VALUE::USER_2;
    return true;
}

/**
 * This method display as user-friendly as possible the array of the game
 */
void Power4::displayArray() {
    //iterate on each case of the array

    for (int i = 0; i < gameArr[0].size(); i++) {
        std::cout << "| " << i << " ";
    }

    std::cout << "|" << std::endl;

    for (int x = 0; x < gameArr.size(); x++) {
        for (int y = 0; y < gameArr[0].size(); y++) {
            if (y == 0) {
                std::cout << "|";
            }
            switch (gameArr[x][y]) {
                case 2:
                    std::cout << " X |";
                    break;
                case 1:
                    std::cout << " * |";
                    break;
                case 0:
                default:
                    std::cout << "   |";
                    break;
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
    bool currentUser = POSSIBLE_VALUE::USER_1;

    displayArray();

    while (!(checkWin(1) || checkWin(2))) {
        bool isPassed = false;
        while (!isPassed) {
            isPassed = addACase(currentUser, isVsComputer && currentUser == POSSIBLE_VALUE::USER_2);
        }
        displayArray();
        currentUser = (currentUser == POSSIBLE_VALUE::USER_1) ?
                      POSSIBLE_VALUE::USER_2
                                                              : POSSIBLE_VALUE::USER_1;
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