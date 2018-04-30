#include <stdio.h>
#include "satranc.h"

/*Vezir Fonksiyon-Fil veya kaleden 1 döner ise return 1 yoksa return 0 */
int isQueenMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow) {
    int x, y;
    x = isBishopMovable(board, sourceCol, sourceRow, targetCol, targetRow);
    y = isRookMovable(board, sourceCol, sourceRow, targetCol, targetRow);
    
    if (x == 1 || y == 1)
        return 1;
    else
        return 0;
}