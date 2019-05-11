//24ms通过 1.两块木板最低的那块决定了存水的多少 2.所以当每次计算完当前的储水量就应该寻找下一块更高的木板 3.也就是移动
//低的那块木板
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