//44ms 负数标记法
class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		vector<int> result;
		int numsSize = nums.size();
		//第一步：标记各个元素出现是否出现
		for (auto num : nums){
			num = abs(num);
			if (nums[num - 1] < 0){//元素出现了两次
				result.push_back(num);
			}
			else{
				//将num排序后所在的下标的元素变号，表示num出现了一次
				nums[num - 1] = -nums[num - 1];
			}
		}
		//第二步：寻找未出现的元素
		for (int index = 0; index < numsSize; ++index){
			if (nums[index] > 0){//大于零，说明index + 1 没有出现过
				result.push_back(index + 1);
				break;
			}
		}
		return result;
	}
};