//4msͨ�� �ο����� 1.�ҵ���λ��һ��С�ڵ�λ��2������ 2.����������Ԫ�� 3.�Ը�λ֮������ֽ�������
class Solution {
public:
	int nextGreaterElement(int n) {
		string s = to_string(n);
		int high = -1, low = -1;
		for (int i = s.size() - 2; i >= 0; i--)
		{
			for (int j = i; j < s.size(); j++)
			{
				if (s[i] < s[j])
				{
					high = i;
					low = low == -1 ? j : (s[j] > s[low] ? low : j);
				}
			}
			if (high != -1)
			{
				char tmp = s[high];
				s[high] = s[low];
				s[low] = tmp;
				sort(s.begin() + high + 1, s.end());
				double d = atol(s.c_str());//ʹ��atol��ֹ����̫�����
				if (d > INT_MAX)
					return -1;
				else
					return d;
			}
		}
		return -1;
	}
};