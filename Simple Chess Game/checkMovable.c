#include <stdio.h>
#include "satranc.h"


/*Hareket edip edememe kontrolu*/
int isPieceMovable(char *board, char sc, int sr, char tc, int tr) {
    int result,x;
    x=1;

    if (isValidCell(sc, sr) == 0 || isValidCell(tc, tr) == 0)
        return 0;

        /*Dizideki indeks ini bulma */
        result = ((8 - sr)*8 + (sc - 'a'));
       
        /*Dizideki indeksine gore hangi fonksiyonu cagiracagi */
        switch (board[result]) {
            case 'r':
            case 'R':
                x = isRookMovable(board, sc, sr, tc, tr);
                break;
            case 'n':
            case 'N':
                x = isKnightMovable(board, sc, sr, tc, tr);
                break;
            case 'b':
            case 'B':
                x = isBishopMovable(board, sc, sr, tc, tr);
                break;
            case 'q':
            case 'Q':
                x = isQueenMovable(board, sc, sr, tc, tr);
                break;
            case 'k':
            case 'K':
                x = isKingMovable(board, sc, sr, tc, tr);
                break;
            case 'p':
            case 'P':
                x = isPawnMovable(board, sc, sr, tc, tr);
                break;
        }
    
    return x;
}