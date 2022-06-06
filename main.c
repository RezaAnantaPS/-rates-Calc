/**
 * Program  : Phirates Calcu
 * File   : main.c
 * Deskripsi : Main driver program
 * IDE   : Dev-C++, VS Code
 * Author  : Aini Diah Rahmawati
 *           Egi Satria Dharma Yudha Wicaksana
 *           Reza Ananta Permadi Supriyo
 */

#include "tree.h"
#include "appUI.h"
#include "Calculator.h"
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


//using namespace std;

int main(int argc, char** argv) {
	int choice;
    // Main Menu
    loadingScreen();
    animation();
    menu:
	mainMenu();
    // Memilih mainMenu
    scanf("%d", &choice);

    while(true){
        switch(choice){
            case 1 :
                calculator();
                
                while(true){
                    fflush(stdin);
                    char input = getch();
                    goto menu;
		        }
                break;
            case 2 :
            	conversion();
            	while(true){
            		fflush(stdin);
            		char input = getch();
            		goto menu;
				}
			case 3 :
				historyRead();
				while(true){
            		fflush(stdin);
            		char input = getch();
            		goto menu;
				}
			case 4 :
				help();
				while(true){
            		fflush(stdin);
            		char input = getch();
            		goto menu;
				}
			case 5 :
				credit();
				while(true){
            		fflush(stdin);
            		char input = getch();
            		goto menu;
				}	
			case 6:
                exit(6);
                break;
            default :
            	goto menu;
        }
    }

    return 0;
}

