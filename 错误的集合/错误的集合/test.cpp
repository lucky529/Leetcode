//44ms ������Ƿ�
class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		vector<int> result;
		int numsSize = nums.size();
		//��һ������Ǹ���Ԫ�س����Ƿ����
		for (auto num : nums){
			num = abs(num);
			if (nums[num - 1] < 0){//Ԫ�س���������
				result.push_back(num);
			}
			else{
				//��num��������ڵ��±��Ԫ�ر�ţ���ʾnum������һ��
				nums[num - 1] = -nums[num - 1];
			}
		}
		//�ڶ�����Ѱ��δ���ֵ�Ԫ��
		for (int index = 0; index < numsSize; ++index){
			if (nums[index] > 0){//�����㣬˵��index + 1 û�г��ֹ�
				result.push_back(index + 1);
				break;
			}
		}
		return result;
	}
};