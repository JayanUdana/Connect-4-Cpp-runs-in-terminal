# Connect 4 Project
I am working on a private project to learn C++ beyond basic applications. My goal is to gain a deeper understanding of how to implement modern C++ practices and achieve optimal time complexity in real-world projects, moving beyond competitive programming.

In this project I tried to improve time complexity as much as i can possible with my current knowledge and given time.

Let's now go throght the code to undersatnd what it is and how i improved certain points to improve performence.  I will explain this code in four parts.

> ### 4 Parts that power the code
> 1. [Colors and GUI](#coloers-and-gui) (Aesthetic part when code in running).
> 2. [Data structures](#data-structures-and-constants) and CONSTANT variables (that gave the code parformance and safety net).
> 3. [Functions](#functions) (magic that powers the code)
> 4. [int main()](#int-main){where everything works as an unit}

## Colors and GUI
const string RED = "\033[1;31m";
constexpr char EMPTY_GUI= '.' , P1_GUI = 'X', P2_GUI = 'O';
## Data Structures and CONSTANTS
struct gamestatus {
    array<array<int , C>, R> board{};
    array<int , C> gravity{5,5,5,5,5,5,5};
    int cur_p = P1;
};
struct direction {
    int row;
    int col;
};
## Functions
void renderBoard(const gamestatus &game);
string menu();
void twoplayer();
int playMaker(const gamestatus &game,int move , int &headRow);
bool winner(const array<array<int,C>,R> &baord, int prev_row , int prev_colom , int player);
## int main()
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