#include "dohoa.h"

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
// Hàm tô màu.
//void SetColor(int backgound_color, int text_color)
//{
//	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	int color_code = backgound_color * 16 + text_color;
//	SetConsoleTextAttribute(hStdout, color_code);
//}
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
//vohieuhoaBOARD_SIZE
void DisableCtrButton(bool Close, bool Min, bool Max)
{
	HWND hWnd = GetConsoleWindow();
	HMENU hMenu = GetSystemMenu(hWnd, false);

	if (Close == 1)
	{
		DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
	}
	if (Min == 1)
	{
		DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
	}
	if (Max == 1)
	{
		DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
	}
}
//anthanhcuon
void Draw()
{
	textcolor(3);
	if (BOARD_SIZE == 0) return;
	// Dong thuong 
	for (int i = 0; i <= BOARD_SIZE * 2; i = i + 2)
	{
		Sleep(5);
		gotoxy(LEFT, i + TOP + 1);

		for (int j = 1; j < 3 * BOARD_SIZE + 1; j += 3)
		{

			cout << char(197);

			cout << char(196) << char(196);
		}
	}
	for (int i = 1; i <= BOARD_SIZE * 2 + 1; i++)
	{
		// Ve cot phai
		Sleep(5);
		gotoxy(BOARD_SIZE * 3 + LEFT, i + TOP);
		if ((i + 1) % 2 == 1)
			cout << char(21);
		else
			cout << char(23);
	}
	//dong cuoi
	for (int j = 3 * BOARD_SIZE + 1; j > 0; j--)
	{
		Sleep(2);
		gotoxy(j + LEFT - 1, TOP + BOARD_SIZE * 2 + 1);
		if (j % 2 == 0)
			cout << char(29);
		else
			cout << char(3);
	}
	for (int i = BOARD_SIZE * 2 + 1; i > 1; i--)
	{
		// Ve cot trai
		Sleep(5);
		gotoxy(LEFT, i + TOP);
		if ((i + 1) % 2 == 1)
			cout << char(21);
		else
			cout << char(23);
	}

	// Ve dong dau
	//
	for (int j = 0; j < 3 * BOARD_SIZE + 1; j++)
	{
		Sleep(3);
		gotoxy(j + LEFT, TOP + 1);
		if (j % 2 == 0)
			cout << char(5);
		else
			cout << char(127);
	}

	for (int i = 1; i <= BOARD_SIZE * 2; i += 2)
	{
		Sleep(20);
		for (int j = 3; j < 3 * BOARD_SIZE; j += 3)
		{
			gotoxy(j + LEFT, i + TOP + 1);
			cout << char(179);
		}
	}
}


void ShowScrollbar(BOOL Show)
{
	HWND hWnd = GetConsoleWindow();
	ShowScrollBar(hWnd, SB_BOTH, Show);
}
//ancontro
//void ShowCur(bool CursorVisibility)
//{
//	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//	CONSOLE_CURSOR_INFO ConCurInf;
//
//	ConCurInf.BOARD_SIZE = 10;
//	ConCurInf.bVisible = CursorVisibility;
//
//	SetConsoleCursorInfo(handle, &ConCurInf);
//}
// Hàm dịch chuyển con trỏ đến tọa độ x, y.


// Hàm xóa màn hình.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
};








