/**
	*Author : Theon_Jay*
**/
#include <iostream>
#include <array>

using namespace std;

//colors
constexpr string RED = "\033[1;31m";
constexpr string YELLOW = "\033[1;33m";
constexpr string BLUE = "\033[1;34m";
constexpr string RESET = "\033[0m";
constexpr string GREEN = "\033[1;32m";
constexpr string CYAN = "\033[1;36m";
constexpr string MAGENTA = "\033[1;35m";

//main elements
constexpr int R=6 , C=7;
constexpr int P1 = 1 , P2 = 2; 
char board[R][C];
bool endgame = false;

//GUI 
constexpr char EMPTY_GUI= '.' , P1_GUI = 'X', P2_GUI = 'O';

//Data Strunctures
struct gamestate {
    array<array<int , C>, R> board{};
    array<int , C> gravity{5,5,5,5,5,5,5};
    int cur_p = P1;
};

struct direction {
    int row;
    int col;
};

//functions
void renderBoard(const gamestate &game);
string menu();
void twoplayer();

int main(){
    
    cout << "\n\n";
    cout << BLUE << "CONNECT "<< RESET<< RED<< "4"<< RESET << " by Jayan \nversion 1"<< "\n\n";

    while(!endgame){
        string mode = menu();
        if (mode == "1") {cout << "\n"; twoplayer();}
        else if (mode == "2") {cout << RED << "mode is on update! , choose a different mode. \n\n" << RESET ;}
        else if (mode == "0") {endgame = true; cout << GREEN <<"GOOD BYE! TAKE CARE! " << RESET;}
        else cout << RED << "Invaid choice , choose a valid mode \n\n" << RESET ;
}
}

void renderBoard(const gamestate &game){
    for ( int i=0 ; i < R ; ++i){
        cout << BLUE << "| " << RESET;
            for(int j=0; j<C ; ++j){
                if (board[i][j]== P1) cout << CYAN << P1_GUI << " " << RESET ;
                else if (board[i][j] == P2)cout << MAGENTA << P2_GUI << " " << RESET ;
                else cout << EMPTY_GUI << " ";}
        cout << BLUE << "|" << RESET <<"\n" ;
    }
    cout << BLUE << "|-";
    for(int i=0 ; i < 2*C ;++i)cout << "-";
    cout << "|" << RESET << "\n" << "  ";
    for(int i=0; i<C ; ++i) cout << i+1 << " ";
    cout << "\n";
}
string menu(){
    
    cout << "Choose the mode to play: \n 1) Two players \n 2) Vs AI \n\n 0) EXIT \n";
    cout << "Mode: ";
    string mode; 
    cin>> mode;
    return mode;
}

void twoplayer(){
    gamestate game;
    bool active = true;
    while (active){
        renderBoard(game);
        cout <<BLUE <<"PRESS 1-7 + enter to choose colom.\n"<< RESET << "to " << RED << "exit "<< RESET << "press 0 + enter\n"; 
        int whoPlay = game.cur_p;
        if (whoPlay == 1){
            cout << CYAN << "Player X " << RESET <<"move: ";
        }
        else cout << MAGENTA << "Player O " << RESET <<"move: ";
        
        int move;
        cin >> move;
        move--;


        active = false;
    }
}

/*
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
    }*/