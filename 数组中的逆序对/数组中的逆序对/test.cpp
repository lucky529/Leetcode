//120ms通过 使用归并排序的思想
class Solution {
public:
	int Inverse(vector<int>& data, vector<int>& copy, int start, int end)
	{
		if (start == end) {
			copy[start] = data[start]; return 0;
		}
		int len = (end - start) / 2;
		int left = Inverse(data, copy, start, start + len) % 1000000007;
		int right = Inverse(data, copy, start + len + 1, end) % 1000000007;
		int i = start + len;
		int j = end;
		int copyindex = end;
		int count = 0;
		while (i >= start && j >= start + len + 1)
		{
			if (data[i] > data[j]) {
				copy[copyindex--] = data[i--];
				count += j - len - start;
				if (count >= 1000000007)//数值过大求余
				{
					count %= 1000000007;
				}
			}
			else {
				copy[copyindex--] = data[j--];
			}
		}
		while (i >= start){
			copy[copyindex--] = data[i--];
		}
		while (j >= start + len + 1){
			copy[copyindex--] = data[j--];
		}
		for (int i = start; i <= end; i++) {
			data[i] = copy[i];
		}
		return count + left + right;
	}
	int InversePairs(vector<int> data) {
		vector<int> copy(data);
		return Inverse(data, copy, 0, data.size() - 1) % 1000000007;
	}
};