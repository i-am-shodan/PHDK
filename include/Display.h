#pragma once

typedef void* DISPLAY_API;

DISPLAY_API getDisplayAPI();

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
extern void displayTxt(
	const DISPLAY_API displayAPI, 
	const char *txtToDisplay,
	const int column,
	const int line, 
	const int lineOffset,
	const int columnOffset,
	const int unknown,
	const int colour, 
	const int txt_style);
