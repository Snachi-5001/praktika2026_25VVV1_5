#include "sort.h"

void shell_sort(int* mass, int n) { // ук. массива + кол-во эл-тов
    for (int step = n / 2; step > 0; step /= 2) { // каждый шаг step делим на 2
        for (int i = step; i < n; i++) {
            int temp = mass[i];
            int j = i; 
            
            while (j >= step && mass[j - step] > temp) { // меняем пока есть что менять
                mass[j] = mass[j - step];
                j -= step;
            }
            
            mass[j] = temp; // ставим на своё место
        }
    }
}
