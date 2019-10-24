#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

#define MAXBUFFER 100 //Max amount of files. should be guaranteed to exeed such amount by 2 at least.
struct myFile
{
	char *filename;
	ino_t inode;
	int isPrinted;
};

int main() {
    DIR *tmpdir;
    struct dirent *entry;
    struct myFile files[MAXBUFFER];
    tmpdir = opendir("/home/omegalul/week10/tmp");

    int i=0;
    while ( (entry = readdir(tmpdir)) != NULL) {
        files[i].filename = entry->d_name;
        files[i].inode = entry->d_ino;
        files[i].isPrinted = 0;
        i++;
    };

    int totalAmountOfFiles = i;
    for (i = 0; i < totalAmountOfFiles; ++i)
    {
    	if(files[i].isPrinted==1) //One filename should not be listed several times
    		continue; 
    	ino_t tempnode = files[i].inode;

    	for (int k = i+1; k < totalAmountOfFiles; ++k)
    	{
    		if(files[k].inode==tempnode)
    		{
    			printf("%s\n",files[k].filename);
    			files[k].isPrinted = 1;
    			files[i].isPrinted = 1;//flag for print later (немного костыль-тоесть элегантное решение)
    		}
    	}
    	if(files[i].isPrinted == 1)
    		printf("%s\n\n",files[i].filename); //Second \n for split files with differt inodes
    }

    return 0;
};