#include<iostream>
#include<windows.h>
#include<vector>
using namespace std;
int findLengthOfLCIS(vector<int>& nums)
{
	if (nums.size() == 0) return 0;
	int max = 1, count = 1, pre = 0, cur = 1;
	while (cur < nums.size())
	{
		if (nums[cur] > nums[pre])
			count++;
		else
			count = 1;
		max = count > max ? count : max;
		pre = cur;
		cur++;
	}
	return max;
}
int main()
{
	vector<int> v = { 2,2,2,2,2 };
	findLengthOfLCIS(v);
	system("pause");
	return 0;
}