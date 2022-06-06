/**
 * Program  : Phirates Calcu
 * File   : tree.c
 * Deskripsi : File body tree
 * IDE   : Dev-C++, VS Code
 * Author  : Aini Diah Rahmawati
 *           Egi Satria Dharma Yudha Wicaksana
 *           Reza Ananta Permadi Supriyo
 */

#include "tree.h"

#ifndef tree_C
#define tree_C

double calculate(addrNode root, bool *isSuccess) {
	
	// root adalah operator
    if(root->isOperantor){
    	// Tentukan operand dan hitung
        switch(root->operator_){
            case PLUS:{
                return calculate(root->left_child,isSuccess) + calculate(root->right_child,isSuccess);
                break;
            }
            case MINUS:{
                return calculate(root->left_child,isSuccess) - calculate(root->right_child,isSuccess);
                break;
            }
            case DIVISION:{
                if(calculate(root->right_child,isSuccess) == 0) {
                    (*isSuccess) = false;
                	return MAX;
				}
                else
                    return calculate(root->left_child,isSuccess) / calculate(root->right_child,isSuccess);
                break;
            }
            case MULTIPLY:{
                return calculate(root->left_child,isSuccess) * calculate(root->right_child,isSuccess);
                break;
            }
            case POWER:{
                return pow(calculate(root->left_child,isSuccess), calculate(root->right_child,isSuccess));
                break;
            }
            case PERCENTAGE:{
                return (calculate(root->left_child,isSuccess) * calculate(root->right_child,isSuccess))/100;
                break;
            }
            case SQUARE:{
                return sqrt(calculate(root->right_child,isSuccess));
                break;
            }
        }
    }
    
    // root adalah operator
    return root->operand;
}

double checkString(char str[], int start, int end){
	int i;
    int flag = 1; // postive or negative flag
    int doubleFlag = 0;
    double sum = 0; // hasil konversi
    double divFactor = 10.0; // bertambah 10x lipat semakin ke posisi kanan dari simbol desimal
    
    
    // Check apakah bilangan negatif
    if (str[start] == MINUS){
        flag = -1;
        start++;
    }
    
    // Parsing string ke operand
    for (i = start ; i <= end ; i++){
    	// Jika char adalah simbol operand dan bukan desimal
        if (!isdigit(str[i]) && str[i] != DECIMAL) 
            return MAX;
        
        // Check apakah bilangan desimal
        if (str[i] == DECIMAL){
            doubleFlag++;
            i++;
        }
        
        // konversi char ke operand
        if (!doubleFlag)
            sum = sum * 10 + str[i] - '0';
        else{
            sum = sum + (str[i] - '0')/divFactor;
            divFactor *= 10;
        }
    }
    
    return sum*flag;
}

int findOperator(char str[], int start, int end) {
	int posPlusOrSub = 0;//Position of plus and minus signs 
    int numPlusOrSub = 0;//operand of plus and minus signs 
    int posDivOrMul = 0;//Multiply and divide and percenting sign position 
    int numDivOrMul = 0;//operand of multiplication and division and percenting operands
    int posPowOrRoot = 0; // Power and square root sign position
    int numPowOrRoot = 0; // operand of the result after powering or square rooting
 
    int in_brackets = 0; //Identifiers not in parentheses 
    int k;
    
    // Tentukan jumlah dan posisi semua operator pada string
    for(k = start ; k <= end ; k++){
        if(str[k] == OPEN_BRACKET)
            in_brackets++;
        else if(str[k] == CLOSE_BRACKET)
            in_brackets--;
        
        // Jika diluar tanda kurung
        if(!in_brackets){
            if(str[k] == PLUS || str[k] == MINUS){
                // check apakah sebelumnya adalah operator
				if (k != start && isdigit(str[k-1])) {
					posPlusOrSub = k;
                	numPlusOrSub++;	
				}else if ((str[k-1] == OPEN_BRACKET || str[k-1] == CLOSE_BRACKET)) {
					posPlusOrSub = k;
                	numPlusOrSub++;	
				}
            }
            else if(str[k] == MULTIPLY || str[k] == DIVISION || str[k] == PERCENTAGE){
                posDivOrMul = k;
                numDivOrMul++; 
            }
            else if(str[k] == POWER || str[k] == SQUARE){
                posPowOrRoot = k;
                numPowOrRoot++;
            }
        }
    }
    
    // posisi operator yang diprioritaskan
    int posOperator = -1;
    
    //Temukan posisi root node dimulai dengan urutan operator derajat terendah
    if(numPlusOrSub)
        posOperator = posPlusOrSub;
    else if(numDivOrMul)
        posOperator = posDivOrMul;
    else if(numPowOrRoot)
        posOperator = posPowOrRoot;
    
    return posOperator;
}

addrNode constructTree(char str[], int start, int end){
    addrNode root = (addrNode)malloc(sizeof(struct TNode));

	// if there is no char left in s[]
    if(start>end) 
		return NULL;
    
    double num = checkString(str, start, end);
	
	// Jika string hanya berisi operand  
    if(num!=0x3f3f3f3f){
        root->isOperantor = false;
        root->operand = num;
        root->left_child = NULL;
        root->right_child = NULL;
        return root;
    }
    
    // Temukan posisi operator prioritas
    int posRoot = findOperator(str, start, end);
    
    // Jika tidak ada operator
    if(posRoot == -1) 
        return constructTree(str,start+1,end-1);
    
    // membuat root berisi operator
    root->isOperantor = true;
    root->operator_ = str[posRoot];
    root->left_child = constructTree(str, start, posRoot-1);
    root->right_child = constructTree(str, posRoot+1, end);
    
    return root;
}

void preOrder(addrNode root){
    if(root){
        if(root->isOperantor==0){
            printf("%d ",(int)root->operand);
        }
        else{
            printf("%c ",root->operator_);
        } 
        preOrder(root->left_child);
        preOrder(root->right_child);
    }
} 

void inOrder(addrNode root){
    if(root){
        inOrder(root->left_child);
        if(root->isOperantor==0){
            printf("%d ",(int)root->operand);
        }
        else{
            printf("%c ",root->operator_);
        } 
        inOrder(root->right_child);
    }
}

void postOrder(addrNode root){
    if(root){
        postOrder(root->left_child);
        postOrder(root->right_child);
        if(root->isOperantor==0){
            printf("%d ",(int)root->operand);
        }
        else{
            printf("%c ",root->operator_);
        }       
    }
}

void deleteTree(addrNode root) {
	if (root == NULL)
		return;
	
	deleteTree(root->left_child);
	deleteTree(root->right_child);
	
	free(root);
}

#endif

