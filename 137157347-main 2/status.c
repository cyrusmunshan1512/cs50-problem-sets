#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing Command Line argument\n");
        return 1;
    }
    else
    {
        printf("hello,%s\n" , argv[1]);
        return 0;
    }

}