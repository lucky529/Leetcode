#include<iostream>
#include<windows.h>
#include<vector>
using namespace std;

//ͨ�� 168ms 1.������λ��ӵ�ԭ�����ѭ�� 2.�ж�����Ƿ��н�λ����k��Ϊ0�����
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