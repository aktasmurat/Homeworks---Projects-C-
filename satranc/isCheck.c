#include <stdio.h>
#include "satranc.h"

int isInCheck(char* board){
    int i,x=0,k;
    int tempWTr,tempBTr,tempWSr,tempBSr;
    char tempWTc,tempBTc,tempWSc,tempBSc;


    /*Beyaz Sahin yeri ---------*/
        for(i=0; i<64; i++){
            if(board[i]=='K')
            {
            tempWTc = 'h'-(i%8)+1;
            tempWTr = 8 - i/8;
            }
    }   
    /*--------------------------*/


    /*Siyah sahin yeri ----------*/
        for(k=0; k<64; k++){
            if(board[k]=='k')
            {
            tempBTc = 'h'-(k%8)+1;
            tempBTr = 8 - k/8;
            }
    }

    
    
    /*---------------------------*/


    /*Hedefte beyaz sah varsa -------------------*/
    for(i=0; i<64 ; i++){
            if(board[i]>='a'){
                tempBSc='a'+(i%8);
                tempBSr=8 - i/8 ;
            }

            if(board[i]=='n'){
               x=isKnightMovable(board, tempBSc, tempBSr, tempWTc, tempWTr);
               if(x==1)
                    return 1;
            }
            if(board[i]=='b'){
               x=isBishopMovable(board, tempBSc, tempBSr, tempWTc, tempWTr);
               if(x==1)
                    return 1;
            }
            if(board[i]=='p'){
               x=isPawnMovable(board, tempBSc, tempBSr, tempWTc, tempWTr);
               if(x==1)
                    return 1;
            }
            if(board[i]=='q'){
               x=isQueenMovable(board, tempBSc, tempBSr, tempWTc, tempWTr);
               if(x==1)
                    return 1;
            }
            if(board[i]=='r'){
               x=isRookMovable(board, tempBSc, tempBSr, tempWTc, tempWTr);
               if(x==1)
                    return 1;
            }
            if(board[i]=='k'){
               x=isKingMovable(board, tempBSc, tempBSr, tempWTc, tempWTr);
               if(x==1)
                    return 1;
            }            
        }
    /*-------------------------------------------*/




    /*Hedefte siyah sah var ise -------------------------------*/
    for(i=0; i<64; i++){
            if(board[i]<'a'){
                tempWSc='a'+(i%8);
                tempWSr=8 - i/8 ;
            }


            if(board[i]=='N'){
               x=isKnightMovable(board, tempWSc, tempWSr, tempBTc, tempBTr);
               if(x==1)
                    return 2;
            }
            if(board[i]=='B'){
               x=isBishopMovable(board, tempWSc, tempWSr, tempBTc, tempBTr);
               if(x==1)
                    return 2;
            }
            if(board[i]=='P'){
               x=isPawnMovable(board, tempWSc, tempWSr, tempBTc, tempBTr);
               if(x==1)
                    return 2;
            }
            if(board[i]=='Q'){
               x=isQueenMovable(board, tempWSc, tempWSr, tempBTc, tempBTr);
               if(x==1)
                    return 2;
            }
            if(board[i]=='R'){
               x=isRookMovable(board, tempWSc, tempWSr, tempBTc, tempBTr);
               if(x==1)
                    return 2;
            }
            if(board[i]=='K'){
               x=isKingMovable(board, tempWSc, tempWSr, tempBTc, tempBTr);
               if(x==1)
                    return 2;
            }            
        }
    /*---------------------------------------------------------*/


    if(x==0)
        return 0;

    return 0;

}