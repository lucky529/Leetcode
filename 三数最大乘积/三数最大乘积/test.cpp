#include<limits.h>
using namespace std;

int main()
{
	long long big1, big2, big3;
	long long sm1, sm2;
	big1 = big2 = big3 = INT_MIN;
	sm1 = sm2 = INT_MAX;
	long long ret;
	int num, n; cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> n;
		if (n > big1)
		{
			big3 = big2;
			big2 = big1;
			big1 = n;
		}
		else if (n > big2)
		{
			big3 = big2;
			big2 = n;
		}
		else if (n > big3)
		{
			big3 = n;
		}

		if (n < sm1)
		{
			sm2 = sm1;
			sm1 = n;
		}
		else if (n < sm2)
		{
			sm2 = n;
		}
	}
	ret = (big1*big2*big3) >(big1*sm1*sm2) ? (big1*big2*big3) : (big1*sm1*sm2);
	cout << ret << endl;
	return 0;
}