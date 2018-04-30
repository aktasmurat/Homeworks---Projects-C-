
extern void getPosition(char *col, int *row);

extern int isValidCell(char col, int row);

extern void printBoard(char *board);

extern void initBoard(char *board);


extern int isKnightMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);

extern int isRookMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);

extern int isBishopMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);

extern int isQueenMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);

extern int isKingMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);

extern int isPawnMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);


extern int isPieceMovable(char *board, char sc, int sr, char tc, int tr);

extern int isInCheck(char* board);

extern int makeMove(char *board, char sc, int sr, char tc, int tr);


extern char getPlayer(char *board, char sc, int sr);

extern int isBlack(char currPlayer);

extern int isWhite(char currPlayer);
