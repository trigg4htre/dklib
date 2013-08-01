#include "DKDebug.h"

void DKDebug(int text){ DKDebug(toString(text)); }
void DKDebug(float text){ DKDebug(toString(text)); }

///////////////////////////
void DKDebug(DKString text)
{
#ifdef WIN32
	OutputDebugString(text.c_str());
#endif

#ifdef MAC
	NSLog(@"%s", text.c_str());
#endif

#ifdef IOS
	NSLog(@"%s", text.c_str());
#endif

#ifdef ANDROID
	__android_log_print(ANDROID_LOG_VERBOSE, "DigitalKnob", text.c_str());
#endif
}