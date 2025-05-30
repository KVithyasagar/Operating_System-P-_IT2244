/*write a c program to generate and print fibonacci series up to a specified number of terms. The program should take the number of terms as input from the user and then display the corresponding fobonacci sequence*/


#include <stdio.h>

int main() {
    int terms, first = 0, second = 1, next;

     
    printf("Enter the number of terms for the Fibonacci series: ");
    scanf("%d", &terms);

     
    if (terms <= 0) {
        printf("Please enter a positive integer for the number of terms.\n");
        return 1;
    }

    printf("Fibonacci Series up to %d terms: \n", terms);

     
    if (terms >= 1) {
        printf("%d ", first);
    }
    if (terms >= 2) {
        printf("%d ", second);
    }

     
    for (int i = 3; i <= terms; i++) {
        next = first + second;
        printf("%d ", next);
        first = second;
        second = next;
    }

    printf("\n");   

    return 0;
}


/*both*/
#include <stdio.h>
#include <time.h>

// Iterative function to print Fibonacci series
void fibonacci_iterative(int n) {
    long long first = 0, second = 1, next;

    if (n >= 1) printf("Fibonacci Series (Iterative): %lld ", first);
    if (n >= 2) printf("%lld ", second);

    for (int i = 3; i <= n; i++) {
        next = first + second;
        printf("%lld ", next);
        first = second;
        second = next;
    }
    printf("\n");
}

// Recursive function to print Fibonacci series
void fibonacci_recursive(int n) {
    printf("Fibonacci Series (Recursive): ");
    for (int i = 0; i < n; i++) {
        printf("%lld ", fibonacci_recursive_helper(i));
    }
    printf("\n");
}

// Helper function for recursive Fibonacci calculation
long long fibonacci_recursive_helper(int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fibonacci_recursive_helper(n - 1) + fibonacci_recursive_helper(n - 2);
}

int main() {
    int num;

    // Input from the user
    printf("Enter the number of terms for Fibonacci series: ");
    scanf("%d", &num);

    // Input validation
    if (num <= 0) {
        printf("Please enter a positive integer.\n");
        return 0;
    }

    // Time measurement for Iterative approach
    clock_t start_time = clock();
    fibonacci_iterative(num);
    clock_t end_time = clock();
    double time_iterative = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    // Time measurement for Recursive approach
    start_time = clock();
    fibonacci_recursive(num);
    end_time = clock();
    double time_recursive = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    // Display the execution time for both methods
    printf("\nTime taken for Iterative approach: %f seconds\n", time_iterative);
    printf("Time taken for Recursive approach: %f seconds\n", time_recursive);

    // Time complexity explanation
    printf("\nTime Complexity (Iterative): O(n)\n");
    printf("Time Complexity (Recursive): O(2^n) (due to repeated function calls)\n");
    printf("Space Complexity (Iterative): O(1)\n");
    printf("Space Complexity (Recursive): O(n) (due to recursion call stack)\n");

    return 0;
}
