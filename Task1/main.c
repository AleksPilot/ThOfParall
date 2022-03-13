#include <stdio.h>
#include <math.h>
#include <malloc.h>
#define N 10000000

int main() {
    double * arr = (double*) malloc(N * sizeof (double));
    double summ = 0;
#pragma acc data copyin (arr) copyout (summ)
    {
#pragma acc kernels
        {
            for (long int i = 0; i < N; ++i) {
                arr[i] = sin((2 * M_PI) / N * i);
                summ += arr[i];
            }

        }

        printf("%e", summ);
        return 0;
    }
}
