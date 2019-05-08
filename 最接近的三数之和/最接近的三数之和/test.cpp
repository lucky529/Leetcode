//20msͨ�� 1.������֮�͵�˼����ȫ��ͬ����������һ��min��������¼��ǰ������target��С�Ĳ��
//		   2.�����ǰ����֮�;���Ϊtarget��ô����ֱ�ӷ���target����
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int n = nums.size(), min = INT_MAX, sum = 0;
		for (int i = 0; i < n; i++) {
			int start = i + 1, end = n - 1;
			while (start < end) {
				int tmp = nums[start] + nums[end] + nums[i];
				if (abs(tmp - target) < min) {
					min = abs(tmp - target); sum = tmp;
				}
				if (tmp > target)
					end--;
				else if (tmp < target)
					start++;
				else
					return target;
			}
		}
		return sum;
	}
};