class Solution {//�������㷨
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
				start = (i - p[i]) / 2;//i-p[i]�൱�ڵ�ǰ��������߽磬������������ˡ�#���ַ�������ԭ������ʼλ��/2
				maxlen = p[i] - 1;
			}
		}
		return s.substr(start, maxlen);
	}
};