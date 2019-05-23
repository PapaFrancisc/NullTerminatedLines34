#include <iostream>
#include <Windows.h>

using namespace std;

void ASCII()
{
	for (int i = 0; i < 256; i++)cout << i << "\t" << (char)i << endl;
}

void InputLine(char szStr[], const int n);
int StrLen(char szStr[]); // ��� �� ��������� ������ 
void UpperCase(char szStr[]); // ��������� ������ � ������� �������
void LowerCase(char szStr[]); // ��������� ������ � ������ �������
void Case2007(char szStr[]);
void Capitalized(char szStr[]);
bool isLowLetter(char symbol);
bool isLowRusLetter(char symbol);

void Shrink(char szStr[]);		//������� ������ ������� ����� ������� � �����������.
bool isPalindrome(char szStr[]);	//���������, �������� �� ������ ������ �����������.
bool isNumber(char szStr[]);	//���������, �������� ������ ������. ������ �������� ������, ���� �������� ������ �����.
bool isHexNumber(char szStr[]);	//���������, �������� ������ ����������������� ������. ������ �������� Hex-������, ���� �������� ������ ����� � ����� ABCDEF ���� abcdef.

void main()
{

	setlocale(LC_ALL, "");
	/*char szStr[] = { 'H', 'e','l','l',0 };
	cout << szStr << endl;
	char szStrM[] = "Hell";
	cout << szStrM << endl;*/
	//ASCII();
	/*cout << (int)'A' << "\t" << (int)'a' << endl;
	cout << 'A' - 'a' << endl;*/
	const int n = 30;
	char szStr[n] = {};
	cout << "������� ���: ";
	/*cin >> szStr;*/
	InputLine(szStr, n);
	cout << szStr << endl;
	cout << sizeof(szStr) << endl;
	cout << StrLen(szStr) << endl;
	UpperCase(szStr);
	cout << szStr << endl;
	LowerCase(szStr);
	cout << szStr << endl;
	/*Case2007(szStr);*/
	Capitalized(szStr);
	//Shrink(szStr);
	isNumber(szStr);
	if (isNumber(szStr) == true) cout << "������ ��������� ������" << endl;
	else cout << "������ �� ��������� ������" << endl;


}

void InputLine(char szStr[], const int n)
{
	/*cout << typeid(szStr).name() << endl;*/
	SetConsoleCP(1251);
	cin.getline(szStr, n);
	SetConsoleCP(866);
}

int StrLen(char szStr[])
{
	int i = 0;
	for (; szStr[i]; i++);
	return i;
}

void UpperCase(char szStr[])
{
	int i = 0;
	for (; szStr[i]; i++)
		if (szStr[i] >= 'a' && szStr[i] <= 'z' ||
			szStr[i] >= '�' && szStr[i] <= '�')
			szStr[i] -= 32;
}


void LowerCase(char szStr[])
{
	int i = 0;
	for (; szStr[i]; i++)
		if (szStr[i] >= 'A'&& szStr[i] <= 'Z' ||
			szStr[i] >= '�'&& szStr[i] <= '�')
			szStr[i] += 32;
}

void Case2007(char szStr[])
{

	for (int i = 0; szStr[i]; i++)
	{
		if (i % 2 == 0)
		{
			if (szStr[i] >= 'a' && szStr[i] <= 'z' ||
				szStr[i] >= '�' && szStr[i] <= '�')
				szStr[i] -= 32;
		}

		else
		{
			if (szStr[i] >= 'A'&& szStr[i] <= 'Z' ||
				szStr[i] >= '�'&& szStr[i] <= '�')
				szStr[i] += 32;
		}
		if (szStr[i] == 'a' || szStr[i] == 'A')szStr[i] = '@';
		if (szStr[i] == 's' || szStr[i] == 'S')szStr[i] = '$';
		if (szStr[i] == 'i' || szStr[i] == 'I')szStr[i] = '1';


	}
	cout << "xXx_" << szStr << "_xXx" << endl;
}

void Capitalized(char szStr[])
{
	LowerCase(szStr);
	if (szStr[0] >= 'a' && szStr[0] <= 'z' ||
		szStr[0] >= '�' && szStr[0] <= '�')
		szStr[0] -= 32;
	for (int i = 1; szStr[i]; i++)
	{
		if (szStr[i - 1] == ' ' &&
			(szStr[i] >= 'a' && szStr[i] <= 'z' ||
				szStr[i] >= '�' && szStr[i] <= '�'))
			szStr[i] -= 32;
	}

	cout << szStr << endl;
}

bool isLowLetter(char symbol)
{
	if (symbol >= '�' && symbol <= '�')return true;
	else return false;
}

bool isLowRusLetter(char symbol)
{
	if (symbol >= 'a' && symbol <= 'z')return true;
	else return false;
}

void Shrink(char szStr[])
{
	const int n = 30;
	char szBff[n] = {};
	LowerCase(szStr);

	for (int i = 0; szStr[i]; i++)
	{
		if (szStr[i] == ' ' && szStr[i - 1] == ' ')
			szStr++;

	}

	cout << szStr << endl;
}

bool isNumber(char szStr[])
{
	for (int i = 0; szStr; i++)
	{
		if (szStr[i] >= 0 && szStr[i] <= 9)return true;
		else return false;
	}
}
