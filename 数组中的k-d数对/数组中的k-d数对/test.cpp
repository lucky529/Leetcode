//想了很久没有通过，利用双指针像冒泡排序一样的思想类似于两数求和，看了大神的思想发现map的接口应该好好复习一下了 
//64ms通过 1.用map统计数字和数字出现的次数 2.然后直接调用count接口查找是否存在当前值加K的和
class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		if (k < 0) return 0;
		map<int, int> mp;
		for (auto& e : nums)
		{
			mp[e]++;
		}
		int count = 0;
		auto it = mp.begin();
		while (it != mp.end())
		{
			if (k)
			{
				int num = it->first + k;
				if (mp.count(num)) count++;
			}
			else
			{
				if (it->second > 1)//此时只要看是否存在相同的值
					count++;
			}
			it++;
		}
		return count;
	}
};
