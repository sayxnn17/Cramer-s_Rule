
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // for fork()
#include <sys/wait.h>   // for wait()

#include "matrix.h"
#include "determinant.h"
#include "parallel.h"


// Function : solve_cramer_parallel
//
// Purpose  : Solve AX = B using Cramer's Rule
//            but in parallel using fork()

// Logic:
// 1.We will Compute det(A) once (parent process)
// 2. Create child processes
// 3. Each child computes one determinant det(Ai)
// 4. Parent waits for all children



void c_parallel(double **A,
                           double *b,
                           double *x,
                           int n)
{
    double **temp;

    // Step 1 →We will compute determinant of original matrix A
    
    temp = allocateMat(n);
    copyMat(A, temp, n);

    double detA = deter(temp, n);

    freeMat(temp, n);

    if (detA == 0)
    {
        printf("System has no unique solution.\n");
        return;
    }

    
    // Step 2 → Create child processes
 
    for (int i = 0; i < n; i++)
    {
        pid_t pid = fork();

        // Child process part
        if (pid == 0)
        {
            // Each child works on its own copy
            double **local = allocateMat(n);
            copyMat(A, local, n);

            // Replace column i with vector b
            replaceCol(local, b, i, n);

            // Compute determinant
            double detAi = deter(local, n);

            // Compute solution value
            x[i] = detAi / detA;

            freeMat(local, n);

            // Child exits after finishing work
            exit(0);
        }
    }

    // Step 3 → Parent waits for all children
   
    for (int i = 0; i < n; i++)
    {
        wait(NULL);
    }

  
    
}