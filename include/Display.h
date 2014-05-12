#pragma once

typedef int* SCREEN_LOCATION;

typedef volatile SCREEN_LOCATION(*xGETSCREEN)();
typedef void(*xDISPLAYTXT)(SCREEN_LOCATION screen, int line, int column, char *txt, int sizeMaybe);
typedef void(*xCLEARSCREEN)(SCREEN_LOCATION screen);
typedef void*(*xICONDISPLAYAPI)(const void*, int);
typedef void(*xDISPLAYICONTXT)(const void*, char *);

#define getScreen ((xGETSCREEN)SYM_GETSCREEN)
#define displayTxt ((xDISPLAYTXT)SYM_DISPLAYTXT)
#define clearScreen ((xCLEARSCREEN)SYM_CLEARSCREEN)

#define iconDisplayAPI ((xICONDISPLAYAPI)SYM_ICONDISPLAYAPI)
#define iconDisplayTxt ((xDISPLAYICONTXT)SYM_ICONDISPLAYTXT)


// this_param - this ptr
// line - Line on which the text should be display
//		  1=Top line, 
//		  2-7=
//		  9 = bottom line
// column - offset into the line
// txtToDisplay - the txt to display
// color - 4=white,21=red,29=blue
// txt_style - 0 for normal, 29=menu style
// unknown - seems to display a question mark
//extern void displayTxt(
//	const DISPLAY_API displayAPI, 
//	const char *txtToDisplay,
//	const int column,
//	const int line, 
//	const int lineOffset,
//	const int columnOffset,
//	const int unknown,
//	const int colour, 
//	const int txt_style);

typedef void* menu;

#define BUTTON_SHUTTER_HALFPRESS 0
#define BUTTON_SHUTTER_FULLPRESS 1
#define BUTTON_TRASH 5
#define BUTTON_LIVEVIEW 5
#define BUTTON_PLUSMINUS 6
#define BUTTON_GREEN 7
#define BUTTON_RAW 8
#define BUTTON_FX 8
#define BUTTON_PLAY 9
#define BUTTON_INFO 10
#define BUTTON_MENU 11
#define BUTTON_AF 12

#define BUTTON_FLASHPOPUP 19
#define BUTTON_OK 20
#define BUTTON_UP 21
#define BUTTON_ISO 21
#define BUTTON_DOWN 22
#define BUTTON_WHITEBALANCE 22
#define BUTTON_LEFT 23
#define BUTTON_FLASH 23
#define BUTTON_RIGHT 24
#define BUTTON_CLOCK 24

#define SWITCH_FOCUS 29

#define WHEEL_MODE 38
#define WHEEL_ZOOM_RIGHT 34
#define WHEEL_ZOOM_LEFT 35
#define WHEEL_FRONT_LEFT 33
#define WHEEL_FRONT_RIGHT 32

#define LENS_DETACH 39
#define LENS_ATTACH 3

