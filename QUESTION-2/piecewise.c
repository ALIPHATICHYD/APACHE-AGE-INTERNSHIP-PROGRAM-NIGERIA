#include <stdio.h>

// Approach 1: Recursive function
int recursiveFib(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    return recursiveFib(n - 3) + recursiveFib(n - 2);
}

// Approach 2: Dynamic Programming (Memoization) function
int memoizedFib(int n, int* memo) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (memo[n] != -1)
        return memo[n];
    memo[n] = memoizedFib(n - 3, memo) + memoizedFib(n - 2, memo);
    return memo[n];
}


// Approach 3: Iterative function
int iterativeFib(int n) {
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    fib[2] = 2;
    for (int i = 3; i <= n; i++) {
        fib[i] = fib[i - 3] + fib[i - 2];
    }
    return fib[n];
}

int main() {
    int n = 10; // You can change n to test with different values

    // Approach 1: Recursive
    printf("Recursive: F(%d) = %d\n", n, recursiveFib(n));

    // Approach 2: Dynamic Programming (Memoization)
    int memo[n + 1];
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }
    printf("Memoized: F(%d) = %d\n", n, memoizedFib(n, memo));

    // Approach 3: Iterative
    printf("Iterative: F(%d) = %d\n", n, iterativeFib(n));

    return 0;
}