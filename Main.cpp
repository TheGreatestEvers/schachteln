#include "ChessBoard.h"
#include <iostream>

int main() {

    ChessBoard cb;
    cb.initBoard();
    cb.printBoard(Color::WHITE);
    std::cout << "\n";
    cb.printBoard(Color::BLACK);

    return 0;
}