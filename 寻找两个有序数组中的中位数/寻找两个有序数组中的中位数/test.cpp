//28ms通过 二分查找思想
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size();
		if (m > n)
		{
			return findMedianSortedArrays(nums2, nums1);
		}
		int start = 0, end = m, mid = (m + n + 1) / 2;
		while (start <= end)
		{
			int i = (start + end) / 2;
			int j = mid - i;
			if (i < end && nums1[i] < nums2[j - 1])
			{
				start = i + 1;
			}
			else if (i > start && nums1[i - 1] > nums2[j])
			{
				end = i - 1;
			}
			else
			{
				int minleft;
				if (i == 0)
				{
					minleft = nums2[j - 1];
				}
				else if (j == 0)
				{
					minleft = nums1[i - 1];
				}
				else
				{
					minleft = max(nums1[i - 1], nums2[j - 1]);
				}
				if ((m + n) % 2 == 1)
					return minleft;

				int maxright;
				if (i == m) //num1 < nums2
				{
					maxright = nums2[j];
				}
				else if (j == n)//nums2 > nums1
				{
					maxright = nums1[i];
				}
				else
				{
					maxright = min(nums1[i], nums2[j]);
				}
				return (minleft + maxright) / 2.0;
			}
		}
		return -1;
	}
};