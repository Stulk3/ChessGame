#include <stdio.h>
#include "deck.h"


deck::deck(){

    int i;
    d[64] = 1;
    
    //free
	for (i = 16; i < 56; i++){
		d[i] =0;
	}
	
	// pawns
	for (i=8 ;i<16; i++){
		d[i]=1;
	}
	for (i=48 ;i<56; i++){
		d[i]=-1;
	}
	
	// bishop
	d[0]=4; d[7]=4; d[56]=-4; d[63]=-4;
	
    // Knight
	d[1]=2; d[6]=2; d[62]=-2; d[57]=-2;
	
    // rook
	d[2]=3; d[5]=3; d[58]=-3;  d[61]=-3;
	
    // King
	d[3]=5; d[59]=-5;
	
    // queen
	d[4]=6; d[60]=-6;
	
    
}


int translateAdress(char a){
    if(a =='A'){
        return 1;
    }
    if(a =='B'){
        return 2;
    }
    if(a =='C'){
        return 3;
    }
    if(a =='D'){
        return 4;
    }
    if(a =='E'){
        return 5;
    }
    if(a =='F'){
        return 6;
    }
    if(a =='G'){
        return 7;
    }
    if(a =='H'){
        return 8;
    }
}
char backtranslateAdress(int a){
    if(a == 1){
        return 'A';
    }
    if(a == 2){
        return 'B';
    }
    if(a == 3){
        return 'C';
    }
    if(a == 4){
        return 'D';
    }
    if(a == 5){
        return 'E';
    }
    if(a == 6){
        return 'F';
    }
    if(a == 7){
        return 'G';
    }
    if(a == 8){
        return 'H';
    }
}
char translateFigure(int a){
    
    if(a == -1){
        return 'p';
    }
    if(a == -2){
        return 'k';
    }
    if(a == -3){
        return 'r';
    }
    if(a == -4){
        return 'b';
    }
    if(a == -5){
        return 'q';
    }
    if(a == -6){
        return '@';
    }
    if(a == 1){
        return 'P';
    }
    if(a == 2){
        return 'K';
    }
    if(a == 3){
        return 'R';
    }
    if(a == 4){
        return 'B';
    }
    if(a == 5){
        return 'Q';
    }
    if(a == 6){
        return '%';
    }
    if(a == 0){
        return ' ';
    }
}
   
int flip(int a, int b){
	if (b==1){
		return a;
	}
	else{
		return b*a + 9;
	}
}
  
int pairToint(int x, int y){
    return (x - 1) * 8 + y - 1;
}
int numToline(int a){
    return a / 8 + 1;
}
int numTocol(int a){
    return a % 8 + 1;
}


int deck::getFigure(int line, int col){

	int i;
	i = col - 1 + (line - 1) * 8;
	return d[i];
    
}


void deck::symmetryDeck(){
    
    d[64] = d[64] * (-1);
    int i;
    int tmp;
    for(i = 0; i < 32; i++){
        tmp = d[i];
        d[i] = d[63 - i];
        d[63 - i] = tmp;
    }
}


void deck::update(int *movement){
    d[movement[1]] = d[movement[0]];
    d[movement[0]] = 0;
}


void deck::printDeck(){
	
	int i;
	int k = 0;
    int j, l;
    printf("    ");
    for(i = 0; i < 33; i++){
            printf("+");
    }
	for(i = 56; i > -1; i++){
        
        if(i % 8 == 0){
            printf("\n  %d |", flip((i / 8) + 1,d[64]));
        }
        
        printf(" %c |", translateFigure(getFigure(numToline(i), numTocol(i))));
        
		k++;
		
		if(k==8){
            
			printf("\n    ");
            for(j = 0; j < 33; j++){
                printf("+");
            }
			i=i-16;
			k=0;
		
        }
	}
	printf("\n");
    if(d[64] == 1){
        printf("      A   B   C   D   E   F   G   H\n");
    }
    else{
        printf("      H   G   F   E   D   C   B   A\n");
    }
}

