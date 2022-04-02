#include "./include/read_writefile.h"


int main()
{
    const char filepath[] = "D:\\Projects\\File-Diff\\test\\601048.jpg";
    char outfilepath[] = "D:\\Projects\\File-Diff\\tmp\\601048";
    splitFileBytes(filepath, outfilepath, 4);
}