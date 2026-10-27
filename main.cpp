/**
	*Author : Theon_Jay*
**/
#include <iostream>

using namespace std;

//colors
constexpr string RED = "\033[1;31m";
constexpr string YELLOW = "\033[1;33m";
constexpr string BLUE = "\033[1;34m";
constexpr string RESET = "\033[0m";
constexpr string GREEN = "\033[1;32m";

//main elements
const int R=6 , C=7;
const char EMPTY= '.' , P1 = 'X', P2 = 'O';
char board[R][C];
bool endgame = false;

//functions
void renderBoard();
string menu();
void iniboard();

int main(){
    iniboard();
    cout << "\n\n";
    cout << BLUE << "CONNECT "<< RESET<< RED<< "4"<< RESET << " by Jayan \nversion 1"<< "\n\n";

    while(!endgame){
        string mode = menu();
        if (mode == "1") {cout << "\n";renderBoard();}
        else if (mode == "2" || mode == "3") {cout << RED << "mode is on update! , choose a different mode. \n" << RESET ;}
        else if (mode == "0") {endgame = true; cout << GREEN <<"GOOD BYE! TAKE CARE! " << RESET;}
        else cout << RED << "Invaid choice , choose a valid mode \n\n" << RESET ;
}
}

void renderBoard(){
    for ( int i=0 ; i < R ; ++i){
        cout << BLUE << "| " << RESET;
            for(int j=0; j<C ; ++j){
                cout << board[i][j] << " ";}
        cout << BLUE << "|" << RESET <<"\n" ;
    }
    cout << BLUE << "|-";
    for(int i=0 ; i < 2*C ;++i)cout << "-";
    cout << "|" << RESET << "\n" << "  ";
    for(int i=0; i<C ; ++i) cout << i+1 << " ";
    cout << "\n";
}
string menu(){
    
    cout << "Choose the mode to play: \n 1) Two players \n 2) Vs Computer \n 3) Vs AI \n 0) EXIT \n";
    cout << "Mode: ";
    string mode; 
    cin>> mode;
    return mode;
}
void iniboard(){
    for (auto &x : board){
       for (auto &y :x){
        y = EMPTY;}
    }
    
}

