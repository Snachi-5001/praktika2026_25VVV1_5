#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

void PrintMass(int* mass, int n) {
    if (n == 0) {
        printf("Массив пуст.\n");
        return;
    }
    printf("Массив:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", mass[i]);
    }
    printf("\n");
}
int* RandMass(int n, int MinVal, int MaxVal) {
    int* mass = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        mass[i] = MinVal + rand() % (MaxVal - MinVal + 1);
    }
    return mass;
}
void PrintMenu() {
    printf("\n== Меню ==\n");
    printf("1. Сгенерировать массив и сохранить\n");
    printf("2. Загрузить массив из файла\n");
    printf("3. Отсортировать массив и сохранить\n");
    printf("4. Вывести текущий массив\n");
    printf("0. Выход\n");
    printf("Выбор: ");
}
