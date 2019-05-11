//24msͨ�� 1.����ľ����͵��ǿ�����˴�ˮ�Ķ��� 2.���Ե�ÿ�μ����굱ǰ�Ĵ�ˮ����Ӧ��Ѱ����һ����ߵ�ľ�� 3.Ҳ�����ƶ�
//�͵��ǿ�ľ��
class Solution {
public:
	int maxArea(vector<int>& height) {
		int wide = height.size() - 1, start = 0, end = height.size() - 1, ret = 0;
		while (start < end) {
			int num = min(height[start], height[end]);
			ret = max(ret, wide*num);
			if (height[start] > height[end]) {
				end--;
			}
			else {
				start++;
			}
			wide--;
		}
		return ret;
	}
};