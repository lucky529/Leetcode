#include<iostream>
#include<windows.h>
#include<vector>
using namespace std;

//通过 168ms 1.按照逐位相加的原理进行循环 2.判断最后是否有进位或者k不为0的情况
int main()
{
	vector<int> A = { 2,1,5 };
	int k = 806;
	int carry = 0, index = A.size() - 1;
	while (index >= 0)
	{
		int tmp = k % 10 + A[index] + carry;
		A[index--] = tmp % 10 ;
		carry = tmp/10;
		k /= 10;
	}
	k += carry;
	while (k != 0)
	{
		int tmp = k % 10;
		A.insert(A.begin(), tmp);
		k /= 10;
	}
	for (auto e : A)
	{
		cout << e << endl;
	}
	system("pause");
	return 0;
}