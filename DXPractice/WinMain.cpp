#include <Windows.h>
#include <string>


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	// your code here ...
	switch (uMsg)
	{
	case WM_CLOSE:
		PostQuitMessage(69);
		break;
	case WM_KEYDOWN:
		if (wParam == 'F')
		{
			SetWindowTextA(hwnd,"Test");
		}
		break;
	case WM_CHAR:
	{
		static std::string title;
		title.push_back((char)wParam);
		SetWindowTextA(hwnd,title.c_str());
	}
		break;
	}
	
	

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int CALLBACK WinMain(	HINSTANCE hInstance,
					HINSTANCE hPrevInstance,
					LPSTR    lpCmdLine,
					int       nCmdShow)
{
	const wchar_t CLASS_NAME[] = L"hw3dbutts";
	
	WNDCLASS wc = {};

	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;

	RegisterClass(&wc);

	HWND hwnd = CreateWindowEx(
		0,                              // Optional window styles.
		CLASS_NAME,                     // Window class
		L"Learn to Program Windows",    // Window text
		WS_OVERLAPPEDWINDOW,            // Window style
		// Size and position
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL,       // Parent window    
		NULL,       // Menu
		hInstance,  // Instance handle
		NULL        // Additional application data
	);

	if (hwnd == NULL)
	{
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);

	//msg loop
	MSG msg = { };
	BOOL GetResult;
	while (GetResult = GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	if (GetResult == -1)
	{
		return -1;
	}

	return msg.wParam;
}

