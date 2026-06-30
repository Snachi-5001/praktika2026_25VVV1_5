#define _CRT_SECURE_NO_WARNINGS
#include "file_io.h"
#include <stdio.h>
#include <stdlib.h>

int* load_file(const char* filename, int* size) // Молчанов: исправлена ошибка чтения CSV
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
	{
        printf("Ошибка открытия файла\n");
        return NULL;
    }

    int cnt = 0;
    int temp;
    // Читаем числа, игнорируя запятые
    while (fscanf(file, "%d", &temp) == 1)
	{
        cnt++;
        // Пропускаем запятую или символ новой строки
        int ch = fgetc(file);
        if (ch == EOF) break;
    }

    if (cnt == 0)
	{
        printf("Файл пуст\n");
        fclose(file);
        return NULL;
    }

    rewind(file);
    int* mass = (int*)malloc(cnt * sizeof(int));
    *size = cnt;

    for (int i = 0; i < cnt; i++)
	{
        fscanf(file, "%d", &mass[i]);
        fgetc(file); // пропускаем запятую
    }

    fclose(file);
    return mass;
}

void save_file(const char* filename, int* mass, int n)
{
    if (n == 0)
	{
        printf("Массив пуст\n");
        return;
    }

    FILE* file = fopen(filename, "w");
    if (file == NULL)
	{
        printf("Ошибка создания\n");
        return;
    }

    for (int i = 0; i < n; i++)
	{
        fprintf(file, "%d", mass[i]);
        if (i < n - 1)
		{
            fprintf(file, ",");
        }
    }

    fclose(file);
    printf("Сохранено в %s\n", filename);
}