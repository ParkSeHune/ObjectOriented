#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>

using namespace std;

void gotoxy(int x, int y)
{
    COORD Pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void Print(int c, int g)
{
    gotoxy(10, 5);
    cout << "현재 온도 : " << c << endl;

    gotoxy(10, 6);
    cout << "목표 온도 : " << g << endl;
}

class AirControl
{
public:
	AirControl(int cTemp, int tTemp);
	~AirControl();
    void control();
private:
    int ch = _getch();
    int currentTemp;
    int toTemp;
};

AirControl::AirControl(int cTemp, int tTemp)
{
    currentTemp = cTemp;
	toTemp = tTemp;
	Print(currentTemp, toTemp);
}

AirControl::~AirControl()
{
}

void AirControl::control()
{
	Print(currentTemp, toTemp);

    while (true)
    {
        ch = _getch();

        if (ch == 224 || ch == 0)
        {
            ch = _getch();
        }
        else if (ch == 72)
        {
            toTemp += 1;
            Print(currentTemp, toTemp);
            ch = _getch();
        }
        else if (ch == 80)
        {
            toTemp -= 1;
            Print(currentTemp, toTemp);
            ch = _getch();
        }
        else if (ch == 13)
        {
            while (currentTemp != toTemp)
            {
                if (currentTemp > toTemp)
                {
                    currentTemp -= 1;
                    Sleep(1000);
                    Print(currentTemp, toTemp);
                }
                else if (currentTemp < toTemp)
                {
					currentTemp += 1;
                    Sleep(1000);
                    Print(currentTemp, toTemp);
                }

                if (currentTemp == toTemp)
                {
                    break;
                }
            }

			ch = _getch();
        }
    }

}

int main()
{
    AirControl airControl(24, 24);
    airControl.control();

    return 0;
}