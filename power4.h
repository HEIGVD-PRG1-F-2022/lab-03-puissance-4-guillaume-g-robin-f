//
// Created by tuxca on 18.10.2022.
//
#include <vector>
#include "env.h"

#ifndef MANDELBROT_POWER4_H
#define MANDELBROT_POWER4_H

class Power4 {
private:
    std::vector<std::vector<POSSIBLE_VALUE>> gameArr;

public:
    Power4(int nLines = 6, int nColumn = 7);

    /**
     * Method that check if a player win the game (currently)
     *
     * @param player the player to check the win
     * @return true if the player as win
     */
    bool checkWin(int player);

    /**
     * Method that check if an equality appended.
     *
     * @return true if an equality appended
     */
    bool checkEquality();

    /**
     * This method ask the user to check a case and then save it on the array
     * @param user the current user
     * @param isComputer if true the case is asked by the computer
     * @return false if an error occurred
     */
    bool addACase(POSSIBLE_VALUE user, bool isComputer);

    void displayArray();

    void newGame(bool isVsComputer);

    int findX(int y);
};

#endif
