#include "Program.h"

#include "include\Display.h"
#include "include\Memory.h"
#include "include\Strings.h"
#include "include\Utilities.h"
#include "include\File.h"

#define BUFFER_SIZE 0x10000
//#define BASE_ADDR 0xA0000000
//#define END_ADDR 0xA0C30000
#define BASE_ADDR 0x60000000
#define END_ADDR  0x60010000

int dumpMem(void* unusedA, void* unusedB)
{
	unsigned char* buffer = (unsigned char*) malloc(BUFFER_SIZE);
	int ret = 0;
	
	//DISPLAY_API displayAPI = getDisplayAPI();
	//displayTxt(displayAPI, "Starting", 0, 1, 0, 0, 0, 4, 0);

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

		if (!fileAPI->api->OpenFileHandle(fileAPI, "C:\\DUMP.BIN", FILE_MODE_WRITE, &handle))
		{
			break;
		}

		for (memLocation = BASE_ADDR; memLocation < END_ADDR; memLocation += BUFFER_SIZE)
		{
			size_t count = BUFFER_SIZE;
			//memcpy(buffer, (void*)memLocation, BUFFER_SIZE);
			char* dst8 = (char*)buffer;
			char* src8 = (char*)memLocation;

			while (count--) {
				*dst8++ = *src8++;
			}

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

	//displayTxt(displayAPI, "Complete", 0, 1, 0, 0, 0, 4, 0);

	return ret;
}
