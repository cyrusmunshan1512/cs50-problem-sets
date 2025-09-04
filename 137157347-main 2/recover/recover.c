#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Ensure proper usage: exactly one argument should be provided.
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // Open the forensic image file for reading.
    FILE *inptr = fopen(argv[1], "rb");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }

    BYTE buffer[512];
    FILE *file = NULL;
    char filename[8];
    int jpeg_counter = 0;

    while (fread(buffer, 512, 1, inptr) == 1)
    { // the loop thing is remaining. enclose all of this in a loop.

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        { // This is the start of a new JPEG

            if (jpeg_counter == 0)

            {
                sprintf(filename, "%03i.jpg", jpeg_counter); // generate name like "000.jpg"

                file = fopen(filename, "w"); // open that file

                if (file == NULL)
                {
                    printf("Could not open file %s\n", filename);
                    return 1;
                }

                fwrite(buffer, 512, 1, file); // write the first 512 bytes(JPEGblock)
                jpeg_counter++;               // ready for next filename
            }

            else
            {

                fclose(file);
                sprintf(filename, "%03i.jpg", jpeg_counter);
                file = fopen(filename, "w"); // open that file

                if (file == NULL)
                {
                    printf("Could not open file %s\n", filename);
                    return 1;
                }

                fwrite(buffer, 512, 1, file); // write the first 512 bytes(JPEGblock)
                jpeg_counter++;               // ready for next filename
            }
        }
        else
        {
            // No new JPEG header detected
            if (file != NULL)
            {
                // Continue writing the current block to the already open JPEG file
                fwrite(buffer, 512, 1, file);
            }
            // Else: No file is open, so do nothing.
        }
    }
    if (file != NULL)
    {
        fclose(file);
    }
    fclose(inptr);
}
