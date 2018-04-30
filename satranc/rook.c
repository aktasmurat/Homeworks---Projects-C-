#include <stdio.h>
#include <stdlib.h>

#include "satranc.h"

/*Kale fonksiyonu */
int isRookMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow) {
    int resultSource, resultTarget, result, counter, i;
    counter = 0;

    /*Konumun ve hedefin dizideki yerlerini bulup farklarını hesaplama */
    resultSource = ((8 - sourceRow)*8 + (sourceCol - 'a'));
    resultTarget = ((8 - targetRow)*8 + (targetCol - 'a'));
    result = resultSource - resultTarget;
    result = abs(result);

    /*Taslar ayni satır veya sutunda degilse 0 dondurme*/
    if (sourceCol != targetCol && sourceRow != targetRow)
        return 0;
    
    /*ayni sutunda ise */
    if (sourceCol == targetCol) {
        /*Hedef daha buyuk indekste ise ve aralarında bosluk varsa kontrolu*/
        if (resultTarget > resultSource && resultTarget - resultSource != 8) {
            for (i = resultSource + 8; i < resultTarget; i += 8) {
                if (board[i] != ' ')
                    counter += 1;
            }
        }/*Hedef kucuk indekste ise ve aralında bosluk varsa kontrol */
        if (resultSource > resultTarget && resultSource - resultTarget != 8) {
            for (i = resultSource - 8; i > resultTarget; i -= 8) {
                if (board[i] != ' ')
                    counter += 1;
            }
        }
        /*Rakip tası yeme durumu ve gidecegi yerle arasinda bosluk olma durumu*/
        if ((board[resultSource] == 'r' || board[resultSource] == 'q') && counter == 0 &&
                (board[resultTarget] < 'a' || board[resultTarget] == ' '))
            return 1;

        else if ((board[resultSource] == 'R' || board[resultSource] == 'Q') && counter == 0 &&
                (board[resultTarget] >= 'a' || board[resultTarget] == ' '))
            return 1;

        else
            return 0;
    }
        /*Aynı satirda ise */
     else if (sourceRow == targetRow) {
       /*Hedef buyuk indekste ve aralarinda bosluk olma durumu*/
        if (resultTarget > resultSource && resultTarget - resultSource != 1) {
            for (i = resultSource; i < resultTarget; i++) {
                if (board[i] != ' ')
                    counter += 1;
            }
      /*Hedef kucuk indekste ve aralarinda bosluk olma durumu*/
        } else if (resultSource > resultTarget && resultSource - resultTarget != 1) {
            for (i = resultTarget; i < resultSource; i++) {
                if (board[i] != ' ')
                    counter += 1;
            }
        }
        /*Rakip tasi yeme ve aralarında tas olmama durumu*/
        if ((board[resultSource] == 'r' || board[resultSource] == 'q') && counter == 0 &&
                (board[resultTarget] < 'a' || board[resultTarget] == ' '))
            return 1;
         /*Rakip tasi yeme ve aralarında tas olmama durumu*/
        else if ((board[resultSource] == 'R' || board[resultSource] == 'Q') && counter == 0 &&
                (board[resultTarget] >= 'a' || board[resultTarget] == ' '))
            return 1;

        else
            return 0;
    } else
        return 0;

    return 0;
}