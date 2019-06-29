//0msͨ�� 1.��ָ�룬����0�����������ǰ�� ������2�������������� ������1ֱ������
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int i = 0, l = 0, r = nums.size() - 1;
		while (i <= r){
			if (i<l || nums[i] == 1)
				i++;
			else if (nums[i] == 0)
				swap(nums[i], nums[l++]);
			else if (nums[i] == 2)
				swap(nums[i], nums[r--]);
		}
	}
};