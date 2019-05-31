//�����������Ǹ�������ô�ᵼ�����ı���С�ģ���С�ı����ġ���˽���������ֵ
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int Max = INT_MIN, imax = 1, imin = 1;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] < 0) swap(imax, imin);
			imax = max(nums[i], imax*nums[i]);
			imin = min(nums[i], imin*nums[i]);

			Max = max(Max, imax);
		}
		return Max;
	}
};
//˼·�� �����ֵ�����Կ�����0��ֵĸ�������������ֵ��
//
//��һ��������û��0���ڣ����Ϊ���������
//
//1.����Ϊż����������������ĸ���ֵ���Ϊ���ֵ��
//
//2.����Ϊ�������������߿�ʼ���˵����һ������ֹͣ��һ�������ֵ�������ұ�Ҳ��һ�������ֵ�����Ƚϣ��ó����ֵ��
class Solution {
	public int maxProduct(int[] nums) {
		int a = 1;
		int max = nums[0];

		for (int num : nums){
			a = a*num;
			if (max<a)max = a;
			if (num == 0)a = 1;

		}
		a = 1;
		for (int i = nums.length - 1; i >= 0; i--){
			a = a*nums[i];
			if (max<a)max = a;
			if (nums[i] == 0)a = 1;
		}
		return max;
	}
}