/*
java implementation of the s3eKochava extension.

Add android-specific functionality here.

These functions are called via JNI from native code.
*/
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
import com.ideaworks3d.marmalade.LoaderAPI;
// Comment in the following line if you want to use ResourceUtility
// import com.ideaworks3d.marmalade.ResourceUtility;

import com.ideaworks3d.marmalade.LoaderActivity;

import com.kochava.android.tracker.Feature;

class s3eKochava
{
	private Feature kTracker = null;
	
    public void s3eKochavaCreate(String appId)
    {
		java.util.HashMap<String, Object> dataMap = new java.util.HashMap<String, Object>();
		dataMap.put(Feature.INPUTITEMS.KOCHAVA_APP_ID, appId );
		kTracker = new Feature ( LoaderActivity.m_Activity, dataMap );
    }
    public void s3eKochavaEvent(String eventName, String eventData)
    {
		if (kTracker != null) {
			kTracker.event(eventName, eventData);
		}
    }
    public void s3eKochavaEventSpatial(String eventName, int x, int y, int z, String eventData)
    {
		if (kTracker != null) {
			kTracker.eventSpatial(eventName, x, y, z, eventData);
		}
    }
    public void s3eKochavaDeepLinkEvent(String uri)
    {
		if (kTracker != null) {
			kTracker.deepLinkEvent(uri);
		}
    }
    public void s3eKochavaEnableDebug(boolean value)
    {
		Feature.enableDebug(value);
    }
    public void s3eKochavaSetErrorDebug(boolean value)
    {
		Feature.setErrorDebug(value);
    }
}
