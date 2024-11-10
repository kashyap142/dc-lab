#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int addVectors(int v1[], int v2[], int res[], int n)
{
    int opsCnt = 0;

    #pragma omp parallel for
    for(int i = 0; i < n; i++) {
        res[i] = v1[i] + v2[i];
        #pragma omp critical
        {
            opsCnt++;
        }
    }

    return opsCnt;
}

int main()
{
    int n;
    printf("Enter value of n: ");
    scanf("%d", &n);

    int v1[n], v2[n], res[n];

    for(int i = 0; i < n; i++) {
        v1[i] = rand() % 100;
        v2[i] = rand() % 1000;
    }

    int opsCnt = addVectors(v1, v2, res, n);

    printf("Number of operations: %d", opsCnt);

    return 0;
}