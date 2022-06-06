#include "listCalculator.h"

void calculator() {
	Calculator calcu;
	
	// Anchor
    calculator_anchor :
    system("cls");

    while(true){
        system("cls");
        
        // create new calculator
        createListCalculator(&calcu);
        
        // insert operation
        insertOperation(&calcu);
        
        // check operation validation
        if(!isOperation(calcu.operation)) {
            sleep(1);
            goto calculator_anchor;
        }
		
		// check minus sign exception
        checkMinFirst(calcu.operation);
            
        // Create operation tree
        calcu.operationTree = constructTree(calcu.operation,0,strlen(calcu.operation)-1);
        
        // calculate operation tree
        bool isSuccess = calculateOperation(&calcu, calcu.operationTree);
        
        // print result
        printResult(calcu, isSuccess);
        
        // delete operation tree
        deleteTree(calcu.operationTree);
        
        // lakukan save history jika perhitungan berhasil
//        if (isSuccess)
//        	saveHistory(calcu.operation, calcu.result);
        
        // tentukan apakah user mengulang proses kalkulasi
        if(!isContinue()){
            break;
        }

    }
    printf("\n\n\n  Press ESCAPE on your keyboard to main menu");
}

