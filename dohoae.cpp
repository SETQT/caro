#include "dohoa.h"
bool TURN;
char _COMMAND;
int _X, _Y;
bool l = true;
int h = 0, k = 0;

struct _POINT {
	int x, y, c;
} _A[BOARD_SIZE][BOARD_SIZE];

void Reset() {
	for (int i = 0; i < BOARD_SIZE - 1; i++) {
		for (int j = 0; j < BOARD_SIZE - 1; j++) {
			_A[i][j].x = LEFT + 3 + j * 3;
			_A[i][j].y = 2 * i + TOP + 3;
			_A[i][j].c = 0;
		}
	}
	_COMMAND = -1;
	TURN = true;
	_X = _A[0][0].x;
	_Y = _A[0][0].y;
};


void starGame() {
	system("cls");
	Reset();
	Draw();
	gotoxy(_X, _Y);
};

void  Checkboard()
{
	if (_A[h][k].c == 0)
		if (l == true)
			if (TURN == true)
			{
				cout << "X";
				TURN = false;
				_A[h][k].c = 1;
			}
			else {
				cout << "O";
				TURN = true;
				_A[h][k].c = -1;
			}

	l = false;
}

bool KT_doc(int n, int m)
{
	int d1 = 0;
	int d2 = 0;
	int i = 0;
	while (1)
	{
		i++;
		if ((m - i) < 0)  break;
		if ((_A[n][m - i].c) == 0) break;

		if ((_A[n][m - i].c) == (_A[n][m].c)) d1++;
	}
	i = 0;
	while (2)
	{
		i++;;
		if ((m + i) > (BOARD_SIZE - 2)) break;
		if ((_A[n][m + i].c) == 0) break;
		else
			if ((_A[n][m + i].c) == (_A[n][m].c)) d2++;
	}
	if ((d1 + d2) >= 4) return true;
	else return false;
}

bool KT_ngang(int n, int m)
{
	int d1 = 0;
	int d2 = 0;
	int i = 0;
	while (1)
	{
		i++;;
		if ((n - i) < 0) break;
		if ((_A[n - i][m].c) == 0) break;

		if ((_A[n - i][m].c) == (_A[n][m].c)) d1++;
	}
	i = 0;
	while (2)
	{
		i++;;
		if ((n + i) > (BOARD_SIZE - 2)) break;
		if ((_A[n + i][m].c) == 0) break;
		else
			if ((_A[n + i][m].c) == (_A[n][m].c)) d2++;
	}
	if ((d1 + d2) >= 4) return true;
	else return false;
}
bool KT_cheo_chinh(int n, int m)
{
	int d1 = 0;
	int d2 = 0;
	int i = 0;
	while (1)
	{
		i++;
		if (((n - i) < 0) || ((m - i) < 0)) break;
		if ((_A[n - i][m - i].c) == 0) break;

		if ((_A[n - i][m - i].c) == (_A[n][m].c)) d1++;
	}
	i = 0;
	while (2)
	{
		i++;
		if (((n + i) > BOARD_SIZE - 2) || ((m + i) > BOARD_SIZE - 2)) break;
		if ((_A[n + i][m + i].c) == 0) break;

		if ((_A[n + i][m + i].c) == (_A[n][m].c)) d2++;
	}

	if ((d1 + d2) >= 4) return true;
	else return false;
}

bool KT_cheo_phu(int n, int m)
{
	int d1 = 0;
	int d2 = 0;
	int i = 0;
	while (1)
	{
		i++;
		if (((n - i) < 0) || ((m + i) > BOARD_SIZE - 2)) break;
		if ((_A[n - i][m + i].c) == 0) break;

		if ((_A[n - i][m + i].c) == (_A[n][m].c)) d1++;
	}
	i = 0;
	while (2)
	{
		i++;
		if (((n + i) > BOARD_SIZE - 2) || ((m - i) < 0)) break;
		if ((_A[n + i][m - i].c) == 0) break;

		if ((_A[n + i][m - i].c) == (_A[n][m].c)) d2++;
	}

	if ((d1 + d2) >= 4) return true;
	else return false;
}
void MoveRight() {

	if (_X < _A[BOARD_SIZE - 2][BOARD_SIZE - 2].x)
	{
		l = true;
		h++;
		_X += 3;
		gotoxy(_X, _Y);
	}
};

void MoveLeft() {

	if (_X > _A[0][0].x)
	{
		l = true;
		h--;
		_X -= 3;
		gotoxy(_X, _Y);
	}
};

void MoveDown() {

	if (_Y < _A[BOARD_SIZE - 2][BOARD_SIZE - 2].y)
	{
		k++;

		l = true;
		_Y += 2;
		gotoxy(_X, _Y);
	}
};

void MoveUp() {

	if (_Y > _A[0][0].y)
	{
		k--;

		_Y -= 2;
		gotoxy(_X, _Y);
		l = true;
	}
};
bool KT()
{
	if (KT_doc(h, k) == true) return true;
	if (KT_ngang(h, k) == true) return true;
	if (KT_cheo_chinh(h, k) == true) return true;
	if (KT_cheo_phu(h, k) == true) return true;
	return false;
}
int START()
{
	while (1) {
		_COMMAND = toupper(_getch());
		if (_COMMAND == 27)
		{
			return 0;
		}
		else {
			if (_COMMAND == 'A') MoveLeft();
			else if (_COMMAND == 'W') MoveUp();
			else if (_COMMAND == 'S') MoveDown();
			else if (_COMMAND == 'D') MoveRight();
			else if (_COMMAND == 13)
			{
				textcolor(10);
				Checkboard();
				if (KT() == true)
				{
					if (_A[h][k].c == -1)
						cout << " O thang";
					else cout << " X thang"; break;
				}
			}

		}
	}
	return 0;
}



int main() {

	//resizeConsole(30000,700);
	FixConsoleWindow();
	textcolor(4);
	starGame();
	START();
	
	
	
	
	return 0;
	}




