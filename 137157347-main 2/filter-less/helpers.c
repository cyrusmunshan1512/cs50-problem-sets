#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = (int)((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int newred, newgreen , newblue;
    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            newred = (int)((image[k][l].rgbtRed * 0.393) + (image[k][l].rgbtGreen * 0.769) + (image[k][l].rgbtBlue * 0.189));
            newgreen = (int)((image[k][l].rgbtRed * 0.349) + (image[k][l].rgbtGreen * 0.686) + (image[k][l].rgbtBlue * 0.168));
            newblue = (int)((image[k][l].rgbtRed * 0.272) + (image[k][l].rgbtGreen * 0.534) + (image[k][l].rgbtBlue * 0.131));


                image[k][l].rgbtRed = cap_value(newred);
                image[k][l].rgbtGreen = cap_value(newgreen);
                image[k][l].rgbtBlue = cap_value(newblue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    if (width % 2 == 0)
    {
        for (int a = 0; a < height; a++)
        {
            for (int b = 0; b <= width/2; b++)
            {
                swap(&image[a][b].rgbtRed , &image[a][width - b].rgbtRed);
                swap(&image[a][b].rgbtGreen , &image[a][width - b].rgbtGreen);
                swap(&image[a][b].rgbtBlue , &image[a][width - b].rgbtBlue);
            }
        }
    }
    else
    {
        for (int c = 0; c < height; c++)
        {
            for (int d = width; d <= (width+1)/2; d++)
            {
                swap(&image[c][d].rgbtRed , &image[c][width -d].rgbtRed);
                swap(&image[c][d].rgbtGreen , &image[c][width -d].rgbtGreen);
                swap(&image[c][d].rgbtBlue , &image[c][width - d].rgbtBlue);
            }
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])

{
    int sum1, sum2, sum3 = 0;
    for (int i = 1; i < height-1; i++)
    {
        for (int j = 1; j < width -1; j++)
        {
            for (int a = i-1; a <= i+1; a++)
            {
                for(int b = j-1; b <= j+1; b++)
                {
                      sum1 += image[a][b].rgbtRed;
                      sum2 += image[a][b].rgbtGreen;
                      sum3 += image[a][b].rgbtBlue;
                }
            }
        }
    }
    for (int i = 1 ; i <= height - 1; i++)
    {
        for(int j = 0)
        {
            for (int a = i-1; a <= i+1; a++)
            {
                for (int b = j; b <= j+1; b++)
                {
                    sum4 = image[a][b].rgbtRed;
                    sum5 = image[a][b].rgbtGreen;
                    sum6 = image[a][b].rgbtBlue;
                }
            }
        }
    }

    for (int i = 1 ; i <= height - 1; i++)
    {
        for(int j = width -1)
        {
            for (int a = i-1; a <= i+1; a++)
            {
                for (int b = j-1; b <= j; b++)
                {
                    sum7 = image[a][b].rgbtRed;
                    sum8 = image[a][b].rgbtGreen;
                    sum9 = image[a][b].rgbtBlue;
                }
            }
        }
    }

    for (int i = 0)
        {
            for(int j = 1; j < width -1; j++)
            {
                for (int a = i; a <= i+1; a++)
                {
                    for (int b = j-1; b <= j + 1; b++)
                    {
                        sum10 = image[a][b].rgbtRed;
                        sum11 = image[a][b].rgbtGreen;
                        sum12 = image[a][b].rgbtBlue;
                    }
                }
            }
        }

        for (int i = height-1)
        {
            for(int j = 1; j <= width -1; j++)
            {
                for (int a = i; a <= i+1; a++)
                {
                    for (int b = j-1; b <= j + 1; b++)
                    {
                        sum10 = image[a][b].rgbtRed;
                        sum11 = image[a][b].rgbtGreen;
                        sum12 = image[a][b].rgbtBlue;
                    }
                }
            }
        }


    return;
}

int cap_value(int value)
            {
                if (value > 255)
                {
                    return 255;
                }
                else
                {
                    return value;
                }

            }


void swap(BYTE *x, BYTE *y)
{
     BYTE tmp;   // Declare a temporary variable

    tmp = *x;  // Store the value of x in tmp
    *x = *y;   // Assign the value of y to x
    *y = tmp;  // Assign the value of tmp (original x) to y
}




