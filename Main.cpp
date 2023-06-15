#include "ChessBoard.h"
#include <iostream>

int main() {

    ChessBoard cb;
    cb.initBoard();
    cb.printBoard(Color::WHITE);
    std::cout << "\n";
    cb.movePiece(Pos{1,4}, Pos{3,4});
    cb.printBoard(Color::WHITE);

    return 0;
}