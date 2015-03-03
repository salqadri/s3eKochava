# s3eKochava
Kochava SDK for Marmalade

## Supported Platforms
 * Android
 * iOS

## Android Integration
Please follow the Kochava docs for Android integration, in particular their instructions on adding the `install_referrer` receiver. You need to do this yourself as this extension does not know if you have any other existing `install_referrer` receivers (Android only allows one). This extension will already add the permissions required by Kochava, except for the optional `GET_ACCOUNTS` permission for email tracking. You will need to add that yourself if you want it.

## iOS Integration
This extension already links against the required frameworks for iOS.

## API usage
Most APIs are implemented, except for the attribution data and identity APIs.

### Initialization
In your app initialization do:
```
	if (s3eKochavaAvailable())
	{
		if (s3eDeviceGetInt(S3E_DEVICE_OS) == S3E_OS_ID_ANDROID)
		{
			s3eKochavaEnableDebug(true); // If you want more debug info
			s3eKochavaCreate("kochava_android_appid");
		}
		else if (s3eDeviceGetInt(S3E_DEVICE_OS) == S3E_OS_ID_IPHONE)
		{
			s3eKochavaEnableDebug(true); // If you want more debug info
			s3eKochavaCreate("kochava_ios_appid");
		}
	}
```

### Post-Install Event Logging
```
s3eKochavaEvent("eventName", "eventValue");
```
