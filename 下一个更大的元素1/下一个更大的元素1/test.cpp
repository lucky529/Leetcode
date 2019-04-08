//20ms通过 1.使用map记住数组一中每个元素在数组二的位置 2.查看从数组2的当前位置开始是否存在比当前元素大的值
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