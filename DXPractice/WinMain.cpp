#include "Window.h"

int CALLBACK WinMain(	HINSTANCE hInstance,
					HINSTANCE hPrevInstance,
					LPSTR    lpCmdLine,
					int       nCmdShow)
{
	try
	{
		Window wnd(800, 300, L"Siwei Test Window");
		MSG msg;
		BOOL gResult;
		while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		if (gResult == -1)
		{
			return -1;
		}
		return msg.wParam;
	}
	catch (const ChiliException& e)
	{
		size_t convertedChars = 0;
		wchar_t wtext[100];
		size_t wconvertedChars = 0;
		wchar_t wTypetext[100];
		mbstowcs_s(&convertedChars,wtext,e.what(),strlen(e.what())+1);
		mbstowcs_s(&wconvertedChars,wTypetext, e.GetType(), strlen(e.GetType()) + 1);
		MessageBox(nullptr, wtext, wTypetext, MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception& e)
	{
		size_t convertedChars = 0;
		wchar_t wtext[100];
		mbstowcs_s(&convertedChars,wtext, e.what(), strlen(e.what()) + 1);
		MessageBox(nullptr, wtext, L"Standard Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBox(nullptr, L"No details available", L"Unknown Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	return -1;
}

