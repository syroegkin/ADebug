/*
 * Debug.h
 *
 *  Created on: Jul 18, 2015
 *      Author: syroegkin
 */

#ifndef ADEBUG_SRC_ADEBUG_H_
#define ADEBUG_SRC_ADEBUG_H_

#include <Arduino.h>

/**
 * Debug levels
 * 1 - specific message type ON
 * 0 - specific message type OFF
 */
#ifndef ADEBUG_STATUS
#define ADEBUG_INFO	1
#endif

#ifndef ADEBUG_STATUS
#define ADEBUG_WARN	1
#endif

#ifndef ADEBUG_STATUS
#define ADEBUG_ERR	1
#endif

/**
 * If everything is quite, there is no needs to do anything
 */
#if ADEBUG_INFO == 0 && ADEBUG_WARN == 0 && ADEBUG_ERR == 0
#ifndef ADEBUG_STATUS
#define ADEBUG_STATUS 0
#endif
#endif

/**
 * This setting is about turn on/off debug mode
 * 0 - debug is off
 * 1 - debug is on
 * Default is 0
 */
#ifndef ADEBUG_STATUS
#define ADEBUG_STATUS 1
#endif


#if ADEBUG_STATUS == 1

/**
 * Structure with statuses reference
 */
struct ErrorTypes {
#if ADEBUG_INFO == 1
	const char* i;
#endif
#if ADEBUG_WARN == 1
	const char* w;
#endif
#if ADEBUG_ERR == 1
	const char* e;
#endif
};

/**
 * Debug related
 * Using log file on SD card or just Serial monitor
 */
class ADebug {

	private:
		static void write(const char* type, const char* message);
	protected:
	public:
		static ErrorTypes etypes;
		static unsigned char wasInit;
		static void init(void);
		static void info(const char* );
		static void warning(const char* );
		static void error(const char* );

};

#define debugInfo(m) ADebug::info(m)
#define debugWarn(m) ADebug::warning(m);
#define debugError(m) ADebug::error(m);
#else
#define debugInfo(m) ;
#define debugWarn(m) ;
#define debugError(m) ;

#endif


#endif /* ADEBUG_SRC_ADEBUG_H_ */
