/**
 * Program  : Phirates Calcu
 * File   : appUI.c
 * Deskripsi : File body UI
 * IDE   : Dev-C++, VS Code
 * Author  : Aini Diah Rahmawati
 *           Egi Satria Dharma Yudha Wicaksana
 *           Reza Ananta Permadi Supriyo
 */

#include "appUI.h"

void mainMenu(){
		system("cls");
		printf("\t   			 _|      _|  _|_|_|_|  _|      _|  _|    _|  \n");
		printf("\t   			 _|_|  _|_|  _|        _|_|    _|  _|    _|  \n");
		printf("\t			 _|  _|  _|  _|_|_|    _|  _|  _|  _|    _|  \n");
		printf("\t			 _|      _|  _|        _|    _|_|  _|    _|  \n");
		printf("\t			 _|      _|  _|_|_|_|  _|      _|    _|_|    \n");
		printf("\t\t\t    ==================================================== \n");
 		printf("\n\n");
		printf("\t                 [1] Kalkulator     \n");
		printf("\t                 [2] Konversi     \n");
		printf("\t                 [3] Riwayat Penggunaan     \n");
		printf("\t                 [4] Bantuan     \n");
        printf("\t                 [5] Kredit     \n");
        printf("\t                 [6] Keluar     \n");
		printf("\t                Masukkan Pilihan Menu [Angka 1-6] : ");
}

void help(){
	system("cls");
	system("MODE 150, 100");
	char help[255];
	int i;
	FILE *fptr;
		
    // membuka file
	if((fptr = fopen("Teks/Help.txt","r")) == NULL){
        printf("Error: File tidak ada!");
        exit(1); // Tutup program karena file gak ada.
    }

	while(!feof(fptr))
	{
		fgets(help,sizeof(help),fptr);
		for(i = 0; i < strlen(help) ; i++)
	   {
	    charToASCII(help[i]);
	   }
	}
	fclose(fptr);
    printf("\n\n\n  Press 0 on your keyboard to main menu");
}

void credit(){
	system("cls");
	char credit[255];
	int i;
	FILE *fptr;
		
    // membuka file
	if ((fptr = fopen("Teks/Credit.txt","r")) == NULL){
        printf("Error: File tidak ada!");
        // Tutup program karena file gak ada.
        exit(1);
    }

	while(!feof(fptr))
	{
		fgets(credit,sizeof(credit),fptr);
		for(i = 0; i < strlen(credit) ; i++)
	   {
	    charToASCII(credit[i]);
	   }
	}
	fclose(fptr);
    printf("\n\n\n  Press 0 on your keyboard to main menu");
}

void showCalcUi(){
 system("cls");
  FILE*source;
  char calcUI[200];
  int i;
  source = fopen("Teks/CalcUi.txt","r");
  if(source == NULL)
  {
   printf("\nFile not found...");
//   getch();
//   showMenu();
  }
  while(!feof(source))
  {
   //gotoxy(20, 5);
   fgets(calcUI,sizeof(calcUI),source);
   for(i = 0; i < strlen(calcUI) ; i++)
   {
    charToASCII(calcUI[i]);
   }
   
  }
  
  fclose(source); 
  printf("\n");
//  system("pause");
//  showMenu();
  //getch();
}

void loadingScreen(){
	int i,j;
	
	for(i=40 ; i<=75;i++){
		gotoxy(i,12);
		system("color A");
		printf("-");
		gotoxy(i,14);
		printf("-");
		delay();
		
	}
	for (i= 1; i<=100 ; i+=3){
		gotoxy(50,13);
		printf("L O A D I N G %d%%", i);
		delay();
	}
	sleep(1);
	system("cls");
} 

void animation(){

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
		gotoxy(i,8);
		printf("                                   ______      __    ");
		gotoxy(i,9);
		printf("                                  / ____/___ _/ /____ ");
		gotoxy(i,10);
		printf("                                 / /   / __ `/ / ___/");
		gotoxy(i,11);
		printf("                                / /___/ /_/ / / /__  ");
		gotoxy(i,12);
		printf("                                \\____/\\__,_/_/\\___/  ");
		delay ();	
	if( i == 50){
		delay();
	}
	}
}

void delay (void){
	int delay;
	delay = 1;
	while(delay<100000000){
		delay++;
	}
}

void charToASCII(char ch) {
 /* Modul yang mengkonversi char ke char tertentu berdasarkan ASCII */
 switch(ch){
  case '=' :
   printf ("%c", 196);
   break;
  case '|' :
   printf ("%c", 186);
   break;
  case '!' :
   printf ("%c", 251);
   break;
  case '?' :
   printf ("%c", 227);
   break;
  case '<' :
   printf ("%c", 199);
   break;
  case '>' :
   printf ("%c", 182);
   break;
  case '{' :
   printf ("%c", 210);
   break;
  case '}' :
   printf ("%c", 183);
   break;
  case '@' :
   printf ("%c", 208);
   break;
  case '~' :
   printf ("%c", 189);
   break;
  default :
   printf ("%c", ch);  
 }
}

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void conversionUI(){
	system("cls");
char con[] = 
		  "\t\t\t\t\t{=====================================}\n\
 		   \t\t\t|              Konversi   	      |\n\
 	       \t\t\t\t|=====================================|\n\
	       \t\t\t\t|             			      |\n\
 	       \t\t\t\t|    [1] Suhu    	              |\n\
 	       \t\t\t\t|    [2] Sistem Bilangan	      |\n\
	       \t\t\t\t|    [0] Back to Main Menu            |\n\
	       \t\t\t\t|                                     |\n\
 	       \t\t\t\t|=====================================|\n\
 	       \t\t\t\t|Choose one :                         |\n\
 	       \t\t\t\t@=====================================~\n\
		   ";
 int i;	
	for(i = 0; i < strlen(con) ; i++)
   {
    charToASCII(con[i]);
   }
}
void basisSuhu(){
	system("cls");
	char bas[] =
	     "\t\t\t\t\t{=====================================}\n\
 		   \t\t\t|      Pilih Basis Suhu   	      |\n\
 	       \t\t\t\t|=====================================|\n\
	       \t\t\t\t|             			      |\n\
 	       \t\t\t\t|    [1] Celcius    	              |\n\
 	       \t\t\t\t|    [2] Reamur	                      |\n\
	       \t\t\t\t|    [3] Fahrenheit                   |\n\
	       \t\t\t\t|    [4] Kelvin	                      |\n\
		   \t\t\t|    [0] Back to Main Menu            |\n\
	       \t\t\t\t|                                     |\n\
 	       \t\t\t\t|=====================================|\n\
 	       \t\t\t\t|Choose one :                         |\n\
 	       \t\t\t\t@=====================================~\n\
		   ";
	int i;
	for(i = 0; i < strlen(bas) ;i++)
	{
		charToASCII(bas[i]);
	}
}
void numberUI(){
	system("cls");
	char num[] =
	     "\t\t\t\t\t{=====================================}\n\
 		   \t\t\t|             Basis Angka   	      |\n\
 	       \t\t\t\t|=====================================|\n\
	       \t\t\t\t|             			      |\n\
 	       \t\t\t\t|    [1] Decimal    	              |\n\
 	       \t\t\t\t|    [2] Biner	                      |\n\
	       \t\t\t\t|    [3] Oktal                        |\n\
	       \t\t\t\t|    [4] Heksadesimal	              |\n\
		   \t\t\t|    [0] Back to Main Menu            |\n\
	       \t\t\t\t|                                     |\n\
 	       \t\t\t\t|=====================================|\n\
 	       \t\t\t\t|Choose one :                         |\n\
 	       \t\t\t\t@=====================================~\n\
		   ";
	int i;
	for(i = 0; i < strlen(num) ;i++)
	{
		charToASCII(num[i]);
	}
}
