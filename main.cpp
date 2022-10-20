#include <iostream>

#include "power4.h"

using namespace std;

int main() {
    cout << "Hello, do you want to play against [c]omputer or [h]umans?";
    string input;
    getline(cin, input);
    bool isComputerActived = input == "c";
    cout << endl;

    cout << "Do you want to choose a size of the game-board (y/n)?";
    cin >> input;
    cout << endl;

    Power4 power4;
    if (input == "y" || input == "Y") {
        cout << "Choose the size (numberOfColumns numberOfLines) ?";
        int nColumns = -1, nLines = -1;
        cin >> nLines >> nColumns;
        cout << endl;

        if ((nColumns > 3 && nLines > 0) || (nLines > 3 && nColumns > 0)) {
            power4 = Power4(nLines, nColumns);
        } else {
            cout << "Not a valid size. default one taken!" << endl;
            power4 = Power4();
        }
    } else {
        power4 = Power4();
    }
    power4.newGame(isComputerActived);

    return EXIT_SUCCESS;
}
