#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    int num, sum = 0, fact = 1, i;
    printf("Enter the value of num : ");
    scanf("%d", &num);
    int n1 = fork();
    if (n1 > 0)
    {
        int n2 = fork();
        if (n2 == 0)
        {
            for (i = 1; i <= num; i++)
            {
                fact *= i;
            }
            printf("Factorial : %d\n", fact);
            printf("Done\n");
        }
        
    }
    else if (n1 == 0)
        {

            for (i = 1; i <= num; i++)
            {
                sum += i;
            }
            printf("Sum is : %d\n", sum);
            
        }

        return 0;
    }

