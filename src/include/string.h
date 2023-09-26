#ifndef _STRING_H
#define _STRING_H
#include <stddef.h>

void* memcpy(void* dest, const void* src, size_t n);
void* memset(void* dest, int value, size_t n);
size_t strlen(const char* str);
size_t strnlen(const char* str, size_t n);
char* strcpy(char* dest, const char* src);
char* strncpy(char* dest, const char* src, size_t n);
int strcmp(const char* s1, const char* s2);
int strncmp(const char* s1, const char* s2, size_t n);

#endif // !_STRING_H
