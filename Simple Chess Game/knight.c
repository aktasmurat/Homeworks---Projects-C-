#include "satranc.h"
#include <math.h>
#include <stdlib.h>


/*At fonksiyonu */
int isKnightMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow) {
    int resultSource, resultTarget, result;
    /*indekslerin bulunmasi */
    resultSource = ((8 - sourceRow)*8 + (sourceCol - 'a'));
    resultTarget = ((8 - targetRow)*8 + (targetCol - 'a'));
    result = resultSource - resultTarget;
    result = abs(result);
    
    /*tasma durumu kontrolu */
    if (sourceCol - targetCol > 2 || targetCol - sourceCol > 2)
        return 0;
        
    /*durum kontrolu */
    if ((result == 6 || result == 10 || result == 15 || result == 17)&&
            (board[resultSource] == 'N' && (board[resultTarget] >= 'a' || board[resultTarget] == ' ')))
        return 1;
    if ((result == 6 || result == 10 || result == 15 || result == 17)&&
            (board[resultSource] == 'n' && (board[resultTarget] < 'a' || board[resultTarget] == ' ')))
        return 1;

    return 0;
}