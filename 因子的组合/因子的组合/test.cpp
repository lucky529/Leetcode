//ʹ������ܺ͵�˼�� 
//�����ܽ�һ�µݹ����±�Ŀ���
�ݹ���ʹ�ã�
//	i :			��ʾ��ǰ���ֿ����ظ�ʹ�ã�����֮������ֶ��ȵ�ǰ����С������ܺ�1����ʹ���ظ����֣�
//	i + 1 :		��ʾ��ǰ���ֲ������ظ�ʹ�ã����Һ�������ֶ��ȵ�ǰ����С ����ܺ�2��������ʹ���ظ����֣� ���
//				�ܺ�3 ���0 �Ӽ�
//	index + 1 : ȫ������ʹ�ã���ʾ��ǰ�±�����ֺ���һ�����ֽ���
class Solution {
public:
	vector<vector<int>> vv;
	vector<int> v;
	void _getFactors(int n, int index)
	{
		if (n == 1)
		{
			if (v.size() > 1)//һ�������ٷֳ���������
			{
				vv.push_back(v);
			}
		}
		for (int i = index; i <= n; i++)
		{
			if (n % i == 0)
			{
				v.push_back(i);
				_getFactors(n / i, i);
				v.pop_back();
			}
		}
	}
	vector<vector<int>> getFactors(int n) {
		if (n == 1) return{};
		_getFactors(n, 2);
		return vv;
	}
};