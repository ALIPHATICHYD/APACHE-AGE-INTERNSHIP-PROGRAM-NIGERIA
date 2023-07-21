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
