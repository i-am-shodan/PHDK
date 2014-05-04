#include "include\Common.h"
#include "include\Memory.h"
#include "include\File.h"

#include "symbols.h"

#define BUFFER_SIZE 0x10000
#define BASE_ADDR 0xA0000000
#define END_ADDR  0xA0C30000

int dumpMem(void* unusedA, void* unusedB)
{
	unsigned char* buffer = (unsigned char*)malloc(BUFFER_SIZE);
	int ret = 0;
	
	do
	{
		unsigned int memLocation;

		if (buffer == NULL)
		{
			break;
		}

		FILEREF fileRef = initFileAPI(); // this has returned the correct value
		FILECLASS *fileAPI = getFileAPI(fileRef);
		FILEHANDLE handle = 0;
		
		if (!fileAPI->api->OpenFileHandle(fileAPI, "C:\\DUMP.BIN", FILE_MODE_WRITE, &handle))
		{
			break;
		}
		
		
		for (memLocation = BASE_ADDR; memLocation < END_ADDR; memLocation += BUFFER_SIZE)
		{
			// begin inline memcpy
			size_t count = BUFFER_SIZE;
			char* dst8 = (char*)buffer;
			char* src8 = (char*)memLocation;

			while (count--) {
				*dst8++ = *src8++;
			}
			// end inline memcpy

			// now write out
			fileAPI->api->WriteFile(fileAPI, handle, buffer, BUFFER_SIZE);
		}

		fileAPI->api->CloseFileHandle(fileAPI, handle);
		
		ret = 1;
	} 
	while (0);
	
	if (buffer != NULL)
	{
		free(buffer);
	}
	
	return ret;
}
