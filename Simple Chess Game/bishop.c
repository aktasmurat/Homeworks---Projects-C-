#include <stdio.h>
#include <stdlib.h>

#include "satranc.h"


/*Fil Fonksiyonu*/
int isBishopMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow) {
    int i, result, counter, resultTarget, resultSource;
    counter = 0;
    
    /*indekslerin bulunmasi */
    resultSource = ((8 - sourceRow)*8 + (sourceCol - 'a'));
    resultTarget = ((8 - targetRow)*8 + (targetCol - 'a'));
    result = resultSource - resultTarget;
    result = abs(result);

    /*Hedef nokta indiksi kucukse bosluklari kontrol etme durumu-sagüst*/
    if (resultSource > resultTarget && result % 7 == 0 && (resultTarget % 8) != 0) {
        for (i = resultSource - 7; i > resultTarget; i -= 7) {
            if (board[i] != ' ')
                counter++;
        }
    }
    /*Hedef nokta indiksi kucukse bosluklari kontrol etme durumu-solalt*/
    if (resultSource < resultTarget && result % 7 == 0 && (resultTarget % 8) != 7) {
        for (i = resultSource + 7; i > resultTarget; i += 7) {
            if (board[i] != ' ')
                counter++;
        }
    }
    /*Hedef nokta indiksi kucukse bosluklari kontrol etme durumu-sagalt*/
    if (resultSource < resultTarget && result % 9 == 0 && (resultTarget % 8) != 0) {
        for (i = resultSource + 9; i > resultTarget; i += 9) {
            if (board[i] != ' ')
                counter++;
        }
    }
    /*Hedef nokta indiksi kucukse bosluklari kontrol etme durumu-solüst*/
    if (resultSource > resultTarget && result % 9 == 0 && (resultTarget % 8) != 7) {
        for (i = resultSource - 9; i > resultTarget; i -= 9) {
            if (board[i] != ' ')
                counter++;

        }
    }
  
    /*Carpraz olmama durumu */
     if(abs(sourceCol-targetCol)!=abs(sourceRow-targetRow)) 
            return 0;
    
    
    /*Gerekli durumlarda rakip tas yeme kontrolu*/
    if ((board[resultSource] == 'b' || board[resultSource] == 'q') &&
            counter == 0 && (board[resultTarget] < 'a' || board[resultTarget] == ' '))
        return 1;
     /*Gerekli durumlarda rakip tas yeme kontrolu*/
    if ((board[resultSource] == 'B' || board[resultSource] == 'Q') &&
            counter == 0 && (board[resultTarget] >= 'a' || board[resultTarget] == ' '))
        return 1;

    else
        return 0;
}
