#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <vector>
#include <memory>
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
    BLACK,
    NONE
};


struct Pos {
    int row;
    int col;
};

struct Piece {
    Type t;
    Color c;
    Pos* possible_moves = nullptr;
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
    Piece getPiece(Pos pos);
    void initBoard();
    void movePiece(Pos src, Pos dest);
    void printBoard(Color c);
    void setBoard(vector<vector<Piece>> board);
    
   
    
    
    

    
};


#endif