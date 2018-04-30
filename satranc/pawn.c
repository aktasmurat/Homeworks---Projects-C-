#include <stdio.h>
#include "satranc.h"


/*Piyon Fonksiyonu*/
int isPawnMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow) {
    int resultSource, resultTarget, result;
    /*Konumun ve hedefin dizideki yerlerini bulup farklarını hesaplama */
    resultSource = ((8 - sourceRow)*8 + (sourceCol - 'a'));
    resultTarget = ((8 - targetRow)*8 + (targetCol - 'a'));
    result = resultSource - resultTarget;

    /*1 satır yukarida ise ve bos ise devam etme durumu */
    if (board[resultSource] == 'P' && result == 8 && board[resultTarget] == ' ')
        return 1;
    /*1 sutun yukarida ise ve bos ise devam etme durumu */
    if (board[resultSource] == 'p' && result == -8 && board[resultTarget] == ' ')
        return 1;
    /*Tasmama kontrolu-Sol*/
    if (((resultSource % 8) != 0 || (resultSource % 8 != 1)) &&
            board[resultSource] == 'P' &&
            (result == 9 || result == 7) && board[resultTarget] >= 'a')
        return 1;
    /*Tasmama kontrolu-Sol*/
    if (((resultSource % 8) != 0 || (resultSource % 8 != 1)) &&
            board[resultSource] == 'p' &&
            (result == -9 || result == -7) &&board[resultTarget] < 'a')
        return 1;
    /*Carprazda tas var ise yeme durumu*/
    if (board[resultSource] == 'P' &&
            resultSource % 8 == 0 &&
            result == 7 && board[resultTarget] >= 'a')
        return 1;
    /*Tasmama kontrolu - sag*/
    if (board[resultSource] == 'P' &&
            resultSource % 8 == 1 &&
            result == 9 && board[resultTarget] >= 'a' )
        return 1;
    /*Carprazda tas var ise yeme durumu*/
    if (board[resultSource] == 'p' &&
            resultSource % 8 == 0 &&
            result == -9 && board[resultTarget] < 'a')
        return 1;
    /*Tasmama kontrolu-sag*/
    if (board[resultSource] == 'p' &&
            resultSource % 8 == 1 &&
            result == -7 && board[resultTarget] < 'a')
        return 1;

    return 0;
}