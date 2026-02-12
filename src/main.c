#define MAX_PROC 8 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Header files of our project modules
#include "matrix.h"
#include "cramer.h"
#include "parallel.h"

int main()
{
    int n;

    // Asking user for matrix size
    // For final assignment testing keep n > 1000
    printf("Enter the size of the matrix (n): ");
    scanf("%d", &n);

    // Seed for random number generation
    // So that every run gives different values
    srand(time(NULL));

    // Dynamically allocating memory for:
    // A → coefficient matrix
    // b → constant vector
    // x → solution vector

    double **A = allocateMat(n);
    double *b = (double *)malloc(n * sizeof(double));
    double *x = (double *)malloc(n * sizeof(double));

    // Filling matrix A and vector b with random values
    // Values kept small just for testing convenience
    for (int i = 0; i < n; i++)
    {
        b[i] = rand() % 10;   // constants

        for (int j = 0; j < n; j++)
        {
            A[i][j] = rand() % 10;   // coefficients
        }
    }

    ////////////////////////////////////////////////////////////
    // SEQUENTIAL EXECUTION
    ////////////////////////////////////////////////////////////

    printf("\nRunning Sequential Cramer's Rule...\n");

    // strt timer
    clock_t strt = clock();

    // Solve using sequential method
    c_sequential(A, b, x, n);

    // Stop timer
    clock_t end = clock();

    // Calculate time taken
    double seqTime =
        (double)(end - strt) / CLOCKS_PER_SEC;

    printf("Sequential Execution Time: %f seconds\n",
           seqTime);

    ////////////////////////////////////////////////////////////
    // PARALLEL EXECUTION
    ////////////////////////////////////////////////////////////

    printf("\nRunning Parallel Cramer's Rule using fork()...\n");

    // strt timer again
    strt = clock();

    // Solve using parallel method
    c_parallel(A, b, x, n);

    // Stop timer
    end = clock();

    // Calculate time taken
    double par_time =
        (double)(end - strt) / CLOCKS_PER_SEC;

    printf("Parallel Execution Time: %f seconds\n",
           par_time);

    ////////////////////////////////////////////////////////////
    // SPEEDUP CALCULATION
    ////////////////////////////////////////////////////////////

    if (par_time > 0)
    {
        double speedup = seqTime / par_time;

        printf("\nSpeedup Achieved: %f\n", speedup);
    }

    ////////////////////////////////////////////////////////////
    // FREEING ALLOCATED MEMORY
    ////////////////////////////////////////////////////////////

    // Always free dynamic memory to avoid memory leaks
    freeMat(A, n);
    free(b);
    free(x);

    printf("\nProgram Finished Successfully.\n");

    return 0;
}