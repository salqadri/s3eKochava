/*
 * android-specific implementation of the s3eKochava extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "s3eKochava_internal.h"

#include "s3eEdk.h"
#include "s3eEdk_android.h"
#include <jni.h>
#include "IwDebug.h"

static jobject g_Obj;
static jmethodID g_s3eKochavaCreate;
static jmethodID g_s3eKochavaEvent;
static jmethodID g_s3eKochavaEventSpatial;
static jmethodID g_s3eKochavaDeepLinkEvent;
static jmethodID g_s3eKochavaEnableDebug;
static jmethodID g_s3eKochavaSetErrorDebug;

s3eResult s3eKochavaInit_platform()
{
    // Get the environment from the pointer
    JNIEnv* env = s3eEdkJNIGetEnv();
    jobject obj = NULL;
    jmethodID cons = NULL;

    // Get the extension class
    jclass cls = s3eEdkAndroidFindClass("s3eKochava");
    if (!cls)
        goto fail;

    // Get its constructor
    cons = env->GetMethodID(cls, "<init>", "()V");
    if (!cons)
        goto fail;

    // Construct the java class
    obj = env->NewObject(cls, cons);
    if (!obj)
        goto fail;

    // Get all the extension methods
    g_s3eKochavaCreate = env->GetMethodID(cls, "s3eKochavaCreate", "(Ljava/lang/String;)V");
    if (!g_s3eKochavaCreate)
        goto fail;

    g_s3eKochavaEvent = env->GetMethodID(cls, "s3eKochavaEvent", "(Ljava/lang/String;Ljava/lang/String;)V");
    if (!g_s3eKochavaEvent)
        goto fail;

    g_s3eKochavaEventSpatial = env->GetMethodID(cls, "s3eKochavaEventSpatial", "(Ljava/lang/String;IIILjava/lang/String;)V");
    if (!g_s3eKochavaEventSpatial)
        goto fail;

    g_s3eKochavaDeepLinkEvent = env->GetMethodID(cls, "s3eKochavaDeepLinkEvent", "(Ljava/lang/String;)V");
    if (!g_s3eKochavaDeepLinkEvent)
        goto fail;

    g_s3eKochavaEnableDebug = env->GetMethodID(cls, "s3eKochavaEnableDebug", "(Z)V");
    if (!g_s3eKochavaEnableDebug)
        goto fail;

    g_s3eKochavaSetErrorDebug = env->GetMethodID(cls, "s3eKochavaSetErrorDebug", "(Z)V");
    if (!g_s3eKochavaSetErrorDebug)
        goto fail;



    IwTrace(KOCHAVA, ("KOCHAVA init success"));
    g_Obj = env->NewGlobalRef(obj);
    env->DeleteLocalRef(obj);
    env->DeleteGlobalRef(cls);

    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;

fail:
    jthrowable exc = env->ExceptionOccurred();
    if (exc)
    {
        env->ExceptionDescribe();
        env->ExceptionClear();
        IwTrace(s3eKochava, ("One or more java methods could not be found"));
    }

    env->DeleteLocalRef(obj);
    env->DeleteGlobalRef(cls);
    return S3E_RESULT_ERROR;

}

void s3eKochavaTerminate_platform()
{ 
    // Add any platform-specific termination code here
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->DeleteGlobalRef(g_Obj);
    g_Obj = NULL;
}

void s3eKochavaCreate_platform(const char* appId)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring appId_jstr = env->NewStringUTF(appId);
    env->CallVoidMethod(g_Obj, g_s3eKochavaCreate, appId_jstr);
}

void s3eKochavaEvent_platform(const char* eventName, const char* eventData)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring eventName_jstr = env->NewStringUTF(eventName);
    jstring eventData_jstr = env->NewStringUTF(eventData);
    env->CallVoidMethod(g_Obj, g_s3eKochavaEvent, eventName_jstr, eventData_jstr);
}

void s3eKochavaEventSpatial_platform(const char* eventName, int x, int y, int z, const char* eventData)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring eventName_jstr = env->NewStringUTF(eventName);
    jstring eventData_jstr = env->NewStringUTF(eventData);
    env->CallVoidMethod(g_Obj, g_s3eKochavaEventSpatial, eventName_jstr, x, y, z, eventData_jstr);
}

void s3eKochavaDeepLinkEvent_platform(const char* uri)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring uri_jstr = env->NewStringUTF(uri);
    env->CallVoidMethod(g_Obj, g_s3eKochavaDeepLinkEvent, uri_jstr);
}

void s3eKochavaEnableDebug_platform(bool value)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_s3eKochavaEnableDebug, value);
}

void s3eKochavaSetErrorDebug_platform(bool value)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_s3eKochavaSetErrorDebug, value);
}
