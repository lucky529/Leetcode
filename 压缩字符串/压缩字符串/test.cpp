//28msͨ����ֵ�ü����һ���⣬����һ�����ͻȻ�е�˼·��1.ǰ��ָ��ͳ��ǰ���ַ���ͬ�ĸ��������countΪһ��ѹ��ֱ�ӷ��õ�����ǰ��
//2.��index����Ƿ��õ�λ�� 3.������count�����ַ���������һ����ԭ���޸�û��ʹ�ö���Ŀռ�
class Solution {
public:
	int compress(vector<char>& chars) {
		int cur = 0, pre = 0, index = 0, count = 0;
		while (cur < chars.size())
		{
			char tmp = chars[pre];
			while (cur < chars.size() && tmp == chars[cur])
			{
				cur++; count++;
			}
			if (count == 1)
			{
				chars[index++] = chars[pre];
				count = 0; pre = cur;
				continue;
			}
			chars[index++] = tmp;
			string tmpp = to_string(count);
			for (int i = 0; i <= tmpp.size() - 1; i++)
			{
				chars[index++] = tmpp[i];
			}
			count = 0; pre = cur;
		}
		return index;
	}
};