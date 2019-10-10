//可以使用set使用哈希映射的思想进行解题
class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		unordered_set<int> s;
		vector<int> v;
		for (auto& e : array) {
			if (s.find(sum - e) != s.end()) {
				if (v.size() == 0) {
					if (sum - e > e)
						v = { e, sum - e };
					else
						v = { sum - e, e };
				}
				else
				{
					if ((sum - e)*e < v[0] * v[1])
					{
						if (sum - e > e)
							v = { e, sum - e };
						else
							v = { sum - e, e };
					}
				}
			}
			s.insert(e);
		}
		return v;
	}
};