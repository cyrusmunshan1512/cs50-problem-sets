#include <cs50.h>
#include <stdio.h>


int main(void)
{
  //Prompting the user for height input.
 int height;
  do
  {
    height = get_int("Height: ");
  }
  while (height < 1 || height > 8);

 // Making the formula to make basic pyramid.

for (int a = height; a > 0; a--)
{
 for (int i = 0; i < a; i++ )
 {
  printf(".");
 }

 for (int j = 0; j < (// i need some variable here whoch would trace along the no. of lin eta which i currently am.); j++)
 {
  printf("#");
 }
  printf("\n");
}


}