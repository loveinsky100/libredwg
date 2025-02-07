#include "dwg_helper.h"

// 初始化 StringBuilder
void sb_init(string_builder *sb) {
    sb->capacity = 16;  // 初始容量
    sb->length = 0;
    sb->str = (char *)malloc(sb->capacity * sizeof(char));
    sb->str[0] = '\0';  // 空字符串
}

// 释放内存
void sb_free(string_builder *sb) {
    free(sb->str);
    sb->str = NULL;
    sb->length = sb->capacity = 0;
}

// 添加字符串到 StringBuilder
void sb_append(string_builder *sb, const char *str) {
    size_t str_len = strlen(str);

    // 如果容量不足，扩大容量
    while (sb->length + str_len + 1 > sb->capacity) {
        sb->capacity *= 2;  // 双倍扩展容量
        sb->str = (char *)realloc(sb->str, sb->capacity * sizeof(char));
    }

    // 将新字符串拼接到已有字符串后面
    strcpy(sb->str + sb->length, str);
    sb->length += str_len;
}

// 添加格式化字符串到 StringBuilder
void sb_appendf(string_builder *sb, const char *format, ...) {
    va_list args;
    va_start(args, format);

    // 计算格式化后的字符串长度
    int required_len = vsnprintf(NULL, 0, format, args) + 1;  // +1 for the null-terminator

    // 确保容量足够
    while (sb->length + required_len > sb->capacity) {
        sb->capacity *= 2;  // 双倍扩展容量
        sb->str = (char *)realloc(sb->str, sb->capacity * sizeof(char));
    }

    // 格式化并将字符串追加到 sb 中
    vsnprintf(sb->str + sb->length, required_len, format, args);
    sb->length += required_len - 1;  // 减去 '\0' 字符

    va_end(args);
}
