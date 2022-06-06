/**
 * Program  : Phirates Calcu
 * File   : temperature.h
 * Deskripsi : File header temperature
 * IDE   : Dev-C++, VS Code
 * Author  : Aini Diah Rahmawati
 *           Egi Satria Dharma Yudha Wicaksana
 *           Reza Ananta Permadi Supriyo
 */

#ifndef temperature_H
#define temperature_H

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#include <math.h>
#include "appUI.h"

typedef struct {
	float celcius, reamur, fahrenheit, kelvin;	
}Temperature;

void printConversion(Temperature temperature);
/**
 * Tanggal  : 25-05-2022
 * Author   : 
 * Deskripsi  : Menampilkan hasil konversi
 * IS    : belum ditampilkan hasil perhitungan konversi suhu
 * FS    : tampil hasil perhitungan konversi suhu
 */

void temperature();
/**
 * Tanggal  : 25-05-2022
 * Author   : 
 * Deskripsi  : Menghitung pengkonversian suhu
 * IS    : nilai suhu belum teridentifikasi ke satuan lainnya
 * FS    : nilai suhu teridentifikasi ke satuan lainnya
 */

#endif
