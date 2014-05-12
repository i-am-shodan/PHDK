#pragma once

#define NULL 0
#define TRUE 1
#define FALSE 0
typedef unsigned long size_t;

typedef void* (*NO_PARAM)(void);
typedef void(*VOID_ONE_PARAM)(void*);
typedef void(*VOID_TWO_PARAM)(void*, int);
typedef void(*VOID_THREE_PARAM)(void*, int, int);
typedef void(*VOID_FOUR_PARAM)(void*, int, int, int);
typedef int(*INT_ONE_PARAM)(void*);