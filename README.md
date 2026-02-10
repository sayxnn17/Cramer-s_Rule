<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>FASTsolve - CSC452 Project 2</title>
    <style>
        body {
            font-family: "Times New Roman", serif;
            margin: 40px;
            line-height: 1.5;
        }
        .container {
            max-width: 800px;
            margin: 0 auto;
        }
        .header {
            text-align: center;
            margin-bottom: 30px;
        }
        .header img {
            width: 120px;
            height: auto;
            margin-bottom: 10px;
        }
        .title {
            font-size: 24px;
            font-weight: bold;
            text-transform: uppercase;
        }
        .subtitle {
            font-size: 18px;
            margin-top: 5px;
        }
        .section-title {
            font-size: 18px;
            font-weight: bold;
            margin-top: 25px;
            margin-bottom: 5px;
        }
        .section-subtitle {
            font-weight: bold;
            margin-top: 15px;
            margin-bottom: 5px;
        }
        p {
            text-align: justify;
            margin: 5px 0;
        }
        .file-block-title {
            font-weight: bold;
            margin-top: 15px;
        }
        .file-block-text {
            margin-left: 15px;
        }
        .team-section {
            margin-top: 25px;
        }
        .team-title {
            font-weight: bold;
            margin-bottom: 5px;
        }
        .team-list {
            margin: 0;
            padding-left: 20px;
        }
        .team-list li {
            margin: 2px 0;
        }
    </style>
</head>
<body>
<div class="container">
    <!-- Header with sample image -->
    <div class="header">
        <img src="sample-image.png" alt="Institute Logo">
        <div class="title">FASTsolve</div>
        <div class="subtitle">Operating Systems Laboratory (CSC452) Project – 2</div>
    </div>

    <!-- Topic -->
    <div>
        <div class="section-title">Topic:</div>
        <p>Write a code that computes the determinant of a matrix. Find solutions to a system of linear equations using determinants via Cramer's Rule. Try it where the number of equations is greater than 1000.</p>
    </div>

    <!-- Process -->
    <div>
        <div class="section-title">Process:</div>
        <p>Cramer’s Rule is a method to solve a system of <i>n</i> linear equations with <i>n</i> variables using determinants. It applies only when the coefficient matrix has a non-zero determinant. Each variable is found by replacing its column in the coefficient matrix with the constants column, then dividing the determinant of this new matrix by the determinant of the original coefficient matrix.</p>
        <p>This project is a structured C-based implementation for solving a system of linear equations using Cramer’s Rule, with a strong emphasis on modularity, clarity, and computational efficiency. The program represents matrices using dynamically allocated data structures and clearly separates responsibilities across multiple source and header files.</p>
        <p>At its core, the project computes the determinant of a square matrix, which is essential for applying Cramer’s Rule. The determinant logic is implemented independently, allowing reuse and easier verification. Matrix-related operations such as creation, copying, column replacement, and memory management are encapsulated in a dedicated matrix module, improving maintainability and abstraction.</p>
        <p>The Cramer’s Rule module constructs modified matrices by replacing individual columns of the coefficient matrix with the constants vector and computes the corresponding determinants to obtain each variable’s value. Additionally, a parallel computation module is included to optimize determinant calculation for larger matrices, demonstrating awareness of performance considerations.</p>
        <p>Overall, the project showcases good software engineering practices in C, combining mathematical correctness with modular design and optional parallelism.</p>
    </div>

    <!-- Files description -->
    <div>
        <div class="section-title">Source Files Overview</div>

        <div class="file-block-title">main.c</div>
        <div class="file-block-text">
            <p>Acts as the entry point of the program. It coordinates the overall flow: reads input (matrix size, coefficients, constants), invokes determinant and Cramer’s Rule functions, and displays the final solution. It does not implement core logic itself, only orchestrates modules.</p>
        </div>

        <div class="file-block-title">matrix.c</div>
        <div class="file-block-text">
            <p>Implements matrix-related operations. This includes dynamic allocation and deallocation of matrices, copying matrices, replacing a column with another vector, and basic matrix handling utilities required by determinant and Cramer’s Rule computations.</p>
        </div>

        <div class="file-block-title">matrix.h</div>
        <div class="file-block-text">
            <p>Declares the matrix data structures and function prototypes used across the project. It provides a clean interface so other modules can manipulate matrices without knowing implementation details.</p>
        </div>

        <div class="file-block-title">determinant.c</div>
        <div class="file-block-text">
            <p>Contains the determinant computation logic. Implements determinant calculation (typically recursive expansion by minors or similar), which is the mathematical core required for applying Cramer’s Rule.</p>
        </div>

        <div class="file-block-title">determinant.h</div>
        <div class="file-block-text">
            <p>Exposes the determinant function declarations. Allows other modules (especially the Cramer’s Rule module) to compute determinants without direct coupling to the implementation.</p>
        </div>

        <div class="file-block-title">cramer.c</div>
        <div class="file-block-text">
            <p>Implements Cramer’s Rule itself. For each variable, it constructs a modified matrix by replacing one column with the constants vector, computes its determinant, and divides by the determinant of the original coefficient matrix to obtain the solution.</p>
        </div>

        <div class="file-block-title">cramer.h</div>
        <div class="file-block-text">
            <p>Declares the Cramer’s Rule–related functions. Serves as the interface between <i>main.c</i> and the mathematical logic used to solve the system.</p>
        </div>

        <div class="file-block-title">parallel.c</div>
        <div class="file-block-text">
            <p>Provides a parallelized version of determinant computation. Uses concurrency (e.g., threads) to speed up determinant calculation for larger matrices, improving performance compared to the purely sequential approach.</p>
        </div>

        <div class="file-block-title">parallel.h</div>
        <div class="file-block-text">
            <p>Declares the parallel computation interfaces. Allows the main program or determinant module to optionally use parallel execution without changing core logic.</p>
        </div>
    </div>

    <!-- Team members (simple list) -->
    <div class="team-section">
        <div class="team-title">Team Members:</div>
        <ul class="team-list">
            <li>24CS8091 – Indrajit Mondal</li>
            <li>24CS8092 – Sayan Karmakar</li>
            <li>24CS8093 – Gudimetla Vikas</li>
            <li>24CS8094 – Sarthak Vats</li>
            <li>24CS8095 – Indrajit Bag</li>
            <li>24CS8096 – Diptanshu Kumar Shaw</li>
            <li>24CS8097 – Aryak Dey</li>
            <li>24CS8099 – Valuganti Susanth Kumar</li>
            <li>24CS8100 – Devineni Anudeep</li>
        </ul>
    </div>
</div>
</body>
</html>
