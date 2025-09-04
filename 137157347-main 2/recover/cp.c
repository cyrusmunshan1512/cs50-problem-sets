#include <stdio.h>
#include <cs50.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main (int argc, char* argv[])
{
    BYTE buffer[512];
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    FILE* inptr = fopen(argv[1],"rb");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s\n" , argv[1]);
        return 2;
    }
    FILE* outptr = fopen("outptr.raw" , "wb");
    if (outptr == NULL)
    {
        fprintf(stderr, "Could not create outptr.raw\n");
        fclose(outptr);
        return 3;
    }

    while(fread(buffer, 512 , 1, inptr) == 1)
    {
        fwrite(buffer, 512 , 1, outptr);
    }
    fclose(inptr);
    fclose(outptr);

return 0;
}
