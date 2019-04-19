//675ms通过 1.使用map（这里实际用set就行）去重 2.如果大于数组的一般说明最多可以拿到一半，当然小于一半也就意味着只能拿
//map.size()个
class Solution {
public:
	int distributeCandies(vector<int>& candies) {
		int part = candies.size() / 2;
		map<int, int> mp;
		for (auto& e : candies)
		{
			mp[e]++;
		}
		if (mp.size() >= part)
			return part;
		else
			return mp.size();
	}
};
//大佬操作 快是快，但是感觉不实用
class Solution {
public:
	int distributeCandies(vector<int>& candies) {
		int n[200001] = { 0 };
		int count = 0;
		for (auto tmp : candies){
			if (n[tmp + 100000] == 0){
				n[tmp + 100000] = 1;
				count++;
			}
		}
		int size = candies.size() / 2;
		return min(count, size);
	}
};