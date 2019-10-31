#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    //Open files
    int inputFileDescriptor = open("ex1.txt", O_RDONLY, (mode_t)0600);
    int outputFileDescriptor = open("ex1.memcpy.txt", O_RDWR | O_CREAT, (mode_t)0600);

    //Calc stats
    struct stat fileInfo;
    fstat(inputFileDescriptor, &fileInfo);

    //mmap to 1 file
    char *inputMap = mmap(0, fileInfo.st_size, PROT_READ, MAP_SHARED, inputFileDescriptor, 0);

    //Same as in 1 ex
    lseek(outputFileDescriptor, fileInfo.st_size , SEEK_SET);
	write(outputFileDescriptor, "", 1);

    //mmap to 2 file
	ftruncate(outputFileDescriptor, fileInfo.st_size); //Instead of fstat.
    char *outputMap = mmap(0, fileInfo.st_size, PROT_WRITE, MAP_SHARED, outputFileDescriptor, 0);

    //Copy
    for (int i = 0; i < fileInfo.st_size; i++)
        outputMap[i] = inputMap[i];

    //Close
    munmap(inputMap, fileInfo.st_size);
    munmap(outputMap, fileInfo.st_size);
    close(inputFileDescriptor);
    close(outputFileDescriptor);    
    return 0;
}