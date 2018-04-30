#include <stdio.h>
#include <stdlib.h>
#include "satranc.h"


/*Kral Fonksiyon */
int isKingMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow) {
    int result, resultTarget, resultSource;

    /*indekslerin bulunmasi */
    resultSource = ((8 - sourceRow)*8 + (sourceCol - 'a'));
    resultTarget = ((8 - targetRow)*8 + (targetCol - 'a'));
    result = resultSource - resultTarget;
    result = abs(result);


    
    /*Tasma durumu kontrolu*/
    if (sourceCol - targetCol > 1 || targetCol - sourceCol > 1)
        return 0;

    /*Gerekli durumlarda hedefte rakip veya bos ise gidebilme durumu*/
    if ((result == 1 || result == 7 || result == 8 || result == 9) &&
            board[resultSource] == 'K' && (board[resultTarget] >= 'a' || board[resultTarget] == ' '))
        return 1;

    /*Gerekli durumlarda hedefte rakip veya bos ise gidebilme durumu*/
    if ((result == 1 || result == 7 || result == 8 || result == 9) &&
            board[resultSource] == 'k' && (board[resultTarget] < 'a' || board[resultTarget] == ' '))
        return 1;
           
    return 0;
}
