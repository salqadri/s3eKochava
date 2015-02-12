# s3eKochava
Kochava SDK for Marmalade

## Supported Platforms
 * Android

## Integration
Please follow the docs for Kochava integration, such as their instructions on modifying your Android manifest file.

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
