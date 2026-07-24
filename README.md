
# RMQ Algorithms in C++

This repository contains my C++ implementations of several algorithms for solving the Range Minimum Query (RMQ) problem.


The implementations and the accompanying report were developed as part of my Advanced Data Structures course.

## Time Complexity

| Algorithm           | Preprocessing | Query |
| ------------------- | ------------: | ----: |
| Naïve               |          O(1) |  O(n) |
| Dynamic Programming |         O(n²) |  O(1) |
| Block Decomposition |          O(n) | O(√n) |
| Sparse Table        |    O(n log n) |  O(1) |


## About RMQ

Range Minimum Query (RMQ) is the problem of finding the minimum element within a specified interval of an array. 
Different algorithms provide different trade-offs between preprocessing time, query time, and memory usage.

This repository presents several classical RMQ algorithms implemented in C++ for educational purposes.

## Repository Contents

- [Naïve Algorithm](RMQ_0_NaiveAlgorithm.cpp)
- [Dynamic Programming](RMQ_1_DynamicProgramming.cpp)
- [Block Decomposition](RMQ_2_BlockDecomposition.cpp)
- [Sparse Table](RMQ_3_SparseTable.cpp)
- [Project Report (PDF)](Report/Report_RMQ%201.pdf)

## Requirements

- C++11 or later
- GCC, Clang, or Microsoft Visual C++

## Compilation

Compile any source file using a C++ compiler.

### Linux / macOS

```bash
g++ RMQ_3_SparseTable.cpp -o RMQ
./RMQ
```

### Windows

```bash
g++ RMQ_3_SparseTable.cpp -o RMQ.exe
RMQ.exe
```

## Citation

If you use this repository in research, educational materials, or other projects, please cite or reference it as:

**Maryam Khasheie**  
*RMQ Algorithms in C++*  
GitHub Repository: https://github.com/MaryamKhasheie/RMQ-Algorithms
