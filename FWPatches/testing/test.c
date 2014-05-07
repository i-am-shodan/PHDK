#include "include\Common.h"
#include "include\Memory.h"
#include "include\File.h"
#include "include\Execution.h"
#include "include\Display.h"
#include "include\Utilities.h"
#include "include\Strings.h"

#include "symbols.h"

typedef void*(*xICONDISPLAYAPI)(void*, int);
#define iconDisplayAPI ((xICONDISPLAYAPI)0xA00D3D20)

typedef void* (*NO_PARAM)(void);
//#define UnknownNoArgs ((showRebuildFirmwareMessage)0xA01A0A8C)

typedef void (*VOID_ONE_PARAM)(void*);
typedef void (*VOID_TWO_PARAM)(void*, int);
typedef void (*VOID_THREE_PARAM)(void*, int, int);
typedef int(*INT_ONE_PARAM)(void*);

typedef void(*xDISPLAYICONTXT)(void*, char *);
#define iconDisplayTxt ((xDISPLAYICONTXT)0xA01A9FE8)

void iconMenuHandleButtonPress(void *this, int button, unsigned short increment)
{
	//char buffer[2];
	void* api;
	//int* apix;
	//int t;
	//void* newFunc;
	//int v3;

	char* buffer;
	const char* HELLO = "HELLO";

	switch (button)
	{
		case 10:
			// i wonder if this is the info button, it seems to interact with the same
			// id used in the display code. Maybe you register some text to be rendered later
			// on demand?

			// think this is some rendering thing
			((VOID_THREE_PARAM)0xA063333C)(this, 0, 0); //sub_A063333C(this, 0, 0);
			break;
		case 20:
			// power button or OK
			((VOID_TWO_PARAM)0xA00D3C48)(this, 3);//iconTest::unknownG(this_param, 3);
			break;
		case 9:
			// power button or OK
			((VOID_TWO_PARAM)0xA00D3C70)(this, 1); // sub_A00D3C70(this_param, 1);
			break;
		case 21:
		case 22:
		case 23:
		case 24:
		case 34:
		case 35:
			buffer = (char*) malloc(150);

			if (buffer != NULL)
			{
				//sprintf(buffer, "%s", "h");
				strcpy(buffer, HELLO);

				api = iconDisplayAPI(this, 0x1406002);
				iconDisplayTxt(api, buffer);
				free(buffer);
			}
			break;
		default:
			break;
	}
}
