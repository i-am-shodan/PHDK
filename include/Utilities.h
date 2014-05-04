#pragma once

typedef void(*xTHREADWAIT)(int timeInMs);
#define threadWait ((xTHREADWAIT)SYM_THREADWAIT)

int GetCameraDebugId();

int GetProductNumber();
