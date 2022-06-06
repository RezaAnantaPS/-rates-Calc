#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;
// Prosedur animasi
void delay (void){
	int delay;
	delay = 1;
	while(delay<11000000){
		delay++;
	}
}
//function gotoxy
void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int main(){
	int i,j;
	char ulang;
	
	for(i=1 ; i<=50 ; i++){
		gotoxy(i,3);
		printf("     ____  __    _            __                       ");
		gotoxy(i,4);
		printf("    / __ \\/ /_  (_)________ _/ /____  _____            ");
		gotoxy(i,5);
		printf("   / /_/ / __ \\/ / ___/ __ `/ __/ _ \\/ ___/          ");
		gotoxy(i,6);
		printf("  / ____/ / / / / /  / /_/ / /_/  __(__  )            ");
		gotoxy(i,7);
		printf(" /_/   /_/ /_/_/_/   \\__,_/\\__/\\___/____/              ");
		printf("\n");
		gotoxy(i,13);
		printf("                                   ______      __    ");
		gotoxy(i,14);
		printf("                                  / ____/___ _/ /____ ");
		gotoxy(i,15);
		printf("                                 / /   / __ `/ / ___/");
		gotoxy(i,16);
		printf("                                / /___/ /_/ / / /__  ");
		gotoxy(i,17);
		printf("                                \\____/\\__,_/_/\\___/  ");
		delay ();	
	if( i == 50){
		delay();
		getch();
	}
	}
	
getch();
return 0;
}
