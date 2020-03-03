#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace std;

bool isIp(string str)
{
	if (count(str.begin(),str.end(), '.') != 3)
		return false;

	const char* s = str.c_str();
	int a1 = -1, a2 = -1, a3 = -1, a4 = -1;
	sscanf(s, "%d.%d.%d.%d", &a1, &a2, &a3, &a4);
	if (a1 > 255 || a2 > 255 || a3 > 255 || a4 > 255 
		|| a1 == -1 || a2 == -1 || a3 == -1 || a4 == -1)
		return false;

	while (*s)
	{
		if (*s != '.' && (*s < '0' || *s > '9')) {
			return false;
		}
		s++;
	}
	return true;
}
int main()
{
	string str;
	while (cin >> str)
	{
		if (isIp(str))
			cout << str + "合法ip" << endl;
		else
			cout << str + "不合法ip" << endl;
	}
	return 0;
}