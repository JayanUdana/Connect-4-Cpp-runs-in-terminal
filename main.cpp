/**
	*Author : Theon_Jay*
**/
#include <iostream>

using namespace std;

//colors
const string RED = "\033[1;31m";
const string YELLOW = "\033[1;33m";
const string BLUE = "\033[1;34m";
const string RESET = "\033[0m";

//main elements
const int R=6 , C=7;
const char EMPTY= '.' , P1 = 'X', P2 = 'O';
char board[R][C];

//functions
void renderBoard();
int menu();
void start();

int main(){
    renderBoard();
    cout << "\n\n";
    cout << BLUE << "CONNECT "<< RESET<< RED<< "4"<< RESET << " by Jayan \nversion 1"<< "\n\n";
    int mode = menu();
    if (mode == 1) cout << "\n";start();
        
}

void renderBoard(){
    for (auto &x : board){
       for (auto &y :x){
        y = EMPTY;}
    }
}
int menu(){
    
    cout << "Choose the mode to play: \n 1) Two players \n 2) Vs Computer \n 3) Vs AI \n";
    cout << "Mode: ";
    int mode; 
    cin>> mode;
    return mode;
}
void start(){
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

