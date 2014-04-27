#include "include\Common.h"
#include "include\Memory.h"
#include "include\File.h"
#include "include\Execution.h"

#include "symbols.h"

#define BUFFER_SIZE 0x10000

int programLoader()
{
	int ret = 0;
	unsigned char* buffer;
	FILEHANDLE handle = 0;

	FILEREF fileRef = initFileAPI();
	FILECLASS *fileAPI = getFileAPI(fileRef);

	do
	{
		// TODO get file size
		unsigned int fileSize = 0;

		if (!fileAPI->api->OpenFileHandle(fileAPI, "C:\\PHDK.BIN", FILE_MODE_READ, &handle))
		{
			break;
		}

		// we add 4 bytes as this gives us the room to ensure
		// any code is aligned correctly
		buffer = (unsigned char*)malloc(fileSize + 4);
		unsigned char* startOfCode = buffer;

		// need to ensure that we start executing from an aligned address
		// we do this by keep adding a byte until addr % 4 == 0
		while ( (unsigned int) startOfCode % 4 != 0)
		{
			++startOfCode;
		}
		
		// now load the file into memory
		if (fileAPI->api->ReadFile(fileAPI, handle, startOfCode, fileSize)) // hmmmm filesize
		{
			break;
		}

		// now execute our code
		((EXECUTE)startOfCode)();

	} while (0);
	
	if (buffer != NULL)
	{
		free(buffer);
	}

	if (handle != 0)
	{
		fileAPI->api->CloseFileHandle(fileAPI, handle);
	}

	return ret;
}
