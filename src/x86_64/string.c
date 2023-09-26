#include <../include/string.h>

void* memcpy(void* dest, const void* src, size_t n)
{
    if (!src || !dest) return NULL;

    for (size_t i = 0; i < n; ++i) {
        ((char*)dest)[i] = ((char*)src)[i];
    }
    return dest;
}

void* memset(void* dest, int value, size_t n)
{
    if (!dest) return NULL;

    for (size_t i = 0; i < n; ++i) {
        ((char*)dest)[i] = (char) value;
    }
    return dest;
}

size_t strlen(const char* str)
{
    size_t len = 0;
    if (!str) {
        return len;
    }

    while (str[len] != '\0') {
        ++len;
    }
    return len;
}

size_t strnlen(const char* str, size_t n)
{
    size_t len = 0;
    if (!str) {
        return len;
    }

    while (str[len] != '\0' && len < n) {
        ++len;
    }
    return len;
}

char* strcpy(char* dest, const char* src)
{
    if (!dest || !src) return NULL;

    size_t i;
    for (i = 0; src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

char* strncpy(char* dest, const char* src, size_t n)
{
    if (!dest || !src) return NULL;

    size_t i;
    for (i = 0; i < n && src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }

    if (i < n) {
        dest[i] = '\0';
    } else {
        dest[n-1] = '\0';
    }
    return dest; 
}

int strcmp(const char* s1, const char* s2)
{
    while (*s1 != '\0' && *s1 == *s2) {
        ++s1;
        ++s2;
    }
    return (*(unsigned char*) s1) - (*(unsigned char*) s2);
}

int strncmp(const char* s1, const char* s2, size_t n)
{
    if (n == 0) return 0;

    while (--n != 0 && *s1 == *s2) {
        if (n == 0 || *s1 == '\0') break;
        ++s1;
        ++s2;
    }
    return (*(unsigned char*) s1) - (*(unsigned char*) s2);
}

