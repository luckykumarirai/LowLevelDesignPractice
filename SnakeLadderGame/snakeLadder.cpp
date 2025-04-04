#include <iostream>
#include <vector>
#include <unordered_map>
#include <ctime>
#include <cstdlib>

// Observer Pattern - Abstract class
class IObserver {
public:
    virtual void update(std::string playerName, int position) = 0;
};

// Singleton Pattern - Board
class Board {
private:
    static Board* instance;
    int size;
    std::unordered_map<int, int> snakes;
    std::unordered_map<int, int> ladders;

    Board(int boardSize) : size(boardSize) {
        srand(time(0));
        generateSnakesAndLadders();
    }

    void generateSnakesAndLadders() {
        for (int i = 0; i < 5; i++) {
            int head = (rand() % (size - 10)) + 10;
            int tail = (rand() % (head - 1)) + 1;
            if (snakes.find(head) == snakes.end()) {
                snakes[head] = tail;
            }
        }
        for (int i = 0; i < 5; i++) {
            int bottom = (rand() % (size - 10)) + 1;
            int top = (rand() % (size - bottom)) + bottom;
            if (ladders.find(bottom) == ladders.end() && snakes.find(bottom) == snakes.end()) {
                ladders[bottom] = top;
            }
        }
    }

public:
    static Board* getInstance(int boardSize = 100) {
        if (!instance) {
            instance = new Board(boardSize);
        }
        return instance;
    }

    static void deleteInstance() {
        delete instance;
        instance = nullptr;
    }

    int checkPosition(int position) {
        if (snakes.find(position) != snakes.end()) {
            std::cout << "Oops! Snake at " << position << " → Move to " << snakes[position] << "\n";
            return snakes[position];
        }
        if (ladders.find(position) != ladders.end()) {
            std::cout << "Yay! Ladder at " << position << " → Move to " << ladders[position] << "\n";
            return ladders[position];
        }
        return position;
    }

    int getSize() const { return size; }
};

Board* Board::instance = nullptr;

// Strategy Pattern - Dice Rolling
class DiceStrategy {
public:
    virtual int roll() = 0;
    virtual ~DiceStrategy() {}
};

class StandardDice : public DiceStrategy {
public:
    int roll() override {
        return (rand() % 6) + 1;
    }
};

// Player class
class Player : public IObserver {
private:
    std::string name;
    int position;
    DiceStrategy* diceStrategy;

public:
    Player(std::string playerName) : name(playerName), position(1) {
        diceStrategy = new StandardDice();
    }

    ~Player() {
        delete diceStrategy;
    }

    void setDiceStrategy(DiceStrategy* strategy) {
        if (diceStrategy) {
            delete diceStrategy;
        }
        diceStrategy = strategy;
    }

    void move() {
        if (!diceStrategy) {
            std::cerr << "Error: Dice strategy not initialized.\n";
            return;
        }

        int diceRoll = diceStrategy->roll();
        std::cout << name << " rolled a " << diceRoll << "\n";
        
        int newPosition = position + diceRoll;

        if (newPosition <= Board::getInstance()->getSize()) { // Prevent overshooting
            position = Board::getInstance()->checkPosition(newPosition);
        }

        update(name, position);
    }

    bool hasWon() {
        return position == Board::getInstance()->getSize();
    }

    void update(std::string playerName, int newPosition) override {
        std::cout << playerName << " is now at position " << newPosition << "\n";
    }

    std::string getName() { return name; }
};

// Command Pattern - Encapsulating Move Command
class MoveCommand {
private:
    Player& player;

public:
    MoveCommand(Player& p) : player(p) {}

    void execute() {
        player.move();
    }
};

// Game Manager (Observer Pattern for turn notification)
class GameManager {
private:
    std::vector<Player> players;
    int currentPlayerIndex;

public:
    GameManager(std::vector<std::string> playerNames) {
        for (auto& name : playerNames) {
            players.emplace_back(name);
        }
        currentPlayerIndex = 0;
    }

    void playGame() {
        while (true) {
            Player& currentPlayer = players[currentPlayerIndex];
            MoveCommand moveCmd(currentPlayer);
            moveCmd.execute();

            if (currentPlayer.hasWon()) {
                std::cout << currentPlayer.getName() << " wins the game! 🎉\n";
                break;
            }

            currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
            std::cout << "-----------------------------\n";
        }
    }
};

// Main function
int main() {
    std::vector<std::string> playerNames = {"Alice", "Bob", "Charlie"};
    GameManager game(playerNames);
    game.playGame();

    // Cleanup singleton instance
    Board::deleteInstance();

    return 0;
}
