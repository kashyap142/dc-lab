#include <stdio.h>
#include <omp.h>
#include <math.h>
// #include <stdbool.h> // use if you want to return true/false in isPrime function

int isPrime(int n)
{
    if(n == 0 || n == 1)
        return 0;

    int root = sqrt(n);

    for(int i = 2; i <= root; ++i) {
        if(n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int n = 100;
    // printf("Enter n: ");
    // scanf("%d", &n);
    double start, end;

    // parallel
    start = omp_get_wtime();

    #pragma omp parallel for
    for(int i = 1; i <= n; ++i) {
        if(isPrime(i)) {
            int t = omp_get_thread_num();
            printf("Thread %d, number %d\n", t, i);
        }
    }

    end = omp_get_wtime();

    printf("Parallel execution, time: %lf\n", (end - start));

    // sequential
    start = omp_get_wtime();

    for(int i = 1; i <= n; ++i) {
        if(isPrime(i)) {
            int t = omp_get_thread_num();
            printf("Thread %d, number %d\n", t, i);
        }
    }

    end = omp_get_wtime();

    printf("Sequential execution, time: %lf\n", (end - start));

    return 0;
}