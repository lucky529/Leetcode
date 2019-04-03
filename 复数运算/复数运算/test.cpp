//4ms通过 1.提取复数中的4个数字 2.按照乘法分配律原则计算转化为字符串即可
class Solution {
public:
	string complexNumberMultiply(string a, string b) {
		int cur1 = a.size() - 1, cur2 = b.size() - 1;
		int x1 = atoi(a.c_str());
		int x2 = atoi(b.c_str());
		while (a[cur1] != '+'){
			cur1--;
		}
		a = a.substr(cur1 + 1);
		while (b[cur2] != '+'){
			cur2--;
		}
		b = b.substr(cur2 + 1);
		int y1 = atoi(a.c_str());
		int y2 = atoi(b.c_str());
		int aa = x1 * x2 - y1 * y2;
		int bb = x1 * y2 + x2 * y1;
		string ret = "";
		ret += (to_string(aa) + "+") + (to_string(bb) + "i");
		return ret;
	}
};