#include <iostream>
#include "board.hpp"

int main() {
    Board board;
    int row, col;
    pieceType currentPlayer = pieceType::X;

    for (int i = 0; i < 9; i++) { // Max 9 moves in Tic-Tac-Toe
        board.display();
        std::cout << "Player " << (currentPlayer == pieceType::X ? "X" : "O") 
                  << ", enter row and column (0-2): ";
        std::cin >> row >> col;

        if (board.placePiece(row, col, currentPlayer)) {
            if (board.checkWin(currentPlayer)) {
                board.display();
                std::cout << "Player " << (currentPlayer == pieceType::X ? "X" : "O") 
                          << " wins!\n";
                return 0;
            }
            // Switch player
            currentPlayer = (currentPlayer == pieceType::X) ? pieceType::O : pieceType::X;
        } else {
            i--; // Invalid move, don't count the turn
        }
    }

    board.display();
    std::cout << "It's a draw!\n";
    return 0;
}
