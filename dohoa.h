#include <iostream>
#include <conio.h>
#include <Windows.h>
#define BOARD_SIZE 16
#define LEFT 3
#define TOP 1



using namespace std;
void gotoxy(int x, int y);
void resizeConsole(int width, int height);
void textcolor(int x);
void DisableCtrButton(bool Close, bool Min, bool Max);
void Draw();
void ShowScrollbar(BOOL Show);
void XoaManHinh();
void FixConsoleWindow();
void Reset();
void starGame();
void  Checkboard();
bool KT_doc(int n, int m);
bool KT_cheo_chinh(int n, int m);
bool KT_ngang(int n, int m);
bool KT_cheo_phu(int n, int m);
void MoveRight();
void MoveLeft();
void MoveDown();
void MoveUp();
int START();
bool KT();


//void SetWindowBOARD_SIZE(SHORT width, SHORT height)
//{
//	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	SMALL_RECT WindowBOARD_SIZE;
//	WindowBOARD_SIZE.Top = 0;
//	WindowBOARD_SIZE.Left = 0;
//	WindowBOARD_SIZE.Right = width;
//	WindowBOARD_SIZE.Bottom = height;
//
//	SetConsoleWindowInfo(hStdout, 1, &WindowBOARD_SIZE);
//}
// Hàm thay đổi kích cỡ của khung cmd với tham số truyền vào là chiều cao, chiều rộng.


// Hàm lấy Key từ bàn phím
/* GetAsyncKeyState(VK_ESCAPE) => bắt sự kiện phím Esc */

// Hàm tự viết
//void ToMau(int x, int y, char* a, int color) // x, y là tọa độ con trỏ cần nhảy đến để viết, a là chuỗi cần truyền vào, color là màu truyền vào.
//{
//	gotoxy(x, y);
//	textcolor(color);
//	cout << a;
//	textcolor(7);
//}
