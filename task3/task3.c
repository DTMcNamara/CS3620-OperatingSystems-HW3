#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

int main(int argc, char *argv[]){
	unsigned char *f, *g;
  	int size;
  	struct stat s;
  	int fd = open(argv[1], O_RDWR);
	if(fd == -1){
		perror("File Failed to Open.\n");
		return 1;
	}
  	int status = fstat(fd, &s);
  	size = s.st_size;
 	char h[size];
  	int i;
  	f = (char *) mmap (0, size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	if(f == MAP_FAILED){
		perror("mmap Failed.\n");
		return 1;
	}
 	for(i = 0; i < size; i++){
    	 	char c;
     		c = f[i];
   		h[size-i-1]=c;
  	}
	memcpy(f,h,size);
 	msync(f,size,MS_SYNC);
  	munmap(f,size);
  	close(fd);
}
