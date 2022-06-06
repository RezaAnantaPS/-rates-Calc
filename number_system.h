/**
 * Program  : Phirates Calcu
 * File   : number_system.c
 * Deskripsi : File body number system
 * IDE   : Dev-C++, VS Code
 * Author  : Aini Diah Rahmawati
 *           Egi Satria Dharma Yudha Wicaksana
 *           Reza Ananta Permadi Supriyo
 */

#ifndef number_system_H
#define number_system_H

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    int dec;
    char oct[6], bin[16], hex[4];
}Number;

void biner(int n);
/**
 * Tanggal  : 26-05-2022
 * Author   : 
 * Deskripsi  : Menampilkan hasil bilangan biner
 * IS    : belum tertampil hasil perhitungan bilangan biner
 * FS    : menampilkan hasil perhitungan bilangan biner
 */

int pangkat(int n, int x);
/**
 * Tanggal  : 26-05-2022
 * Author   : 
 * Deskripsi  : Mengembalikkan nilai yang dipangkatkan
 * IS    : belum tertampil hasil perhitungan pangkat
 * FS    : menampilkan hasil perhitungan pangkat
 */

int cekDesimal(int dec);
/**
 * Tanggal  : 26-05-2022
 * Author   : 
 * Deskripsi  : Mengecek desimal atau tidaknya suatu bilangan
 * FS    : Mengembalikan 1 jika tidak ada bilangan negatif dan 0 jika positif
 */

int cekBiner(char bin[], int * dec);
/**
 * Tanggal  : 26-05-2022
 * Author   : 
 * Deskripsi  : Mengecek biner atau tidaknya suatu bilangan
 * FS    : Mengembalikan 1 jika bilangan yang dicek adalah bilangan biner dan 0 jika bukan
 */

int cekOktal(char oct[], int * dec);
/**
 * Tanggal  : 26-05-2022
 * Author   : 
 * Deskripsi  : Mengecek oktal atau tidaknya suatu bilangan
 * FS    : Mengembalikan 1 jika bilangan yang dicek adalah bilangan oktal dan 0 jika bukan
 */

int cekHeksadesimal(char hex[], int * dec);
/**
 * Tanggal  : 26-05-2022
 * Author   : 
 * Deskripsi  : Mengecek hexa atau tidaknya suatu bilangan
 * FS    : Mengembalikan 1 jika bilangan yang dicek adalah bilangan hexa dan 0 jika bukan
 */

void numberSystem();
/**
 * Tanggal  : 26-05-2022
 * Author   : 
 * Deskripsi  : Menampilkan pilihan konversi bilangan
 * IS 	 : tampilan konversi menu
 * FS    : tampilan memilih bilangan yang akan dikonversikan
 */

#endif
