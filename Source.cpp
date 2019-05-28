
#include <iostream>
#include <Windows.h>

using namespace std;

void ASCII()
{
	for (int i = 0; i < 256; i++)cout << i << "\t" << (char)i << endl;
}

void InputLine(char szStr[], const int n);
int StrLen(char szStr[]); // êîë âî ýëåìåíòîâ ñòðîêè 
void UpperCase(char szStr[]); // ïåðåâîäèò ñòðîêó â âåðõíèé ðåãèñòð
void LowerCase(char szStr[]); // ïåðåâîäèò ñòðîêó â íèæíèé ðåãèñòð
void Case2007(char szStr[]);
void Capitalized(char szStr[]);
bool isLowLetter(char symbol);
bool isLowRusLetter(char symbol);

void Shrink(char szStr[]);		//Óäàëÿåò ëèøíèå ïðîáåëû ìåæäó ñëîâàìè â ïðåäëîæåíèè.
bool isPalindrome(char szStr[]);	//Ïðîâåðÿåò, ÿâëÿåòñÿ ëè äàííàÿ ñòðîêà ïàëèíäðîìîì.
bool isNumber(char szStr[]);	//Ïðîâåðÿåò, ÿâëÿåòñÿ ñòðîêà ÷èñëîì. Ñòðîêà ÿâëÿåòñÿ ÷èñëîì, åñëè ñîäåðæèò òîëüêî öèôðû.
bool isHexNumber(char szStr[]);	//Ïðîâåðÿåò, ÿâëÿåòñÿ ñòðîêà øåñòíàäöàòåðè÷íûì ÷èñëîì. Ñòðîêà ÿâëÿåòñÿ Hex-÷èñëîì, åñëè ñîäåðæèò òîëüêî öèôðû è áóêâû ABCDEF ëèáî abcdef.
int StringToInt(char szStr[]);
bool isBinNumber(char szStr[]);
int Bin2Dec(char szStr[]);
int Hex2Dec(char szStr[]);
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
	cout << "Введите строку: ";
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
	cout << isNumber(szStr) << endl;
	cout << StringToInt(szStr) << endl;
	cout << isHexNumber(szStr) << endl;
	cout << isPalindrome(szStr) << endl;
	cout << isBinNumber(szStr) << endl;
	cout << Bin2Dec(szStr) << endl;
	cout << Hex2Dec(szStr) << endl;

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
			szStr[i] >= 'à' && szStr[i] <= 'ÿ')
			szStr[i] -= 32;
}


void LowerCase(char szStr[])
{
	int i = 0;
	for (; szStr[i]; i++)
		if (szStr[i] >= 'A'&& szStr[i] <= 'Z' ||
			szStr[i] >= 'À'&& szStr[i] <= 'ß')
			szStr[i] += 32;
}

void Case2007(char szStr[])
{

	for (int i = 0; szStr[i]; i++)
	{
		if (i % 2 == 0)
		{
			if (szStr[i] >= 'a' && szStr[i] <= 'z' ||
				szStr[i] >= 'à' && szStr[i] <= 'ÿ')
				szStr[i] -= 32;
		}

		else
		{
			if (szStr[i] >= 'A'&& szStr[i] <= 'Z' ||
				szStr[i] >= 'À'&& szStr[i] <= 'ß')
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
		szStr[0] >= 'à' && szStr[0] <= 'ÿ')
		szStr[0] -= 32;
	for (int i = 1; szStr[i]; i++)
	{
		if (szStr[i - 1] == ' ' &&
			(szStr[i] >= 'a' && szStr[i] <= 'z' ||
				szStr[i] >= 'à' && szStr[i] <= 'ÿ'))
			szStr[i] -= 32;
	}

	cout << szStr << endl;
}

bool isLowLetter(char symbol)
{
	if (symbol >= 'à' && symbol <= 'ÿ')return true;
	else return false;
}

bool isLowRusLetter(char symbol)
{
	if (symbol >= 'a' && symbol <= 'z')return true;
	else return false;
}

void Shrink(char szStr[])
{
	for (int i = 0; szStr[i];i++)
	{
		while (szStr[i] == ' ')
		{
			for (int j = 0; szStr[j]; j++)
			{
				szStr[j] = szStr[j + 1];
			}
		}
	}
	cout << szStr << endl;
}

bool isNumber(char szStr[])
{
	if ((szStr[0] < '0' || szStr[0] > '9') && szStr[0] != '-' && szStr[0] != '+')return false;
	for (int i = 1; szStr[i]; i++)
	{
		if (szStr[i] < '0' || szStr[i] > '9') return false;
	}
	return true;
}

int StringToInt(char szStr[])
{
	if (isNumber(szStr) == false)return 0;


	int decimal = 0;
	bool signed_number = false;
	if (szStr[0] == '+' || szStr[0] == '-')signed_number = true;
	for (int i = signed_number ? 1 : 0; szStr[i]; i++)
	{
		decimal *= 10;
		decimal += szStr[i] - 48;
	}
	if (szStr[0] == '-')decimal = -decimal;
	return decimal;
}

bool isHexNumber(char szStr[])
{
	for (int i = 0; szStr[i]; i++)
	{
		if (
			!(szStr[i] >= '0' && szStr[i] <= '9') &&
			!(szStr[i] >= 'A' && szStr[i] <= 'F') &&
			!(szStr[i] >= 'a' && szStr[i] <= 'f')
			)
		{
			return false;
		}
	}
	return true;
}

bool isPalindrome(char szStr[])
{
	int size = StrLen(szStr);
	char* buffer = new char[size + 1]{};
	for (int i = 0; i < size; i++)buffer[i] = szStr[i];
	LowerCase(buffer);
	Shrink(buffer);
	size = StrLen(buffer);
	for (int i = 0;i<size/2 ; i++)
	{
		if (buffer[i] != buffer[size -i-1])
		{
			delete[] buffer;
			return false;
		}

	}
	delete[]buffer;
	return true;

}

bool isBinNumber(char szStr[])
{
	int n = StrLen(szStr);
	char* buffer = new char[n + 1]{};
	for (int i = 0; szStr[i]; i++)buffer[i] = szStr[i];
	Shrink(buffer);
	
	for (int i = 0; buffer[i];i++)
	{
		if (buffer[i] != '0' && buffer[i] != '1')
		{
			delete[]buffer;
			return false;
		}
	}
	delete[]buffer;
			return true;
}

int Bin2Dec(char szStr[])
{
	if (!isBinNumber(szStr))
	{
		cout << "Error: not binary" << endl;
		return 0;
	}
	
	int decimal = 0; // десятичное число
	int weight = 1; // весовой коофициент
	int capacity = StrLen(szStr);
	for (int i = capacity-1; i>=0; i--)
	{
		if (szStr[i] == ' ') continue;
		decimal += (szStr[i] - 48)*weight;
		weight *= 2;
	}
	return decimal;
}

int Hex2Dec(char szStr[])
{
	if (!isHexNumber(szStr))
	{
		cout << "Error: not heximal" << endl;
		return 0;
	}

	int decimal = 0;
	int weight = 1;
	int capacity = StrLen(szStr);
	for (int i = capacity-1; i>=0; i--)
	{
		int digit ;
		if (szStr[i] >= 'a')digit = szStr[i] - 87;
		else if (szStr[i] >= 'A')digit = szStr[i] - 55;
		else digit = szStr[i] - 48;
		decimal += digit*weight;
		weight *= 16;
	}
	return decimal;

}