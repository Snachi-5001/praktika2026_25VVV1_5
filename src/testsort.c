#include <stdio.h>
#include "sort.h"

int main() {
    int a[] = {4, 2, 7, 1, 9, 3};
    int n = 6;

    printf("DO: ");
    for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
    printf("\n");

    shell_sort(a, n);

    printf("POSLE: ");
    for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
    printf("\n");

    return 0;
}