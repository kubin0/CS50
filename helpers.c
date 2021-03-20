#include "helpers.h"
#include <math.h>
#include <string.h>
#include <stdio.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //looping through rows
    for (int i = 0; i < height; ++i)
    {
        //looping through columns
        for (int j = 0; j < width; ++j)
        {
            //get values of RGB
            float blue = image[i][j].rgbtBlue;
            float green = image[i][j].rgbtGreen;
            float red = image[i][j].rgbtRed;

            //grayscale formula
            int grayS = round((blue + green + red) / 3);

            //set new values
            image[i][j].rgbtBlue = grayS;
            image[i][j].rgbtGreen = grayS;
            image[i][j].rgbtRed = grayS;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //looping through rows
    for (int i = 0; i < height; ++i)
    {
        //looping through columns
        for (int j = 0; j < width; ++j)
        {
            //get values of RGB
            float blue = image[i][j].rgbtBlue;
            float green = image[i][j].rgbtGreen;
            float red = image[i][j].rgbtRed;

            //sepia formula
            int sepiaB = round(.272 * red + .534 * green + .131 * blue);
            int sepiaG = round(.349 * red + .686 * green + .168 * blue);
            int sepiaR = round(.393 * red + .769 * green + .189 * blue);


            //handling if more than 8 bytes aka value of color more than 255
            if (sepiaB > 255)
            {
                sepiaB = 255;
            }

            if (sepiaG > 255)
            {
                sepiaG = 255;
            }

            if (sepiaR > 255)
            {
                sepiaR = 255;
            }
            //set new values for sepia
            image[i][j].rgbtBlue = sepiaB;
            image[i][j].rgbtGreen = sepiaG;
            image[i][j].rgbtRed = sepiaR;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    //looping through rows
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width / 2; ++j)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }

    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE blur[height][width];

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            blur[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            float blue = 0;
            float green = 0;
            float red = 0;
            int sum = 0;

            //checking wheter is above/below right/left a pixel if not than skip it
            for (int x = -1; x < 2; ++x)
            {
                for (int y = -1; y < 2; ++y)
                {
                    if (i + x < 0 || i + x >= height)
                    {
                        continue;
                    }
                    if (j + y < 0 || j + y >= width)
                    {
                        continue;
                    }

                    //counting pixels
                    blue = blue + blur[i + x][j + y].rgbtBlue;
                    green = green + blur[i + x][j + y].rgbtGreen;
                    red = red + blur[i + x][j + y].rgbtRed;
                    ++sum;
                }
            }

            // final math to get blured image
            image[i][j].rgbtBlue = round(blue / sum);
            image[i][j].rgbtGreen = round(green / sum);
            image[i][j].rgbtRed = round(red / sum);
        }
    }


    return;
}
