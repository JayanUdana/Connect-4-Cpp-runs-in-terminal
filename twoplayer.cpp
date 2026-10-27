struct Direction {
    int row;
    int col;
};

struct GameState {
    array<std::array<int, COLS>, ROWS> board{}; // Automatically initializes all slots to 0 (EMPTY)
    array<int, COLS> nextAvailableRow{5, 5, 5, 5, 5, 5, 5}; // Bottom row is 5, top is 0
    int currentPlayer = PLAYER_1;
};

// Functions declarations
void renderBoard(const GameState& game);
string menu();
bool checkWinner(const std::array<std::array<int, COLS>, ROWS>& board, int lastRow, int lastCol, int player);
bool makeMove(GameState& game, int col, int& outRowPlaced);
void playTwoPlayerGame();