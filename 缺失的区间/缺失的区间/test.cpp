//δ���ǵ�����������ʱ������
class Solution {
public:
	vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
		vector<int> v;
		vector<string> ret;
		for (int i = lower; i <= upper; i++)
		{
			if (find(nums.begin(), nums.end(), i) == nums.end())
				v.push_back(i);
		}
		int pre;
		for (int i = 0; i < v.size(); i++)
		{
			pre = i;
			while (i < v.size() - 1 && v[i + 1] - v[i] == 1)
			{
				i++;
			}
			if (i == pre) ret.push_back(to_string(v[i]));
			else ret.push_back(to_string(v[pre]) + "->" + to_string(v[i]));
		}
		return ret;
	}
};
//���ڴ������ް취�����ܽ���ǿ������ת��
class Solution {
public:
	vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
		vector<string> ret;
		long l = lower;
		for (int i = 0; i < nums.size() + 1; i++)
		{
			long r = (i < nums.size() && nums[i] <= upper) ? (long)nums[i] : ((long)upper + 1);
			if (l == r) l++;
			else if (r > l)
			{
				if (r - l == 1) ret.push_back(to_string(l));
				else ret.push_back(to_string(l) + "->" + to_string(r - 1));
				l = r + 1;
			}
		}
		return ret;
	}
};