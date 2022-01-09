#include <stdio.h>
#include "cleanBuffer.h"
#include <windows.h>
#include "unistd.h"

void askColumn(int *column, int player, WORD, HANDLE);
void askRow(int *row, int player, WORD, HANDLE);
void clearScreen(void);
void changeColor(int, WORD, HANDLE);

int main() {

    char cell1 = ' ';
    char cell2 = ' ';
    char cell3 = ' ';

    char cell4 = ' ';
    char cell5 = ' ';
    char cell6 = ' ';

    char cell7 = ' ';
    char cell8 = ' ';
    char cell9 = ' ';


    int cell1Occupied = 0;
    int cell2Occupied = 0;
    int cell3Occupied = 0;

    int cell4Occupied = 0;
    int cell5Occupied = 0;
    int cell6Occupied = 0;

    int cell7Occupied = 0;
    int cell8Occupied = 0;
    int cell9Occupied = 0;

    int occupied = 0;


    char sign;

    int doneOnce = 0;

    int won = 0;
    int player = 0;
    int column = -1;
    int row = -1;

    int playsLast = 9;

    char playAgain = 'N';

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    while (!won) {
        clearScreen();
        do {
            if (doneOnce){
                clearScreen();
            }
            changeColor(1, saved_attributes, hConsole);
            printf(""
               "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n"
               "//////////////////////////////////////////////////\n");
            changeColor(2, saved_attributes, hConsole);
            printf(""
               "  _____ _        _____            _____          \n"
               " |_   _(_) ___  |_   _|_ _  ___  |_   _|__   ___ \n"
               "   | | | |/ __|   | |/ _` |/ __|   | |/ _ \\ / _ \\\n"
               "   | | | | (__    | | (_| | (__    | | (_) |  __/\n"
               "   |_| |_|\\___|   |_|\\__,_|\\___|   |_|\\___/ \\___|\n");
            changeColor(3, saved_attributes, hConsole);
            printf(""
               "//////////////////////////////////////////////////\n"
               "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n"
               "\n"
               );
            changeColor(7, saved_attributes, hConsole);

            printf
                (""
                 "   ||   ||   \n"
                 " %c || %c || %c \n"
                 "   ||   ||   \n"
                 "=============\n"
                 "   ||   ||   \n"
                 " %c || %c || %c \n"
                 "   ||   ||   \n"
                 "=============\n"
                 "   ||   ||   \n"
                 " %c || %c || %c \n"
                 "   ||   ||   \n",
                 cell1, cell2, cell3, cell4, cell5, cell6, cell7, cell8, cell9);

            if (doneOnce){
                printf("Occupied !\n");
            }
            askRow(&row, player, saved_attributes, hConsole);
            askColumn(&column, player, saved_attributes, hConsole);

            occupied = 0;
            occupied = (cell1Occupied && (row == 1 && column == 1)) ? 1 : occupied;
            occupied = (cell2Occupied && (row == 1 && column == 2)) ? 1 : occupied;
            occupied = (cell3Occupied && (row == 1 && column == 3)) ? 1 : occupied;
            occupied = (cell4Occupied && (row == 2 && column == 1)) ? 1 : occupied;
            occupied = (cell5Occupied && (row == 2 && column == 2)) ? 1 : occupied;
            occupied = (cell6Occupied && (row == 2 && column == 3)) ? 1 : occupied;
            occupied = (cell7Occupied && (row == 3 && column == 1)) ? 1 : occupied;
            occupied = (cell8Occupied && (row == 3 && column == 2)) ? 1 : occupied;
            occupied = (cell9Occupied && (row == 3 && column == 3)) ? 1 : occupied;
            doneOnce = 1;

        } while (occupied);
        doneOnce = 0;

        cell1Occupied = (row == 1 && column == 1) ? 1 : cell1Occupied;
        cell2Occupied = (row == 1 && column == 2) ? 1 : cell2Occupied;
        cell3Occupied = (row == 1 && column == 3) ? 1 : cell3Occupied;
        cell4Occupied = (row == 2 && column == 1) ? 1 : cell4Occupied;
        cell5Occupied = (row == 2 && column == 2) ? 1 : cell5Occupied;
        cell6Occupied = (row == 2 && column == 3) ? 1 : cell6Occupied;
        cell7Occupied = (row == 3 && column == 1) ? 1 : cell7Occupied;
        cell8Occupied = (row == 3 && column == 2) ? 1 : cell8Occupied;
        cell9Occupied = (row == 3 && column == 3) ? 1 : cell9Occupied;


        printf(""
               "=======================\n"
               "Row : %d || Column : %d\n"
               "=======================\n"
               , row, column);

        sign = (player == 0) ? 'X' : 'O';
        cell1 = (row == 1 && column == 1) ? sign : cell1;
        cell2 = (row == 1 && column == 2) ? sign : cell2;
        cell3 = (row == 1 && column == 3) ? sign : cell3;
        cell4 = (row == 2 && column == 1) ? sign : cell4;
        cell5 = (row == 2 && column == 2) ? sign : cell5;
        cell6 = (row == 2 && column == 3) ? sign : cell6;
        cell7 = (row == 3 && column == 1) ? sign : cell7;
        cell8 = (row == 3 && column == 2) ? sign : cell8;
        cell9 = (row == 3 && column == 3) ? sign : cell9;

        playsLast -= 1;

        if (    ((cell1 == cell2 && cell2 == cell3) && cell1 != ' ')||
                ((cell4 == cell5 && cell5 == cell6) && cell4 != ' ')||
                ((cell7 == cell8 && cell8 == cell9) && cell7 != ' ')||
                ((cell1 == cell5 && cell5 == cell9) && cell1 != ' ')||
                ((cell3 == cell5 && cell5 == cell7) && cell3 != ' ')||
                ((cell1 == cell4 && cell4 == cell7) && cell1 != ' ')||
                ((cell2 == cell5 && cell5 == cell8) && cell2 != ' ')||
                ((cell3 == cell6 && cell6 == cell9) && cell3 != ' ')
        ){
            won = 1;
        }
        else if (playsLast == 0){
            printf("No one wins !\n");
            won = 1;
        }
        player = !player;
    }
    player = !player;
    if ((cell1 == cell2 && cell2 == cell3) && cell1 != ' '){
        printf(""
               "   ||   ||   \n"
               "-%c-||-%c-||-%c-\n"
               "   ||   ||   \n"
               "=============\n"
               "   ||   ||   \n"
               " %c || %c || %c \n"
               "   ||   ||   \n"
               "=============\n"
               "   ||   ||   \n"
               " %c || %c || %c \n"
               "   ||   ||   \n",
               cell1, cell2, cell3, cell4, cell5, cell6, cell7, cell8, cell9);
    }

    if ((cell4 == cell5 && cell5 == cell6) && cell4 != ' '){
        printf(""
               "   ||   ||   \n"
               " %c || %c || %c \n"
               "   ||   ||   \n"
               "=============\n"
               "   ||   ||   \n"
               "-%c-||-%c-||-%c-\n"
               "   ||   ||   \n"
               "=============\n"
               "   ||   ||   \n"
               " %c || %c || %c \n"
               "   ||   ||   \n",
               cell1, cell2, cell3, cell4, cell5, cell6, cell7, cell8, cell9);
    }

    if ((cell7 == cell8 && cell8 == cell9) && cell7 != ' '){
        printf(""
               "   ||   ||   \n"
               " %c || %c || %c \n"
               "   ||   ||   \n"
               "=============\n"
               "   ||   ||   \n"
               " %c || %c || %c \n"
               "   ||   ||   \n"
               "=============\n"
               "   ||   ||   \n"
               "-%c-||-%c-||-%c-\n"
               "   ||   ||   \n",
               cell1, cell2, cell3, cell4, cell5, cell6, cell7, cell8, cell9);
    }

    if ((cell1 == cell5 && cell5 == cell9) && cell1 != ' '){
        printf(""
               "\\  ||   ||   \n"
               " %c || %c || %c \n"
               "  \\||   ||   \n"
               "=============\n"
               "   ||\\  ||   \n"
               " %c || %c || %c \n"
               "   ||  \\||   \n"
               "=============\n"
               "   ||   ||\\  \n"
               " %c || %c || %c \n"
               "   ||   ||  \\\n",
               cell1, cell2, cell3, cell4, cell5, cell6, cell7, cell8, cell9);
    }

    if ((cell3 == cell5 && cell5 == cell7) && cell3 != ' '){
        printf(""
               "   ||   ||  /\n"
               " %c || %c || %c \n"
               "   ||   ||/  \n"
               "=============\n"
               "   ||  /||   \n"
               " %c || %c || %c \n"
               "   ||/  ||   \n"
               "=============\n"
               "  /||   ||   \n"
               " %c || %c || %c \n"
               "/  ||   ||   \n",
               cell1, cell2, cell3, cell4, cell5, cell6, cell7, cell8, cell9);
    }

    if ((cell1 == cell4 && cell4 == cell7) && cell1 != ' '){
        printf(""
               " | ||   ||   \n"
               " %c || %c || %c \n"
               " | ||   ||   \n"
               "=============\n"
               " | ||   ||   \n"
               " %c || %c || %c \n"
               " | ||   ||   \n"
               "=============\n"
               " | ||   ||   \n"
               " %c || %c || %c \n"
               " | ||   ||   \n",
               cell1, cell2, cell3, cell4, cell5, cell6, cell7, cell8, cell9);
    }

    if ((cell2 == cell5 && cell5 == cell8) && cell2 != ' '){
        printf(""
               "   || | ||   \n"
               " %c || %c || %c \n"
               "   || | ||   \n"
               "=============\n"
               "   || | ||   \n"
               " %c || %c || %c \n"
               "   || | ||   \n"
               "=============\n"
               "   || | ||   \n"
               " %c || %c || %c \n"
               "   || | ||   \n",
               cell1, cell2, cell3, cell4, cell5, cell6, cell7, cell8, cell9);
    }

    if ((cell3 == cell6 && cell6 == cell9) && cell3 != ' '){
        printf(""
               "   ||   || | \n"
               " %c || %c || %c \n"
               "   ||   || | \n"
               "=============\n"
               "   ||   || | \n"
               " %c || %c || %c \n"
               "   ||   || | \n"
               "=============\n"
               "   ||   || | \n"
               " %c || %c || %c \n"
               "   ||   || | \n",
               cell1, cell2, cell3, cell4, cell5, cell6, cell7, cell8, cell9);
    }

    if (++player == 1){
        changeColor(1, saved_attributes, hConsole);
        printf(""
               "  ____  _                                                                  _ \n"
               " |  _ \\| | __ _ _   _  ___ _ __    ___  _ __   ___  __      _____  _ __   | |\n"
               " | |_) | |/ _` | | | |/ _ \\ '__|  / _ \\| '_ \\ / _ \\ \\ \\ /\\ / / _ \\| '_ \\  | |\n"
               " |  __/| | (_| | |_| |  __/ |    | (_) | | | |  __/  \\ V  V / (_) | | | | |_|\n"
               " |_|   |_|\\__,_|\\__, |\\___|_|     \\___/|_| |_|\\___|   \\_/\\_/ \\___/|_| |_| (_)\n"
               "                |___/                                                        \n");
    }
    else{
        changeColor(3, saved_attributes, hConsole);
        printf(""
               "  ____  _                         _                                         _ \n"
               " |  _ \\| | __ _ _   _  ___ _ __  | |___      _____   __      _____  _ __   | |\n"
               " | |_) | |/ _` | | | |/ _ \\ '__| | __\\ \\\\/\\ / / _ \\  \\ \\ /\\ / / _ \\| '_ \\  | |\n"
               " |  __/| | (_| | |_| |  __/ |    | |_ \\ V  V / (_) |  \\ V  V / (_) | | | | |_|\n"
               " |_|   |_|\\__,_|\\__, |\\___|_|     \\__| \\_/\\_/ \\___/    \\_/\\_/ \\___/|_| |_| (_)\n"
               "                |___/                                                         \n");
    }
    changeColor(7, saved_attributes, hConsole);
    printf("Play again ? Y/N \n>>>");
    scanf("%c", &playAgain);

    if (playAgain == 'Y' || playAgain == 'y'){
        main();
    }
    else {
        printf("Thanks for playing !\nby TheFoxan12");
        sleep(1);
        return 0;
    }
}

void askColumn(int *column, int player, WORD saved_attributes, HANDLE hConsole){
    int color = (player != 1) ? 1 : 3;
    changeColor(color, saved_attributes, hConsole);
    do {
        printf("Which column ? >>>", player + 1);
        scanf("%d", column);
        cleanBuffer();
    } while (*column > 3 || *column < 1);
    changeColor(7, saved_attributes, hConsole);
}

void askRow(int *row, int player, WORD saved_attributes, HANDLE hConsole){
    int color = (player != 1) ? 1 : 3;
    changeColor(color, saved_attributes, hConsole);
    do {
        printf("Player %d's turn :\nWhich row ? >>>", player + 1);
        scanf("%d", row);
        cleanBuffer();
    } while (*row > 3 || *row < 1);
    changeColor(7, saved_attributes, hConsole);
}

void clearScreen(){
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
          "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
          "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void changeColor(int colorNumber, WORD saved_attributes, HANDLE hConsole){
    /*
     * Colors :
     *      1: RED
     *      2: BLUE
     *      3: GREEN
     *      4:
     *      5:
     *      6:
     *      7: reset
    */

    switch (colorNumber) {
        case 1:
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            break;
        case 2:
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            break;
        case 3:
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            break;
        case 4:
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED || FOREGROUND_BLUE);
            break;
        case 5:
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN);
            break;
        case 6:
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            break;
        case 7:
            SetConsoleTextAttribute(hConsole, saved_attributes);
            break;

    }

}



// 400 lines !