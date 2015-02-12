# s3eKochava
Kochava SDK for Marmalade

## Supported Platforms
 * Android

## Android Integration
Please follow the Kochava docs for Android integration, in particular their instructions on adding the `install_referrer` receiver. You need to do this yourself as this extension does not know if you have any other existing `install_referrer` receivers (Android only allows one). This extension will already add the permissions required by Kochava, except for the optional `GET_ACCOUNTS` permission for email tracking. You will need to add that yourself if you want it.

## API usage

### Initialization
In your app initialization do:
```
	if (s3eKochavaAvailable())
	{
		if (s3eDeviceGetInt(S3E_DEVICE_OS) == S3E_OS_ID_ANDROID)
		{
			s3eKochavaEnableDebug(true); // If you want more debug info
			s3eKochavaCreate("kored-card-rampage54dbbdfdafcbb");
		}
	}
```

### Post-Install Event Logging
```
s3eKochavaEvent("eventName", "eventValue");
```
