#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int A, B, C;

int factorial(int A)
{
    int fact = 1;
    for(int i = 2; i <= A; i++)
    {
        fact = fact * i;
    }
    return fact;
}

void fibonacci(int B)
{
    int a = 0, b = 1, next;
    printf("Fibonacci sequence up to %d terms:\n", B);
    for (int i = 0; i < B; i++)
    {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

void check_prime(int C)
{
    if (C < 2)
    {
        printf("%d is not a prime number.\n", C);
        return;
    }
    for (int i = 2; i * i <= C; i++)
    {
        if (C % i == 0)
        {
            printf("%d is not a prime number.\n", C);
            return;
        }
    }
    printf("%d is a prime number.\n", C);
}

int main()
{
    printf("Enter A: ");
    scanf("%d", &A);
    printf("Enter B: ");
    scanf("%d", &B);
    printf("Enter C: ");
    scanf("%d", &C);

    pid_t pidA = fork();
    if (pidA == 0)
    {
        // Child A: factorial
        printf("Child A: Factorial of %d is %d\n", A, factorial(A));
        printf("Child A parent_ID: %d\n", getppid());
        return 0;
    }
    else
    {
        pid_t pidB = fork();
        if (pidB == 0)
        {
            // Child B: fibonacci
            printf("Child B: ");
            fibonacci(B);
            printf("Child B parent_ID: %d\n", getppid());
            return 0;
        }
        else
        {
            pid_t pidC = fork();
            if (pidC == 0)
            {
                // Child C: prime check
                printf("Child C: ");
                check_prime(C);
                printf("Child C parent_ID: %d\n", getppid());
                return 0;
            }
            else
            {
                // Parent waits for all children to finish
                wait(NULL);
                wait(NULL);
                wait(NULL);
            }
        }
    }

    return 0;
}