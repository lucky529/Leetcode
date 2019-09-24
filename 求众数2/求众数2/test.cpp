//真的贼经典且有趣的一道题，看起来简单，但是要求时间和空间复杂度之后就必须使用摩尔投票的算法
//1.在求数组中出现一半的数（假定这个数一定存在）那么使用摩尔投票最后保留的数字就是众数
//2.现在要求数组中出现大于n/3的数字，那么众数最多只能有两个，所以我们使用俩个标记
//3.当出现的数字与标记标识的数字都不相同时就同时--，最后我们得到的两个数可能会成为众数中的一个
class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		vector<int> v;
		int x = 0, y = 0, cx = 0, cy = 0;
		for (auto& e : nums) {
			if ((cx == 0 || e == x) && e != y) {
				cx++; x = e;
			}
			else if (cy == 0 || e == y) {
				cy++; y = e;
			}
			else {
				cy--; cx--;
			}
		}
		int count = 0;
		for (auto& e : nums) {
			if (e == x) count++;
		}
		if (count > nums.size() / 3) v.push_back(x);
		count = 0;
		for (auto& e : nums) {
			if (e == y) count++;
		}
		if (count > nums.size() / 3 && x != y) v.push_back(y);
		return v;
	}
};