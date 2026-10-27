/**
	*Author : Theon_Jay*
**/
#include <iostream>
#include <array>

using namespace std;

//colors
const string RED = "\033[1;31m";
const string YELLOW = "\033[1;33m";
const string BLUE = "\033[1;34m";
const string RESET = "\033[0m";
const string GREEN = "\033[1;32m";
const string MAGENTA = "\033[1;35m";

//main elements
constexpr int R=6 , C=7;
constexpr int P1 = 1 , P2 = 2; 
//char board[R][C];
bool endgame = false;

//GUI 
constexpr char EMPTY_GUI= '.' , P1_GUI = 'X', P2_GUI = 'O';

//Data Strunctures
struct gamestatus {
    array<array<int , C>, R> board{};
    array<int , C> gravity{5,5,5,5,5,5,5};
    int cur_p = P1;
};

struct direction {
    int row;
    int col;
};

//functions
void renderBoard(const gamestatus &game);
string menu();
void twoplayer();
int playMaker(const gamestatus &game,int move , int &headRow);
bool winner(const array<array<int,C>,R> &baord, int prev_row , int prev_colom , int player);

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

void renderBoard(const gamestatus &game){
    for ( int i=0 ; i < R ; ++i){
        cout << BLUE << "| " << RESET;
            for(int j=0; j<C ; ++j){
                if (game.board[i][j]== P1) cout << MAGENTA << P1_GUI << " " << RESET ;
                else if (game.board[i][j] == P2)cout << YELLOW << P2_GUI << " " << RESET ;
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

int playMaker(gamestatus &game, int move , int &headRow){
    if (move <0 || move >= C) return 1;
    if (game.gravity[move] < 0 ) return 2;
    game.board[game.gravity[move]][move] = game.cur_p;
    headRow = game.gravity[move];
    game.gravity[move]--;
    return 0;

}
bool winner(const array<array<int,C>,R> &board, int prev_row, int prev_colom, int player){
     constexpr array<direction, 4> directions = {
            direction{1,0},
            direction{0,1},
            direction{1,1},
            direction{1,-1}
        };

            for(const auto &[row,col] : directions){
                int wincnt = 1;

                int newrow = prev_row + row ;
                int newcol = prev_colom + col;
                while (newrow >= 0 && newrow<R && newcol>=0 && newcol<C &&  board[newrow][newcol]==player){
                    wincnt++;
                    newrow += row;
                    newcol += col;
                }

                newrow = prev_row - row;
                newcol = prev_colom - col;
                while(newrow>=0 && newrow<R && newcol>=0 && newcol<C && board[newrow][newcol]==player){
                    wincnt++;
                    newrow -= row;
                    newcol -= col;
                }
                if(wincnt >= 4) return true;
            }
            return false;
}

void twoplayer(){
    gamestatus game;
    bool active = true;
    int roundcnt = 0;
    int round_max = R*C;
    while (active){
        renderBoard(game);
        cout <<BLUE <<"PRESS 1-7 + enter to choose colom.\n"<< RESET << "to " << RED << "exit "<< RESET << "press 0 + enter\n"; 
        if (game.cur_p == 1){
            cout << MAGENTA << "Player X " << RESET <<"move: ";
        }
        else cout << YELLOW << "Player O " << RESET <<"move: ";
        
        int move;
        cin >> move;
        if (cin.fail()){
            cin.clear();
            cin.ignore(1e9, '\n');
            cout << RED << "Invalid key please Enter only valid keys \n" << RESET;
            continue;
        }
        if(move == 0)break;

        move--;

        int headRow = 5;
        
        int playRes= playMaker(game,move,headRow);

        if(playRes==1)cout << RED <<++move << " : such a colom does not exit enter a valid colom 1-7\n" << RESET;
        else if (playRes==2)cout << RED <<" colom "<< ++move <<" is full try a different colom.\n" << RESET;
        else roundcnt++;

        bool win = winner(game.board, headRow, move , game.cur_p);

        if(win){
            renderBoard(game);
            string winner = (game.cur_p==P1)? "Player X" : "Player O";
            cout << GREEN << "CONGRATULATIONS! " << BLUE << winner << GREEN <<" Won this Round\n"<<RESET;

            active = false;}
        else if (roundcnt == round_max){
            renderBoard(game);
            cout << GREEN << "GOOD GAME! IT IS A DRAW\n"<<RESET ;

            active = false;}
        game.cur_p = (game.cur_p == P1) ? P2 : P1;
        
    }
}