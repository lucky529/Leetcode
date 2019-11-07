//����������������ǣ�浽���ŵ�������⣬һ��ʹ�õݹ� + ���ݵ�˼�롣��Ҫ�뷨��
//
//��һ���ݹ���ݡ����Բ������е���Ϸ�ʽ��
//
//�����ÿ��С��Ϸ�ʽ�൱��һ���Ӽ������ϵĽ����������ظ���һ�㡣
//
//������a + (b - (c * d))�᲻�ϵı��a + (b - (res1 * res2))->a + (res1 - res2)->res1 + res2
//
//�ƺ�����������Ҫforѭ������ʵ�����������a + (b - (c * d))��a + (b - c) * d))������ a + res2
//��res2�Ϳ����ж��������
class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		vector<int> ret;
		for (int i = 0; i < input.size(); i++) {
			char c = input[i];
			if (c == '+' || c == '-' || c == '*') {
				auto l = diffWaysToCompute(input.substr(0, i));
				auto r = diffWaysToCompute(input.substr(i + 1));
				for (auto ll : l) {
					for (auto rr : r) {
						if (c == '+') {
							ret.push_back(ll + rr);
						}
						else if (c == '-') {
							ret.push_back(ll - rr);
						}
						else if (c == '*') {
							ret.push_back(ll*rr);
						}
					}
				}
			}
		}
		if (ret.empty())
			ret.push_back(stoi(input));
		return ret;
	}
};