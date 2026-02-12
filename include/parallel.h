#ifndef PARALLEL_H
#define PARALLEL_H

// Function to solve system of equations
// using Cramer's Rule in parallel (fork-based)
void c_parallel(double **A,
                           double *b,
                           double *x,
                           int n);

#endif 

