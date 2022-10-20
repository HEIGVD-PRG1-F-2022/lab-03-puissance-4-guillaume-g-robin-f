/**
 * A class file for the power 4 algorithm and display
 * (because we need to have access the array to display it)
 *
 * @name Power 4
 * @date 20.10.2022
 * @authors Guillaume Gonin and Robin Forestier
 */

//Externals imports
#include <iostream>
#include <vector>

//If it's windows (32) we can import that for the color in terminal.
#ifdef _WIN32
#include <windows.h>
#endif

//Internals imports
#include "power4.h"

using namespace std;
//Renaming Power4::POSSIBLE_VALUE to just POSSIBLE_VALUE for a cleaner code reading
using POSSIBLE_VALUE = Power4::POSSIBLE_VALUE;

/**
 * A constructor that take a number of lines and a number of columns
 *
 * @param nLines Number of lines. Optional: if not given = 6
 * @param nColumn Number of columns. Optional: if not given = 7
 */
Power4::Power4(int nLines, int nColumn) {
    this->gameArr.assign(nColumn, vector(nLines, POSSIBLE_VALUE::EMPTY));
}

/**
 * Method that check if an equality appended.
 *
 * @return true if an equality appended
 */
bool Power4::checkEquality() {
    for (int x = 0; x < gameArr.size(); x++) {
        for (int y = 0; y < gameArr[0].size(); y++) {
            if (gameArr[x][y] == POSSIBLE_VALUE::EMPTY) {
                return false;
            }
        }
    }
    return true;
}

/**
 * Method that check if a player win the game (currently).
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

/**
 * Find the first x coord empty regarding the y coord.
 *
 * @param y the coord
 * @return the x or -1 if not found
 */
int Power4::findX(int y) {
    for (int x = gameArr.size() - 1; x >= 0; x--) {
        if (gameArr[x][y] == POSSIBLE_VALUE::EMPTY) {
            return x;
        }
    }
    return -1;
}

/**
 * This method ask the user to check a case and then save it on the array
 *
 * @param user the current user
 * @param isComputer if true the case is asked by the computer
 * @return false if an error occurred
 */
bool Power4::addACase(POSSIBLE_VALUE user, bool isComputer) {
    cout << "User " << user << " give a number of column (in range: 0-" << gameArr[0].size() - 1 << "):" << endl;

    int y = -1;

    if (isComputer) {
        //generate random coordinate
        y = rand() % gameArr[0].size();
    } else {
        //ask user the coordinate of the case to check
        while (y < 0 || y >= gameArr[0].size()) {
            cin >> y;
            y < 0 ||
            y >= gameArr[0].size() && cout << "Not a valid index please enter a valid value: " << endl;
        }
    }

    //cast coordinate to int and get the asked case in the array
    int x = findX(y);

    if (x == -1) {
        cout << "No place on this column please choose another one." << endl;
        return false;
    }

    POSSIBLE_VALUE &askedCase = gameArr[x][y];

    askedCase = user == 1 ? POSSIBLE_VALUE::USER_1 : POSSIBLE_VALUE::USER_2;
    return true;
}

/**
 * This method display as user-friendly as possible the two-dimension vector of the game.
 */
void Power4::display2DVector() {
    //if it's windows (32) we can execute this line to change the terminal to UTF8 and as that have a display for ours colors.
    #ifdef _WIN32
        system(("chcp "s + to_string(CP_UTF8)).c_str());
    #endif

    //iterate on each case of the array
    for (int i = 0; i < gameArr[0].size(); i++) {
        cout << "| " << i << " ";
    }

    cout << "|" << endl;

    for (int x = 0; x < gameArr.size(); x++) {
        for (int y = 0; y < gameArr[0].size(); y++) {
            if (y == 0) {
                cout << "|";
            }
            switch (gameArr[x][y]) {
                case POSSIBLE_VALUE::USER_2:
                    cout << " \033[33;91m\u25CF\033[0m |";
                    break;
                case POSSIBLE_VALUE::USER_1:
                    cout << " \033[33;94m\u25CF\033[0m |";
                    break;
                case POSSIBLE_VALUE::EMPTY:
                default:
                    cout << "   |";
                    break;
            }
        }
        cout << endl;
    }
}

/**
 * This method create a new game and describe all the process of a game until someone win.
 *
 * @param isVsComputer if true user 2 is the computer
 */
void Power4::newGame(bool isVsComputer) {
    POSSIBLE_VALUE currentUser = POSSIBLE_VALUE::USER_1;

    display2DVector();

    while (!(checkWin(POSSIBLE_VALUE::USER_1) || checkWin(POSSIBLE_VALUE::USER_2) || checkEquality())) {
        bool isPassed = false;
        while (!isPassed) {
            isPassed = addACase(currentUser, isVsComputer && currentUser == POSSIBLE_VALUE::USER_2);
        }
        display2DVector();
        currentUser = (currentUser == POSSIBLE_VALUE::USER_1)
                      ? POSSIBLE_VALUE::USER_2
                      : POSSIBLE_VALUE::USER_1;
    }

    if (checkWin(POSSIBLE_VALUE::USER_1)) {
        if (isVsComputer) {
            cout << "Congratulation, you won !" << endl;
        } else {
            cout << "Congratulation, User 1 won !" << endl;
        }
    } else if (checkEquality()) {
        if (isVsComputer) {
            cout << "What !?! HOW? it's an equality." << endl;
        } else {
            cout << "Oh no, you are equally bad !" << endl;
        }
    } else {
        if (isVsComputer) {
            cout << "What a reveal your IQ is less than mine, you lost !" << endl;
        } else {
            cout << "Congratulation, User 2 won !" << endl;
        }
    }
}