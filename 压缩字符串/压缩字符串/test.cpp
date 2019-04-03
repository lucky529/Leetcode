//28ms通过（值得纪念的一道题，踩了一下午坑突然有的思路）1.前后指针统计前后字符相同的个数，如果count为一不压缩直接放置到数组前面
//2.用index来标记放置的位置 3.将计数count拆解成字符串，遍历一遍且原地修改没有使用额外的空间
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