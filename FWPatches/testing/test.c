#include "include\Common.h"
#include "include\Memory.h"
#include "include\File.h"
#include "include\Execution.h"
#include "include\Display.h"
#include "include\Utilities.h"
#include "include\Strings.h"

#include "symbols.h"



//typedef void* (*NO_PARAM)(void);
//#define UnknownNoArgs ((showRebuildFirmwareMessage)0xA01A0A8C)

//typedef void (*VOID_ONE_PARAM)(void*);
//typedef void (*VOID_TWO_PARAM)(void*, int);
//typedef void (*VOID_THREE_PARAM)(void*, int, int);
//typedef int(*INT_ONE_PARAM)(void*);

int index = 0;

void iconMenuHandleButtonPress(void *this, int button, unsigned short increment)
{
	/*
	void* api;

	char* buffer;
	const char* LINE_1 = "LOOKS LIKE";
	const char* LINE_2 = "IM RUNNING";
	const char* LINE_3 = "CODE ON";
	const char* LINE_4 = "MY K30";
	const char* LINE_5 = "SHODAN!";

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
				api = iconDisplayAPI(this, 0x1406002);
				char * line;
				switch (index)
				{
				case 0: line = LINE_1; break;
				case 1: line = LINE_2; break;
				case 2: line = LINE_3; break;
				case 3: line = LINE_4; break;
				case 4: line = LINE_5; break;
				default: line = LINE_1; index = 0; break;
				}

				++index;

				sprintf(buffer, line);
				iconDisplayTxt(api, buffer);

				free(buffer);
			}
			break;
		default:
			break;
	}*/
}
