//只能对不含数字的字符串进行编码和解码
class Codec {
public:

	string encode(vector<string>& strs) {
		string ret = "";
		for (auto& str : strs) {
			int pre = 0, cur = 0;
			while (cur < str.size()) {
				pre = cur;
				while (cur < str.size() && str[cur] == str[pre]) cur++;
				if (cur - pre > 1)
					ret += (to_string(cur - pre) + str[pre]);
				else
					ret += str[pre];
			}
			ret += " ";
		}
		return ret;
	}

	// Decodes a single string to a list of strings.
	vector<string> decode(string s) {
		vector<string> v;
		istringstream ss(s); string tmp;
		while (ss >> tmp) {
			int val = 0; string str = "";
			for (auto& e : tmp) {
				if (e >= '0' && e <= '9') {
					val = val * 10 + (e - '0');
				}
				else {
					if (val == 0)
						str += e;
					else {
						while (val--) str += e;
						val = 0;
					}
				}
			}
			v.push_back(str);
			str.clear();
		}
		return v;
	}
};