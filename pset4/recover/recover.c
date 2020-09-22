#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <stdint.h>

#define BLOCK 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{        
    // Open Card
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open.\n");
        return 1;
    }
    
    // Buffer 512
    BYTE buffer[BLOCK];
    char filename[8];
    
    FILE *img;
    bool jpg = false;
    int file_counter = 0;
    
    // iterate over Card
    while (fread(buffer, BLOCK, 1, file) != 0)
    {    
        
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff 
            && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
        {
            // FileName
            sprintf(filename, "%03d.jpg", file_counter);
                        
            if (jpg)
            {
                fclose(img);               
                img = fopen(filename, "a");
                fwrite(buffer, BLOCK, 1, img);
                
                file_counter++;
            } 
            else if (!jpg)
            {

                img = fopen(filename, "a");
                fwrite(buffer, BLOCK, 1, img);
                

                jpg = true;
                file_counter++;
            }   
        }
        else if (jpg)
        { 
            fwrite(buffer, BLOCK, 1, img);     
        }
    }
    
    //Close img
    if (img)
    {
        fclose(img); 
    }    
    
    //Close card
    fclose(file);
    
    return 0;
}
