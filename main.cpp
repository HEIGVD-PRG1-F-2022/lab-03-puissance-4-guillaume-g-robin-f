#include <iostream>

#include "power4.h"

using namespace std;

int main() {
    cout << "Hello, do you want to play against [c]omputer or [h]umans?" << endl;
    string input;
    getline(cin, input);
    bool isComputerActived = input == "c";

    cout << "Do you want to choose a size of the game-board (y/n)?" << endl;
    cin >> input;

    Power4 power4;
    if (input == "y" || input == "Y") {
        cout << "Choose the size (numberOfColumns numberOfLines) ?" << endl;
        int nColumns = -1, nLines = -1;
        cin >> nLines >> nColumns;

        if (nColumns > 0) {
            power4 = Power4(nLines, nColumns);
        } else {
            power4 = Power4();
        }
    } else {
        power4 = Power4();
    }
    power4.newGame(isComputerActived);

    return EXIT_SUCCESS;
}
