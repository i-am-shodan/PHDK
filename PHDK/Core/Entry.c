#include "include\Common.h"
#include "include\Memory.h"
#include "include\File.h"
#include "include\Execution.h"
#include "include\Display.h"
#include "include\Utilities.h"
#include "include\Strings.h"

#include "symbols.h"

void main(void *this_original_caller, int button_pressed)
{
	const void* api = iconDisplayAPI(this_original_caller, 0x1406002);
	iconDisplayTxt(api, "It worked!");
}