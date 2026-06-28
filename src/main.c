#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"

int main() {
    srand((unsigned)time(NULL));
    
    int* mass = NULL;
    int n = 5;
    int min = 1;
    int max = 20;
    int choice = -1;
    
    while (choice != 0) {
        PrintMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (mass) free(mass);
                mass = RandMass(n, min, max);
                printf("Генерация\n");
                PrintMass(mass, n);
                break;
                
            case 2:
                printf("Загрузка\n");
                break;
                
            case 3:
                printf("Сортировка\n");
                break;
                
            case 4:
                if (mass) PrintMass(mass, n);
                else printf("пусто\n");
                break;
                
            case 0:
                printf("Выход\n");
                break;
                
            default:
                printf("Ошибка\n");
        }
    }
    
    if (mass) free(mass);
    return 0;
}