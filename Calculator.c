/**
 * Program  : Phirates Calcu
 * File   : Calculator.c
 * Deskripsi : File body calculator
 * IDE   : Dev-C++, VS Code
 * Author  : Aini Diah Rahmawati
 *           Egi Satria Dharma Yudha Wicaksana
 *           Reza Ananta Permadi Supriyo
 */

#include "Calculator.h"
#ifndef Calculator_C
#define Calculator_C

void createCalculator(Calculator *calculator) {
	// pemberian nilai default
	memset(calculator->operation, '\0', sizeof(calculator->operation));
	calculator->result = 0;
	calculator->operationTree = (struct TNode *)malloc(sizeof(struct TNode));
}

bool isOperation(char *operation) {
	int i;
	
	// Check apakah pada string terdapat simbol yang bukan operator atau tidak valid
	for(i=strlen(operation)-1 ; i>=0 ; i--){
        if(!isdigit(operation[i]) && operation[i] != MINUS && operation[i] != PLUS 
							&& operation[i] != DIVISION && operation[i] != MULTIPLY 
							&& operation[i] != POWER && operation[i] != PERCENTAGE && operation[i] != SQUARE
							&& operation[i] != DECIMAL && operation[i] != OPEN_BRACKET && operation[i] != CLOSE_BRACKET) {
			printf("  Invalid input!!!\n");		
			return false;				
		}
    }
    
    return true;
}

void checkMinFirst(char *operation) {
	int i;
	
	// Menambahkan 0 di awal string, jika inputan indeks pertama negatif
    if(operation[0] == '-'){
        for(i=strlen(operation)-1 ; i>=0 ; i--){
                operation[i+1] = operation[i];
        }

        operation[0] = '0';
    }
}

void insertOperation(Calculator *calculator) {
	// melakukan proses insertion
    fflush(stdin);
    gotoxy(13,6);
    scanf("%s", calculator->operation);
    printf("\n\n");
}

bool calculateOperation(Calculator *calculator, addrNode root) {
	bool isSuccess = true;
	
	// hitung hasil dari ekspresi pada tree
	calculator->result = calculate(root, &isSuccess);
	
	// kembalikan status perhitungan
	return isSuccess;
}

void printResult(Calculator calculator, bool isSuccess) {
	// print calculator sesuai dengan format
	gotoxy(13,7);
    if(!isSuccess){
    	// jika proses kalkulasi tidak berhasil
        printf("= %s","Error: Tidak bisa dibagi nol");
    }
    else if (ceil(calculator.result) > calculator.result){
    	// jika proses kalkulasi berhasil dan hasilnya adalah bilangan desimal
        printf("= %.2f",calculator.result);
    }
	else{
		// jika proses kalkulasi berhasil dan hasilnya adalah bilangan bulat
        printf("= %d",(int)calculator.result);
    }
    
}



bool isContinue() {
	char choice;
	gotoxy(5,25);
	// tentukan apakah user mengulang proses atau tidak
	while(true){

    	printf("  Coba lagi? [y/t] : ");
        fflush(stdin);
        scanf("%c", &choice);
            
        if(choice == 'y'){
            return true;
        }else if(choice == 't') {
        	return false;
		}else {
            printf("  Input; y[ya], t[tidak]\n");
        }
    }
}

void calculator() {
	Calculator calcu;
	
	// Anchor
    calculator_menu:

    while(true){
        system("cls");
		gotoxy(12, 5); 
        showCalcUi();
           
        //printf("press any key");
        
        // create new calculator
        createCalculator(&calcu);
        
        // insert operation
        insertOperation(&calcu);
        
        // check operation validation
        if(!isOperation(calcu.operation)) {
            sleep(1);
            goto calculator_menu;
        }
		
		// check minus sign exception
        checkMinFirst(calcu.operation);
            
        // Create operation 
        calcu.operationTree = constructTree(calcu.operation,0,strlen(calcu.operation)-1);
        
        // calculate operation tree
        bool isSuccess = calculateOperation(&calcu, calcu.operationTree);
        
        // print result
        printResult(calcu, isSuccess);
        
        //print prefix, infix, postfix
        gotoxy(50,5), printf("Prefix : \n");
		gotoxy(50,6), preOrder(calcu.operationTree);
		
		gotoxy(50,8), printf("Infix : \n");
		gotoxy(50,9), inOrder(calcu.operationTree);
		
		gotoxy(50,11), printf("Postfix : \n");
		gotoxy(50,12), postOrder(calcu.operationTree);
        
        // delete operation tree
        deleteTree(calcu.operationTree);
        
        // lakukan save history jika perhitungan berhasil
        if (isSuccess)
        	historySave(calcu.operation, calcu.result);
        
        // tentukan apakah user mengulang proses kalkulasi
        if(!isContinue()){
            break;
        }

    }
    printf("\n\n\n  Press 0 on your keyboard to main menu");
}

#endif

