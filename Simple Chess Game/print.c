#include <stdio.h>
#include "satranc.h"

void printBoard(char *board) {
    int i, lcv, line;
    line =8;

    printf("  a b c d e f g h\n");
    printf("  - - - - - - - -\n");

    i = 0;
    printf("%d|", line);
    line -= 1;

    for (lcv = 0; lcv < 64; lcv += 8) {
        while (i != 7 && i != 15 && i != 23 && i != 31 && i != 39
                && i != 47 && i != 55 && i != 63) {
            printf("%c ", board[i]);
            i++;
        }
        printf("%c",board[(8-(line+1))*8+7]);
        printf("|\n");
        if (line != 0) {
            printf("%d|", line);
            
        }
        i++;
        line -= 1;
    }
    printf("  - - - - - - - -\n");
}