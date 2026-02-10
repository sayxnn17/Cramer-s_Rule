<p align="center">
  <img src="assets/logo.png" width="120" alt="Institute Logo">
</p>

# FASTsolve  
## Operating Systems Laboratory (CSC452) – Project 2

---

## Topic

Write a program that computes the **determinant of a matrix** and finds solutions to a system of linear equations using **Cramer’s Rule**. The implementation should be scalable and tested for cases where the number of equations exceeds **1000**.

---

## Process

Cramer’s Rule is a method to solve a system of *n* linear equations with *n* variables using determinants. It is applicable only when the determinant of the coefficient matrix is non-zero. Each variable is computed by replacing its corresponding column in the coefficient matrix with the constants column and dividing the determinant of the resulting matrix by the determinant of the original matrix.

This project is a structured **C-based implementation** for solving systems of linear equations using Cramer’s Rule, with strong emphasis on **modularity, clarity, and computational efficiency**. The program uses dynamically allocated matrices and separates responsibilities across multiple source and header files.

At its core, the project focuses on computing the **determinant of a square matrix**, which is fundamental to applying Cramer’s Rule. Determinant computation is implemented independently to allow reuse and easier validation. Matrix operations such as creation, copying, column replacement, and memory management are encapsulated within a dedicated matrix module.

The Cramer’s Rule module constructs modified matrices for each variable by replacing individual columns with the constants vector and computes their determinants to obtain the solution. Additionally, a **parallel computation module** is included to optimize determinant calculation for large matrices, demonstrating awareness of performance and scalability concerns.

Overall, the project demonstrates good software engineering practices in C, combining mathematical correctness with clean modular design and optional parallelism.

---

## Source Files Overview

### `main.c`
Acts as the **entry point** of the program. It handles input, coordinates execution, invokes determinant and Cramer’s Rule functions, and displays results. Core logic is delegated to other modules.

### `matrix.c`
Implements **matrix-related operations**, including dynamic memory allocation/deallocation, matrix copying, column replacement, and utility functions required by determinant and Cramer’s Rule computations.

### `matrix.h`
Declares **matrix data structures and function prototypes**, providing a clean abstraction layer for matrix operations across the project.

### `determinant.c`
Contains the **determinant computation logic**, typically implemented using recursive expansion or similar methods. This module forms the mathematical backbone of the project.

### `determinant.h`
Exposes determinant-related **function declarations**, allowing other modules to compute determinants without depending on implementation details.

### `cramer.c`
Implements **Cramer’s Rule**. For each variable, it constructs a modified matrix by replacing a column with the constants vector, computes its determinant, and divides it by the determinant of the coefficient matrix.

### `cramer.h`
Declares **Cramer’s Rule interfaces**, enabling interaction between `main.c` and the solving logic.

### `parallel.c`
Provides a **parallelized determinant computation** mechanism using concurrency (e.g., threads) to improve performance for large matrices.

### `parallel.h`
Declares **parallel computation interfaces**, allowing optional parallel execution without altering the main logic.

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
