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
        vector<vector<Piece>> board(8, vector<Piece>(8, Piece{Type::EMPTY, Color::WHITE}));
        this->board = board;
    }

    vector<vector<Piece>> ChessBoard::getBoard() {
        return this->board;
    }
    void ChessBoard::setBoard(vector<vector<Piece>> board) {
        this->board = board;
    }
    Piece ChessBoard::getPiece(size_t i, size_t j){
        return this->board.at(i).at(j);
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
    }

    

    void ChessBoard::printBoard(Color c) {

        if (c == Color::WHITE){
            std::cout << "-------------------------\n";
            int i = 8;
            for(int row = 7; row >= 0; row--){
                for(int col = 0; col < 8; col++) {
                    std::cout << "|" << getPiece(row, col);
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
                    std::cout << "|" << getPiece(row, col);
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