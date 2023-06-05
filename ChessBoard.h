#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <vector>
using namespace std;

enum Type {
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING,
    PAWN,
    EMPTY
};

enum Color {
    WHITE,
    BLACK
};

struct Piece {
    Type t;
    Color c;
};

class ChessBoard {  

    private:
    //Member representing the chessboard
        vector<vector<Piece>> board;

    public:
    //Constructor
        ChessBoard();

    //Getter and setter for board
    vector<vector<Piece>> getBoard();
    void setBoard(vector<vector<Piece>> board);
    Piece getPiece(size_t i, size_t j);
    
    void initBoard();
    void printBoard(Color c);

    
};


#endif