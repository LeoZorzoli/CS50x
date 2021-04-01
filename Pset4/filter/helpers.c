#include "helpers.h"
#include <math.h>

// R = ROW 
// C = COL

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float promedio;
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            //Promedio = Average
            promedio = round((image[r][c].rgbtRed + image[r][c].rgbtGreen + image[r][c].rgbtBlue) / 3.000);
            image[r][c].rgbtRed = promedio;
            image[r][c].rgbtGreen = promedio;            
            image[r][c].rgbtBlue = promedio;
        }
    }
    return;
}


// Function Limit
int limit(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed;
    int sepiaGreen;
    int sepiaBlue;
    
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            sepiaRed = limit(round(image[r][c].rgbtRed * 0.393 + image[r][c].rgbtGreen * 0.769 + image[r][c].rgbtBlue * 0.189));
            sepiaGreen  = limit(round(image[r][c].rgbtRed * 0.349 + image[r][c].rgbtGreen * 0.686 + image[r][c].rgbtBlue * 0.168));
            sepiaBlue  = limit(round(image[r][c].rgbtRed * 0.272 + image[r][c].rgbtGreen * 0.534 + image[r][c].rgbtBlue * 0.131));
            
            image[r][c].rgbtRed = sepiaRed;
            image[r][c].rgbtGreen = sepiaGreen;
            image[r][c].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width / 2; c++)
        {
            // Temporaly Var
            int aR = image[r][c].rgbtRed;
            int aG = image[r][c].rgbtGreen;
            int aB = image[r][c].rgbtBlue;
            
            image[r][c].rgbtRed = image[r][width - c - 1].rgbtRed;
            image[r][c].rgbtGreen = image[r][width - c - 1].rgbtGreen;
            image[r][c].rgbtBlue = image[r][width - c - 1].rgbtBlue;

            image[r][width - c - 1].rgbtRed = aR;
            image[r][width - c - 1].rgbtGreen = aG;
            image[r][width - c - 1].rgbtBlue = aB;
        }
    }
    
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Colors
    int sumBlue;
    int sumGreen;
    int sumRed;
    float counter;

    RGBTRIPLE temp[height][width];

    for (int r = 0; r < width; r++)
    {
        for (int c = 0; c < height; c++)
        {
            sumBlue = 0;
            sumGreen = 0;
            sumRed = 0;
            counter = 0.00;

            // Sum values 9 pixel
            for (int a = -1; a < 2; a++)
            {
                if (c + a < 0 || c + a > height - 1)
                {
                    continue;
                }

                for (int b = -1; b < 2; b++)
                {
                    if (r + b < 0 || r + b > width - 1)
                    {
                        continue;
                    }

                    sumBlue += image[c + a][r + b].rgbtBlue;
                    sumGreen += image[c + a][r + b].rgbtGreen;
                    sumRed += image[c + a][r + b].rgbtRed;
                    counter++;
                }
            }

            // Averages
            temp[c][r].rgbtBlue = round(sumBlue / counter);
            temp[c][r].rgbtGreen = round(sumGreen / counter);
            temp[c][r].rgbtRed = round(sumRed / counter);
        }
    }

    //Temp Values
    for (int c = 0; c < width; c++)
    {
        for (int r = 0; r < height; r++)
        {
            image[r][c].rgbtBlue = temp[r][c].rgbtBlue;
            image[r][c].rgbtGreen = temp[r][c].rgbtGreen;
            image[r][c].rgbtRed = temp[r][c].rgbtRed;
        }
    }
}
