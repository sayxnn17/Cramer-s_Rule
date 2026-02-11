#include <stdio.h>
#include <stdlib.h>

//including the header file matrix.h
#include "matrix.h" 


// Function: allocateMat
// Purpose : Dynamically allocates memory for an n x n
//           matrix in the heap 
// Returns : Pointer to the matrix

double **allocateMat(int n)
{
    // Allocating array of row pointers
    double **A = (double **)malloc(n * sizeof(double *));
    if (A == NULL) return NULL;

    // Allocating each row
    for (int i = 0; i < n; i++)
    {
        A[i] = (double *)malloc(n * sizeof(double));
        if (A[i] == NULL) return NULL;
    }

    return A;
}



// Function: copyMat
// Purpose : Copies contents of one matrix to another
//           Used when we need temporary matrices
// Returns : void

void copyMat(double **src, double **dest, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dest[i][j] = src[i][j];
        }
    }
}


// Function: replaceCol
// Purpose : Replaces elements of a specific column col of matrix A
//           with elements of vector b (Cramer's Rule)
// Returns : void

void replaceCol(double **A, double *b, int col, int n)
{
    for (int i = 0; i < n; i++)
    {
        A[i][col] = b[i];
    }
}


// Function: freeMat
// Purpose : Frees memory allocated to matrix
//           hence preventing memory leaks
// Returns : void

void freeMat(double **A, int n)
{
    // Freeing each row first
    for (int i = 0; i < n; i++)
    {
        free(A[i]);
    }

    // Then freeing the row pointer array
    free(A);
}
