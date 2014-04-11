#pragma once

#define FILE_MODE_READ 1
#define FILE_MODE_WRITE 0

struct FILEAPI;
struct FILECLASS;

typedef int BOOL;
typedef int FILEHANDLE;
typedef BOOL(*OPEN_FILE_HANDLE)
	(struct FILECLASS* a, 
     const char* filename, 
	 int mode, 
	 FILEHANDLE*);
typedef void(*CLOSE_FILE_HANDLE)(struct FILECLASS*, FILEHANDLE);
typedef BOOL(*READ_FILE)(struct FILECLASS*, FILEHANDLE, unsigned char* buffer, unsigned int size);
typedef BOOL(*WRITE_FILE)(struct FILECLASS*, FILEHANDLE, unsigned char* buffer, unsigned int size);
typedef void* FILEREF;

typedef struct FILEAPI {
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	OPEN_FILE_HANDLE OpenFileHandle;
	CLOSE_FILE_HANDLE CloseFileHandle;
	READ_FILE ReadFile;
	WRITE_FILE WriteFile;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
	int field_3C;
	int field_40;
} FILEAPI;

typedef struct FILECLASS {
	FILEAPI* api;
} FILECLASS;

FILEREF initFileAPI();
struct FILECLASS* getFileAPI(FILEREF ref);
