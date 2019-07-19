//16msͨ�� 1.���������ҵ������е�һ��nums[i-1] < nums[i]��λ�� 
//		   2.Ȼ���i֮���ҵ���һ������nums[i-1]����ӽ���������
//		   3.����nums[i - 1], ����ӽ��������֣�֮��i֮�������ǰ�������������н���
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		for (int i = nums.size() - 1; i >= 1; i--) {
			if (nums[i - 1] < nums[i]) {
				int cur = nums.size() - 1;
				while (cur >= i) {
					if (nums[cur] > nums[i - 1]) {
						break;
					}
					cur--;
				}
				swap(nums[i - 1], nums[cur]);

				int end = nums.size() - 1;
				while (i < end) {
					swap(nums[i], nums[end]);
					i++; end--;
				}
				return;
			}
		}
		reverse(nums.begin(), nums.end());
	}
};