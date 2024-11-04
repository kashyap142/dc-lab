#include <stdio.h>
#include <omp.h>
#include <time.h>

void merge(int arr[], int left, int mid, int right)
{
    int size = right - left + 1;
    int temp[size];

    int l = left, r = mid + 1, k = 0;
    int i;

    while(l <= mid && r <= right) {
        if(arr[l] < arr[r]) {
            temp[k] = arr[l];
            ++l;
        }
        else {
            temp[k] = arr[r];
            ++r;
        }
        ++k;
    }

    while(l <= mid) {
        temp[k] = arr[l];
        ++k, ++l;
    }

    while(r <= right) {
        temp[k] = arr[r];
        ++r, ++k;
    }

    for(i = 0; i < size; i++) {
        arr[left + i] = temp[i];
    }

    free(temp);
}

// sequential
void mergeSortSequential(int arr[], int left, int right)
{
    int mid;
    if(left < right) {
        mid = (left + right) / 2;

        mergeSortSequential(arr, left, mid);
        mergeSortSequential(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// parallel
void mergeSortParallel(int arr[], int left, int right)
{
    int mid;
    if(left < right) {
        mid = (left + right) / 2;

        #pragma omp parallel sections
        {
            #pragma omp section
            mergeSortParallel(arr, left, mid);

            #pragma omp section
            mergeSortParallel(arr, mid + 1, right);
        }
        merge(arr, left, mid, right);
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], copy_arr[n];

    for(int i = 0; i < n; ++i) {
        arr[i] = rand();
        copy_arr[i] = arr[i];
    }

    double start, end;

    // sequential
    start = omp_get_wtime();
    mergeSortSequential(arr, 0, n - 1);
    end = omp_get_wtime();

    printf("Sequential execution, time: %lf\n", (end - start));

    // parallel execution
    start = omp_get_wtime();
    #pragma omp parallel
    {
        #pragma omp single
        mergeSortParallel(copy_arr, 0, n - 1);
    }

    end = omp_get_wtime();

    printf("Parallel execution, time: %lf", (end - start));

    return 0;
}