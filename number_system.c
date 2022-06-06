/**
 * Program  : Phirates Calcu
 * File   : number_system.h
 * Deskripsi : File header number system
 * IDE   : Dev-C++, VS Code
 * Author  : Aini Diah Rahmawati
 *           Egi Satria Dharma Yudha Wicaksana
 *           Reza Ananta Permadi Supriyo
 */

#include "number_system.h"


void cls(){
  int i;
  for (i = 0; i < 100; i++){
    printf("\n");
  }
}

void biner(int n){
  if (n > 0) {
    biner(n / 2);
    printf("%d", n % 2);
  }
}

int pangkat(int n, int x){
  int nilai = 1, i;
  for (i = 0; i < x; i++){
    nilai = nilai * n;
  }
  return nilai;
}

int cekDesimal(int x) {
  //checking
  if (x < 0) { //no minus
    return 1;
  }
  //end of checking, all is right
  return 0;
}

int cekBiner(char str[], int * x) {
  int i, dec = 0;
  //checking
  for (i = 0; i < strlen(str); i++) {
    if ((str[i] - '0' != 1) && (str[i] - '0' != 0)) {
      return 1;
    }
  }
  //end of checking, all is right
  for (i = 0; i < strlen(str); i++) {
    if (str[i] - '0' == 1) {
      dec = dec + pangkat(2, strlen(str) - 1 - i);
    }
  }
  * x = dec;
  return 0;
}

int cekOktal(char str[], int * x) {
  int i, dec = 0;
  //checking
  if ((strlen(str) >= 6) && (str[0] > 49)) {
    return 1;
  }
  for (i = 0; i < strlen(str); i++) {
    if (!((str[i] > 47) && (str[i] < 56))) {
      return 1;
    }
  }
  //end of checking, all is right
  for (i = 0; i < strlen(str); i++) {
    dec = dec + (str[i] - '0') * pangkat(8, strlen(str) - 1 - i);
  }
  * x = dec;
  return 0;
}

int cekHeksadesimal(char str[], int * x) {
  int i, dec = 0;
  //checking
  for (i = 0; i < strlen(str); i++) {
    if (!(((str[i] > 47) && (str[i] < 58)) || ((str[i] > 96) && (str[i] < 103)) || ((str[i] > 64) && (str[i] < 71)))) {
      return 1;
    }
  }
  //end of checking, all is right
  for (i = 0; i < strlen(str); i++) {
    if ((str[i] >= '0') && (str[i] <= '9')) {
      dec = dec + (str[i] - '0') * pangkat(16, strlen(str) - 1 - i);
    } else if ((str[i] > '@') && (str[i] < 'G')) {
      dec = dec + (str[i] - 55) * pangkat(16, strlen(str) - 1 - i);
    } else if ((str[i] > 96) && (str[i] < 'g')) {
      dec = dec + (str[i] - 87) * pangkat(16, strlen(str) - 1 - i);
    }
  }

  * x = dec;
  return 0;
}

void numberSystem() {
  char conversionLimit;
  int x;
  Number number;

  // Anchor
  number_menu :
  while (true) {
    system("cls");
    numberUI();
    gotoxy(54,11);
    scanf("%d", & x);
    switch (x) {
      case 1:
        system("cls");
        printf("\n\n     Masukan angka Decimal [Maksimal 65535] : ");
        scanf("%d", &number.dec);
        if (cekDesimal(number.dec) != 0) {
          printf("     Invalid input!!!");
          break;
        }
        printf("     Biner : ");
        biner(number.dec);
        printf("\n     Oktal : %o", number.dec);
        printf("\n     Heksadesimal : %X", number.dec);
        break;

      case 2:
        system("cls");
        printf("\n\n     Masukan angka Biner [Maksimal 16 bit] : ");
        scanf("%s", number.bin);
        if (cekBiner(number.bin, &number.dec) != 0) {
          printf("     Invalid input!!!");
          break;
        }
        printf("\n     Desimal : %d", number.dec);
        printf("\n     Oktal : %o", number.dec);
        printf("\n     Heksadesimal : %X", number.dec);
        break;

      case 3:
        system("cls");
        printf("\n\n     Masukan angka Oktal [Maksimal 177777] : ");
        scanf("%s", number.oct);
        if (cekOktal(number.oct, &number.dec) != 0) {
          printf("     Invalid input!!!");
          break;
        }
        printf("     Desimal :  %d", number.dec);
        printf("\n     Biner : ");
        biner(number.dec);
        printf("\n     Heksadesimal : %X", number.dec);
        break;
      
      case 4:
        system("cls");
        printf("\n\n     Masukan angka Heksadesimal [Maksimal FFFF] : ");
        scanf("%s", number.hex);
        if (cekHeksadesimal(number.hex, &number.dec) != 0) {
          printf("     Input salah");
          break;
        }
        printf("     Desimal : %d", number.dec);
        printf("\n     Biner : ");
        biner(number.dec);
        printf("\n     Oktal : %o", number.dec);
        break;
      case 0 :
        break;
      default:
        goto number_menu;
    }

    if(x == 0)
      break;
    while (true) {
      printf("\n\n  Coba lagi? [y/t] : ");
      fflush(stdin);
      scanf("%c", &conversionLimit);

      if(conversionLimit == 'y'){
            return true;
        }else if(conversionLimit == 't') {
        	return false;
		}else {
            printf("  Input; y[ya], t[tidak]\n");
        }
    }
  }
}
