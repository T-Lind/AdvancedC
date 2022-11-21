#include<stdio.h>
#include <stdlib.h>
#include "math.h"
#include "time.h"

struct boolean {
    unsigned b0: 1;
};
typedef struct boolean bool;

void printTurn(bool turn) {
    if (turn.b0 == 0) { printf("It is your turn.\n"); }
    else { printf("It is the computer's turn\n"); }
}

void printBoard(char board[3][3]) {
    for (short r = 0; r < 3; r++) {
        for (short c = 0; c < 3; c++) {
            if (c == 0)
                printf("|");
            printf("%c|", board[r][c]);
        }
        printf("\n-------\n");
    }
    printf("\n");
}

void moveOnBoard(char board[3][3], bool turn, bool first, int number) {
    int row = number / 3;
    int column = (number - 1) % 3;

    if(turn.b0 == 0){
        if(first.b0 == 0)
            board[row][column] = 'X';
        else
            board[row][column] = 'O';
    }
    else {
        if(first.b0 == 0)
            board[row][column] = 'O';
        else
            board[row][column] = 'X';
    }
}

void playTictactoe() {
    srand(time(0));

    char board[3][3] = {{' ', ' ', ' '},
                        {' ', ' ', ' '},
                        {' ', ' ', ' '}};

    bool inGame = {1};

    bool turn = {round(rand() % 2)};
    bool first = turn;

    while (inGame.b0 == 1) {
        printTurn(turn);
        printBoard(board);

        // Player's turn
        if (turn.b0 == 0) {
            printf("Enter your move 1-9, 1=top left, 9=bottom right: ");
            short move;
            scanf("%hd", &move);
            moveOnBoard(board, turn, first, move);
            printf("\n");


        }

        // Switch turns
        turn.b0 = abs(turn.b0 - 1);
    }

}