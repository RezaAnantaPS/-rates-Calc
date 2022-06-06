/**
 * Program  : Phirates Calcu
 * File   : tree.h
 * Deskripsi : File header tree
 * IDE   : Dev-C++, VS Code
 * Author  : Aini Diah Rahmawati
 *           Egi Satria Dharma Yudha Wicaksana
 *           Reza Ananta Permadi Supriyo
 */

#ifndef tree_H
#define tree_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <ctype.h>
#include <math.h>
#include <unistd.h>

#define MAX 0x3f3f3f3f

#define OPEN_BRACKET '('
#define CLOSE_BRACKET ')'
#define DECIMAL '.'
#define PLUS '+'
#define MINUS '-'
#define MULTIPLY '*'
#define DIVISION '/'
#define SQUARE 'v'
#define POWER '^'
#define PERCENTAGE '%'

typedef struct TNode* addrNode;

typedef struct  TNode{
    bool isOperantor;
    double operand;
    char operator_; 
    addrNode left_child;
    addrNode right_child;
}Node;

double calculate(addrNode root, bool *isSuccess);
/**
 * Tanggal  : 22-05-2022
 * From : https://www.programmersought.com/article/95294413292/
 * Author   : 
 * Deskripsi  : Melakukan perhitungan terhadap suatu sub-tree
 * IS    : Mengembalikan hasil perhitungan jika terdapat operator (root berisi operator)
 * FS    : Mengembalikan nilai operand jika tidak terdapat operator (root berisi operand)
 */



double checkString(char str[],int start,int end);
/**
 * Tanggal  : 23-05-2022
 * From https://www.programmersought.com/article/95294413292/
 * Author   : 
 * Deskripsi  : melakukan cek karakter pertama yang ada pada expression dan mengembalikan nilai kode ASCII operand yang paling awal
 * IS    : Mengembalikan hasil konversi operand jika tidak ditemukan operator pada string
 * FS    : Mengembalikan nilai MAX jika terdapat operator pada string
 */

int findOperator(char str[],int start,int end);
/**
 * Tanggal  : 23-05-2022
 * From https://www.programmersought.com/article/95294413292/
 * Author   : 
 * Deskripsi  : Menemukan operator dengan aturan yang telah ditentukan
 				1. PLUS or MINUS
 				2. MULTIPLY or DIVISION
 				3. SQUARE_ROOT or PERCENTAGE or POWER
 * IS    : Posisi operator belum teridentifikasi
 * FS    : Mengembalikan posisi operator tersebut dalam string
 */


addrNode constructTree(char str[],int start,int end);
/**
 * Tanggal  : 23-05-2022
 * Author   : 
 * Deskripsi  : Membuat tree
 * IS    : Mengembalikan hasil perhitungan jika terdapat operator (root berisi operator)
 * FS    : Mengembalikan tree yang telah berisi operation
 */

void preOrder(addrNode root);
/**
 * Tanggal  : 23-05-2022
 * Author   : 
 * Deskripsi  : Menampilkan urutan preorder dari tree
 * IS    : urutan belum tertampil
 * FS    : urutan tertampil
 */
 
void inOrder(addrNode root);
/**
 * Tanggal  : 23-05-2022
 * Author   : 
 * Deskripsi  : Menampilkan urutan inorder dari tree
 * IS    : urutan belum tertampil
 * FS    : urutan tertampil
 */

void postOrder(addrNode root);
/**
 * Tanggal  : 23-05-2022
 * Author   : 
 * Deskripsi  : Menampilkan urutan postorder dari tree
 * IS    : urutan belum tertampil
 * FS    : urutan tertampil
 */

void deleteTree(addrNode root);
/**
 * Tanggal  : 23-05-2022
 * Author   : 
 * Deskripsi  : Menghapus semua node pada tree
 * IS : node pada tree tersedia
 * FS : node pada tree telah di dealokasi
 */

#endif

