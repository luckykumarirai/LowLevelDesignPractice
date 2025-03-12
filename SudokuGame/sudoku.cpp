#include<iostream>
#include<vector>
using namespace std;



class Cell{
    private:
        int value;
        bool isFixed;
    public:
    Cell() : value(0), isFixed(false) {}
    Cell(int value, bool isFixed) : value(value), isFixed(isFixed) {}

    // Getter to get Private attribute 
    int getValue() const { return value; }
    void setValue(int val) {
        if (!isFixed) value = val;
    }
    bool getIsFixed() const { return isFixed; }

};

// Suduko baord with 9*9 
//Each of the digits 1-9 must occur exactly once in each row.
//Each of the digits 1-9 must occur exactly once in each column.
//Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

class SudukoBaord
{
private:
    Cell board[9][9];
public:
    // Explicit Constructor
    SudukoBaord() {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                board[i][j] = Cell(0, false); // Provide initial values
            }
        }
    }
    // Initialize with a given board
    void initializeBoard(vector<vector<int>> &initialValues)
    {
        for(int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9;j++)
            {
                bool isFixed= (initialValues[i][j]!=0);
                board[i][j]=Cell(initialValues[i][j], isFixed);
            }
        }
    }
    // To display 
    void display()
    {
        for(int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9;j++)
            {
                cout << board[i][j].getValue();
            }
            cout << endl;
        }
    }

    // to check given number can place at particular Cell or not
    bool isValidMove(int value, int row, int col)
    {
        // if any row or col conatin this value
        for (int i = 0; i < 9;i++)
        {
            if(board[row][i].getValue()==value || board[i][col].getValue()==value)
            {
                return false;
            }
            if(board[3*(row/3)+i/3][3*(col/3)+i%3].getValue()==value)
            {
                return false;
            }
        }
        return true;
    }

    // To place number at any position
    bool placeNumber(int row, int col, int value)
    {
        if(isValidMove(value,row,col))
        {
            board[row][col].setValue(value);
            return true;
        }
        return false;
    }
};

class Player {
private:
    string name;
    int score;

public:
    Player(string playerName) : name(playerName), score(0) {}

    string getName() const { return name; }
    int getScore() const { return score; }

    void increaseScore(int points) { score += points; }
};


// Suduko Game Manager

class GameManager {
    private:
    SudukoBaord board;
    vector<Player> players;
    int currentPlayerIndex;
    int movesLeft;

public:
    GameManager(vector<string> playerNames, vector<vector<int>> initialBoard) {
        for (auto &name : playerNames) {
            players.push_back(Player(name));
        }
        board.initializeBoard(initialBoard);
        currentPlayerIndex = 0;
        movesLeft = 81; // Total Cell
    }
    void displayGameState() {
        board.display();
        cout << "Current Player: " << players[currentPlayerIndex].getName() << endl;
    }

   void makeMove(int row, int col, int num) {
        if (board.placeNumber(row, col, num)) {
            cout << players[currentPlayerIndex].getName() << " placed " << num << " at (" << row << "," << col << ")\n";
            players[currentPlayerIndex].increaseScore(10);
            movesLeft--;
            switchTurn();
        } else {
            cout << "Invalid move. Try again.\n";
        }
    }

    void switchTurn() {
        currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
    }

    bool isGameOver() {
        cout << movesLeft;
        return movesLeft == 0;
    }

    void showFinalScores() {
        cout << "\nFinal Scores:\n";
        for (auto &player : players) {
            cout << player.getName() << ": " << player.getScore() << " points\n";
        }
    }
};

int main() {
    vector<string> playerNames = {"Alice", "Bob"};
    
    // Example starting board (0 represents an empty Cell)
    vector<vector<int>> initialBoard = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    GameManager game(playerNames, initialBoard);
    game.displayGameState();

    game.makeMove(0, 2, 4);
    game.makeMove(1, 1, 7);
    game.makeMove(2, 6, 5);

    cout << "gaem status" <<game.isGameOver()<< endl;
    if (game.isGameOver()==0)
    {
        game.showFinalScores();
    }

    return 0;
}
