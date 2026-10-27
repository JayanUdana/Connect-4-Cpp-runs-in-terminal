/** 	*Author : Theon_Jay* **/
#include <iostream>
#include <array>
#include <string>

using namespace std;

// Colors
constexpr string_view RED = "\033[1;31m";
constexpr string_view YELLOW = "\033[1;33m";
constexpr string_view BLUE = "\033[1;34m";
constexpr string_view RESET = "\033[0m";
constexpr string_view GREEN = "\033[1;32m";

// Constants
constexpr int ROWS = 6;
constexpr int COLS = 7;
constexpr int EMPTY = 0;
constexpr int PLAYER_1 = 1;
constexpr int PLAYER_2 = 2;

// Representing pieces visually
constexpr char TOKEN_EMPTY = '.';
constexpr char TOKEN_P1 = 'X';
constexpr char TOKEN_P2 = 'O';

struct Direction {
    int row;
    int col;
};

struct GameState {
    array<array<int, COLS>, ROWS> board{}; // Automatically initializes all slots to 0 (EMPTY)
    array<int, COLS> nextAvailableRow{5, 5, 5, 5, 5, 5, 5}; // Bottom row is 5, top is 0
    int currentPlayer = PLAYER_1;
};

// Functions declarations
void renderBoard(const GameState& game);
string menu();
bool checkWinner(const std::array<std::array<int, COLS>, ROWS>& board, int lastRow, int lastCol, int player);
bool makeMove(GameState& game, int col, int& outRowPlaced);
void playTwoPlayerGame();

int main() {
    bool endgame = false;
    cout << "\n\n" << BLUE << "CONNECT " << RESET << RED << "4" << RESET << " by Jayan \nversion 2 (Refactored)\n\n";

    while (!endgame) {
        string mode = menu();
        if (mode == "1") {
            playTwoPlayerGame();
        } 
        else if (mode == "2" || mode == "3") {
            cout << RED << "mode is on update! , choose a different mode. \n" << RESET;
        } 
        else if (mode == "0") {
            endgame = true;
            cout << GREEN << "GOOD BYE! TAKE CARE! \n" << RESET;
        } 
        else {
            cout << RED << "Invalid choice , choose a valid mode \n\n" << RESET;
        }
    }
    return 0;
}

string menu() {
    cout << "Choose the mode to play: \n 1) Two players \n 2) Vs Computer \n 3) Vs AI \n 0) EXIT \n";
    cout << "Mode: ";
    string mode;
    cin >> mode;
    return mode;
}

void renderBoard(const GameState& game) {
    cout << "\n";
    for (int i = 0; i < ROWS; ++i) {
        cout << BLUE << "| " << RESET;
        for (int j = 0; j < COLS; ++j) {
            if (game.board[i][j] == PLAYER_1) {
                cout << RED << TOKEN_P1 << RESET << " ";
            } else if (game.board[i][j] == PLAYER_2) {
                cout << YELLOW << TOKEN_P2 << RESET << " ";
            } else {
                cout << TOKEN_EMPTY << " ";
            }
        }
        cout << BLUE << "|" << RESET << "\n";
    }
    cout << BLUE << "|-";
    for (int i = 0; i < 2 * COLS; ++i) cout << "-";
    cout << "|" << RESET << "\n" << "  ";
    for (int i = 0; i < COLS; ++i) cout << i + 1 << " ";
    cout << "\n\n";
}

bool makeMove(GameState& game, int col, int& outRowPlaced) {
    if (col < 0 || col >= COLS || game.nextAvailableRow[col] < 0) {
        return false;
    }
    int row = game.nextAvailableRow[col];
    game.board[row][col] = game.currentPlayer;
    outRowPlaced = row;
    game.nextAvailableRow[col]--;
    return true;
}

bool checkWinner(const array<array<int, COLS>, ROWS>& board, int lastRow, int lastCol, int player) {
    constexpr array<Direction, 4> directions = {{
        {0, 1},   // Horizontal
        {1, 0},   // Vertical
        {1, 1},   // Diagonal Down-Right
        {1, -1}   // Diagonal Down-Left
    }};

    for (const auto& [dRow, dCol] : directions) {
        int count = 1;

        // Look Forward
        int r = lastRow + dRow;
        int c = lastCol + dCol;
        while (r >= 0 && r < ROWS && c >= 0 && c < COLS && board[r][c] == player) {
            count++;
            r += dRow;
            c += dCol;
        }

        // Look Backward
        r = lastRow - dRow;
        c = lastCol - dCol;
        while (r >= 0 && r < ROWS && c >= 0 && c < COLS && board[r][c] == player) {
            count++;
            r -= dRow;
            c -= dCol;
        }

        if (count >= 4) {
            return true;
        }
    }
    return false;
}

void playTwoPlayerGame() {
    GameState game;
    bool gameActive = true;
    int movesCount = 0;
    int maxMoves = ROWS * COLS;

    while (gameActive) {
        renderBoard(game);
        
        int activePlayer = game.currentPlayer;
        if (activePlayer == PLAYER_1) {
            cout << RED << "Player 1 (X)" << RESET;
        } else {
            cout << YELLOW << "Player 2 (O)" << RESET;
        }
        cout << ", enter column (1-" << COLS << "): ";

        int chosenColumn;
        cin >> chosenColumn;
        chosenColumn--; // Convert 1-indexed choice to 0-indexed array space

        int rowPlaced = -1;
        if (makeMove(game, chosenColumn, rowPlaced)) {
            movesCount++;
            
            // Check win condition using the freshly placed move details
            if (checkWinner(game.board, rowPlaced, chosenColumn, activePlayer)) {
                renderBoard(game);
                if (activePlayer == PLAYER_1) {
                    cout << GREEN << "CONGRATULATIONS! Player 1 (X) wins!\n\n" << RESET;
                } else {
                    cout << GREEN << "CONGRATULATIONS! Player 2 (O) wins!\n\n" << RESET;
                }
                gameActive = false;
            } 
            // Check for draw condition
            else if (movesCount == maxMoves) {
                renderBoard(game);
                cout << YELLOW << "It's a tie game! The board is full.\n\n" << RESET;
                gameActive = false;
            } 
            else {
                // Alternates current player only after a valid non-winning turn
                game.currentPlayer = (activePlayer == PLAYER_1) ? PLAYER_2 : PLAYER_1;
            }
        } else {
            cout << RED << "Column is full or invalid! Try again.\n" << RESET;
        }
    }
}
