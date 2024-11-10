#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    int n, i;
    int sum = 0;

    printf("Enter value of n: ");
    scanf("%d", &n);

    #pragma omp parallel for
    for(i = 1; i <= n; i++) {
        #pragma omp critical
        sum += i;
    }

    printf("Sum of first %d natural numbers: %d\n", n, sum);

    return 0;
}
