class Solution {
public:
	enum Status{ valueTrue = 0, valueFalse };
	int g_val = valueTrue;
	long long StrToIntCore(string& str, int& index, bool minus)
	{
		long long num = 0;
		while (str[index] != '\0')
		{
			if (str[index] >= '0' && str[index] <= '9')
			{
				int flag = minus ? -1 : 1;
				num = num * 10 + flag*(str[index] - '0');
				if ((!minus && num > 0x7fffffff) || (minus && num < (signed int)0x80000000))
				{
					num = 0; break;
				}
				index++;
			}
			else{
				num = 0; break;
			}
		}
		if (str[index] == '\0')
			g_val = valueTrue;
		return num;
	}
	int StrToInt(string str) {
		g_val = valueFalse;
		long long num = 0;
		int index = 0;
		if (str[index] != '\0')
		{
			bool minus = false;
			if (str[index] == '+')
				++index;
			else if (str[index] == '-')
			{
				minus = true;
				++index;
			}
			if (str[index] != '\0')
			{
				num = StrToIntCore(str, index, minus);
			}
		}
		return (int)num;
	}
};