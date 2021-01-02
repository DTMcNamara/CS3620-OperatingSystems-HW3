#include <errno.h>
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
	int fd = open("/dev/null",O_RDWR);
	const void *ptr = argv[1];
	if(write(fd,ptr,1)==0){ 
			
	}
}
