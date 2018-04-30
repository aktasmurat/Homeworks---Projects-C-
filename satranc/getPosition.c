#include <stdio.h>
#include "satranc.h"

/*Pozisyon bilgilerinin alinmasi */
void getPosition(char *col, int *row) {
    scanf(" %c", col);
    scanf("%d", row);
}
/*Girilen pozisyonun tahtada olup olmama kontrolu*/
int isValidCell(char col, int row) {
    if (row <= 0 || row >= 9)
        return 0;

    if (col != 'a' && col != 'b' && col != 'c' && col != 'd' && col != 'e' && col != 'f'
            && col != 'g' && col != 'h')
        return 0;

    else
        return 1;
}

/*Tahtayi tanimlama                 */
void initBoard(char *board) {
    int i;
    board[0] = 'r';
    board[7] = 'r';
    board[1] = 'n';
    board[6] = 'n';
    board[2] = 'b';
    board[5] = 'b';
    board[3] = 'q';
    board[4] = 'k';
    for (i = 8; i <= 15; i++)
        board[i] = 'p';
    for (i = 16; i <= 47; i++)
        board[i] = ' ';
    for (i = 48; i <= 55; i++)
        board[i] = 'P';
    board[56] = 'R';
    board[63] = 'R';
    board[57] = 'N';
    board[62] = 'N';
    board[58] = 'B';
    board[61] = 'B';
    board[59] = 'Q';
    board[60] = 'K';
 
}