# FASTsolve – AI Generated Implementation

## Description

This folder contains the AI generated solution for the FASTsolve assignment.

The code was produced using an AI tool based on the problem statement given. The idea behind this is to compare the AI generated approach with the manually written implementation.

The program calculates the determinant of an n×n matrix and uses Cramer’s Rule to solve a system of linear equations. It also compares sequential execution with a parallel version created using multiple processes.

---

## Prompt Used

Below is the prompt that was used to generate the code:

"Write a C program to compute the determinant of a matrix and solve a system of linear equations using Cramer’s Rule. Use dynamic memory allocation for 2D and 1D arrays and populate the matrix with random values using srand()/random(). Create multiple child processes using fork() to parallelize determinant computations, compare it with sequential implementation, and measure execution time and speedup."

---

## Concepts Used

Some of the main concepts used in this AI code:

- fork() → for creating child processes  
- malloc(), free() → for dynamic memory allocation  
- Gaussian elimination → for determinant calculation  
- Cramer’s Rule → for solving linear equations  
- wait() → process synchronization  
- clock() / gettimeofday() → time measurement  
- rand(), srand() → random matrix generation  

---

## Difference from Man-made Code

Compared to the manual implementation, this version:

- Is more modular in structure  
- Has consistent formatting  
- Includes generalized functions  
- Uses process based parallelism  
- Measures execution time and speedup  

This helps in understanding how AI structures and optimizes code differently.

---

## Files Included

- fastsolve_ai.c → AI generated source code  
- ai_prompt.txt → prompt used to generate the code  

---

## Purpose

The purpose of submitting this AI implementation is to:

- Compare AI vs manual coding styles  
- Study optimization differences  
- Analyze parallel execution performance  
- Understand AI assisted development  

---

## Team Members

- **24CS8091** – Indrajit Mondal  
- **24CS8092** – Sayan Karmakar  
- **24CS8093** – Gudimetla Vikas  
- **24CS8094** – Sarthak Vats  
- **24CS8095** – Indrajit Bag  
- **24CS8096** – Diptanshu Kumar Shaw  
- **24CS8097** – Aryak Dey  
- **24CS8099** – Valuganti Susanth Kumar  
- **24CS8100** – Devineni Anudeep  



