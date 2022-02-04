#include "read_writefile.h"


void splitFileBytes(char in_filepath[], char out_filepath[], int out_byte_count)
{
    /*declare a file pointer*/
    FILE *infile;
    FILE *outfile;
    unsigned char *buffer;
    long totalBytes = 0L;

    /*open existing file*/
    infile = fopen(in_filepath, "rb");

    if(infile == NULL)
    {
        printf("ERR: NO SUCH FILE EXISTS.");
        return;
    }
    
    /*get file size in bytes*/
    if(totalBytes == 0)
    {
        fseek(infile, 0L, SEEK_END);
        totalBytes = ftell(infile);
        printf("%d\n",totalBytes);
        fseek(infile,0L,SEEK_SET);
    }

    unsigned int splits = (unsigned int)ceil(totalBytes/out_byte_count);
    printf("No of splits = %d\n",splits);
    char fileno[10];
    for (unsigned int i = 1; i <= splits; i++)
    {
        char newfilePath[] = "";
        /*Grab memory for the buffer*/
        buffer = (unsigned char*) calloc(out_byte_count, sizeof(unsigned char));

        /*memory error*/
        if(buffer == NULL)
        {
            printf("ERR: UNABLE TO ALLOCATE BUFFER");
            return;
        }
        /*copying data into buffer*/
        //fseek(infile,0L,SEEK_CUR);
        fread(buffer, sizeof(unsigned char), out_byte_count, infile);
        
        //adding a new file path
        itoa(i, fileno, 10);
        strcat(newfilePath , fileno);
        printf("%s\n",newfilePath);

        /*write the output file*/
        outfile = fopen(newfilePath,"wb");
        
        fwrite(buffer, sizeof(unsigned char), out_byte_count, outfile);
        fclose(outfile);
        /*free the buffer*/
        free(buffer);
    }
    fclose(infile);

}
