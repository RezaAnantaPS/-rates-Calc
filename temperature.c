/**
 * Program  : Phirates Calcu
 * File   : temperature.c
 * Deskripsi : File body temperature
 * IDE   : Dev-C++, VS Code
 * Author  : Aini Diah Rahmawati
 *           Egi Satria Dharma Yudha Wicaksana
 *           Reza Ananta Permadi Supriyo
 */

#include "temperature.h"

void printConversion(Temperature temperature){
    printf(" =====================================================\n");
    printf(" |                 KONVERSI SUHU                     |\n");
    printf(" =====================================================\n");
    printf(" |  Celcius  |   Fahrenheit |  Reamur   |   Kelvin   |\n");
    printf(" =====================================================\n");
    printf(" |  %.2f    |  %.2f    |   %.2f      |   %.2f   |\n", temperature.celcius, temperature.fahrenheit, temperature.reamur, temperature.kelvin);
    printf(" =====================================================\n");
}

void temperature(){
    char conversionLimit;
    int choiceTem;
    Temperature temperature;
    // Anchor
    tempe_anchor :
    system("cls");
    basisSuhu();
    gotoxy(54,11);
    scanf("%d", &choiceTem);
    while(true){

        switch(choiceTem){
            case 1 :
                system("cls");
                printf("\n\n  Masukan nilai Celcius: ");
                scanf("%f", &temperature.celcius);
                
                temperature.reamur = temperature.celcius * 4/5;
                temperature.fahrenheit = (temperature.celcius * 9/5) + 32;
                temperature.kelvin = temperature.celcius + 273.15;
                
                printConversion(temperature);

                break;

            case 2 :
                system("cls");
                printf("\n\n  Masukan nilai Reamur: ");
                scanf("%f", &temperature.reamur);

                temperature.celcius = temperature.reamur * 5/4;
                temperature.fahrenheit = (temperature.reamur * 9/4) + 32;
                temperature.kelvin = (temperature.reamur * 5/4) + 273.15;
                
                printConversion(temperature);

                break;

            case 3 :
                system("cls");
                printf("\n\n  Masukan nilai Fahrenheit: ");
                scanf("%f", &temperature.fahrenheit);

                temperature.celcius = (temperature.fahrenheit-32) * 5/9;
                temperature.reamur = (temperature.fahrenheit-32) * 4/9;
                temperature.kelvin = ((temperature.fahrenheit-32) * 5/9) + 273.15;
                
                printConversion(temperature);

                break;
            
            case 4 :
                system("cls");
                printf("\n\n  Masukan nilai Kelvin: ");
                scanf("%f", &temperature.kelvin);

                temperature.celcius =  temperature.kelvin - 273.15;
                temperature.reamur = (temperature.kelvin - 273.15) * 4/5;
                temperature.fahrenheit =  ((temperature.kelvin - 273.15) * 9/5) + 32;
                
                printConversion(temperature);

                break;
            case 0 :
                break;
            default :
                goto tempe_anchor;
        }
        if(choiceTem == 0)
            break;
        while (true) {
            printf("\n\n  Coba lagi? [y/t] : ");
            fflush(stdin);
            scanf("%c", &conversionLimit);

            if (conversionLimit == 'y' || conversionLimit == 't') {
                break;
            } else {
                printf("  Input; y[ya], t[tidak]\n\n");
                sleep(1);
            }
        }
        if (conversionLimit == 't'){
            break;
        }

    }
}
