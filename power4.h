//
// Created by tuxca on 18.10.2022.
//
#include <vector>

//If it's windows (32) we can import that for the color in terminal.
#ifdef _WIN32
#include <windows.h>
#endif

#ifndef MANDELBROT_POWER4_H
#define MANDELBROT_POWER4_H

class Power4 {
public:
    enum POSSIBLE_VALUE {
        EMPTY, USER_1, USER_2
    };
private:
    std::vector<std::vector<POSSIBLE_VALUE>> gameArr;

public:
    /**
     * A constructor that take a number of lines and a number of columns
     *
     * @param nLines Number of lines. Optional: if not given = 6
     * @param nColumn Number of columns. Optional: if not given = 7
     */
    Power4(int nLines = 6, int nColumn = 7);

    /**
     * Method that check if an equality appended.
     *
     * @return true if an equality appended
     */
    bool checkEquality();

    /**
     * Method that check if a player win the game (currently).
     *
     * @param player the player to check the win
     * @return true if the player as win
     */
    bool checkWin(int player);

    /**
     * Find the first x coord empty regarding the y coord.
     *
     * @param y the coord
     * @return the x or -1 if not found
     */
    int findX(int y);

    /**
     * This method ask the user to check a case and then save it on the array
     *
     * @param user the current user
     * @param isComputer if true the case is asked by the computer
     * @return false if an error occurred
     */
    bool addACase(POSSIBLE_VALUE user, bool isComputer);

    /**
     * This method display as user-friendly as possible the two-dimension vector of the game
     */
    void display2DVector();

    /**
     * This method create a new game and describe all the process of a game until someone win.
     *
     * @param isVsComputer if true user 2 is the computer
     */
    void newGame(bool isVsComputer);
};

#endif
