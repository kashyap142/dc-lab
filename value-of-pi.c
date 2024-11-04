#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

/**
 * value of pi = 4 * sum ((-1) ^ k / (2 * k + 1))
 * k -> 0 to infinity
 */

int main()
{
    int itr = 100, thread_cnt;
    double ans = 0;
    double start, end;

    printf("Enter numnber of iterations: ");
    scanf("%d", &itr);

    printf("Enter thread count: ");
    scanf("%d", &thread_cnt);

    start = omp_get_wtime();
    
    #pragma omp parallel for num_threads(thread_cnt) reduction(+:ans)

    for(int i = 0; i <= itr; ++i) {
        if(i & 1) { // (i % 2 == 1)
            ans -= 1.0 / (2 * i + 1);
        }
        else {
            ans += 1.0 / (2 * i + 1);
        }
    }

    end = omp_get_wtime();
    ans = 4 * ans;

    printf("Parallel:\n\tPI = %lf\n", ans);
    printf("\tTime taken: %lf\n", (double)end - start);
    
    // sequential
    ans = 0;
    start = omp_get_wtime();

    for(int i = 0; i <= itr; ++i) {
        if(i & 1) { // (i % 2 == 1)
            ans -= 1.0 / (2 * i + 1);
        }
        else {
            ans += 1.0 / (2 * i + 1);
        }
    }
    
    end = omp_get_wtime();
    ans = 4 * ans;

    printf("Sequential\n\tPI = %lf\n", ans);
    printf("\tTime taken: %lf\n", (double)end - start);
    
    return 0;
}