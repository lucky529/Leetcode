//nums = [10 9 2 5 3 4 101 18], tail = []
//i = 0��tail = [10] ��size = 1
//i = 1��tail = [9]��size = 1����Ϊ9��10С����û�б�9��С����������ֱ�Ӱ�10�滻Ϊ9
//i = 2��tail = [2]��size = 1��ͬ��
//i = 3��tail = [2, 5]�� size = 2�� tail�����һ������С��5�����Կ���ֱ�Ӱ�5�ŵ�����
//i = 4��tail = [2, 3]�� size = 2�� 2 < 3 < 5������3�����5�Ǹ��Ž�
//i = 5��tail = [2, 3, 4]��size = 3��4 > 3, ֱ��append
//i = 6��tail = [2, 3, 4, 101]�� size = 4�� 101 > 4, ֱ��append
//i = 7�� tail = [2, 3, 4, 18], size = 4��4 < 18 < 101�� ���Խ��Ϊ 4
//�Ż��� ʹ�ö��ַ��ҵ� ��ǰ����Ҫ���뵽tail�е�λ��

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int maxL = 0;
		vector<int> dp(nums.size(), 0);
		for (int num : nums) {
			// ���ַ�����, Ҳ���Ե��ÿ⺯����binary_search
			int lo = 0, hi = maxL;
			while (lo < hi) {
				int mid = lo + (hi - lo) / 2;
				if (dp[mid] < num)
					lo = mid + 1;
				else
					hi = mid;
			}
			dp[lo] = num;
			if (lo == maxL)
				maxL++;
		}
		return maxL;
	}
};

class Solution {//lower_bound�ĵײ���ʹ�ö��ֲ���ʵ�ֵ�
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> arr;
		for (auto num : nums) {
			if (arr.empty() || num > arr.back()) {
				arr.push_back(num);
			}
			else {
				*(lower_bound(arr.begin(), arr.end(), num)) = num;
			}
		}
		return arr.size();
	}
};

//��̬�滮��˼�룬����ʵ����ʱ�临�ӶȻ���on2
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();
		vector<int> dp(nums.size(), 1);
		for (int i = 1; i < nums.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (nums[j] < nums[i])
					dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		int ret = dp[0];
		for (auto& e : dp)
		{
			if (e > ret)
				ret = e;
		}
		return ret;
	}
};