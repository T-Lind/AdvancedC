#include<stdio.h>
#include <stdlib.h>
#include "math.h"
#include "time.h"
#include "Boolean.h"

enum Agent {
    PLAYER, COMPUTER, NONE
};

struct Coordinate {
    int row, col;
};
typedef struct Coordinate Coord;
typedef enum Agent Agent;
typedef char INT_8;

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int min(int a, int b) {
    if (a < b)
        return a;
    return b;
}

void printTurn(Agent turn) {
    if (turn == PLAYER) { printf("It is your turn.\n"); }
    else { printf("It is the computer's turn\n"); }
}

void printBoard(char board[3][3]) {
    for (INT_8 r = 0; r < 3; r++) {
        for (INT_8 c = 0; c < 3; c++) {
            if (c == 0)
                printf("|");
            printf("%c|", board[r][c]);
        }
        printf("\n-------\n");
    }
    printf("\n");
}

int coordToNum(Coord loc) {
    return loc.row * 3 + loc.col + 1;
}

Coord numToCoord(INT_8 number) {
    Coord ret;
    ret.row = (number - 1) / 3;
    ret.col = (number - 1) % 3;
    return ret;
}

void moveOnBoard(char board[3][3], char player, char computer, Agent turn, int number) {
    Coord move = numToCoord(number);

    if (turn == COMPUTER)
        board[move.row][move.col] = computer;
    else
        board[move.row][move.col] = player;
}

bool movesLeft(char board[3][3]) {
    for (INT_8 r = 0; r < 3; r++) {
        for (INT_8 c = 0; c < 3; c++) {
            if (board[r][c] == ' ') {
                return true;
            }
        }
    }
    return false;
}

int evaluate(char board[3][3], char player, char opponent) {
    for (INT_8 r = 0; r < 3; r++) {
        if (board[r][0] == board[r][1] && board[r][1] == board[r][2]) {
            if (board[r][0] == player)
                return 10;
            else if (board[r][0] == opponent)
                return -10;
        }
    }

    for (int c = 0; c < 3; c++) {
        if (board[0][c] == board[1][c] && board[1][c] == board[2][c]) {
            if (board[0][c] == player)
                return 10;
            else if (board[0][c] == opponent)
                return -10;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == player)
            return 10;
        else if (board[0][0] == opponent)
            return -10;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == player)
            return 10;
        else if (board[0][2] == opponent)
            return -10;
    }

    return 0;
}

int maximizeFunc(char board[3][3], INT_8 depth, bool isMaximum, char player, char opponent) {
    int score = evaluate(board, player, opponent);

    if (score == 10)
        return score;
    if (score == -10)
        return score;

    if (isMaximum) {
        int best = INT_MIN;
        for (INT_8 r = 0; r < 3; r++) {
            for (INT_8 c = 0; c < 3; c++) {
                if (board[r][c] == ' ') {
                    board[r][c] = player;

                    best = max(best, maximizeFunc(board, depth + 1, !isMaximum, player, opponent));

                    board[r][c] = ' ';
                }
            }
        }
        return best;
    } else {
        int best = INT_MAX;
        for (INT_8 r = 0; r < 3; r++) {
            for (INT_8 c = 0; c < 3; c++) {
                if (board[r][c] == ' ') {
                    board[r][c] = opponent;

                    best = min(best, maximizeFunc(board, depth + 1, !isMaximum, player, opponent));

                    board[r][c] = ' ';
                }
            }
        }
        return best;
    }
}

bool isOpen(char board[3][3], Coord loc) {
    if (board[loc.row][loc.col] == ' ')
        return true;
    return false;
}

int computerMove(char board[3][3], char player, char computer) {
    int bestVal = INT_MIN;
    Coord bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    for (INT_8 r = 0; r < 3; r++) {
        for (INT_8 c = 0; c < 3; c++) {
            if (board[r][c] == ' ') {
                board[r][c] = player;

                int moveValue = maximizeFunc(board, 0, false, player, computer);

                board[r][c] = ' ';

                if (moveValue > bestVal) {
                    bestMove.row = r;
                    bestMove.col = c;
                    bestVal = moveValue;
                }
            }
        }
    }
    if (rand() % 4 > 1) {
        return coordToNum(bestMove);
    }
    INT_8 randNum = rand() % 10;
    while (!isOpen(board, numToCoord(randNum)))
        randNum = rand() % 10;
    return randNum;
}

bool isWon(char board[3][3], char player) {
    // Check verticals
    for (INT_8 r = 0; r < 3; r++) {
        INT_8 count = 0;
        for (INT_8 c = 0; c < 3; c++) {
            if(board[r][c] == player)
                count++;
        }
        if(count == 3)
            return true;
    }

    // Check horizontals
    for (INT_8 c = 0; c < 3; c++) {
        INT_8 count = 0;
        for (INT_8 r = 0; r < 3; r++) {
            if(board[r][c] == player)
                count++;
        }
        if(count == 3)
            return true;
    }

    // Check diagonals
    char diagCount1 = 0;
    for(INT_8 i=0;i<3;i++){
        if(board[i][i] == player)
            diagCount1++;
    }
    if(diagCount1 == 3){
        return true;
    }

    INT_8 diagCount2 = 0;
    for(INT_8 i=0;i<3;i++){
        if(board[i][2-i] == player)
            diagCount2++;
    }
    if(diagCount2 == 3){
        return true;
    }
    return false;
}




void playTictactoe() {
    printf("TIC-TAC-TOE SOLVER:\n");
    srand(time(0));

    char board[3][3] = {{' ', ' ', ' '},
                        {' ', ' ', ' '},
                        {' ', ' ', ' '}};


    bool isComputerTurn = round(rand() % 2);
    Agent turn;
    if (isComputerTurn)
        turn = COMPUTER;
    else
        turn = PLAYER;

    char player, computer;
    if (isComputerTurn) {
        computer = 'X';
        player = 'O';
    } else {
        computer = 'O';
        player = 'X';
    }

    while (movesLeft(board)) {
        printTurn(turn);
        printBoard(board);

        if(isWon(board, player)){
            printf("Congrats! You have won!\n");
            break;
        }
        if(isWon(board, computer)){
            printf("Sorry! You have lost!\n");
            break;
        }

        // Player's isComputerTurn
        if (turn == PLAYER) {
            printf("Enter your move 1-9, 1=top left, 9=bottom right: ");
            INT_8 move;
            scanf("%hd", &move);
            if (isOpen(board, numToCoord(move)))
                moveOnBoard(board, player, computer, turn, move);
            else {
                printf("%d is a full square. Please choose an open square!\n", move);
                continue;
            }
            printf("\n");
        }

        // Computer's turn
        if (turn == COMPUTER) {
            moveOnBoard(board, player, computer, turn, computerMove(board, player, computer));
        }

        // Switch turns
        if (turn == COMPUTER)
            turn = PLAYER;
        else
            turn = COMPUTER;
    }

    if(!isWon(board, player) && !isWon(board, player)){
        printf("Ended in a draw! At least you didn't lose!\n");
    }
}
