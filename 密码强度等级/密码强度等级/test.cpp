//浪费生命的一道题
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

string GetPassWordLevel(string& s)
{
	int sum = 0;
	if (s.size() <= 4) sum += 5;
	else if (s.size() >= 5 && s.size() <= 7) sum += 10;
	else sum += 25;

	unordered_map<char, int> mp;
	for (auto& e : s)
	{
		mp[e]++;
	}
	int numflag = 0, bigchar = 0, smchar = 0, other = 0;
	for (auto& kv : mp)
	{
		if (kv.first >= '0' && kv.first <= '9')
			numflag += kv.second;
		else if (kv.first >= 'A' && kv.first <= 'Z')
			bigchar += kv.second;
		else if (kv.first >= 'a' && kv.first <= 'z')
			smchar += kv.second;
		else
			other += kv.second;
	}
	if ((bigchar != 0 && smchar == 0) || (bigchar == 0 && smchar != 0)) sum += 10;
	else if (bigchar != 0 && smchar != 0) sum += 20;

	if (numflag == 1) sum += 10;
	else if (numflag > 1) sum += 20;

	if (other == 1) sum += 10;
	else if (other > 1) sum += 25;

	if ((bigchar || smchar) && numflag) sum += 2;
	else if (bigchar && smchar && numflag && other) sum += 5;
	else if ((bigchar || smchar) && numflag && other) sum += 3;

	if (sum >= 90) return string("VERY_SECURE");
	else if (sum >= 80) return string("SECURE");
	else if (sum >= 70) return string("VERY_STRONG");
	else if (sum >= 60) return string("STRONG");
	else if (sum >= 50) return string("AVERAGE");
	else if (sum >= 25) return string("Weak");
	else if (sum >= 0) return ("VERY_WEAK");
	return "";
}
int main()
{
	string str;
	while (cin >> str)
	{
		string tmp = GetPassWordLevel(str);
		cout << tmp << endl;
	}
	return 0;
}