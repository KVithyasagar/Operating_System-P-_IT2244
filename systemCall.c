#include <stdio.h>
#include <unistd.h>

int main()
{
    int f1 = fork(); // First fork

    if (f1 == 0)
    {
        // This is Child B
        printf("I am child B\n");
        printf("My parent ID is: %d\n", getppid());
    }
    else
    {
        int f2 = fork(); // Second fork

        if (f2 == 0)
        {
            // This is Child C (sibling of B)
            printf("I am child C\n");
            printf("My parent ID is: %d\n", getppid());
        }
        else
        {
            // This is the original parent
            printf("I am the parent\n");
            printf("My ID: %d\n", getpid());
            printf("My parent ID: %d\n", getppid());
        }
    }

    return 0;
}