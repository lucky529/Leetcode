//40ms通过 使用哈希表记录数字的位置
class Solution {
public:
	string getHint(string secret, string guess) {
		int a = 0, b = 0;
		unordered_map<char, int> mp;
		unordered_set<int> s;
		for (int i = 0; i < secret.size(); i++)
		{
			if (secret[i] == guess[i])
			{
				s.insert(i); a++;
			}
			else mp[secret[i]]++;
		}
		for (int i = 0; i < guess.size(); i++)
		{
			if (s.find(i) == s.end() && mp[guess[i]] != 0)
			{
				b++;
				mp[guess[i]]--;
			}
		}
		return to_string(a) + "A" + to_string(b) + "B";
	}
};
//优化
class Solution {
public:
	string getHint(string secret, string guess) {
		if (secret.length() != guess.length())return "";
		int counta = 0;
		int countb = 0;
		int hashtable[10] = { 0 };
		for (int i = 0; i<secret.length(); i++){
			if (secret[i] == guess[i])
				counta++;
			else
				hashtable[secret[i] - '0']++;
		}
		for (int i = 0; i<secret.length(); i++){
			if (secret[i] != guess[i] && hashtable[guess[i] - '0']){
				countb++;
				hashtable[guess[i] - '0']--;
			}
		}
		return to_string(counta) + "A" + to_string(countb) + "B";

	}
};