#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <string>
#include <math.h>
#include <time.h>

using namespace std;

struct Vector3
{
	float x = 0, y = 0, z = 0;

	Vector3() {};

	Vector3(float _x, float _y)
		: x(_x), y(_y), z(0) {};

	Vector3(float _x, float _y, float _z)
		: x(_x), y(_y), z(_z) {};
};

struct Transform
{
	Vector3 Postion;
	Vector3 Rotation;
	Vector3 Scale;
};

struct Information
{
	char* Texture;
	int Color;
	int Option;
};

struct Object
{
	char* Name;
	int Speed;

	Information Info;
	Transform TransInfo;
};

struct DrawTextInfo
{
	Information Info;
	Transform TransInfo;
};

void Logo();

void Initialize(Object* _Object, char* _Texture, float _PosX = 0, float _PosY = 0, float _PosZ = 0);

char* SetName();

void SetCursorPostion(const float _x, const float _y);

void SetTextColor(const int _Color);

void OnDrawText(const char* _str, const float _x, const float _y, const int _Color);

void OnDrawText(const int _Value, const float _x, const float _y, const int _Color);

void HideCursor(const bool _Visible);





int main(void)
{
	HideCursor(false);
	int level;
	char name[30];
	while (1)
	{
		system("mode con cols = 60 lines = 30 | title 미로찾기");

		SetTextColor(10);
		cout << "                    미로 찾기 게임" << endl;

		SetTextColor(14);
		cout << "1 . 난이도 쉬움" << endl;
		cout << "2 . 난이도 중간" << endl;
		cout << "3 . 난이도 어려움" << endl;
		cout << "4 . 랭킹" << endl;
		cout << "5 . 종료" << endl;

		SetTextColor(11);
		cout << "번호 입력 : " << endl;
		SetTextColor(15);
		cin >> level;

		SetTextColor(11);
		cout << "플레이어 이름 입력 : " << endl;
		SetTextColor(15);
		cin >> name;

		system("cls");


		switch(level)
		{
		case 1:easy_mode();

			break;
		}
	}
	




	return 0;
}

void easy_mode()
{

}


void Logo()
{
	cout << "미로찾기 게임에 오신것을 환영합니다. ";
	system("cls");
}

void Initialize(Object* _Object, char* _Texture, float _PosX, float _PosY, float _PosZ)
{
	_Object->Info.Texture = (_Texture == nullptr) ? SetName() : _Texture;

	_Object->Speed = 0;

	_Object->TransInfo.Postion = Vector3(_PosX, _PosY, _PosZ);

	_Object->TransInfo.Rotation = Vector3(0.0f, 0.0f, 0.0f);

	_Object->TransInfo.Scale = Vector3(
		(float)strlen(_Object->Info.Texture), 1.0f, 0.0f);
}

char* SetName()
{
	char Buffer[128] = "";

	cout << "입력 : "; cin >> Buffer;

	char* pName = new char[strlen(Buffer) + 1];

	strcpy(pName, Buffer);

	return pName;
}

void SetCursorPostion(const float _x, const float _y)
{
	COORD Pos = { (SHORT)_x,(SHORT)_y };

	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void SetTextColor(const int _Color)
{
	SetConsoleTextAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE), _Color);
}

void OnDrawText(const char* _str, const float _x, const float _y, const int _Color)
{
	SetCursorPostion(_x, _y);
	SetTextColor(_Color);
	cout << _str;
}

void OnDrawText(const int _Value, const float _x, const float _y, const int _Color)
{
	SetCursorPostion(_x, _y);
	SetTextColor(_Color);

	char* pText = new char[4];
	_itoa(_Value, pText, 10);
	cout << _Value;
}

void HideCursor(const bool _Visible)
{
	CONSOLE_CURSOR_INFO CursorInfo;

	CursorInfo.bVisible = _Visible;
	CursorInfo.dwSize = 1;

	SetConsoleCursorInfo(
		GetStdHandle(STD_OUTPUT_HANDLE), &CursorInfo);
}