/* ************************************************************************** */
/*                                                                            */
/* C05 QUICK REFERENCE - Most Common Exercises                               */
/* Study these if C05 topics appear in tomorrow's exam                       */
/*                                                                            */
/* ************************************************************************** */

/* ========================================================================== */
/* EX01: ft_recursive_factorial                                               */
/* ========================================================================== */

int ft_recursive_factorial(int nb)
{
    // Edge case: negative number
    if (nb < 0)
        return (0);
    
    // Base case: 0! = 1, 1! = 1
    if (nb == 0 || nb == 1)
        return (1);
    
    // Recursive case: n! = n * (n-1)!
    return (nb * ft_recursive_factorial(nb - 1));
}

/*
 * Examples:
 * ft_recursive_factorial(5) = 5 * 4 * 3 * 2 * 1 = 120
 * ft_recursive_factorial(0) = 1
 * ft_recursive_factorial(-5) = 0
 */

/* ========================================================================== */
/* EX00: ft_iterative_factorial (easier alternative)                          */
/* ========================================================================== */

int ft_iterative_factorial(int nb)
{
    int result;

    // Edge case: negative number
    if (nb < 0)
        return (0);
    
    // Base case
    if (nb == 0 || nb == 1)
        return (1);
    
    result = 1;
    // Multiply from 2 to nb
    while (nb > 1)
    {
        result *= nb;
        nb--;
    }
    return (result);
}

/* ========================================================================== */
/* EX03: ft_recursive_power                                                   */
/* ========================================================================== */

int ft_recursive_power(int nb, int power)
{
    // Edge case: negative power
    if (power < 0)
        return (0);
    
    // Base case: anything^0 = 1
    if (power == 0)
        return (1);
    
    // Recursive case: nb^power = nb * nb^(power-1)
    return (nb * ft_recursive_power(nb, power - 1));
}

/*
 * Examples:
 * ft_recursive_power(2, 3) = 2 * 2 * 2 = 8
 * ft_recursive_power(5, 0) = 1
 * ft_recursive_power(2, -1) = 0
 */

/* ========================================================================== */
/* EX02: ft_iterative_power (easier alternative)                              */
/* ========================================================================== */

int ft_iterative_power(int nb, int power)
{
    int result;

    // Edge case: negative power
    if (power < 0)
        return (0);
    
    // Base case
    if (power == 0)
        return (1);
    
    result = 1;
    // Multiply nb 'power' times
    while (power > 0)
    {
        result *= nb;
        power--;
    }
    return (result);
}

/* ========================================================================== */
/* EX04: ft_fibonacci                                                         */
/* ========================================================================== */

int ft_fibonacci(int index)
{
    // Edge case: negative index
    if (index < 0)
        return (-1);
    
    // Base cases
    if (index == 0)
        return (0);
    if (index == 1)
        return (1);
    
    // Recursive case: fib(n) = fib(n-1) + fib(n-2)
    return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

/*
 * Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34...
 * 
 * Examples:
 * ft_fibonacci(0) = 0
 * ft_fibonacci(1) = 1
 * ft_fibonacci(5) = 5
 * ft_fibonacci(10) = 55
 */

/* ========================================================================== */
/* EX05: ft_sqrt (might appear)                                               */
/* ========================================================================== */

int ft_sqrt(int nb)
{
    long i;
    long target;

    // Negative numbers don't have real square roots
    if (nb < 0)
        return (0);
    
    // 0 and 1 are their own square roots
    if (nb == 0 || nb == 1)
        return (nb);
    
    i = 1;
    target = (long)nb;
    
    // Find i where i^2 = nb
    while (i * i <= target)
    {
        if (i * i == target)
            return (i);
        i++;
    }
    
    // No perfect square root
    return (0);
}

/*
 * Examples:
 * ft_sqrt(9) = 3
 * ft_sqrt(16) = 4
 * ft_sqrt(10) = 0 (not a perfect square)
 */

/* ========================================================================== */
/* EX06: ft_is_prime (might appear)                                           */
/* ========================================================================== */

int ft_is_prime(int nb)
{
    int i;

    // Numbers <= 1 are not prime
    if (nb <= 1)
        return (0);
    
    // 2 and 3 are prime
    if (nb == 2 || nb == 3)
        return (1);
    
    // Even numbers (except 2) are not prime
    if (nb % 2 == 0)
        return (0);
    
    // Check divisors from 3 to sqrt(nb)
    i = 3;
    while (i * i <= nb)
    {
        if (nb % i == 0)
            return (0);  // Found a divisor, not prime
        i += 2;  // Only check odd numbers
    }
    
    return (1);  // No divisors found, is prime
}

/*
 * Prime numbers: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29...
 * 
 * Examples:
 * ft_is_prime(7) = 1 (true)
 * ft_is_prime(10) = 0 (false)
 * ft_is_prime(1) = 0 (false)
 */

/* ========================================================================== */
/* RECURSION PATTERNS - MEMORIZE THESE                                       */
/* ========================================================================== */

/*
 * Pattern 1: COUNTDOWN
 * Base case: n == 0 or n == 1
 * Recursive: func(n-1)
 * 
 * Example: factorial, power
 */

/*
 * Pattern 2: DOUBLE RECURSION
 * Base case: n <= 1
 * Recursive: func(n-1) + func(n-2)
 * 
 * Example: fibonacci
 */

/*
 * Pattern 3: DIVIDE AND CONQUER
 * Base case: simple case
 * Recursive: split problem in half
 * 
 * Example: binary search (advanced)
 */

/* ========================================================================== */
/* COMMON MISTAKES TO AVOID                                                  */
/* ========================================================================== */

/*
 * 1. Missing base case
 *    → Infinite recursion → Stack overflow
 * 
 * 2. Wrong return for edge cases
 *    factorial(-5) should return 0, not crash
 * 
 * 3. Not handling 0
 *    0! = 1 (not 0!)
 *    n^0 = 1 (not 0!)
 * 
 * 4. Integer overflow
 *    Use long for large calculations
 *    factorial(20) already overflows int
 * 
 * 5. Forgetting function prototype
 *    If using helper function, declare it first
 */

/* ========================================================================== */
/* TESTING YOUR RECURSION FUNCTIONS                                          */
/* ========================================================================== */

#include <stdio.h>  // Only for testing, remove in exam!

int main(void)
{
    // Test factorial
    printf("Factorial tests:\n");
    printf("5! = %d (expected: 120)\n", ft_recursive_factorial(5));
    printf("0! = %d (expected: 1)\n", ft_recursive_factorial(0));
    printf("-5! = %d (expected: 0)\n", ft_recursive_factorial(-5));
    
    // Test power
    printf("\nPower tests:\n");
    printf("2^3 = %d (expected: 8)\n", ft_recursive_power(2, 3));
    printf("5^0 = %d (expected: 1)\n", ft_recursive_power(5, 0));
    printf("2^-1 = %d (expected: 0)\n", ft_recursive_power(2, -1));
    
    // Test fibonacci
    printf("\nFibonacci tests:\n");
    printf("fib(0) = %d (expected: 0)\n", ft_fibonacci(0));
    printf("fib(5) = %d (expected: 5)\n", ft_fibonacci(5));
    printf("fib(10) = %d (expected: 55)\n", ft_fibonacci(10));
    
    return (0);
}

/*
 * Compile and test:
 * gcc -Wall -Wextra -Werror c05_cheatsheet.c -o test
 * ./test
 */

/* ========================================================================== */
/* EXAM TIPS FOR RECURSION                                                   */
/* ========================================================================== */

/*
 * 1. ALWAYS handle edge cases first:
 *    - Negative numbers
 *    - Zero
 *    - The subject might specify these!
 * 
 * 2. Write base case BEFORE recursive case
 *    - Think: "When should recursion stop?"
 *    - This prevents infinite loops
 * 
 * 3. Trace execution on paper:
 *    factorial(3) = 3 * factorial(2)
 *                 = 3 * 2 * factorial(1)
 *                 = 3 * 2 * 1
 *                 = 6
 * 
 * 4. If stuck, write iterative version first!
 *    - Easier to think through
 *    - Then convert to recursion
 * 
 * 5. Test with small numbers (0, 1, 2, 3)
 *    - Easy to verify by hand
 *    - Catch base case errors
 * 
 * 6. Remember: Recursion is just a function calling itself
 *    - Not magic!
 *    - Must have stopping point (base case)
 *    - Must progress toward base case
 */
