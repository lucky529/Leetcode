//16ms 1.�ܼ����ƶ����˼·��ȫ��ͬ 2.����tmp�ڱ����ݣ������ظ����� 3.ֻҪʹ��index�±갤����ǰ�žͿ���
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int index = 0, cur = 0, flag = 2;
		while (cur < nums.size())
		{
			int tmp = nums[cur];
			while (cur < nums.size() && nums[cur] == tmp && flag)
			{
				nums[index++] = nums[cur++]; flag--;
			}
			while (cur < nums.size() && nums[cur] == tmp)
			{
				cur++;
			}
			flag = 2;
		}
		return index;
	}
};