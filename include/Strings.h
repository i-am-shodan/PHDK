#pragma once

typedef int (*xSPRINTF)(char *str, const char *format, ...);
typedef char*(*xSTRCPY)(char *result, const char *source);


char* strcat(char *destination, const char *source);
char* strcpy(char *result, const char *source);
int strstr(char *str1, const char *str2);

#define sprintf ((xSPRINTF)SYM_SPRINTF)
#define strcpy ((xSTRCPY)SYM_STRCPY)