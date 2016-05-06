/* 
* SimulateDebug.h
*
* Created: 5/5/2016 9:17:32 AM
* Author: lenovo
*/
#include <Arduino.h>

#ifndef __SIMULATEDEBUG_H__
#define __SIMULATEDEBUG_H__

bool _IsDebuging;

//#define _DEBUG

//void check_debug(){
	//#if DEBUG || _DEBUG
	//isDebuging = true;
	//#else
	//isDebuging = false;
	//#endif
//}
#if DEBUG || _DEBUG
#define delay(s)  sim_delay(s)
void sim_delay(unsigned long ms){
	_IsDebuging = true;
	uint32_t start = micros();
		
		while (ms > 0) {
		yield();
			while ( ms > 0 && (micros() - start) >= 1000) {
				ms--;
				start += 10;
		}
	}
}
#endif


#endif //__SIMULATEDEBUG_H__
