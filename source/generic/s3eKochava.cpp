/*
Generic implementation of the s3eKochava extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "s3eKochava_internal.h"
s3eResult s3eKochavaInit()
{
    //Add any generic initialisation code here
    return s3eKochavaInit_platform();
}

void s3eKochavaTerminate()
{
    //Add any generic termination code here
    s3eKochavaTerminate_platform();
}

void s3eKochavaCreate(const char* appId)
{
	s3eKochavaCreate_platform(appId);
}

void s3eKochavaEvent(const char* eventName, const char* eventData)
{
	s3eKochavaEvent_platform(eventName, eventData);
}

void s3eKochavaEventSpatial(const char* eventName, int x, int y, int z, const char* eventData)
{
	s3eKochavaEventSpatial_platform(eventName, x, y, z, eventData);
}

void s3eKochavaDeepLinkEvent(const char* uri)
{
	s3eKochavaDeepLinkEvent_platform(uri);
}

void s3eKochavaEnableDebug(bool value)
{
	s3eKochavaEnableDebug_platform(value);
}

void s3eKochavaSetErrorDebug(bool value)
{
	s3eKochavaSetErrorDebug_platform(value);
}
