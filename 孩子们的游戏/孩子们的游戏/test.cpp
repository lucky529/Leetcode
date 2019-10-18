//当数组当前元素为1时表示有效，否则表示无效
class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		vector<int> v(n, 1);
		int flag = 1, index = 0, size = n;
		while (n > 1)
		{
			if (flag%m == 0 && v[index] != 0){
				v[index] = 0;
				flag++;
				n--;
			}
			if (v[index] != 0)
				flag++;
			index++;
			if (index == size)
				index = 0;
		}
		for (int i = 0; i < size; i++){
			if (v[i] == 1)
				return i;
		}
		return -1;
	}
};