/*C program to generate Pascal's triangle.*/

#include <stdio.h>

int main() {
    int rows;

    // Accept the number of rows from the user
    printf("Enter the number of rows for Pascal's triangle: ");
    scanf("%d", &rows);

    // Generate Pascal's Triangle
    for (int i = 0; i < rows; i++) {
        // Print spaces for formatting the triangle shape
        for (int j = 0; j < rows - i - 1; j++) {
            printf(" ");
        }

        // Print the numbers for the current row
        int value = 1;  // First element of every row is 1
        for (int j = 0; j <= i; j++) {
            printf("%d ", value);  // Print the current value

            // Update the value for the next position in the row
            value = value * (i - j) / (j + 1);
        }

        // Move to the next line for the next row
        printf("\n");
    }

    return 0;
}