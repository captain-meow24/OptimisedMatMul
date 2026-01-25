# Optimised Matrix Multiplication

This project optimizes matrix multiplication in 3 different ways -

## 1. By changing how matrix b (of a*b) is accessed -
Traditionally, the elements of matrix B are accessed sequentially in a column but if we access it row-wise and keep the formula the same (C[i][j] += A[i][k] * B[k][i], we can access the memory sequentially and hence reduce cache misses.
## 2. By using SSE vector instructions -
They are 128 bits wide registers that can store upto 4 floats at a time and perform the same operation on them at the same time.
## 3. By using AVX vector instructions -
They are 256 bits wide and can store upto 8 floats at a time.

## Benchmarking
I benchmarked their effieciency using the time taken by each of them including the traditional matrix multiplication on 13th Gen Intel(R) Core(TM) i5-1335U, and these are the results -

```

Time taken for normal matrix multiplication - 534
Time taken when minimizing cache misses - 563
Time taken by using SSE registers - 171
Time taken by using AVX registers -  87

```




