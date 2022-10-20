/**
 * The main file
 *
 * @name Connect 4
 * @date 20.10.2022
 * @authors Guillaume Gonin and Robin Forestier
 */

//Externals exports
#include <iostream>

//Internals exports
#include "connect4.h"

using namespace std;

int main() {
    //Asking for computer or human play-style
    cout << "Hello, do you want to play against [c]omputer or [h]umans?";
    string input;
    getline(cin, input);
    bool isComputerActived = input == "c";
    cout << endl;

    //Asking for custom game-board size
    cout << "Do you want to choose a size of the game-board (y/n)?";
    cin >> input;
    cout << endl;

    Connect4 connect4;
    if (input == "y" || input == "Y") {
        //Asking the size chosen
        cout << "Choose the size (numberOfColumns numberOfLines) ?";
        int nColumns = -1, nLines = -1;
        cin >> nLines >> nColumns;
        cout << endl;

        //Validate size
        if ((nColumns > 3 && nLines > 0) || (nLines > 3 && nColumns > 0)) {
            connect4 = Connect4(nLines, nColumns);
        } else {
            //If not valide we create with the default size anyway
            cout << "Not a valid size. default one taken!" << endl;
            connect4 = Connect4();
        }
    } else {
        connect4 = Connect4();
    }
    //Launching the game
    connect4.newGame(isComputerActived);

    return EXIT_SUCCESS;
}
