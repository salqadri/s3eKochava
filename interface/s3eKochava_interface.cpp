/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */

#include "s3eExt.h"
#include "IwDebug.h"
#include "s3eDevice.h"


#include "s3eKochava.h"


#ifndef S3E_EXT_SKIP_LOADER_CALL_LOCK
// For MIPs (and WP8) platform we do not have asm code for stack switching
// implemented. So we make LoaderCallStart call manually to set GlobalLock
#if defined __mips || defined S3E_ANDROID_X86 || (defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP))
#define LOADER_CALL_LOCK
#endif
#endif

/**
 * Definitions for functions types passed to/from s3eExt interface
 */
typedef       void(*s3eKochavaCreate_t)(const char* appId);
typedef       void(*s3eKochavaEvent_t)(const char* eventName, const char* eventData);
typedef       void(*s3eKochavaEventSpatial_t)(const char* eventName, int x, int y, int z, const char* eventData);
typedef       void(*s3eKochavaDeepLinkEvent_t)(const char* uri);
typedef       void(*s3eKochavaEnableDebug_t)(bool value);
typedef       void(*s3eKochavaSetErrorDebug_t)(bool value);

/**
 * struct that gets filled in by s3eKochavaRegister
 */
typedef struct s3eKochavaFuncs
{
    s3eKochavaCreate_t m_s3eKochavaCreate;
    s3eKochavaEvent_t m_s3eKochavaEvent;
    s3eKochavaEventSpatial_t m_s3eKochavaEventSpatial;
    s3eKochavaDeepLinkEvent_t m_s3eKochavaDeepLinkEvent;
    s3eKochavaEnableDebug_t m_s3eKochavaEnableDebug;
    s3eKochavaSetErrorDebug_t m_s3eKochavaSetErrorDebug;
} s3eKochavaFuncs;

static s3eKochavaFuncs g_Ext;
static bool g_GotExt = false;
static bool g_TriedExt = false;
static bool g_TriedNoMsgExt = false;

static bool _extLoadNoMsg()
{
    if (!g_GotExt && !g_TriedNoMsgExt)
    {
        s3eResult res = s3eExtGetHash(0xa7eec10d, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        g_TriedNoMsgExt = true;
        if (g_TriedExt)
            g_TriedExt = true;
    }

    return g_GotExt;
}

s3eBool s3eKochavaAvailable()
{
    _extLoadNoMsg();
    return g_GotExt ? S3E_TRUE : S3E_FALSE;
}

void s3eKochavaCreate(const char* appId)
{
    IwTrace(KOCHAVA_VERBOSE, ("calling s3eKochava[0] func: s3eKochavaCreate"));

    if (!_extLoadNoMsg())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eKochavaCreate(appId);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eKochavaEvent(const char* eventName, const char* eventData)
{
    IwTrace(KOCHAVA_VERBOSE, ("calling s3eKochava[1] func: s3eKochavaEvent"));

    if (!_extLoadNoMsg())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eKochavaEvent(eventName, eventData);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eKochavaEventSpatial(const char* eventName, int x, int y, int z, const char* eventData)
{
    IwTrace(KOCHAVA_VERBOSE, ("calling s3eKochava[2] func: s3eKochavaEventSpatial"));

    if (!_extLoadNoMsg())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eKochavaEventSpatial(eventName, x, y, z, eventData);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eKochavaDeepLinkEvent(const char* uri)
{
    IwTrace(KOCHAVA_VERBOSE, ("calling s3eKochava[3] func: s3eKochavaDeepLinkEvent"));

    if (!_extLoadNoMsg())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eKochavaDeepLinkEvent(uri);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eKochavaEnableDebug(bool value)
{
    IwTrace(KOCHAVA_VERBOSE, ("calling s3eKochava[4] func: s3eKochavaEnableDebug"));

    if (!_extLoadNoMsg())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eKochavaEnableDebug(value);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eKochavaSetErrorDebug(bool value)
{
    IwTrace(KOCHAVA_VERBOSE, ("calling s3eKochava[5] func: s3eKochavaSetErrorDebug"));

    if (!_extLoadNoMsg())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eKochavaSetErrorDebug(value);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}
