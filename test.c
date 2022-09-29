//
// Created by khanh on 9/28/2022.
//
#include <stdbool.h>

#ifndef _FILE_DEFINED
struct _iobuf {
#ifdef _UCRT
    void *_Placeholder;
#else
    char *_ptr;
    int _cnt;
    char *_base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    char *_tmpfname;
#endif
};
typedef struct _iobuf FILE;
#define _FILE_DEFINED
#endif

int __cdecl fputs(const char * __restrict__ _Str, FILE * __restrict__ _File);

int printf(const char *arg) {
    fputs("Success!", stdout);
}

int main() {
    int j = 5;
    if (j > 5) {
        printf("Success!");
    } else {
        printf("Oof!");
    }
    return 0;
}