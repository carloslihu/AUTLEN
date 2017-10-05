#include "generic_string.h"

void destroy_p_string(void* p_string) { 
	free(p_string);
}

void* copy_p_string(const void* p_string) { 
	
	char* p_string2 = (char*)calloc(strlen(p_string)+1,sizeof(char));
	strcpy(p_string2,(char*)p_string);
	return (void*)p_string2;
}

int print_p_string(FILE * fd, const void* p_string) { 
	return fprintf(fd, "(STRING) %s \n", (char*)p_string);
}