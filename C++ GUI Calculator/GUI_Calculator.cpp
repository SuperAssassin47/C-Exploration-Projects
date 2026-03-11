#include <windows.h>
#include <stdio.h>

//Global Variables
HWND hDisplay;
int storedValue = 0;
wchar_t currentOperator = 0;
bool enteringSecondNumber = false;

// Allocates 256 CHARs of Memory Location to store one string
// It also becomes a place to store the current number
wchar_t displayBuffer[256] = L"";


/*WndProc --> The Windows Procedure

--> Windows calls this function whenever an event happens within this GUI Window.
--> An event could be: painting, resizing, key presses, button clicks,
or closing the window itself.
--> This function basically decide how the GUI Window responds to each message here.*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_COMMAND: // button_click event handler
	{
		int id = LOWORD(wParam); // gives the button ID

		// SetWindowText updates the display box

		switch (id) {
		case 1: // Button 1
			wcscat_s(displayBuffer, L"1"); // appends CHAR to existing STR
			SetWindowText(hDisplay, displayBuffer); // updates display with new INT
			break;
		case 2: // Button 2
			wcscat_s(displayBuffer, L"2");
			SetWindowText(hDisplay, displayBuffer);
			break;
		case 3: // Button 3
			wcscat_s(displayBuffer, L"3");
			SetWindowText(hDisplay, displayBuffer);
			break;
		case 4:
			wcscat_s(displayBuffer, L"4");
			SetWindowText(hDisplay, displayBuffer);
			break;
		case 5:
			wcscat_s(displayBuffer, L"5");
			SetWindowText(hDisplay, displayBuffer);
			break;
		case 6:
			wcscat_s(displayBuffer, L"6");
			SetWindowText(hDisplay, displayBuffer);
			break;
		case 7:
			wcscat_s(displayBuffer, L"7");
			SetWindowText(hDisplay, displayBuffer);
			break;
		case 8:
			wcscat_s(displayBuffer, L"8");
			SetWindowText(hDisplay, displayBuffer);
			break;
		case 9:
			wcscat_s(displayBuffer, L"9");
			SetWindowText(hDisplay, displayBuffer);
			break;
		case 100:
			wcscat_s(displayBuffer, L"0");
			SetWindowText(hDisplay, displayBuffer);
			break;
		case 11:
			displayBuffer[0] = L'\0';
			storedValue = 0;
			currentOperator = 0;
			enteringSecondNumber = false;
			SetWindowText(hDisplay, L"");
			break;
		case 12: // add button
			storedValue = _wtoi(displayBuffer);
			currentOperator = L'+';
			displayBuffer[0] = L'\0';
			enteringSecondNumber = true;
			break;
		case 13: // subtract button
			storedValue = _wtoi(displayBuffer);
			currentOperator = L'-';
			displayBuffer[0] = L'\0';
			enteringSecondNumber = true;
			break;
		case 14: // multiply button
			storedValue = _wtoi(displayBuffer);
			currentOperator = L'*';
			displayBuffer[0] = L'\0';
			enteringSecondNumber = true;
			break;
		case 15: // divide button
			storedValue = _wtoi(displayBuffer);
			currentOperator = L'/';
			displayBuffer[0] = L'\0';
			enteringSecondNumber = true;
			break;
		case 16: // modulo button
			storedValue = _wtoi(displayBuffer);
			currentOperator = L'%';
			displayBuffer[0] = L'\0';
			enteringSecondNumber = true;
			break;
		case 17:
		{
			int secondValue = _wtoi(displayBuffer);
			int result = 0;

			switch (currentOperator) {
				case L'+':
					result = storedValue + secondValue;
					break;
				case L'-':
					result = storedValue - secondValue;
					break;
				case L'*':
					result = storedValue * secondValue;
					break;
				case L'/':
					if (secondValue != 0)
					{
						result = storedValue / secondValue;
					}
					else {
						result = 0;
					}
					break;
				case L'%':
					if (secondValue != 0)
					{
						result = storedValue % secondValue;
					}
					else {
						result = 0;
					}
					break;
			}

			swprintf_s(displayBuffer, 256, L"%d", result);
			SetWindowText(hDisplay, displayBuffer);

			storedValue = result;
			currentOperator = 0;
			enteringSecondNumber = false;
		}
		break;
		}

		break;
	}
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return 0;
}

/*WinMain --> The Window Entry Point

--> This is the main entry point for any Windows GUI Application.
--> This function REGISTERS the window class, creates/draws the Parent Window,
and runs the message loop. Basically, this function keeps the window responsive.
--> The program remains alive until the message loop terminates.*/
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow)
{
	WNDCLASS wc = { 0 };
	wc.lpfnWndProc = WndProc;
	wc.hInstance = hInst;
	wc.lpszClassName = L"CalcWindowClass";

	RegisterClass(&wc);

	//creating the Main Window (the shell)
	HWND hWnd = CreateWindow(
		L"CalcWindowClass",
		L"GUI Calculater",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		100, 100, 400, 400,
		NULL, NULL, hInst, NULL
	);

	// creating the display box
	hDisplay = CreateWindow(
		L"EDIT",
		L"",
		WS_CHILD | WS_VISIBLE | ES_RIGHT | ES_READONLY | WS_BORDER,
		10, 10, 360, 40,
		hWnd,
		NULL,
		hInst,
		NULL
	);

	// creating three visible buttons 1, 2, 3
	CreateWindow(
		L"BUTTON", L"1",
		WS_CHILD | WS_VISIBLE,
		10, 60, 60, 60,
		hWnd,
		(HMENU)1, // button ID
		hInst,
		NULL
	);

	CreateWindow(
		L"BUTTON", L"2",
		WS_CHILD | WS_VISIBLE,
		80, 60, 60, 60,
		hWnd,
		(HMENU)2, // button ID
		hInst,
		NULL
	);

	CreateWindow(
		L"BUTTON", L"3",
		WS_CHILD | WS_VISIBLE,
		150, 60, 60, 60,
		hWnd,
		(HMENU)3, // button ID
		hInst,
		NULL
	);

	// creating buttons 4, 5, 6
	CreateWindow(
		L"BUTTON", L"4",
		WS_CHILD | WS_VISIBLE,
		10, 130, 60, 60,
		hWnd,
		(HMENU)4, // button ID
		hInst,
		NULL
	);

	CreateWindow(
		L"BUTTON", L"5",
		WS_CHILD | WS_VISIBLE,
		80, 130, 60, 60,
		hWnd,
		(HMENU)5, // button ID
		hInst,
		NULL
	);

	CreateWindow(
		L"BUTTON", L"6",
		WS_CHILD | WS_VISIBLE,
		150, 130, 60, 60,
		hWnd,
		(HMENU)6, // button ID
		hInst,
		NULL
	);

	// creating buttons 7, 8, 9
	CreateWindow(
		L"BUTTON", L"7",
		WS_CHILD | WS_VISIBLE,
		10, 200, 60, 60,
		hWnd,
		(HMENU)7, // button ID
		hInst,
		NULL
	);

	CreateWindow(
		L"BUTTON", L"8",
		WS_CHILD | WS_VISIBLE,
		80, 200, 60, 60,
		hWnd,
		(HMENU)8, // button ID
		hInst,
		NULL
	);

	CreateWindow(
		L"BUTTON", L"9",
		WS_CHILD | WS_VISIBLE,
		150, 200, 60, 60,
		hWnd,
		(HMENU)9, // button ID
		hInst,
		NULL
	);

	// creating the button 0
	CreateWindow(
		L"BUTTON", L"0",
		WS_CHILD | WS_VISIBLE,
		10, 270, 200, 60,
		hWnd,
		(HMENU)100, // button ID
		hInst,
		NULL
	);

	// creating the All Clear (AC) button
	CreateWindow(
		L"BUTTON", L"AC",
		WS_CHILD | WS_VISIBLE,
		220, 60, 60, 60,
		hWnd,
		(HMENU)11, // button ID
		hInst,
		NULL
	);

	// creating the arithmetical buttons
	CreateWindow(
		L"BUTTON", L"+",
		WS_CHILD | WS_VISIBLE,
		300, 60, 60, 60,
		hWnd,
		(HMENU)12, // button ID
		hInst,
		NULL
	);

	CreateWindow(
		L"BUTTON", L"-",
		WS_CHILD | WS_VISIBLE,
		220, 130, 60, 60,
		hWnd,
		(HMENU)13, // button ID
		hInst,
		NULL
	);

	CreateWindow(
		L"BUTTON", L"*",
		WS_CHILD | WS_VISIBLE,
		300, 130, 60, 60,
		hWnd,
		(HMENU)14, // button ID
		hInst,
		NULL
	);

	CreateWindow(
		L"BUTTON", L"/",
		WS_CHILD | WS_VISIBLE,
		220, 200, 60, 60,
		hWnd,
		(HMENU)15, // button ID
		hInst,
		NULL
	);

	CreateWindow(
		L"BUTTON", L"%",
		WS_CHILD | WS_VISIBLE,
		300, 200, 60, 60,
		hWnd,
		(HMENU)16,
		hInst,
		NULL
	);

	// creating the equals (=) button
	CreateWindow(
		L"BUTTON", L"=",
		WS_CHILD | WS_VISIBLE,
		220, 270, 140, 60,
		hWnd,
		(HMENU)17, // button ID
		hInst,
		NULL
	);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}
