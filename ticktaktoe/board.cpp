#include<iostream>
#include "board.hpp"
#include "piece.hpp"

Board::Board(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = nullptr;
        }
    }
}

// Destructor to clean up dynamically allocated memory
Board::~Board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            delete board[i][j];
        }
    }
}

bool Board::placePiece(int row, int col, pieceType type){
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != nullptr) {
        std::cout << "Invalid move! Try again.\n";
        return false;
    }

    if (type == pieceType::X) {
        board[row][col] = new PieceX();
    } else {
        board[row][col] = new PieceO();
    }

    return true;
}


// Display the board
void Board::display() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == nullptr) {
                std::cout << " . ";
            } else if (board[i][j]->type == pieceType::X) {
                std::cout << " X ";
            } else {
                std::cout << " O ";
            }
        }
        std::cout << "\n";
    }
}
bool Board::checkWin(pieceType type){
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] && board[i][0]->type == type && 
             board[i][1] && board[i][1]->type == type && 
             board[i][2] && board[i][2]->type == type) || 
            (board[0][i] && board[0][i]->type == type && 
             board[1][i] && board[1][i]->type == type && 
             board[2][i] && board[2][i]->type == type)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] && board[0][0]->type == type && 
         board[1][1] && board[1][1]->type == type && 
         board[2][2] && board[2][2]->type == type) || 
        (board[0][2] && board[0][2]->type == type && 
         board[1][1] && board[1][1]->type == type && 
         board[2][0] && board[2][0]->type == type)) {
        return true;
    }

    return false;
}