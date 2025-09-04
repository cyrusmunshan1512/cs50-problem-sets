#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int a = get_int("a: ");
    int b = get_int("b: ");
    float z = (float)a / (float)b;
    printf("%f\n", z);
}