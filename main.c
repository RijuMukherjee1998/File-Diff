#include "read_writefile.h"


int main()
{
    char filepath[] = "test.txt";
    char outfilepath[] = "test.txt";
    splitFileBytes(filepath, outfilepath, 4);
}