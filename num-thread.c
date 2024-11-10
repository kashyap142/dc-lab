#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    int n, i, t, itmes[8];

    printf("Enter number of items: ");
    scanf("%d", &n);

    for(i = 0; i < 8; i++) {
        itmes[i] = rand() % 1000;
    }

    #pragma omp parallel for schedule(static, 3)
    for(i = 0; i < n; i++) {
        t = omp_get_thread_num();
        printf("Thread %d, item: %d, value %d\n", t, i, itmes[t]);
    }

    return 0;
}