#include <iostream>

#include "power4.h"

int main(){
    std::cout << "Hello, do you want to play against [c]omputer or [h]umans?" << std::endl;
    std::string input;
    std::getline(std::cin, input);
    bool isComputerActived = input.compare("c") == 0;
    std::cout << "Do you want to choose a size of the game-board (y/n)?" << std::endl;
    std::cin >> input;
    if (input.compare("y") == 0 || input.compare("Y") == 0) {
        std::cout << "Choose the size (numberOfColumns numberOfLines) ?" << std::endl;
        int nColumns = -1, nLines = -1;
        std::cin >> nLines >> nColumns;
        if (nColumns > 0) {
            Power4 power4 = Power4(nLines, nColumns);
            power4.newGame(isComputerActived);
        } else {
            Power4 power4 = Power4();
            power4.newGame(isComputerActived);
        }
    }
    Power4 power4 = Power4();
    power4.newGame(isComputerActived);
    return EXIT_SUCCESS;
}
