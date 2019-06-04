//���������ڵ��������ֽ������δ�С�ıȽϽ�������
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		if (nums.size() == 0 || nums.size() == 0) return;
		int cur = 1, pre = 0;
		while (cur < nums.size()) {
			if (nums[cur] < nums[pre]) {
				int tmp = nums[cur];
				nums[cur] = nums[pre];
				nums[pre] = tmp;
			}
			cur += 2;
			pre += 2;
		}
		if (nums.size() == 2) return;
		cur = 2, pre = 1;
		while (cur < nums.size()) {
			if (nums[cur] > nums[pre]) {
				int tmp = nums[cur];
				nums[cur] = nums[pre];
				nums[pre] = tmp;
			}
			cur += 2;
			pre += 2;
		}
	}
};
//�ж�����ż��λ�ý�������
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		int size = nums.size();
		for (int i = 1; i < size; ++i)
		{
			if (i & 1)
			{
				if (nums[i - 1] > nums[i])
				{
					swap(nums[i - 1], nums[i]);
				}
			}
			else
			{
				if (nums[i - 1] < nums[i])
				{
					swap(nums[i - 1], nums[i]);
				}
			}
		}
	}
};