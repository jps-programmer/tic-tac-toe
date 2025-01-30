#include <stdio.h>
char board[3][3] = {{'1','2','3'},
                    {'4','5','6'},
                    {'7','8','9'}};
int player = 1;
int noMoves = 0;

int checkForWin() {
    int check = 0;

    if (board[0][0] == 'x' && board[0][1] == 'x' && board[0][2] == 'x') {
        check = 1;
    } else if (board[0][0] == 'o' && board[0][1] == 'o' && board[0][2] == 'o') {
        check = 2;
    }

    if (board[1][0] == 'x' && board[1][1] == 'x' && board[1][2] == 'x') {
        check = 1;
    } else if (board[1][0] == 'o' && board[1][1] == 'o' && board[1][2] == 'o') {
        check = 2;
    }

    if (board[2][0] == 'x' && board[2][1] == 'x' && board[2][2] == 'x') {
        check = 1;
    } else if (board[2][0] == 'o' && board[2][1] == 'o' && board[2][2] == 'o') {
        check = 2;
    }

    if (board[0][0] == 'x' && board[1][0] == 'x' && board[2][0] == 'x') {
        check = 1;
    } else if (board[0][0] == 'o' && board[1][0] == 'o' && board[2][0] == 'o') {
        check = 2;
    }

    if (board[0][1] == 'x' && board[1][1] == 'x' && board[2][1] == 'x') {
        check = 1;
    } else if (board[0][1] == 'o' && board[1][1] == 'o' && board[2][1] == 'o') {
        check = 2;
    }

    if (board[0][2] == 'x' && board[1][2] == 'x' && board[2][2] == 'x') {
        check = 1;
    } else if (board[0][2] == 'o' && board[1][2] == 'o' && board[2][2] == 'o') {
        check = 2;
    }

    if (board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x') {
        check = 1;
    } else if (board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == 'o') {
        check = 2;
    }

    if (board[2][0] == 'x' && board[1][1] == 'x' && board[0][2] == 'x') {
        check = 1;
    } else if (board[2][0] == 'o' && board[1][1] == 'o' && board[0][2] == 'o') {
        check = 2;
    }

    return check;
}

void drawBoard() {

    printf("\t\t|\t\t|\n");
    printf("\t%c\t|\t%c\t|\t%c\n",board[0][0],board[0][1],board[0][2]);
    printf("________________|_______________|________________\n");
    printf("\t\t|\t\t|\n");
    printf("\t%c\t|\t%c\t|\t%c\n",board[1][0],board[1][1],board[1][2]);
    printf("________________|_______________|________________\n");
    printf("\t\t|\t\t|\n");
    printf("\t%c\t|\t%c\t|\t%c\n",board[2][0],board[2][1],board[2][2]);
    printf("\t\t|\t\t|\n");

}

void markBoard(int entry) {

    if (entry < 0 || entry > 9) {
        return;
    }

    switch (entry) {

    case 1:
        if (player == 1) {
            board[0][0] = 'x';
        } else {
            board[0][0] = 'o';
        }

        noMoves += 1;
        break;

    case 2:
        if (player == 1) {
            board[0][1] = 'x';
        } else {
            board[0][1] = 'o';
        }

        noMoves += 1;
        break;

    case 3:
        if (player == 1) {
            board[0][2] = 'x';
        } else {
            board[0][2] = 'o';
        }

        noMoves += 1;
        break;

    case 4:
        if (player == 1) {
            board[1][0] = 'x';
        } else {
            board[1][0] = 'o';
        }

        noMoves += 1;
        break;

    case 5:
        if (player == 1) {
            board[1][1] = 'x';
        } else {
            board[1][1] = 'o';
        }

        noMoves += 1;
        break;

    case 6:
        if (player == 1) {
            board[1][2] = 'x';
        } else {
            board[1][2] = 'o';
        }

        noMoves += 1;
        break;

    case 7:
        if (player == 1) {
            board[2][0] = 'x';
        } else {
            board[2][0] = 'o';
        }

        noMoves += 1;
        break;

    case 8:
        if (player == 1) {
            board[2][1] = 'x';
        } else {
            board[2][1] = 'o';
        }

        noMoves += 1;
        break;

    case 9:
        if (player == 1) {
            board[2][2] = 'x';
        } else {
            board[2][2] = 'o';
        }

        noMoves += 1;
        break;

    default:
        break;
    }

}

int main() {
    int pick = 0;
    int win = 0;

    printf("\n\tTic Tac Toe\n");
    printf("Player 1 (x) - Player 2 (o)\n");

    while (win == 0 && noMoves != 9) {
        drawBoard();
        printf("Player %d, enter a number: ",player);
        scanf("%d",&pick);

        markBoard(pick);
        win = checkForWin();

        if (player == 1) {
            player = 2;
        } else {
            player = 1;
        }
    }

    drawBoard();

    if (win == 1) {
        printf("\nPlayer 1 wins!");
    } else if (win == 2) {
        printf("\nPlayer 2 wins!");
    } else {
        printf("\nIt's a draw!");
    }

    return 0;
}
