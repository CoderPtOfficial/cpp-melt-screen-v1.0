#include <Windows.h>
#include <time.h>

void GetScreenSize(int& scW, int& scH);

int main() {
	//Esconder console
	ShowWindow(GetConsoleWindow(), SW_HIDE);

	//Obter window
	HDC window = GetDC(GetDesktopWindow());

	//Resolucao
	int ScreenW, ScreenH;
	GetScreenSize(ScreenW, ScreenH);

	//POSICAO INICIAL
	int x, y;

	//Posicao final
	int x1, y1;

	//seed
	srand(time(NULL));

	while (1) {
		//Parar programa, apenas para garantir que consigo parar
		if (GetKeyState(0x41) < 0) { //0x41 = Aa
			exit(1);
		}

		x = rand() % (ScreenW - 10) + 1; //numero aleatoria de 1 a Width-10
		y = rand() % (ScreenH - 100) + 1; //numero aleatoria de 1 a Height-100

		x1 = rand() % ScreenW + 1;
		y1 = rand() % ScreenH + 1;

		BitBlt(window, x, y, 10, 100, window, x1, y1, SRCCOPY);

		//Delay (opcional)
		Sleep(50);
	}
	return 1;
}

void GetScreenSize(int& scW, int& scH)
{
	RECT screen;
	GetWindowRect(GetDesktopWindow(), &screen);
	scW = screen.right;
	scH = screen.bottom;
}
