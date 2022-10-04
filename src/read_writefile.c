#include "./include/read_writefile.h"

struct Dir
{
    char file_path[128];
    unsigned int file_count;
    struct Dir* next;
};
struct Dir* head_files_in_dir;

void splitFileBytes(const char in_filepath[], char out_filepath[], const char extension[], unsigned int out_byte_count)
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
        printf("%ld\n",totalBytes);
        fseek(infile,0L,SEEK_SET);
    }
    const float sp = (float)totalBytes/(float)out_byte_count;
    unsigned int splits = (unsigned int)ceil(sp);
    printf("No of splits = %u\n",splits);
    char fileno[10];
    char new_filepath[128];
    
    // Initializing head_files_in_dir to NULL
    head_files_in_dir = NULL;
    struct Dir* files_in_dir = NULL;
    
    for (unsigned int i = 1; i <= splits; i++)
    {
        //copying the output dir path into a new variable.
        strcpy(new_filepath, out_filepath);
        /*Grab memory for the buffer*/
        buffer = (unsigned char*) calloc(out_byte_count, sizeof(unsigned char));

        /*memory error*/
        if(buffer == NULL)
        {
            printf("ERR: UNABLE TO ALLOCATE BUFFER NOT ENOUGH MEMORY");
            return;
        }
        /*copying data into buffer*/
        //fseek(infile,0L,SEEK_CUR);
        fread(buffer, sizeof(unsigned char), out_byte_count, infile);
        
        //adding a new file path
        snprintf(fileno, 10,"%u",i);
        strcat(new_filepath, fileno);
        strcat(new_filepath, extension);
        printf("%s\n",new_filepath);
        
        /* add the name of the files in the directory */
        if(head_files_in_dir == NULL)
        {
            files_in_dir = (struct Dir*) malloc(sizeof(struct Dir));
            head_files_in_dir = files_in_dir;
            strcpy(files_in_dir->file_path,new_filepath);
            head_files_in_dir->file_count = splits;
            head_files_in_dir->next = NULL;
        }
        else{
            files_in_dir->next = (struct Dir*) malloc(sizeof(struct Dir));
            files_in_dir = files_in_dir->next;
            strcpy(files_in_dir->file_path,new_filepath);
            files_in_dir->file_count = i;
            files_in_dir->next = NULL;
        }
        /*write the output file*/
        outfile = fopen(new_filepath,"wb");
        
        fwrite(buffer, sizeof(unsigned char), out_byte_count, outfile);
        fclose(outfile);
        /*free the buffer*/
        free(buffer);
    }
    
    fclose(infile);
}

void combineFileBytes(const char outfile_path[])
{
	FILE *infile;
	FILE *outfile;
	
    long temp_file_size = 0L;
	unsigned char *buffer;
	struct Dir* dir_iter = head_files_in_dir;
    unsigned int global_splits = dir_iter->file_count;
    
    /* Opening output file for writing output */
    outfile = fopen(outfile_path,"wb");
    
    for(unsigned int i=0; i<global_splits; i++)
	{
		printf("TEMP_FILE = %s \t",dir_iter->file_path); 
		/* Open in-file */
		infile = fopen(dir_iter->file_path,"rb");
		
		/* Get file size in bytes */
		if(infile == NULL)
		{
			printf("ERR::NO SUCH FILE EXISTS");
			return;
		}
		
		/* get total temp  file size in bytes */

		if(temp_file_size == 0)
		{
			fseek(infile,0L,SEEK_END);
			temp_file_size = ftell(infile);
			fseek(infile,0L,SEEK_SET);
		}
		
        printf("File Size in bytes = %ld \n",temp_file_size);
		
        /* create buffer to read the contents of temp file*/
		buffer = (unsigned char*) calloc(temp_file_size,sizeof(unsigned char));
		
        /* read into buffer the contents of temp file*/
        fread(buffer, sizeof(unsigned char), temp_file_size, infile);
        
		/*Write into file from buffer*/
		fwrite(buffer, sizeof(unsigned char), temp_file_size, outfile);
		
		/* close the files */
		fclose(infile);

		/*free the buffer*/
		free(buffer);
        dir_iter = dir_iter->next;
	}
	
	fclose(outfile);
}

