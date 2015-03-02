/*
 * iphone-specific implementation of the s3eKochava extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "s3eKochava_internal.h"

#include "TrackAndAd.h"
 
KochavaTracker *kochavaTracker = nil;

s3eResult s3eKochavaInit_platform()
{
    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;
}

void s3eKochavaTerminate_platform()
{ 
	if (kochavaTracker != nil)
	{
		[kochavaTracker release];
	}
}

void s3eKochavaCreate_platform(const char* appId)
{
	NSDictionary *initDict = [NSDictionary dictionaryWithObjectsAndKeys:
	[NSString stringWithUTF8String:appId], @"kochavaAppId",
	@"1", @"enableLogging", // optional - 0 is default
	nil];
	kochavaTracker = [[KochavaTracker alloc] initKochavaWithParams:initDict];
}

void s3eKochavaEvent_platform(const char* eventName, const char* eventData)
{
	[kochavaTracker trackEvent:[NSString stringWithUTF8String:eventName]
           					 :[NSString stringWithUTF8String:eventData]];
}

void s3eKochavaEventSpatial_platform(const char* eventName, int x, int y, int z, const char* eventData)
{
	[kochavaTracker spatialEvent:[NSString stringWithUTF8String:eventName]
           						:x
           						:y
           						:z];
}

void s3eKochavaDeepLinkEvent_platform(const char* uri)
{
	[kochavaTracker sendDeepLink:[NSURL URLWithString:[NSString stringWithUTF8String:uri]]:@""];
}

void s3eKochavaEnableDebug_platform(bool value)
{
	[kochavaTracker enableConsoleLogging:(value)?YES:NO];
}

void s3eKochavaSetErrorDebug_platform(bool value)
{
	s3eKochavaEnableDebug_platform(value);
}
