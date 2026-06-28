#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#include "sort.h"
#include "file_io.h"
#include "menu.h"

int main() {
    setlocale(LC_ALL, "Russian");
    srand((unsigned int)time(NULL));

    int* mass = NULL;
    int size = 0;
    int choice = -1;

    char filename[100];

    while (choice != 0) {
        PrintMenu();
        
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                int n, min, max;
                printf("Кол-во элементов: ");
                scanf("%d", &n);
                
                if (n <= 0) {
                    printf("Кол-во должно быть больше 0\n");
                    break;
                }

                printf("Минимальное значение: ");
                scanf("%d", &min);
                printf("Максимальное значение: ");
                scanf("%d", &max);

                if (min > max) {
                    break;
                }

                if (mass != NULL) free(mass);
                
                mass = RandMass(n, min, max);
                size = n;
                printf("Массив создан\n");
                
                printf("Имя файла для сохранения (например, input.csv): ");
                scanf("%s", filename);
                save_file(filename, mass, size);
                break;
            }
            case 2: {
                printf("Имя файла: ");
                scanf("%s", filename);
                
                int new_size = 0;
                int* new_mass = load_file(filename, &new_size);
                
                if (new_mass != NULL) {
                    if (mass != NULL) free(mass);
                    mass = new_mass;
                    size = new_size;
                    printf("Загружено %d эл-тов\n", size);
                }
                break;
            }
            case 3: {
                if (mass == NULL || size == 0) {
                    printf("Массив пустой\n");
					break;
                }
				
                clock_t start = clock();
                shell_sort(mass, size);
                clock_t end = clock();
                    
                printf("Сортировка завершена. Время: %.6f сек.\n", (double)(end - start) / CLOCKS_PER_SEC);
                    
                printf("Файл для результата (например, output.csv): ");
                scanf("%s", filename);
                save_file(filename, mass, size);
                break;
            }
            case 4: {
                PrintMass(mass, size);
                break;
            }
            case 0:
                break;
            default:
                printf("Неверный пункт\n");
        }
    }

    if (mass) {
        free(mass);
    }

    return 0;
}
