//
// Created by tuxca on 18.10.2022.
//
#include <array>
#ifndef MANDELBROT_POWER4_H
#define MANDELBROT_POWER4_H
#endif

class Power4{
private:
    std::array<std::array<int, 7>, 6> GAME_ARR = {{{0, 0, 0, 0, 0, 0, 0},
                                                   {0, 0, 0, 0, 0, 0, 0},
                                                   {0, 0, 0, 0, 0, 0, 0},
                                                   {0, 0, 0, 0, 0, 0, 0},
                                                   {0, 0, 0, 0, 0, 0, 0},
                                                   {0, 0, 0, 0, 0, 0, 0}}};
public:
    Power4();

    /**
     * Method that check if a player win the game (currently)
     *
     * @param player the player to check the win
     * @return true if the player as win
     */
    bool checkWin(int player);

    /**
     * This method ask the user to check a case and then save it on the array
     * @param user the current user
     * @param isComputer if true the case is asked by the computer
     * @return false if an error occurred
     */
    bool addACase(int user, bool isComputer);

    void displayArray();

    void newGame(bool isVsComputer);

    int findX(int y);
};