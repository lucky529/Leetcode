//20msͨ�� 1.ʹ��map��ס����һ��ÿ��Ԫ�����������λ�� 2.�鿴������2�ĵ�ǰλ�ÿ�ʼ�Ƿ���ڱȵ�ǰԪ�ش��ֵ
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> mp;
		for (int i = 0; i < nums2.size(); i++)
		{
			mp[nums2[i]] = i;
		}
		for (int i = 0; i < nums1.size(); i++)
		{
			int flag = 1;
			for (int j = mp[nums1[i]]; j < nums2.size(); j++)
			{
				if (nums1[i] < nums2[j])
				{
					nums1[i] = nums2[j];
					flag = 0;
					break;
				}
			}
			if (flag)
				nums1[i] = -1;
		}
		return nums1;
	}
};