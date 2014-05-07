#pragma once

typedef int (*xSPRINTF)(char *str, const char *format, ...);

char* strcat(char *destination, const char *source);
char* strcpy(char *result, const char *source);
int strstr(char *str1, const char *str2);

#define sprintf ((xSPRINTF)SYM_SPRINTF)
