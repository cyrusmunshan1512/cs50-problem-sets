#include <stdio.h>
#include <cs50.h>

int main(void)
{
     string name = get_string("Whats your name? ");
     int age = get_int("Whats your age? ");
     string number = get_string("Whats your phone number? ");

     printf("Name is %s. Age is %i. Phone number is %s." , name , age ,  number);
     printf("\n");
}
