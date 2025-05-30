/*write a c program to calculate the factorial of a given non-negative integer*/

#include <stdio.h>

// Function to calculate factorial
long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    int num;

    // Input from the user
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    // Check if the number is non-negative
    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        // Calculate and display the factorial
        printf("Factorial of %d is %lld\n", num, factorial(num));
    }

    return 0;
}




/*both method*/



int main() {
    int num;

     
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 0;
    }

     
    clock_t start_time = clock();   
    long long result_iterative = factorial_iterative(num);
    clock_t end_time = clock();   
    double time_iterative = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;   

     
    start_time = clock();   
    long long result_recursive = factorial_recursive(num);
    end_time = clock();   
    double time_recursive = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;   

     
    printf("\nFactorial of %d (Iterative) is: %lld\n", num, result_iterative);
    printf("Time taken (Iterative): %f seconds\n", time_iterative);

    printf("\nFactorial of %d (Recursive) is: %lld\n", num, result_recursive);
    printf("Time taken (Recursive): %f seconds\n", time_recursive);

     
    printf("\nTime Complexity (both methods): O(n)\n");
    printf("Space Complexity (Iterative): O(1)\n");
    printf("Space Complexity (Recursive): O(n) (due to function call stack)\n");

    return 0;
}