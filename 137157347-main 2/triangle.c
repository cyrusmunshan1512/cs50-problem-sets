#include <cs50.h>
#include <stdio.h>

int main(void)
{
    side1 = get_int("Side a - ");
    side2 = get_int("Side b - ");
    if (side1 <= 0 || side2 <= 0)
    {
        printf("Invalid side length.");
    }
}
