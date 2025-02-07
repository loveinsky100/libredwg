#ifndef _DWG_HELPER_H_
#define _DWG_HELPER_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct {
    char *str;
    size_t length;
    size_t capacity;
} string_builder;


void sb_init(string_builder *sb);
void sb_free(string_builder *sb);
void sb_append(string_builder *sb, const char *str);
void sb_appendf(string_builder *sb, const char *format, ...);

#ifdef __cplusplus
}
#endif

#endif