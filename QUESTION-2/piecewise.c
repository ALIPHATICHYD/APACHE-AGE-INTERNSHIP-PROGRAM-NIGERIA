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