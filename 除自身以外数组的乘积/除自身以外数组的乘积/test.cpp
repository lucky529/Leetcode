//�����˻������к��� 16msͨ�� 1.�������ұ��������ȥ��ǰ���ֵ���� 2.����������������ȥ��ǰ���ֵ��ұ�
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> v(nums.size(), 1);
		int k = 1;
		for (int i = 0; i < nums.size(); i++)//�Գ��˵�ǰ����������������
		{
			v[i] *= k;
			k = k*nums[i];
		}
		k = 1;
		for (int i = nums.size() - 1; i >= 0; i--)//�Ե�ǰ�����ұ߽������
		{
			v[i] *= k;
			k = k*nums[i];
		}
		return v;
	}
};