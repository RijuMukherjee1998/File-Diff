#include "./include/read_writefile.h"


int main()
{
    const char filepath[] = "/home/riju/Desktop/File-Diff/test/cat.jpg";
    const char extension[] = ".tmp";
    char outfilepath[] = "/home/riju/Desktop/File-Diff/tmp/test";
    splitFileBytes(filepath, outfilepath,extension, 4288);

    // const char temp_file_dir[] = "/home/riju/Desktop/File-Diff/tmp/test";
    const char op_path[] = "/home/riju/Desktop/File-Diff/tmp/cat.jpg"; 
    combineFileBytes(op_path);
}
