/**
 * Enable debug in the header file
 */
#include <ADebug.h>

void setup() {
	
	debugInfo("Setup");
	debugInfo("Setup Done");
	debugWarn("Something is wrong");
	debugError("Critical error");
	
}

void loop() {
	;
}