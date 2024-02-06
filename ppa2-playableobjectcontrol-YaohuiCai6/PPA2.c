#include <stdio.h>
#include "MacUILib.h"

// PPA2 GOAL: 
//       Construct the game backbone where the player can control an object 
//       to move freely in the game board area with border wraparound behaviour.

// Watch Briefing Video and Read Lab Manual before starting on the activity!

// PREPROCESSOR CONSTANTS DEFINITION HERE
/////////////////////////////////////////
#define LENGTH 21
#define WIDTH 11

// GLOBAL VARIABLE DEFINITION HERE
/////////////////////////////////////////
char board[WIDTH][LENGTH];
int gamespeed;
int exitFlag; // Program Exiting Flag - old stuff

// For storing the user input - from PPA1
char input;

// [TODO] : Define objPos structure here as described in the lab document
struct objPos{
    int x;
    int y;
};
struct objPos position;

struct speedFlag{
    int gamespeed;
    int level;
};
struct speedFlag speedFlag;
// [TODO] : Define the Direction enumeration here as described in the lab document
//          This will be the key ingredient to construct a simple Finite State Machine
//          For our console game backbone.
enum objDir {UP, DOWN, LEFT, RIGHT};
enum objDir direction;

// FUNCTION PROTOTYPING DEFINITION HERE
/////////////////////////////////////////

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

// You may insert additional helper function prototypes below.
// 
// As a good practice, always insert prototype before main() and implementation after main()
// For ease of code management.



// MAIN PROGRAM LOOP
/////////////////////////////////////////
// This part should be intuitive by now.
// DO NOT TOUCH

int main(void)
{

    Initialize();

    while(!exitFlag)  
    {
        GetInput();

        RunLogic();

        DrawScreen();

        LoopDelay();
    }

    CleanUp();

}


// INITIALIZATION ROUTINE
/////////////////////////////////////////
void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    input = 0; // NULL
    exitFlag = 0;  // not exiting    
   
    // [TODO] : Initialize more variables here as seen needed.
    //          PARTICULARLY for the structs!!
    position.x = 5;
    position.y = 10;
    speedFlag.gamespeed = 100000;
    speedFlag.level = 0;

    for(int i = 0; i < WIDTH - 1; i++){
        for(int j = 0; j < LENGTH - 1; j++){
            if(i == 0 || i == WIDTH - 2){
                board[i][j] = '#';
            }
            else if(j == 0 || j == LENGTH - 2){
                board[i][j] = '#';
            }
            else{
                board[i][j] = ' ';
            }
        }
    }
    board[position.x][position.y] = '@';
}


// INPUT PROCESSING ROUTINE
/////////////////////////////////////////
void GetInput(void)
{
    // [TODO] : Implement Asynchronous Input - non blocking character read-in    
    //          (Same as PPA1)
    if(MacUILib_hasChar() == 1){
        input = MacUILib_getChar();
    }
}


// PROGRAM LOGIC ROUTINE
/////////////////////////////////////////
void RunLogic(void)
{
    // [TODO] : First, process the input by mapping
    //          WASD to the corresponding change in player object movement direction

    if(input != 0)  // if not null character
    {
        switch(input)
        {                      
            case ' ':  // exit
                exitFlag = 1;
                break;
            case 'w':
                direction = UP;
                break;
            case 'a':
                direction = LEFT;
                break;   
            case 's':
                direction = DOWN;
                break;
            case 'd':
                direction = RIGHT;
                break;
            case 'm':
                if(speedFlag.level < 2){
                    speedFlag.level++;
                }
                break;
            case 'n':
                if(speedFlag.level > -2){
                    speedFlag.level--;
                }
                break;
            default:
                break;
        }
        input = 0;
    }

    // [TODO] : Next, you need to update the player location by 1 unit 
    //          in the direction stored in the program
    struct objPos temp;
    temp.x = position.x;
    temp.y = position.y;
    
    switch(direction){
        case UP:
            position.x = (position.x - 1 + (WIDTH - 2)) % (WIDTH - 2);
            if(position.x == 0){
                position.x = WIDTH - 3; //boundary control
            }else if(position.x == WIDTH - 2){
                position.x = 1;
            }
            break;
        case DOWN:
            position.x = (position.x + 1) % (WIDTH - 2);
            break;
        case LEFT:
            position.y = (position.y - 1 + (LENGTH - 2)) % (LENGTH - 2);
            if(position.y == 0){
                position.y = (LENGTH - 3);
            }
            break;
        case RIGHT:
            position.y = (position.y + 1) % (LENGTH - 2);
            if(position.y == (LENGTH - 3)){
                position.y = 1;
            }
            break;
        default:
            break;
    }

    if(speedFlag.level >= -2 && speedFlag.level <= 2){
        speedFlag.gamespeed = 100000 + speedFlag.level * 25000;
    }

    // [TODO] : Heed the border wraparound!!!
    board[position.x][position.y] = '@';
    if(temp.x == 0 || temp.x == (WIDTH - 2)){
        board[temp.x][temp.y] = '#';
    }
    else if(temp.y == 0 || temp.y == (LENGTH - 2)){
        board[temp.x][temp.y] = '#';
    }else{
        board[temp.x][temp.y] = ' ';
    }
}



// SCREEN DRAWING ROUTINE
/////////////////////////////////////////
void DrawScreen(void)
{
    // [TODO] : Implement the latest drawing logic as described in the lab manual
    //
    //  1. clear the current screen contents

    //  2. Iterate through each character location on the game board
    //     using the nested for-loop row-scanning setup.

    //  3. For every visited character location on the game board
    //          If on border on the game board, print a special character
    //          If at the player object position, print the player symbol
    //          Otherwise, print the space character
    //     Think about how you can format the screen contents to achieve the
    //     same layout as presented in the lab manual

    //  4. Print any debugging messages as seen needed below the game board.
    //     As discussed in class, leave these debugging messages in the program
    //     throughout your dev process, and only remove them when you are ready to release
    //     your code. 

   MacUILib_clearScreen();
   for(int i = 0; i < (WIDTH - 1); i++){
       for(int j = 0; j < (LENGTH - 1); j++){
           MacUILib_printf("%c", board[i][j]);
       }
       MacUILib_printf("\n");
   }
   MacUILib_printf("Current direction: ");
   switch(direction){
       case UP:
           MacUILib_printf("UP\n");
           break;
       case DOWN:
           MacUILib_printf("DOWN\n");
           break;
       case LEFT:
           MacUILib_printf("LEFT\n");
           break;
       case RIGHT:
           MacUILib_printf("RIGHT\n");
           break;
       default:
           break;
   }
   MacUILib_printf("Press n or m to change game speed\n");
   MacUILib_printf("Current game speed is %f sec\n", speedFlag.gamespeed/1000000.0);
}



// PROGRAM LOOOP DELAYER ROUTINE
/////////////////////////////////////////
void LoopDelay(void)
{
    // Change the delaying constant to vary the movement speed.
    MacUILib_Delay(speedFlag.gamespeed);
}



// PROGRAM CLEANUP ROUTINE
/////////////////////////////////////////
// Recall from PPA1 - this is run only once at the end of the program
// for garbage collection and exit messages.
void CleanUp(void)
{
    MacUILib_uninit();
}



