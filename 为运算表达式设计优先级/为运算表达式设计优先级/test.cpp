//回溯搜索。该问题牵涉到括号的组合问题，一般使用递归 + 回溯的思想。主要想法：
//
//其一，递归回溯。可以产生所有的组合方式。
//
//其二，每个小组合方式相当于一个子集，不断的将计算结果返回给上一层。
//
//举例：a + (b - (c * d))会不断的变成a + (b - (res1 * res2))->a + (res1 - res2)->res1 + res2
//
//似乎计算结果不需要for循环？其实有这种情况，a + (b - (c * d))和a + (b - c) * d))，这里 a + res2
//，res2就可能有多种情况。
class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		vector<int> ret;
		for (int i = 0; i < input.size(); i++) {
			char c = input[i];
			if (c == '+' || c == '-' || c == '*') {
				auto l = diffWaysToCompute(input.substr(0, i));
				auto r = diffWaysToCompute(input.substr(i + 1));
				for (auto ll : l) {
					for (auto rr : r) {
						if (c == '+') {
							ret.push_back(ll + rr);
						}
						else if (c == '-') {
							ret.push_back(ll - rr);
						}
						else if (c == '*') {
							ret.push_back(ll*rr);
						}
					}
				}
			}
		}
		if (ret.empty())
			ret.push_back(stoi(input));
		return ret;
	}
};