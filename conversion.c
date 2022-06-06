/**
 * Program  : Phirates Calcu
 * File   : conversion.c
 * Deskripsi : Main driver konfersi
 * IDE   : Dev-C++, VS Code
 * Author  : Aini Diah Rahmawati
 *           Egi Satria Dharma Yudha Wicaksana
 *           Reza Ananta Permadi Supriyo
 */

  #include "conversion.h"

  void conversion() {
    // Batas Konversi
    char conversion_limit;
    // Menu Konversi
    int convertChoice = 0;
    // Grid Layout
  //  konversiGridLayout();
    conversion_menu :
    conversionUI();
    // KonversiMenu
    gotoxy(54,9);
    scanf("%d", &convertChoice);

    while (true) {
      switch (convertChoice) {
        case 1:
          temperature();
          printf("\n\n\n  Press 0 to back to conversion menu");
          getch();
          goto conversion_menu;
          break;
        case 2:
          numberSystem();
          printf("\n\n\n  Press 0 to back to conversion menu");
          getch();
          goto conversion_menu;
          break;
        case 0 :
          break;
        default:
          goto conversion_menu;
      }
      if(convertChoice == 0){
        printf("\n\n\n  Press 0 to back to main menu");
      }
      break;
    }
  }
