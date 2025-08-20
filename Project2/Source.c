#include "EnumerateCamera.h"

void main() {
	//Initalizing media foundation
	CoInitializeEx(NULL, COINIT_MULTITHREADED);
	hr = MFStartup(MF_VERSION, MFSTARTUP_FULL);

	if SUCCEEDED(hr) {
		camera_details cameras[10];
		UINT32 count, i, *handle = NULL;
		int ch, s_ch = 1, c,ind = 1;
		long value;

		printf("Starting application to enumerate\n");
		count = getCameraDetails(&cameras);
		printf("Choose the camera\n");
		for (i = 0; i < count; i++) {
			printf("%d: %s\n", i, cameras[i].name);
		}
		printf("Enter choice: ");
		scanf_s("%d", &ch);
		DeInitExtension(handle);
		if (InitExtensionUnit(cameras[ch].path, &handle)) {
			printf("Initialization successfull\n");
			while (ind != 3) {
				printf("1.Read firmware version\n2.Reset Device\n3.Exit\nEnter your choice: ");
				scanf_s("%d", &ind);
				if (ind == 1) {
					printf("Reading Firmware version\n");
					ReadFirmwareVersion(handle);
				}
				else if (ind == 2) {
					ResetDevice(handle);
					break;
				}
				//else if (ind == 3) {
				//	getUVCSettings(cameras[ch].ppDevices);
				//	//UVCSettings menu
				//	while (s_ch != 4) {
				//		printf("\nUVC Settings\n");
				//		printf("1.Brightness\n2.White Balance\n3.Exposure\n4.Exit\n");
				//		printf("Enter choice:");
				//		scanf_s("%d", &s_ch);
				//		if (s_ch == 1) {
				//			set_UVC_settings(cameras[ch].ppDevices, "Brightness");
				//		}
				//		else if (s_ch == 2) {
				//			set_UVC_settings(cameras[ch].ppDevices, "White Balance");
				//		}
				//		else if (s_ch == 3) {
				//			set_UVC_settings(cameras[ch].ppDevices, "Exposure");
				//		}
				//		else if (s_ch == 4) {
				//			break;
				//		}
				//		else {
				//			printf("Option Invalid. Choose another option\n");
				//		}
				//	}
				//}
				else if (ch == 3) {
					printf("Deinitializing extension unit\n");
					DeInitExtension(handle);
				}
				else {
					printf("Invalid option\n");
				}
			}
		}
	}
	MFShutdown();
}