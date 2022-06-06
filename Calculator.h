/**
 * Program  : Phirates Calcu
 * File   : Calculator.h
 * Deskripsi : File header calculator
 * IDE   : Dev-C++, VS Code
 * Author  : Aini Diah Rahmawati
 *           Egi Satria Dharma Yudha Wicaksana
 *           Reza Ananta Permadi Supriyo
 */

#ifndef Calculator_H
#define Calculator_H

#include <stdbool.h>
#include "tree.h"


typedef struct {
	char operation[200];
	double result;
	addrNode operationTree;	
}Calculator;

void createCalculator(Calculator *calculator);
/**
 * Tanggal  : 24-05-2022
 * Author   : 
 * Deskripsi  : Membuat calculator baru
 * IS : calculator random value
 * FS : calculator default value
 */

bool isOperation(char *operation);
/**
 * Tanggal  : 24-05-2022
 * Author   : 
 * Deskripsi  : Mengecek apakah pada string ekspresi memuat karakter illegal (bukan operator/simbol matematis)
 * IS :  Mengembalikan true jika tidak ada karakter ilegal
 * FS : Mengembalikan false jika terdapat karakter ilegal
 */
 
void checkMinFirst(char *operation);
/**
 * Tanggal  : 24-05-2022
 * Author   : 
 * Deskripsi  : Mengecek apakah simbol pertama merupakan minus
 * IS : ekspresi string
 * FS1 : ekspresi string digeser ke kanan 1, dan pada index 0 insert '0'
 * FS2 : ekspresi string tidak dimanipulasi
 */
 
void insertOperation(Calculator *calculator);
/**
 * Tanggal  : 24-05-2022
 * Author   : 
 * Deskripsi  : Memasukan string ekspresi kedalam kalkulator
 * IS : perhitungan dengan ekspresi kosong
 * FS : perhitungan dengan ekspresi terisi oleh inputan user
 */

bool calculateOperation();
/**
 * Tanggal  : 24-05-2022
 * Author   : 
 * Deskripsi  : Melakukan kalkulasi ekspresi matematika pada tree
 * IS : Mengembalikan true jika proses perhitungan berhasil
 * FS : Mengembalikan false jika proses perhitungan gagal
 */

void printResult(Calculator calculator, bool isSuccess);
/**
 * Tanggal  : 24-05-2022
 * Author   : 
 * Deskripsi  : Menampilkan hasil expresi
 * IS : belum ditampilkan hasil perhitungan
 * FS : tampil hasil perhitungan ekspresi aritmatik dan ekspresinya
 */

bool isContinue();
/**
 * Tanggal  : 24-05-2022
 * Author   : 
 * Deskripsi  : Mengecek apakah pengguna mengulang proses perhitungan
 * IS : Mengembalikan true jika iya
 * FS : Mengembalikan false jika tidak
 */
 
void calculator();
/**
 * Tanggal  : 24-05-2022
 * Author   : 
 * Deskripsi  : main driver untuk calculator
 * IS : Modul-modul yang ada di dalam kalkulator belum di jalankan
 * FS : Modul-modul yang ada di dalam kalkulator sudah dijalankan dan manampilkan hasil perhitungan
 */

#endif

