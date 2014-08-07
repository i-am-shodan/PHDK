#include "include\Common.h"
#include "include\Memory.h"
#include "include\File.h"
#include "include\Execution.h"
#include "include\Display.h"
#include "include\Utilities.h"
#include "include\Strings.h"

#include "symbols.h"

#define BUFFER_SIZE 0x10000
#define BASE_ADDR 0xA0000000
#define END_ADDR  0xA0C30000

int count;

void button_handler(menu *caller, int button_pressed, int firstRun)
{
	if (firstRun)
	{
		count = 0;
	}
	else
	{
		count++;
	}

	unsigned char* buffer = (unsigned char*)malloc(BUFFER_SIZE);
	int ret = 0;
	
	do
	{
		unsigned int memLocation;

		if (buffer == NULL)
		{
			break;
		}

		FILEREF fileRef = initFileAPI();
		FILECLASS *fileAPI = getFileAPI(fileRef);
		FILEHANDLE handle = 0;
		
		char* filenameBuf = (char*)malloc(50);

		if (filenameBuf == NULL)
		{
			break;
		}

		sprintf(filenameBuf, "C:\\DUMP%d.BIN", count);

		if (!fileAPI->api->OpenFileHandle(fileAPI, filenameBuf, FILE_MODE_WRITE, &handle))
		{
			free(filenameBuf);
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
		
		free(filenameBuf);

		ret = 1;
	} 
	while (0);
	
	if (buffer != NULL)
	{
		free(buffer);
	}
	
	// jump to live view
	((VOID_TWO_PARAM)0xA00D3C48)(caller, 3);
}
