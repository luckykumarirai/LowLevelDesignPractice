#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "piece.hpp" // Include the Piece class
#include<vector>
using namespace std;

class Board {
private:
    int size;
    Piece* board[3][3];

public:
    Board(); // Constructor to initialize board
    ~Board(); // Destructor to clean up memory
    bool placePiece(int row, int col, pieceType type); // Place a piece
    void display(); // Display the board
    bool checkWin(pieceType type); // Check for a winner
};

#endif // BOARD_H
