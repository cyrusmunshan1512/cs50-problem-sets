#include <cs50.h>
#include <stdio.h>

float average(int scores[]);
const int N = 1;

int main(void)
{
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
        if (scores[i] < 0)
        {
            printf("Enter a valid score: https://chat.openai.com/c/369621f1-81dc-4d4a-bcdf-c3e580dc5ae2");
        }
    }

    printf("Your average is: %f\n" , average(scores));
}

float average(int scores[])
{
    int sum = 0;
    for(int i = 0; i < N; i++)
    {
        sum = sum + scores[i];
    }
    return sum/(float) N;
}