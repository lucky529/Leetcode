//44ms通过 简单的map计数，巧妙利用istringstream去除字符串首位的空格
class Solution {
public:
	vector<string> subdomainVisits(vector<string>& cpdomains) {
		map<string, int> mp;
		vector<string> v;
		for (auto& e : cpdomains)
		{
			int num = atoi(e.c_str()), cur = 0;
			string str = "";
			istringstream tmp(e);
			while (tmp >> str){}
			mp[str] += num;
			while (cur < str.size())
			{
				string s = "";
				while (cur < str.size() && str[cur] != '.')
				{
					cur++;
				}
				if (cur + 1 < str.size())
					s = str.substr(++cur);
				mp[s] += num;
			}
		}
		for (auto it = (++mp.begin()); it != mp.end(); it++)
		{
			v.push_back(to_string(it->second) + " " + it->first);
		}
		return v;
	}
};