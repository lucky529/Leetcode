//对数组进行排序，必须保证前一个单词加上后一个单词的值最小即可
class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		vector<string> v;
		for (auto e : numbers) {
			v.push_back(to_string(e));
		}
		sort(v.begin(), v.end(), [](string& a, string& b)
		{
			return a + b < b + a;
		});
		string ret = "";
		for (auto& e : v) {
			ret += e;
		}
		return ret;
	}
};