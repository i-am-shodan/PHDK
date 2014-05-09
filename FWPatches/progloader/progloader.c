#include "include\Common.h"
#include "include\Memory.h"
#include "include\File.h"
#include "include\Execution.h"
#include "include\Display.h" 
#include "include\Strings.h"

#include "symbols.h"

#define PARASITE_PATCH_LOCATION 0xA0A2D670
#define ALREADY_EXECUTED_VALUE 9723

int alreadyExecuted;

void iconMenuHandleButtonPress(void *this, int button, unsigned short increment)
{
	FILEHANDLE handle = 0;
	int loaded = 0;
	const char* filename = "C:\\PHDK.BIN";

	const FILEREF fileRef = initFileAPI();
	const FILECLASS *fileAPI = getFileAPI(fileRef);

	const void* api = iconDisplayAPI(this, 0x1406002);

	do
	{
		FILE file;

		if (button == 10)
		{
			// i wonder if this is the info button, it seems to interact with the same
			// id used in the display code. Maybe you register some text to be rendered later
			// on demand?

			// think this is some rendering thing
			((VOID_THREE_PARAM)0xA063333C)(this, 0, 0); //sub_A063333C(this, 0, 0);
			break;
		}
		else if (button == 20)
		{
			// power button or OK
			((VOID_TWO_PARAM)0xA00D3C48)(this, 3);//iconTest::unknownG(this_param, 3);
			break;
		}
		else if (button == 9)
		{
			// power button or OK
			((VOID_TWO_PARAM)0xA00D3C70)(this, 1); // sub_A00D3C70(this_param, 1);
			break;
		}
		else if (
			button != 21 &&
			button != 22 &&
			button != 23 &&
			button != 24 &&
			button != 34 &&
			button != 35)
		{
			char* buffer = (char*)malloc(150);
			if (buffer != NULL)
			{
				sprintf(buffer, "invalid key: %d", button);
				iconDisplayTxt(api, buffer);
				free(buffer);
			}
			break;
		}

		if (alreadyExecuted == ALREADY_EXECUTED_VALUE)
		{
			iconDisplayTxt(api, "Error: already executed");
			break;
		}

		// great we have been called by a valid button press
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

		loaded = TRUE;

	} while (FALSE);

	if (handle != 0)
	{
		fileAPI->api->CloseFileHandle(fileAPI, handle);
	}

	if (loaded)
	{
		// now execute our code
		iconDisplayTxt(api, "Code executed");
		((EXECUTE)PARASITE_PATCH_LOCATION)(this, button);
		alreadyExecuted = ALREADY_EXECUTED_VALUE;
	}
}
