//44ms 1.�жϵ�ǰ�����Ƿ��б���������� 2.�жϵ�ǰ�����Ƿ��б���С������ 3.�������Ϊ��˵���������򣬲�Ϊ��ȡС��count
//�ж��Ƿ�Ϊ1
class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		int n = nums.size(), a = nums[0], b = nums[n - 1], count1 = 0, count2 = 0;
		for (int i = 0; i<n; i++){
			b = min(b, nums[n - 1 - i]);
			a = max(a, nums[i]);
			if (a != nums[i])
				count2++;
			if (b != nums[n - 1 - i])
				count1++;
		}
		if (count1 == 0 && count2 == 0)
			return true;
		return min(count1, count2) == 1;
	}
};