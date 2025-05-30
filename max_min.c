/*9.Write a C program that:
	Accepts an array of integers from the user
	finds and displays the maximum and minimum values in the array*/
	
#include <stdio.h>

int main() {
    int n;

    // Accept the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n]; // Declare the array of size n

    // Accept array elements from the user
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize max and min with the first element
    int max = arr[0];
    int min = arr[0];

    // Find the maximum and minimum values
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i]; // Update max
        }
        if (arr[i] < min) {
            min = arr[i]; // Update min
        }
    }

    // Display the maximum and minimum values
    printf("Maximum value in the array: %d\n", max);
    printf("Minimum value in the array: %d\n", min);

    return 0;
}