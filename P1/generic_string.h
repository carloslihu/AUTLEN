#ifndef GENERIC_STRING_H
#define GENERIC_STRING_H
#include "basic_types.h"

void destroy_p_string(void* p_string);
void* copy_p_string(const void* p_string);
int print_p_string(FILE * fd, const void* p_string);

#endif