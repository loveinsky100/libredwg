#ifndef _DWG_HELPER_H_
#define _DWG_HELPER_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dwg.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct {
    char *str;
    size_t length;
    size_t capacity;
} string_builder;


EXPORT void sb_init(string_builder *sb);
EXPORT void sb_free(string_builder *sb);
EXPORT void sb_append(string_builder *sb, const char *str);
EXPORT void sb_appendf(string_builder *sb, const char *format, ...);


// dwg helper
EXPORT void dwg2svg(Dwg_Data *dwg, string_builder *sb);

#ifdef __cplusplus
}
#endif

#endif