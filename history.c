/**
 * Program  : Phirates Calcu
 * File   : history.c
 * Deskripsi : File body history
 * IDE   : Dev-C++, VS Code
 * Author  : Aini Diah Rahmawati
 *           Egi Satria Dharma Yudha Wicaksana
 *           Reza Ananta Permadi Supriyo
 */

#include "history.h"

int historySave(char *operations, double results){
    FILE* pFile = 0;
    struct history Record;
    time_t _time;
    
    time (&_time);
    struct tm *tmi;
	  tmi = localtime (&_time);
    strftime (Record.time,100,"%d %b %Y %H:%M",tmi);
        
    strcpy(Record.operations, operations);
    Record.results = results;

    fopen_s(&pFile,"history.dat","ab+"); // append and update binary, can be read
    if(!pFile)
    return 1; //fopen error

    fwrite(&Record,sizeof(Record),1,pFile);
    fclose(pFile);
        
    return 0;
}

int historyRead(){  //
    system("cls");
    FILE* pFile = 0;
    int i = 1;
    pFile = fopen("history.dat","ab+"); // append and update binary, can be read
    if(!pFile)
      return 1; //fopen error
    printf("\n\n\t\t\t=================================================");
    printf("\n\t\t\t|                   History		        |\n");
		printf(" \t\t\t=================================================\n\n");
    printf( "  \xDA\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n" );
    printf( "  \xB3 %-3s\xB3        %-12s\xB3         %-31s\xB3      %-14s\xB3\n", "No","Time", "Operations", "Result");
    printf( "  \xC3\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xB4\n" );

    do{
        fseek(pFile,(-i)*sizeof(Record),SEEK_END);
        fread(&Record,sizeof(Record),1,pFile);
        if(!feof(pFile) && i <= 15){
            if (ceil(Record.results) > Record.results)
                printf("  \xB3 %-3d\xB3 %-19s\xB3 %-39s\xB3 %-19f\xB3\n", i++, Record.time, Record.operations, Record.results);
            else
                printf("  \xB3 %-3d\xB3 %-19s\xB3 %-39s\xB3 %-19d\xB3\n", i++, Record.time, Record.operations, (int)Record.results);
        }
    }while(!feof(pFile) && i <= 15);
    printf( "  \xC0\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9" );
        
    fclose(pFile);

    printf("\n\n\n  Press 0 on your keyboard to main menu"); 

    return 0;
}
