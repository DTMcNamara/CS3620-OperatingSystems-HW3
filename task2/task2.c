#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main ( int argc, char *argv[] ) {
	const char *intake = argv[1];
	char assembly_code[strlen(intake)];
	for(int i=0;i<strlen(intake);i+=2){
		int x = sscanf(&intake[i], "%02hhx", &assembly_code[i/2]);
	}
	size_t ac_size = sizeof(assembly_code)/sizeof(assembly_code[0]);
	void *code = mmap( NULL, ac_size, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
	if ( code == MAP_FAILED ) {
		perror("Failed mmap");
		return 1;
	}
	memcpy(code,assembly_code,ac_size);
	((void (*) (void))code)();
}
