//24ms通过 使用map统计各卡牌的数量，并且判断两两之间是否存在最大公约数
class Solution {
public:
	int getgys(int p, int q){
		if (q == 0) return p;
		return getgys(q, p%q);
	}
	bool hasGroupsSizeX(vector<int>& deck) {
		map<int, int> mp;
		for (auto& e : deck)
		{
			mp[e]++;
		}
		if (mp.size() == 1 && mp.begin()->second >= 2)
			return true;
		else if (mp.size() == 1 && mp.begin()->second < 2)
			return false;

		auto cur = (++mp.begin()), pre = mp.begin();
		while (cur != mp.end())
		{
			if (pre->second < 2 || cur->second < 2) return false;
			if (getgys(pre->second, cur->second) <= 1) return false;
			cur++; pre++;
		}
		return true;
	}
};