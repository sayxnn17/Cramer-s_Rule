
#include <stdio.h>
#include <math.h>

#include "determinant.h"

// Function : deter
// Purpose  : Calculates determinant of a square matrix
// Method   : Gaussian Elimination
//
// Why this method?
// Because recursive determinant is very slow for n>1000 (gives time complexity of O(n!)).
// Gaussian elimination converts matrix to upper triangular form and multiplies diagonal elements.

double deter(double **A, int n)
{
    double det = 1.0;   // Final determinant value

    // Loop through each pivot row
    for (int i = 0; i < n; i++)
    {
        // If pivot element is zero → determinant becomes 0
        if (fabs(A[i][i]) < 0.000000001)
        {
            return 0;
        }

        // Eliminate elements below pivot
        for (int j = i + 1; j < n; j++)
        {
            double ratio = A[j][i] / A[i][i];

            // Row operation
            for (int k = 0; k < n; k++)
            {
                A[j][k] = A[j][k] - ratio * A[i][k];
            }
        }

        // Multiply pivot element to determinant
        det = det * A[i][i];
    }

    return det;
}