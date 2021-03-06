#include <windows.h>
#include <WinUser.h>

#define UnusedParam(x)(void)(x)


int wmain(int , wchar_t* [])
{
	wWinMain(GetModuleHandle(0), 0, 0, SW_SHOW);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance/*always null*/, wchar_t* lpdCmdLine , int nCmdShow)
{
	wchar_t const* engineName = L"Vita3D";

	WNDCLASSEX windowsClass{0};
	windowsClass.cbSize = sizeof(windowsClass);
	windowsClass.style = CS_OWNDC;
	windowsClass.lpfnWndProc = DefWindowProc;
	windowsClass.lpszClassName = engineName;
	windowsClass.hInstance = hInstance;

	RegisterClassEx(&windowsClass);

	HWND windowHandle = CreateWindowEx(
		0,
		engineName,
		L"Vitabiskoek",
		WS_OVERLAPPED | WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200, 640, 480,
		nullptr,
		nullptr,
		hInstance,
		nullptr);

	ShowWindow(windowHandle, nCmdShow);
	

	UnusedParam(hPrevInstance);
	UnusedParam(lpdCmdLine);
}
