#include "./include/read_writefile.h"


int main()
{
    const char filepath[] = "/home/riju/Desktop/File-Diff/test/test.txt";
    char outfilepath[] = "/home/riju/Desktop/File-Diff/tmp/test";
    splitFileBytes(filepath, outfilepath, 4);
}
