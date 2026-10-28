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
For colors I used //technique, to choose colors as you can see I used this code const string RED = "\033[1;31m"; for colors. "\033[ then 1;31m"; to tell which color I need. After using a color code we need to remove the color currently active otherwise everything after using the color will take color I do not need to happen that so used RESET do change color in to defalt back again.

For user friendly visuals I used following varible to show pieces of the game combined with colors constexpr char EMPTY_GUI= '.' , P1_GUI = 'X', P2_GUI = 'O';. This help players to indentify pieces quickly and make game more visual pleasing. You can see how I used this pieces to work together with the board in this function [void renderBoard(const gamestatus &game);](#void-renderboardconst-gamestatus-game).

## Data Structures and CONSTANTS
For repeatable data that I am going to use over and over I used custom data sturcture because calling one is easier than calling 3 different values and passing that into modes every time which helps to reduce human erroers. **gamestatus** have three different data types I used an array for board , gravity array to save each colom lowest point to reduce time complexity rather than serching for the available lowest point each time. **direction** used instead of pair for convience. This data structer is used to find the each move is a winner move or now by searching (this save direction cordinates that need to search). For more details read this function in the code [bool winner();](#bool-winnerconst-arrayarrayintcr-baord-int-prev_row--int-prev_colom--int-player).

>[!NOTE]
>struct gamestatus {
>    array<array<int , C>, R> board{};
>    array<int , C> gravity{5,5,5,5,5,5,5};
>    int cur_p = P1;};
>
>struct direction {
>    int row;
>    int col;};

In order to not to accidently change board size and player values I used constexpr in c++20 instead of const which is more modern.
constexpr int R=6 , C=7;
constexpr int P1 = 1 , P2 = 2;

## Functions

### void renderBoard(const gamestatus &game);
This function is used to reder the board after each move.
### string menu();
This function is used to choose the mode to play between available modes.
### void twoplayer();
After chosing the two player mode in main menu. Also handle error cases which player can make, entering wrong colom that do not exist or colom that already full or choosing wrong mode in menu.
### int playMaker(const gamestatus &game,int move , int &headRow);
This function has the instruction to do what happens after each move played, where to put the pieces after each move. Gravity array comes in handy in this to reduce time complexity. 
### bool winner(const array<array<int,C>,R> &baord, int prev_row , int prev_colom , int player);
In this function rather than seaching through all the board to find if a winner move exist we can see if the last move is the winner move.Using directions data type I created we can search if the last move is winner or not. For visual undersatnd is in down below.


## int main()
This where the magic happens using all function working together to make the game work. From begging of the game to showing the menu and choosing the mode then start that mode, play that mode and finding the winner to and finally to end the game all happens in this area.