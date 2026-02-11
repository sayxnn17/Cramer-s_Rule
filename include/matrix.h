#ifndef MATRIX_H
#define MATRIX_H

// Function to dynamically allocate a square matrix of size n x n
double **allocateMat(int n);

// Function to copy one matrix (src) into another matrix (dest)
void copyMat(double **src, double **dest, int n);

// Function to replace a column col of matrix A with vector b
// Used in Cramer's Rule
void replaceCol(double **A, double *b, int col, int n);

// Function to free allocated matrix memory
void freeMat(double **A, int n);

#endif