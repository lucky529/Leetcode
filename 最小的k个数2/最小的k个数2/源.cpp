class Solution {
public:
	int PartSort(vector<int>& input, int start, int end)
	{
		if (input.empty() || start>end) return -1;
		int key = start;
		int pre = start, cur = start + 1;
		while (cur <= end)
		{
			if (input[cur] <= input[key] && ++pre != cur)
			{
				swap(input[cur], input[pre]);
			}
			++cur;
		}
		swap(input[pre], input[key]);
		return pre;
	}
	vector<int> QuickSort(vector<int>& input, int start, int end, int k)
	{
		vector<int> v;
		if (input.empty() || k>input.size() || k <= 0) return v;
		int index = PartSort(input, start, end);
		if (index == k - 1)
		{
			for (int i = 0; i < k; i++)
				v.push_back(input[i]);
			return v;
		}
		if (index > k - 1)
			return QuickSort(input, start, index - 1, k);
		if (index < k - 1)
			return QuickSort(input, index + 1, end, k);
		return v;
	}
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		return QuickSort(input, 0, input.size() - 1, k);
	}
};