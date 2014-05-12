#include "include\Common.h"
#include "include\Memory.h"
#include "include\File.h"
#include "include\Execution.h"
#include "include\Display.h" 
#include "include\Strings.h"

#include "symbols.h"

#define PARASITE_PATCH_LOCATION 0xA0A2D670
#define ALREADY_EXECUTED_VALUE 9723

void iconMenuHandleButtonPress(void *this, int button, unsigned short increment)
{
	FILEHANDLE handle = 0;
	int justLoadedFromSD = 0;
	const char* filename = "C:\\PHDK.BIN";

	const FILEREF fileRef = initFileAPI();
	const FILECLASS *fileAPI = getFileAPI(fileRef);

	const void* api = iconDisplayAPI(this, 0x1406002);

	do
	{
		FILE file;

		if (*(int*)PARASITE_PATCH_LOCATION != 0xFFFFFFFF)
		{
			// we've already loaded something from the SD card
			break;
		}

		// check that the file is on the SD
		fileCtor(&file);
		if (!loadFile(fileAPI, filename, &file))
		{
			iconDisplayTxt(api, "Error: loadFile failed");
			fileDtor(&file);
			break;
		}

		int fileSize = getFileSize(&file);
		fileDtor(&file);

		if (fileSize == 0 || fileSize > 2048)
		{
			iconDisplayTxt(api, "Error: file size invalid");
			break;
		}

		if (!fileAPI->api->OpenFileHandle(fileAPI, filename, FILE_MODE_READ, &handle))
		{
			iconDisplayTxt(api, "Error: file open failed");
			break;
		}
		
		// now load the file into memory
		if (!fileAPI->api->ReadFile(fileAPI, handle, (unsigned char*) PARASITE_PATCH_LOCATION, fileSize))
		{
			iconDisplayTxt(api, "Error: read file failed");
			break;
		}

		justLoadedFromSD = TRUE;

	} while (FALSE);

	if (handle != 0)
	{
		fileAPI->api->CloseFileHandle(fileAPI, handle);
	}

	// ensure we have loaded something at our special address
	if (*(int*)PARASITE_PATCH_LOCATION != 0xFFFFFFFF)
	{
		// now execute our code
		iconDisplayTxt(api, "Code executed");
		((EXECUTE)PARASITE_PATCH_LOCATION)(this, button, justLoadedFromSD);
	}
}
