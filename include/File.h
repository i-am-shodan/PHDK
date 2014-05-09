#pragma once

#define FILE_MODE_READ 1
#define FILE_MODE_WRITE 0

struct FILEAPI;
struct FILECLASS;
struct FILE;

typedef int BOOL;
typedef int FILEHANDLE;
typedef BOOL(*OPEN_FILE_HANDLE)
	(const struct FILECLASS* a, 
     const char* filename, 
	 int mode, 
	 FILEHANDLE*);
typedef void(*CLOSE_FILE_HANDLE)(const struct FILECLASS*, FILEHANDLE);
typedef BOOL(*READ_FILE)(const struct FILECLASS*, FILEHANDLE, unsigned char* buffer, unsigned int size);
typedef BOOL(*WRITE_FILE)(const struct FILECLASS*, FILEHANDLE, unsigned char* buffer, unsigned int size);
typedef void* FILEREF;

typedef BOOL(*xLOADFILE)(const struct FILECLASS* api, const char* filename, struct FILE* file);
typedef int(*xGETFILESIZE)(struct FILE*);
typedef void(*xFILECTOR)(struct FILE* file);
typedef void(*xFILEDTOR)(struct FILE* file);

typedef struct FILE {
	int field_0;
	int field_4;
	int field_8;
	int field_12;
	int field_16;
	int field_20;
	int field_24;
	int field_28;
	int field_32;
	int field_36;
	int field_40;
} FILE;

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

typedef FILEREF(*xINITFILEAPI)();
typedef struct FILECLASS*(*xGETFILEAPI)(FILEREF ref);

#define initFileAPI ((xINITFILEAPI)SYM_INITFILEAPI)
#define getFileAPI ((xGETFILEAPI)SYM_GETFILEAPI)
#define loadFile ((xLOADFILE)SYM_LOADFILE)
#define getFileSize ((xGETFILESIZE)SYM_GETFILESIZE)
#define fileCtor ((xFILECTOR)SYM_FILECTOR)
#define fileDtor ((xFILEDTOR)SYM_FILEDTOR)
