#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "determinant.h"
#include "cramer.h"


// Function : c_sequential
//LOGIC 

void c_sequential(double **A, double *b, double *x, int n)
{
   
    double **temp;
  
    // Step 1 → Find determinant of original matrix A
    
    temp = allocateMat(n);
    copyMat(A, temp, n);

    double detA = deter(temp, n);

    freeMat(temp, n);

    if (detA == 0)
    {
        printf("System has no unique solution\n");
        return;
    }

    
    // Step 2 → Calculate each variable using Cramer's Rule
   
    for (int i = 0; i < n; i++)
    {
        
        temp = allocateMat(n);
        copyMat(A, temp, n);

        replaceCol(temp, b, i, n);

        double detAi = deter(temp, n);

        x[i] = detAi / detA;

        freeMat(temp, n);
    }

   
    if (n <= 10)  
    {
        printf("\nSolution Vector:\n");

        for (int i = 0; i < n; i++)
        {
            printf("x[%d] = %lf\n", i, x[i]);
        }
    }
}
