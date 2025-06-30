#include <cs50.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Create a buffer for the block of memory (512 bits per block accd. to FAT file system)
#define FAT 512

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *src = fopen(argv[1], "r");
    if (src == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 2;
    }

    bool found_jpeg = false; // Flag to keep track of jpeg_found
    int counter = 0;
    uint8_t buffer[FAT];
    char filename[8];
    FILE *dst;

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, FAT, src) == 512)
    {
        // if start of new jpeg

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)

        { // close any open jpeg
            if (found_jpeg)
            {
                fclose(dst);
            }
            else
            {
                found_jpeg = true;
            }

            {
                // Create the correct filename string
                sprintf(filename, "%03i.jpg", counter);
                // Open file
                dst = fopen(filename, "w");
                // check file
                if (dst == NULL)
                {
                    fclose(src);
                    printf("Could not open file. \n");
                    return 3;
                }
                // increase counter
                counter++;
            }
        }
        if (found_jpeg)
        {
            // write file
            fwrite(buffer, 1, FAT, dst);
        }
    }
    fclose(src);
    fclose(dst);

    // Exit program
    return 0;
}
