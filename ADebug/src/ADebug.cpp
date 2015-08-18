/*
 * Debug.cpp
 *
 *  Created on: Jul 18, 2015
 *      Author: syroegkin
 */
#include "ADebug.h"

#if ADEBUG_STATUS == 1

unsigned char ADebug::wasInit = 0;

ErrorTypes ADebug::etypes;

/**
 * Initialize Serial interface
 */
void ADebug::init(void) {
	if(ADebug::wasInit != 1){

#if ADEBUG_INFO == 1
		ADebug::etypes.i = "[Info]: ";
#endif
#if ADEBUG_WARN == 1
		ADebug::etypes.w = "[Warn]: ";
#endif
#if ADEBUG_ERR == 1
		ADebug::etypes.e = "[Error]: ";
#endif

		// Open serial communications and wait for port to open:
		Serial.begin(9600);
		while(!Serial); // for the Arduino Leonardo/Micro only
		ADebug::wasInit = 1;
	}
}

/**
 * Write a message to the log
 */
void ADebug::write(const char* type, const char* message) {
	ADebug::init();
	Serial.print(type);
	Serial.print("\t");
	Serial.print(message);
	Serial.print("\n");
}

/**
 * Displaying info
 */
void ADebug::info(const char * message) {
#if ADEBUG_INFO == 1
	ADebug::write(etypes.i, message);
#endif
}

/**
 * Displaying warning
 */
void ADebug::warning(const char * message) {
#if ADEBUG_WARN == 1
	ADebug::write(etypes.w, message);
#endif
}

/**
 * Displaying Error
 */
void ADebug::error(const char * message) {
#if ADEBUG_ERR == 1
	ADebug::write(etypes.e, message);
#endif
}

#endif

