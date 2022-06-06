/**
 * Program  : Phirates Calcu
 * File   : history.h
 * Deskripsi : File header history
 * IDE   : Dev-C++, VS Code
 * Author  : Aini Diah Rahmawati
 *           Egi Satria Dharma Yudha Wicaksana
 *           Reza Ananta Permadi Supriyo
 */

#ifndef history_H
#define history_H

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "tree.h"

struct history{
	char operations[200];
    double results;
	char time[100];
}Record;

int historySave(char *operations, double results);
/**
 * Tanggal  : 27-05-2022
 * Author   : 
 * Deskripsi  : Menyimpan history kedalam file
 * IS 	 : history belum tersimpan
 * FS    : history sudah tersimpan
 */

int historyRead();
/**
 * Tanggal  : 27-05-2022
 * Author   : 
 * Deskripsi  : Membaca data history yang tersimpan didalam file
 * IS 	 : history belum tertampil
 * FS    : history sudah tertampil
 */
 
#endif
