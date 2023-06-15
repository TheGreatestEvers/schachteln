#include "ChessBoard.h"
#include <iostream>

using namespace std;

    //overloading the << operator for enum type Piece

    std::ostream& operator<<(std::ostream& os, Piece p) {
        switch(p.t) {
            case KING:
                p.c == WHITE ? os << "wK" : os << "bK";
                break;
            case QUEEN:
                p.c == WHITE ? os << "wQ" : os << "bQ";
                break;
            case ROOK:
                p.c == WHITE ? os << "wR" : os << "bR";
                break;
            case BISHOP:
                p.c == WHITE ? os << "wB" : os << "bB";
                break;
            case KNIGHT:
                p.c == WHITE ? os << "wN" : os << "bN";
                break;
            case PAWN:
                p.c == WHITE ? os << "wP" : os << "bP";
                break;
            case EMPTY:
                os << "  ";
                break;
        }
        return os;
    }

    ChessBoard::ChessBoard() {
        vector<vector<Piece>> board(8, vector<Piece>(8, Piece{Type::EMPTY, Color::NONE}));
        this->board = board;
    }


    // From this point on member functions of ChessBoard
    //
    //
    //
 
    vector<vector<Piece>> ChessBoard::getBoard() {
        return this->board;
    }

    Piece ChessBoard::getPiece(Pos pos){
        return this->board.at(pos.row).at(pos.col);
    }

    void ChessBoard::initBoard() {
        for (int i = 0; i < 3; i++) {
            this->board.at(0).at(i) = Piece{static_cast<Type>(i), Color::WHITE};
            this->board.at(0).at(7-i) = Piece{static_cast<Type>(i), Color::WHITE};
            this->board.at(7).at(i) = Piece{static_cast<Type>(i), Color::BLACK};
            this->board.at(7).at(7-i) = Piece{static_cast<Type>(i), Color::BLACK};     
        }

        this->board.at(0).at(3) = Piece{Type::QUEEN, Color::WHITE};
        this->board.at(0).at(4) = Piece{Type::KING, Color::WHITE};
        this->board.at(7).at(3) = Piece{Type::QUEEN, Color::BLACK};
        this->board.at(7).at(4) = Piece{Type::KING, Color::BLACK};

        for (int i = 0; i < 8; i++) {
            this->board.at(1).at(i) = Piece{Type::PAWN, Color::WHITE};
            this->board.at(6).at(i) = Piece{Type::PAWN, Color::BLACK};
        }

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                Piece p = getPiece(Pos{i, j});
                size_t size;
                switch (p.t) {
                    case EMPTY:
                        break;
                    case KING:
                        size = 8;
                        p.possible_moves = new Pos[size];
                        break;
                    case QUEEN:
                        size = 27;
                        p.possible_moves = new Pos[size];
                        break;
                    case ROOK:
                        size = 14;
                        p.possible_moves = new Pos[size];
                        break;
                    case BISHOP:
                        size = 13;
                        p.possible_moves = new Pos[size];
                        break;
                    case KNIGHT:
                        size = 8;
                        p.possible_moves = new Pos[size];
                        break;
                    case PAWN:
                        size = 4;
                        p.possible_moves = new Pos[size];
                        break;

                }
            }
        }
    }

    void ChessBoard::movePiece(Pos src, Pos dst) {
        Piece piece = this->getPiece(src);
        this->board.at(src.row).at(src.col) = Piece{Type::EMPTY, Color::NONE};
        this->board.at(dst.row).at(dst.col) = piece;
    }
    
    void ChessBoard::printBoard(Color c) {

        if (c == Color::WHITE){
            std::cout << "-------------------------\n";
            int i = 8;
            for(int row = 7; row >= 0; row--){
                for(int col = 0; col < 8; col++) {
                    std::cout << "|" << getPiece(Pos{row, col});
                }
                std::cout << "|" << i << "\n";
                std::cout << "-------------------------\n";
                i--;
            }
            std::cout << " ";
            for (int j = 0; j < 8; j++) {
                std::cout << " " << char('a'+j) << " ";
            }
            std::cout << "\n";
        } else {
            std::cout << "-------------------------\n";
            int i = 0;
            for(int row = 0; row < 8; row++){
                i++;
                for(int col = 7; col >= 0; col--) {
                    std::cout << "|" << getPiece(Pos{row, col});
                }
                std::cout << "|" << i << "\n";
                std::cout << "-------------------------\n";
            }
            std::cout << " ";
            for (int j = 0; j < 8; j++) {
                std::cout << " " << char('h'-j) << " ";
            }
            std::cout << "\n";
        }
    }
    
    void ChessBoard::setBoard(vector<vector<Piece>> board) {
        this->board = board;
    }