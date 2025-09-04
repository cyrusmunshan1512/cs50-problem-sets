#include <stdio.h>
#include <cs50.h>
int main(void)
{
 //Prompting the user for name.

     string name = get_string("What is your name? ");

 //Printing the input name.

     printf("hello, %s\n", name);
}