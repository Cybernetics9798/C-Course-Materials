#include <stdio.h>
#include "MacUILib.h"
#include "myStringLib.h"   // This is your first custom C library
#include <stdlib.h>
#include <time.h>

// PREPROCESSOR DIRECTIVE CONSTANTS
// ================================
// For program-wide constants, define them here using #define.  Add as seen needed.
// [COPY AND PASTE FROM PPA2] Copy your additional preprocessor constants from PPA2 and paste them below
#define LENGTH 21
#define WIDTH 11

// [TODO] Then, define more constants here as seen needed.
#define BINSIZE 5

// GLOBAL VARIABLES
// ================================
char board[WIDTH][LENGTH];
int gamespeed;
int exitFlag; // Program Exiting Flag

// [COPY AND PASTE FROM PPA2] Copy your additional global from PPA2 and paste them below
char input;
struct objPos{
    int x;
    int y;
    char symbol;
};
struct objPos position;

struct speedFlag{
    int gamespeed;
    int level;
};
struct speedFlag speedFlag;

enum objDir {UP, DOWN, LEFT, RIGHT, STOP, CHEAT};
enum objDir direction;
// [TODO] Declare More Global Variables as seen needed.
int win;
int length;
int newlen;
int listSize;
int xRange;
int yRange;
int movecount;
char goalString[] = "McMaster-ECE";

// [TODO] Declare Global Pointers as seen needed / instructed in the manual.
char *displayString;
char *itempool;
struct objPos *itembin;


// FUNCTION PROTOTYPES
// ================================
// Declare function prototypes here, so that we can organize the function implementation after the main function for code readability.
void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

// [TODO] In PPA3, you will need to implement this function to generate random items on the game board
//        to set the stage for the Scavenger Hunter game.
// list[]       The pointer to the Item Bin
// listSize     The size of the Item Bin (5 by default)
// playerPos    The pointer to the Player Object, read only.
// xRange       The maximum range for x-coordinate generation (probably the x-dimension of the gameboard?)
// yRange       The maximum range for y-coordinate generation (probably the y-dimension of the gameboard?)
// str          The pointer to the start of the Goal String (to choose the random characters from)
void GenerateItems(struct objPos list[], const int listSize, const struct objPos *playerPos, const int xRange, const int yRange, const char* str);


// MAIN PROGRAM
// ===============================
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
// ===============================
void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    input = 0;
    exitFlag = 0;  // 0 - do not exit, non-zero - exit the program

    // [COPY AND PASTE FROM PPA2] Copy your initialization routine from PPA2 and paste them below
    length = my_strlen(goalString);
    newlen = length;
    position.x = 5;
    position.y = 10;
    position.symbol = '@';
    direction = STOP;
    speedFlag.gamespeed = 100000; // 0.1s delay by default
    speedFlag.level = 0;

    // [TODO] Initialize any global variables as required.
    win = 0;
    listSize = 5;
    movecount = 0;
    xRange = WIDTH - 2;
    yRange = LENGTH - 2;

    //Board initialization
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
    
    
    // [TODO] Allocated heap memory for on-demand variables as required.  Initialize them as required.
    itembin = (struct objPos *)malloc(listSize * sizeof(struct objPos));
    displayString = (char *)malloc(length * sizeof(char));
    itempool = (char *)malloc(length * sizeof(char));   //initialize a pool of characters for the random generation function to choose from
    
    if(itembin == NULL){
        printf("Error: itembin memory allocation failed\n");
        exit(1);
    }
    if(displayString == NULL){
        printf("Error: displayString memory allocation failed\n");
        exit(1);
    }
    if(itempool == NULL){
        printf("Error: itempool memory allocation failed\n");
        exit(1);
    }

    for(int i = 0; i < length; i++){
        displayString[i] = '?';
    }

    for(int i = 0; i < length; i++){
        itempool[i] = goalString[i];
    }

    // [TODO] Seed the random integer generation function with current time.
    srand(time(NULL));
    
    // [TODO] Generate the initial random items on the game board at the start of the game.
    GenerateItems(itembin, BINSIZE, &position, xRange, yRange, itempool);
}


// INPUT COLLECTION ROUTINE
// ===============================
void GetInput(void)
{
    // Asynchronous Input - non blocking character read-in
    // [COPY AND PASTE FROM PPA2] Copy your input collection routine from PPA2 and paste them below
    if(MacUILib_hasChar() == 1){
        input = MacUILib_getChar();
    }
    // [TODO] Though optional for PPA3, you may insert any additional logic for input processing.
}


// MAIN LOGIC ROUTINE
// ===============================
void RunLogic(void){
    if(win == 1){
        exitFlag = 1;
    }
    
    // [COPY AND PASTE FROM PPA2] Copy your main logic routine from PPA2 and paste them below
    if(input != 0)  // if not null character
    {
        switch(input)
        {                      
            case ' ':  // exit
                exitFlag = 1;
                break;
            case 'w':
                if(direction != DOWN){
                    direction = UP;
                }
                break;
            case 'a':
                if(direction != RIGHT){
                    direction = LEFT;
                }
                break;
            case 's':
                if(direction != UP){
                    direction = DOWN;
                }
                break;
            case 'd':
                if(direction != LEFT){
                    direction = RIGHT;
                }
                break;
            case 'p':
                direction = CHEAT;
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
            case 'q':
                exitFlag = 1;
                break;
            default:
                break;
        }
        input = 0;
    }

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
            movecount++;
            break;
        case DOWN:
            position.x = (position.x + 1) % (WIDTH - 2);
            if(position.x == 0){
                position.x = 1;
            }
            movecount++;
            break;
        case LEFT:
            position.y = (position.y - 1 + (LENGTH - 2)) % (LENGTH - 2);
            if(position.y == 0){
                position.y = LENGTH - 3;
            }
            movecount++;
            break;
        case RIGHT:
            position.y = (position.y + 1) % (LENGTH - 2);
            if(position.y > (LENGTH - 3)){
                position.y = 1;
            }else if(position.y == 0){
                position.y = 1;
            }
            movecount++;
            break;
        case STOP:
            break;
        case CHEAT:
            win = 1;
            break;
        default:
            break;
    }

    if(speedFlag.level >= -2 && speedFlag.level <= 2){
        speedFlag.gamespeed = 100000 + speedFlag.level * 25000;
    }

    // [TODO] : Heed the border wraparound!!!
    board[position.x][position.y] = position.symbol;
    if(direction != STOP){
        if(temp.x == 0 || temp.x == (WIDTH - 2)){
            board[temp.x][temp.y] = '#';
        }
        else if(temp.y == 0 || temp.y == (LENGTH - 2)){
            board[temp.x][temp.y] = '#';
        }else{
            board[temp.x][temp.y] = ' ';
        }
    }

    // [TODO]   Implement the Object Collision logic here
    //
    //      Simple Collision Algorithm
    //      1. Go through all items on board and check their (x,y) against the player object x and y.
    //      2. If a match is found, use the ASCII symbol of the collided character, and 
    //         find all the occurrences of this ASCII symbol in the Goal String
    //      3. For every occurrence, reveal its ASCII character at the corresponding location in the
    //         Collected String
    //      4. Then, determine whether the game winning condition is met.
    int collide = 0;
    int i = 0;
    int check = 0;
    
    while(i < BINSIZE && collide == 0){
        if(itembin[i].x == position.x && itembin[i].y == position.y){
            collide = 1;
            for(int j = 0; j < length; j++){
                if(displayString[j] == '?'){
                    if(goalString[j] == itembin[i].symbol){
                        displayString[j] = goalString[j];
                        newlen--;
                    }else if(goalString[j] == itembin[i].symbol - 32 && (itembin[i].symbol - 32) >= 'A' && (itembin[i].symbol - 32) <= 'Z'){
                        displayString[j] = goalString[j];
                        newlen--;
                    }
                }
            }

            if(newlen != 0){
                itempool = realloc(itempool, newlen * sizeof(char));
            }else if(newlen == 0){
                free(itempool);
            }

            if(itempool == NULL && newlen != 0){
                printf("Error: itempool memory allocation failed\n");
                exit(1);
            }

            int tempindex = 0;
            for(int o = 0; o < length; o++){
                if(displayString[o] == '?'){
                    itempool[tempindex] = goalString[o];
                    tempindex++;
                }
            }

            for(int k = 0; k < BINSIZE; k++){
                board[itembin[k].x][itembin[k].y] = ' ';
            }
            GenerateItems(itembin, BINSIZE, &position, xRange, yRange, itempool);
        }

        i++; //Don't forget to increase i!!!!!!
    }

    // [TODO]   Implement Game Winning Check logic here
    //
    //      Game Winning Check Algorithm
    //      1. Check if the contents of the Collected String exactly matches that of the Goal String.
    //         YOU MUST USE YOUR OWN my_strcmp() function from Lab 3.
    //      2. If matched, end the game.
    //      3. Otherwise, discard the current items on the game board, and 
    //         generate a new set of random items on the board.  Game continues.
    if(newlen == 0){
        win = 1;
    }
}


// DRAW ROUTINE
// ===============================
void DrawScreen(void){
    // [COPY AND PASTE FROM PPA2] Copy your draw logic routine from PPA2 and paste them below
    MacUILib_clearScreen();
    for(int i = 0; i < (WIDTH - 1); i++){
        for(int j = 0; j < (LENGTH - 1); j++){
           MacUILib_printf("%c", board[i][j]);
        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("Mystery String: ");
    for(int i = 0; i < length; i++){
        MacUILib_printf("%c", displayString[i]);
    }
    MacUILib_printf("\n");

    MacUILib_printf("\nCurrent direction: ");
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
        case STOP:
            MacUILib_printf("STOP\n");
            break;
        default:
            break;
    }
    MacUILib_printf("Current move count: %d\n", movecount);
    MacUILib_printf("Press n or m to change game speed\n");
    MacUILib_printf("Current game speed is %f sec\n", speedFlag.gamespeed/1000000.0);
    MacUILib_printf("\nPress q to quit\n");
   
    // [TODO]   Insert somewhere in the draw routine to draw the randomly generated items on the board.
    for(int i = 0; i < BINSIZE; i++){
        board[itembin[i].x][itembin[i].y] = itembin[i].symbol;
    }

    // [TODO]   Display the "Mystery String" contents at the bottom of the game board
    //          To help players keep track of their game progress.
    
    if(win == 1){
        MacUILib_printf("\nYou win!\n");
    }
}


// DELAY ROUTINE
// ===============================
void LoopDelay(void){
    MacUILib_Delay(speedFlag.gamespeed);
}


// TEAR-DOWN ROUTINE
// ===============================
void CleanUp(void){
    // [TODO]   To prevent memory leak, free() any allocated heap memory here
    //          Based on the PPA3 requirements, you need to at least deallocate one heap variable here.
    free(displayString);
    free(itembin);
    //free(itempool);
    // Insert any additional end-game actions here.
    MacUILib_uninit();  
}


// The Item Generation Routine
////////////////////////////////////
void GenerateItems(struct objPos list[], const int listSize, const struct objPos *playerPos, const int xRange, const int yRange, const char* str){
    // This is possibly one of the most conceptually challenging function in all PPAs
    // Once you've mastered this one, you are ready to take on the 2SH4 course project!

    // Random Non-Repeating Item Generation Algorithm
    ////////////////////////////////////////////////////

    // Use random number generator function, rand(), to generate a random x-y coordinate and a random choice of character from the Goal String as the ASCII character symbol.
    //      The x and y coordinate range should fall within the xRange and yRange limits, which should be the x- and y-dimension of the board size.
    // This will then be a candidate of the randomly generated Item to be placed on the game board.

    // In order to make sure this candidate is validated, it needs to meet both criteria below:
    //  1. Its coordinate and symbol has not been previously generated (no repeating item)
    //  2. Its coordinate does not overlap the Player's position
    // Thus, for every generated item candidate, check whether its x-y coordinate and symbol has previously generated.  
    //  Also, check if it overlaps the player position
    //      If yes, discard this candidate and regenerate a new one
    //      If no, this candidate is validated.  Add it to the input list[]

    // There are many efficient ways to do this question
    //  We will take a deep dive into some methods in 2SI.

    //Random coordinate generation section
    int xcount = 0;
    int ycount = 0;
    int index = 0;
    char characters[5];
    int xnum[5];
    int ynum[5];
    int xvector[xRange];
    int yvector[yRange];

    //Initialize the xvector and yvector arrays with 0
    for(int a = 0; a < xRange; a++){
        xvector[a] = 0;
    }
    for(int b = 0; b < yRange; b++){
        yvector[b] = 0;
    }

    //Generate x values
    while (xcount < listSize){
        int temp = (rand() % xRange); //temp is the random number generated
        if(temp == 0){
            temp++;
        }
        if(temp == xRange - 1){
            temp--;
        }
        if(xvector[temp] == 0 && temp != playerPos->x){
            xvector[temp] = 1;
            xcount++;
        }
    }
    index = 0;
    for(int c = 0; c < xRange; c++){
        if(xvector[c] == 1){
            xnum[index] = c;
            index++;
        }
    }

    //Generate y values
    while (ycount < listSize){
        int temp = rand() % yRange;
        if(temp == 0){
            temp++;
        }
        if(temp == xRange - 1){
            temp--;
        }
        if(yvector[temp] == 0 && temp != playerPos->y){
            yvector[temp] = 1;
            ycount++;
        }
    }
    index = 0;
    for(int d = 0; d < yRange; d++){
        if(yvector[d] == 1){
            ynum[index] = d;
            index++;
        }
    }
    
    //Random character generation section
    int charvector[27];
    int ccount = 0;

    for(int c = 0; c < 26; c++){ //initialize the charvector array with 0
        charvector[c] = 0;
    }

    //Randomly generate 5 characters
    while(ccount < 5){
        int temp = rand() % 26;
        if(charvector[temp] == 0){
            charvector[temp] = 1;
            ccount++;
        }
    }

    //Put the random characters into the characters array
    index = 0;
    for(int d = 0; d < 27; d++){
        if(charvector[d] == 1){
            characters[index] = d + 'a';
            index++;
        }else if(charvector[d] == '-'){
            characters[index] = '-';
            index++;
        }
    }

    //Make sure 2 of the random characters are from the goal string
    if(newlen >= 2){
        for(int i = 0; i < 2; i++){
            char tempchar = str[i];
            if(tempchar >= 'A' && tempchar <= 'Z'){
                tempchar = tempchar + 32;
            }

            int repeat = 0;
            for(int j = 0; j < listSize; j++){
                if(characters[j] == tempchar){
                    repeat = 1;
                }
            }
            if(repeat == 0){
                characters[i] = tempchar;
            }
        }
    }else if(newlen == 1){
        char tempchar = str[0];
        if(tempchar >= 'A' && tempchar <= 'Z'){
            tempchar = tempchar + 32;
        }

        int repeat = 0;
        for(int j = 0; j < listSize; j++){
            if(characters[j] == tempchar){
                repeat = 1;
            }
        }
        if(repeat == 0){
            characters[0] = tempchar;
        }
    }

    //Put the random characters and coordinates into the list
    for(int i = 0; i < listSize; i++){
        list[i].x = xnum[i];
        list[i].y = ynum[i];
        list[i].symbol = characters[i];
    }
}
