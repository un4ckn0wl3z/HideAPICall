#include <windows.h>

typedef int (WINAPI* DynamicMessageBoxFn)(HWND wnd, LPCSTR message, LPCSTR title, UINT icon);

int __stdcall DynamicMessageBox(HWND wnd, LPCSTR message, LPCSTR title, UINT icon)
{
	BOOL FreeResult = 0, RuntimeLinkSuccess = 0;
	HMODULE LibHandle = 0;
	DynamicMessageBoxFn dnMsgBox = 0;
	LibHandle = LoadLibrary("user32.dll");
	if (LibHandle != NULL) 
	{
		dnMsgBox = (DynamicMessageBoxFn)GetProcAddress(LibHandle, "MessageBoxA");
		if (RuntimeLinkSuccess = (dnMsgBox != NULL) ) 
		{
			int ReturnResult = dnMsgBox( wnd,  message,  title,  icon);
		}
		FreeResult = FreeLibrary(LibHandle);
		return FreeResult;
	}
	return EXIT_FAILURE;

}

int main() {
	DynamicMessageBox(0, "Hello", "Test!", 0);
}