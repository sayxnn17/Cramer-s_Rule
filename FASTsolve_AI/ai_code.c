/********************************************************************
 * Parallel Cramer's Rule Solver
 * ---------------------------------------------------------------
 * Computes determinant using Gaussian Elimination and solves
 * Ax = b using Cramer's Rule.
 *
 * Includes:
 *  • Sequential implementation
 *  • Parallel version using fork()
 *  • Execution time comparison
 ********************************************************************/

#define MAX_PROC 8

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

#define EPS 1e-9   // Tolerance for zero pivot checking

/* ============================================================
   MATRIX MEMORY UTILITIES
   ============================================================ */

// Dynamically allocate an n×n matrix
double **allocate_matrix(int n)
{
    double **A = (double **)malloc(n * sizeof(double *));
    if (!A)
    {
        perror("Allocation failed");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        A[i] = (double *)malloc(n * sizeof(double));
        if (!A[i])
        {
            perror("Row allocation failed");
            exit(1);
        }
    }

    return A;
}

// Free matrix memory
void free_matrix(double **A, int n)
{
    for (int i = 0; i < n; i++)
        free(A[i]);

    free(A);
}

// Copy one matrix into another
void copy_matrix(double **src, double **dest, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dest[i][j] = src[i][j];
}

// Replace a column with vector b (used in Cramer’s Rule)
void replace_column(double **A, double *b, int col, int n)
{
    for (int i = 0; i < n; i++)
        A[i][col] = b[i];
}

/* ============================================================
   DETERMINANT USING GAUSSIAN ELIMINATION
   ============================================================ */

double determinant(double **A, int n)
{
    double det = 1.0;

    for (int i = 0; i < n; i++)
    {
        // If pivot is zero → determinant is zero
        if (fabs(A[i][i]) < EPS)
            return 0.0;

        // Eliminate entries below pivot
        for (int j = i + 1; j < n; j++)
        {
            double ratio = A[j][i] / A[i][i];

            for (int k = 0; k < n; k++)
                A[j][k] -= ratio * A[i][k];
        }

        det *= A[i][i];
    }

    return det;
}

/* ============================================================
   SEQUENTIAL CRAMER'S RULE
   ============================================================ */

void solve_sequential(double **A, double *b, double *x, int n)
{
    double **temp = allocate_matrix(n);
    copy_matrix(A, temp, n);

    double detA = determinant(temp, n);
    free_matrix(temp, n);

    if (fabs(detA) < EPS)
    {
        printf("No unique solution exists.\n");
        return;
    }

    // Compute each variable
    for (int i = 0; i < n; i++)
    {
        temp = allocate_matrix(n);
        copy_matrix(A, temp, n);

        replace_column(temp, b, i, n);

        double detAi = determinant(temp, n);
        x[i] = detAi / detA;

        free_matrix(temp, n);
    }
}

/* ============================================================
   PARALLEL CRAMER'S RULE USING fork()
   Each child computes one determinant
   ============================================================ */

void solve_parallel(double **A, double *b, double *x, int n)
{
    double **temp = allocate_matrix(n);
    copy_matrix(A, temp, n);

    double detA = determinant(temp, n);
    free_matrix(temp, n);

    if (fabs(detA) < EPS)
    {
        printf("No unique solution exists.\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        pid_t pid = fork();

        if (pid == 0)   // Child process
        {
            double **local = allocate_matrix(n);
            copy_matrix(A, local, n);

            replace_column(local, b, i, n);

            double detAi = determinant(local, n);
            x[i] = detAi / detA;

            free_matrix(local, n);
            exit(0);
        }
    }

    // Parent waits for all children
    for (int i = 0; i < n; i++)
        wait(NULL);
}

/* ============================================================
   MAIN DRIVER
   ============================================================ */

int main()
{
    int n;

    printf("Enter matrix size (n): ");
    scanf("%d", &n);

    srand(time(NULL));

    // Allocate system
    double **A = allocate_matrix(n);
    double *b = (double *)malloc(n * sizeof(double));
    double *x = (double *)malloc(n * sizeof(double));

    // Populate with random values
    for (int i = 0; i < n; i++)
    {
        b[i] = rand() % 10;

        for (int j = 0; j < n; j++)
            A[i][j] = rand() % 10;
    }

    /* -------- Sequential Run -------- */
    clock_t start = clock();
    solve_sequential(A, b, x, n);
    clock_t end = clock();

    double seq_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nSequential Time: %f sec\n", seq_time);

    /* -------- Parallel Run -------- */
    start = clock();
    solve_parallel(A, b, x, n);
    end = clock();

    double par_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Parallel Time: %f sec\n", par_time);

    if (par_time > 0)
        printf("Speedup: %fx\n", seq_time / par_time);

    // Cleanup
    free_matrix(A, n);
    free(b);
    free(x);

    return 0;
}

