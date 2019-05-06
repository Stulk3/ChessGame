#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //for linux
// #include "windows.h" // for windows

#include "deck.h"
#include "game.h"

/*
void newScreen(){
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
}
*/
void newScreen(){
    system("clear");
}
void printStep(int *movement,deck desk){
    
    printf("\nLast step was %c%d --> %c%d\n", backtranslateAdress(flip(numTocol(movement[0]), desk.d[64])), flip(numToline(movement[0]), desk.d[64]), backtranslateAdress(flip(numTocol(movement[1]), desk.d[64])), flip(numToline(movement[1]), desk.d[64]));
}
int getPLayer(int a){
    return a % 2;
}
void printPlayer(int a){
    if(a == 1){
        printf("WHITE\n");
    }
    else{
        printf("BLACK\n");
    }
}
/*
void waitSec(int a){
    
    int i;
    printf("Wait for %d", a);
    for(i = a; i > 0; i--){
        sleep(1);
        printf("%d", i);
    }
    printf("\n");
}
*/
void getStep(int *movement, deck desk){
    
    int x1, y1;
    int x2, y2;
    char *z = new char[2];
    
    
    printf("From: ");
    scanf("\n%c", &z[0]);
    scanf("%d", &x1);
    
    y1 = translateAdress(z[0]);
    
    movement[0] = pairToint(flip(x1, desk.d[64]), flip(y1, desk.d[64]));
    
    
    printf("To: ");
    scanf("\n%c", &z[1]);
    scanf("%d", &x2);
    y2 = translateAdress(z[1]);
    
    movement[1] = pairToint(flip(x2, desk.d[64]), flip(y2, desk.d[64]));
    
}



bool checkMovement(int *movement){
    return true;
}


void makeStep(deck desk){
	
    int *movement = new int[2];
    
    getStep(movement, desk);
        
    
    if(checkMovement(movement)){
        desk.update(movement);
    }
    
    newScreen(); 
    desk.printDeck();
    printStep(movement,desk);
    
    sleep(2);
    
    newScreen();
    printStep(movement,desk);
    desk.symmetryDeck();
    desk.printDeck();
    
    
    
}


void game(){
	
    newScreen();
	deck desk;

	bool finish = false;
	int step;
	desk.printDeck();
	for(step = 1; step < 7; step++){
		
        	printPlayer(getPLayer(step));
		
		makeStep(desk);
        
	}

}

