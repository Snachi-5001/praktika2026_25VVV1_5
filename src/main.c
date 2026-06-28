#include <stdio.h>
#include <stdlib.h>
#include "file_io.h"
#include "sort.h"

int main()
{
    int n = 0;
    char fname[100];
    
    printf("Имя файла: ");
    scanf("%s", fname);
    
    int* mass = load_file(fname, &n);
    
    if (mass)
	{
        printf("Массив: ");
        for (int i = 0; i < n; i++) printf("%d ", mass[i]);
        printf("\n");
		
		shell_sort(mass, n);
		printf("После сортировки: ");
		for (int i = 0; i < n; i++)
        {
			printf("%d ", mass[i]);
		}
		printf("\n");
        
        printf("Имя файла для сохранения: ");
        scanf("%s", fname);
        save_file(fname, mass, n);
        
        free(mass);
    }
    
    return 0;
}