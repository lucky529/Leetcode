//16ms通过 1.贪婪算法，如果当前数字为1就直接跳过两步 2.如果为0就走一步 3.如果走到了cur == bits.size() - 1说明只有
//这一种编码方式
class Solution {
public:
	bool isOneBitCharacter(vector<int>& bits) {
		int cur = 0;
		while (cur < bits.size())
		{
			if (cur == bits.size() - 1)
				return true;
			if (bits[cur] == 0)
			{
				cur++;
			}
			else if (bits[cur] == 1)
			{
				cur += 2;
			}
		}
		return false;
	}
};