
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


typedef uint8_t BYTE;

bool jpg_check(unsigned char bytes[]);

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./recover image \n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");


    if (file == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }

    //declaring output file and allocating memory for it

    FILE *output = NULL;
    BYTE *bytes = malloc(512);
    char jpg_name[8];
    int count = 0;



    //looping through file image
    while (fread(bytes, sizeof(BYTE), 512, file) != 0)
    {
        //check if it is jpg file
        if (jpg_check(bytes) == true)
        {
            if (count != 0)
            {
                fclose(output);
            }

            sprintf(jpg_name, "%03i.jpg", count);

            output = fopen(jpg_name, "w");

            ++count;

        }
        //write found jpeg to the file
        if (count != 0)
        {
            fwrite(bytes, sizeof(BYTE), 512, output);
        }

    }

    free(bytes);

    //close files
    fclose(file);
    fclose(output);


    return 0;
}


//jpeg checker via bool function
bool jpg_check(unsigned char bytes[])
{
    if ((bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && ((bytes[3] & 0xf0) == 0xe0)))
    {
        return true;
    }
    return 0;
}
