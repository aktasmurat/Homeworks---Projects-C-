#include <stdio.h>
#include "satranc.h"

char getPlayer(char *board, char sc, int sr){

    int result;
    
    result = ((8 - sr)*8 + (sc - 'a'));

   return board[result];

}

int isBlack(char currPlayer){

    if(currPlayer >= 'a')
        return 1;
    else 
        return 0;
}

int isWhite(char currPlayer){

    if(currPlayer >= 'a')
        return 0;
    else 
        return 1;
}