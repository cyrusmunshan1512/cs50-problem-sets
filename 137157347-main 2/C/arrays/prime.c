#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    for (int i = 2; i <= n; i++)
    {
        int j;
        for (j = 2; j <= sqrt(i); j++)
        {
            if (i%j == 0)
            {
                break;
            }
       }
        if (j > sqrt(i))
        {
            printf("%d\n" , i);
        }
    }
    return 0;
}
