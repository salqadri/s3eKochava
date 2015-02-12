/*
 * Internal header for the s3eKochava extension.
 *
 * This file should be used for any common function definitions etc that need to
 * be shared between the platform-dependent and platform-indepdendent parts of
 * this extension.
 */

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#ifndef S3EKOCHAVA_INTERNAL_H
#define S3EKOCHAVA_INTERNAL_H

#include "s3eTypes.h"
#include "s3eKochava.h"
#include "s3eKochava_autodefs.h"


/**
 * Initialise the extension.  This is called once then the extension is first
 * accessed by s3eregister.  If this function returns S3E_RESULT_ERROR the
 * extension will be reported as not-existing on the device.
 */
s3eResult s3eKochavaInit();

/**
 * Platform-specific initialisation, implemented on each platform
 */
s3eResult s3eKochavaInit_platform();

/**
 * Terminate the extension.  This is called once on shutdown, but only if the
 * extension was loader and Init() was successful.
 */
void s3eKochavaTerminate();

/**
 * Platform-specific termination, implemented on each platform
 */
void s3eKochavaTerminate_platform();
void s3eKochavaCreate_platform(const char* appId);

void s3eKochavaEvent_platform(const char* eventName, const char* eventData);

void s3eKochavaEventSpatial_platform(const char* eventName, int x, int y, int z, const char* eventData);

void s3eKochavaDeepLinkEvent_platform(const char* uri);

void s3eKochavaEnableDebug_platform(bool value);

void s3eKochavaSetErrorDebug_platform(bool value);


#endif /* !S3EKOCHAVA_INTERNAL_H */