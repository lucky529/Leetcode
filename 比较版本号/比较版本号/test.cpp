//8ms Í¨¹ý
class Solution {
public:
	int compareVersion(string version1, string version2) {
		for (int i = 0, j = 0; i < version1.size() || j < version2.size();)
		{
			int v1 = 0, v2 = 0;
			while (i < version1.size() && version1[i] != '.')
			{
				v1 = v1 * 10 + (version1[i] - '0');
				i++;
			}
			i++;
			while (j < version2.size() && version2[j] != '.')
			{
				v2 = v2 * 10 + (version2[j] - '0');
				j++;
			}
			j++;
			if (v1 > v2) return 1;
			if (v1 < v2) return -1;
		}
		return 0;
	}
};