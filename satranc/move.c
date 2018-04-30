#include <stdio.h>
#include "satranc.h"

int makeMove(char *board, char sc, int sr, char tc, int tr){
    
    int resultS,resultT,x;
    char tempResultS,tempResultT;

    x=1;
        resultS=((8 - sr)*8 + (sc - 'a'));           
        resultT=((8 - tr)*8 + (tc - 'a'));
        tempResultS=board[resultS];
        tempResultT=board[resultT];


    /*INVALID DURUMLARDA TASIN YERINI DEGISTIRMEME */
    if(isPieceMovable(board, sc, sr, tc,tr)==0 && isInCheck(board) == 0){
        
        return 0;
    }
    /*----------------------------------------------*/

    else{
        if (isPieceMovable(board, sc, sr, tc,tr)==0)
            return 0;
        else{
                /*TASIN YERINI GUNCELLEME -----*/
                 board[resultT]=board[resultS];
                 board[resultS]=' ';
                /*------------------------------*/

                    if(tempResultS>='a'){
                       x=isInCheck(board);
                        if(x==2){              
                            board[resultS]=board[resultT];
                            board[resultT]=tempResultT ;
                            return 1;
                        }

                        if(x==1){                   
                            return 3;
                        }
                    }

                     if(tempResultS<'a'){
                       x=isInCheck(board);
                        if(x==1){
                             
                            board[resultS]=board[resultT];
                             board[resultT]=tempResultT;
                            return 1;
                        }

                        
                        if(x==2) {
                            return 3;
                        }
                        
                    }

                    x=isInCheck(board);   
                        if(x==0){
                            return 2;
                        }
                }
         
        }
return 0;

}