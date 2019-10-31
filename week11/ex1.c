
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    int fileDescriptor = open("ex1.txt", O_RDWR , (mode_t)0600);

    char *text = "This is a nice day";
    int size = strlen(text) + 1;

    lseek(fileDescriptor, strlen(text) , SEEK_SET);
	write(fileDescriptor, "", 1);

	ftruncate(fileDescriptor, size); //Instead of fstat.
    char *map = mmap(0, size, PROT_WRITE, MAP_SHARED, fileDescriptor, 0);

    for (int i = 0; i < size; i++)
        map[i] = text[i];

    munmap(map, size);
    close(fileDescriptor);    
    return 0;
}