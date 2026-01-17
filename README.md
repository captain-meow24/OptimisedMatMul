This is a simple project that optimizes matrix multiplication in 3 different ways-
1. By changing how matrix b (of a*b) is accessed- Usually it is accessed sequentially in a column but if we access it one element of a row and next and keep the formula the same (C[i][j] += A[i][k] * B[k][i], we can access the memory sequentially and hence reduce cache misses.
2. By using SSE vector instructions- They are 128 bits wide registers that can store upto 4 floar at a time and perform the same operation on them at the same timw.
3. By using AVX vector instructions- they are 256 bits wide and can store upto 8 floats at a time.

I benchmarked their effieciency using the time taken by each of them including the traditional matrix multiplication by the time taken by them.
