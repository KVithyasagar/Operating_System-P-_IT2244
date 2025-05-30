/* 8.write C program that takes a binary number (as an integer) as input and converts it to its decimal equivalent*/

#include <stdio.h>
#include <math.h>

int main() {
    int binary, decimal = 0, remainder, base = 1;

    // Accept binary input from the user
    printf("Enter a binary number: ");
    scanf("%d", &binary);

    // Convert binary to decimal
    while (binary > 0) {
        remainder = binary % 10;  // Get the last digit (0 or 1)
        decimal = decimal + remainder * base; // Add the appropriate power of 2
        binary = binary / 10;     // Remove the last digit
        base = base * 2;          // Move to the next power of 2
    }

    // Display the decimal result
    printf("The decimal equivalent is: %d\n", decimal);

    return 0;
}