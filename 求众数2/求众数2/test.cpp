//�������������Ȥ��һ���⣬�������򵥣�����Ҫ��ʱ��Ϳռ临�Ӷ�֮��ͱ���ʹ��Ħ��ͶƱ���㷨
//1.���������г���һ��������ٶ������һ�����ڣ���ôʹ��Ħ��ͶƱ����������־�������
//2.����Ҫ�������г��ִ���n/3�����֣���ô�������ֻ������������������ʹ���������
//3.�����ֵ��������Ǳ�ʶ�����ֶ�����ͬʱ��ͬʱ--��������ǵõ������������ܻ��Ϊ�����е�һ��
class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		vector<int> v;
		int x = 0, y = 0, cx = 0, cy = 0;
		for (auto& e : nums) {
			if ((cx == 0 || e == x) && e != y) {
				cx++; x = e;
			}
			else if (cy == 0 || e == y) {
				cy++; y = e;
			}
			else {
				cy--; cx--;
			}
		}
		int count = 0;
		for (auto& e : nums) {
			if (e == x) count++;
		}
		if (count > nums.size() / 3) v.push_back(x);
		count = 0;
		for (auto& e : nums) {
			if (e == y) count++;
		}
		if (count > nums.size() / 3 && x != y) v.push_back(y);
		return v;
	}
};