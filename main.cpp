#include <iostream>

#include "power4.h"

int main(){
    Power4 power4 = Power4();
    std::cout << "Hello, do you want to play against [c]omputer or [h]umans?";
    std::string input = "";
    std::getline(std::cin, input);
    power4.newGame(input.compare("c") == 0);
    return EXIT_SUCCESS;
}
