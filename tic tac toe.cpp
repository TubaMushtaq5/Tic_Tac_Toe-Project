#include <stdio.h>

#define EMPTYCELL ' '
void initialize(char b[][3]){
int i,j;
for (i=0;i<3;i++){
for (j=0;j<3;j++)
b[i][j]=EMPTYCELL;
}
}

void printBoard (char b[][3]){
	int i,j;
    for (i=0;i<3;i++){
    for (j=0;j<3;j++){
     printf("%c   ",b[i][j]);
     if (j<2)
     printf(" |");
 }
printf("\n____   ____  ____\n\n");
}
}

int checkFirstDiagonal(char b[][3], char c){
	if (b[0][0] == c && b[1][1] == c && b[2][2] == c)
	return 1;
	else 
	return 0;
}

int checkSecondDiagonal(char b[][3], char c){
	if (b[2][0] == c && b[1][1] == c && b[0][2] == c)
	return 1;
	else 
	return 0;
}

int checkFirstRow(char b[][3], char c){
	if (b[0][0] == c && b[0][1] == c && b[0][2] == c)
	return 1;
	else 
	return 0;
}

int checkSecondRow(char b[][3], char c){
	if (b[1][0] == c && b[1][1] == c && b[1][2] == c)
	return 1;
	else 
	return 0;
}

int checkThirdRow(char b[][3], char c){
	if (b[2][0] == c && b[2][1] == c && b[2][2] == c)
	return 1;
	else 
	return 0;
}

int checkFirstColumn(char b[][3], char c){
	if (b[0][0] == c && b[1][0] == c && b[2][0] == c)
	return 1;
	else 
	return 0;
}

int checkSecondColumn(char b[][3], char c){
	if (b[1][0] == c && b[1][1] == c && b[1][2] == c)
	return 1;
	else 
	return 0;
}


int checkThirdColumn(char b[][3], char c){
	if (b[2][0] == c && b[2][1] == c && b[2][2] == c)
	return 1;
	else 
	return 0;
}

int checkwin(char b[][3] , char c){
	if (checkFirstDiagonal(b , c) == 1) return 1;
	else if (checkSecondDiagonal(b , c) == 1) return 1;
	else if (checkFirstRow(b , c) == 1) return 1;
	else if (checkSecondRow(b , c) == 1) return 1;
	else if (checkThirdRow(b , c) == 1) return 1;
	else if (checkFirstColumn(b , c) == 1) return 1;
	else if (checkSecondColumn(b , c) == 1) return 1;
	else if (checkThirdColumn(b , c) == 1) return 1;
	return 0;
}

void turns(char b[][3]){
	int i , cellno , rows , columns;
	char player = 'x' ;
	for (i = 0 ; i < 9 ; i ++){
		printf("Enter cell no:") ;
		scanf("%d",&cellno) ;
		cellno --;
		rows = cellno / 3;
	    columns = cellno % 3;
	    b[rows][columns] = player ;
	    printBoard(b) ;
	    checkwin(b , player) ;
	    if (checkwin (b , player ) == 1){
	    	printf("Congratulations! player %c wins",player) ;
	    	break;
		}
	    if (player == 'x') player = '0' ;
	    else player = 'x' ;
	    
	}
}
int main(){
	int i;
	char board[3][3] , turnA = 'x' ,turnB = '0',row , col;
    initialize(board);
    printBoard(board);
    turns(board) ;
	return 0;
}
