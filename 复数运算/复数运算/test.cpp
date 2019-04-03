//4msͨ�� 1.��ȡ�����е�4������ 2.���ճ˷�������ԭ�����ת��Ϊ�ַ�������
class Solution {
public:
	string complexNumberMultiply(string a, string b) {
		int cur1 = a.size() - 1, cur2 = b.size() - 1;
		int x1 = atoi(a.c_str());
		int x2 = atoi(b.c_str());
		while (a[cur1] != '+'){
			cur1--;
		}
		a = a.substr(cur1 + 1);
		while (b[cur2] != '+'){
			cur2--;
		}
		b = b.substr(cur2 + 1);
		int y1 = atoi(a.c_str());
		int y2 = atoi(b.c_str());
		int aa = x1 * x2 - y1 * y2;
		int bb = x1 * y2 + x2 * y1;
		string ret = "";
		ret += (to_string(aa) + "+") + (to_string(bb) + "i");
		return ret;
	}
};