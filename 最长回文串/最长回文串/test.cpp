//最长回文串真的是一道特别有趣的题，有各种各样的解法，从这些不同的解法中你能感受到这些算法的魅力

//算法1.暴力求解
//时间复杂度：on^3 空间复杂度：o1
//思路：双循环判断每一个子串是否是回文串，因为每次都要反转子串，所以效率极低，未通过
class Solution {//暴力算法
public:
	string longestPalindrome(string s) {
		if (s.size() == 0 || s.size() < 2) return s;
		int max = 0;
		string ret = "";
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = 1; j < s.size(); j++)
			{
				string tmp = s.substr(i, j - i + 1);
				string tmpr(tmp);
				reverse(tmp.begin(), tmp.end());
				if (tmp == tmpr && tmp.size() > max)
				{
					max = tmp.size();
					ret = s.substr(i, j - i + 1);
				}
			}
		}
		return ret;
	}
};

//算法2.动态规划
//时间复杂度：on^2 空间复杂度：on^2
//思路：一个子串是否为回文串可以判断这个子串的第一个与最后一个是否相等+中间的子串是否为回文
//		中间的子串又可以分解为第一个与最后一个是否相等+中间的子串是否为回文，所以我们就有了dp方程

	//P(i, j) = (P(i + 1, j - 1) \text{ and } S_i == S_j)
	//P(i, j) = (P(i + 1, j−1) and S
	

class Solution {//动态规划
public:
	string longestPalindrome(string s) {
		if (s.size() == 0) return s;
		int dp[s.size()][s.size()] = { 0 };
		string ret = "";
		int max = 0;
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j <= i; j++) {
				dp[i][j] = s[i] == s[j] && (i - j <= 2 || dp[i - 1][j + 1]);
				if (dp[i][j]) {
					if (i - j + 1 > max) {
						max = i - j + 1;
						ret = s.substr(j, i - j + 1);
					}
				}
			}
		}
		return ret;
	}
};

//算法3.中心扩散法
//时间复杂度：on^2 空间复杂度：o1
//思路：很容易理解，将当前字符作为中心，直到蔓延到不构成回文串为止
class Solution {//中心扩散法
public:
	int max = 0;
	string ret = "";
	void spread(string& s, int left, int right) {
		int L = left, R = right;
		while (L >= 0 && R < s.size() && s[L] == s[R]) {
			if (R - L + 1 > max) {
				max = R - L + 1;
				ret = s.substr(L, R - L + 1);
			}
			L--; R++;
		}
	}
	string longestPalindrome(string s) {
		if (s.size() <= 1) return s;
		for (int i = 0; i < s.size(); i++) {
			spread(s, i, i);
			spread(s, i, i + 1);
		}
		return ret;
	}
};

//算法4.马拉车算法
//思路：真的需要好好写博客来理解这种有趣的算法，效率只需要on的时间复杂度和on的常数空间
class Solution {//马拉车算法
public:
	string longestPalindrome(string s) {
		if (s.size() <= 1) return s;
		string str = "@#";
		for (int i = 0; i < s.size(); i++) {
			str += s[i];
			str += '#';
		}

		vector<int> p(str.size(), 0);
		int mx = 0, id = 0, start = 0, maxlen = 0;
		for (int i = 1; str[i] != '\0'; i++) {
			p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
			while (str[i + p[i]] == str[i - p[i]]) p[i]++;
			if (i + p[i] > mx) {
				mx = i + p[i];
				id = i;
			}
			if (p[i] - 1 > maxlen)
			{
				start = (i - p[i]) / 2;
				maxlen = p[i] - 1;
			}
		}
		return s.substr(start, maxlen);
	}
};