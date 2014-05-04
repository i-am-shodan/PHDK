#include "include\Common.h"
#include "include\Memory.h"
#include "include\File.h"
#include "include\Execution.h"
#include "include\Display.h"
#include "include\Utilities.h"

#include "symbols.h"

typedef volatile void*(*xgetDisplayAPI)();

typedef void(*xTEST)(
	void *thisp, 
	char *txtToDisplay, 
	int column, 
	int line, 
	int lineOffset, 
	int columnOffset, 
	int a7, 
	int colour, 
	int txtStyle);

int test(void* this_debug, void* b)
{
	char* menuTxt = (char*)SYM_DEVELOPMENT_MENU_THREE_STR;

	*menuTxt = 'H';
	*(menuTxt + 1) = 'A';
	*(menuTxt + 2) = 'C';
	*(menuTxt + 3) = 'K';
	*(menuTxt + 4) = 'E';
	*(menuTxt + 5) = 'D';
	*(menuTxt + 6) = '\0';

	threadWait(1000);

	return 1;
}
