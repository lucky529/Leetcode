//����һ���ǿ��ַ��� s ��һ�������ǿյ����б���ֵ� wordDict���ж� s �Ƿ���Ա��ո���Ϊһ���������ֵ��г��ֵĵ��ʡ�
//
//˵����
//
//���ʱ�����ظ�ʹ���ֵ��еĵ��ʡ�
//����Լ����ֵ���û���ظ��ĵ��ʡ�
//ʾ�� 1��
//
//���� : s = "leetcode", wordDict = ["leet", "code"]
// ��� : true
//  ���� : ���� true ��Ϊ "leetcode" ���Ա���ֳ� "leet code"��
//	   ʾ�� 2��
//
//   ���� : s = "applepenapple", wordDict = ["apple", "pen"]
//	��� : true
//	 ���� : ���� true ��Ϊ "applepenapple" ���Ա���ֳ� "apple pen apple"��
//		  ע��������ظ�ʹ���ֵ��еĵ��ʡ�
//		  ʾ�� 3��
//
//	  ���� : s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
//	   ��� : false

//��ʵ���Ͽ���ת��һ����ȫ��������
//˼·��1.ʹ�ö�̬�滮��˼���жȵ��ʵ�ǰi���Ƿ�����зֳ��ֵ��еĵ���
//      2.��leetcodeΪ�� ���leetcode��ǰһ����leet�����ֵ��� ��ô��벿��codeҲֻҪ�����ֵ��оͿ�����

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		vector<bool> dp(s.size() + 1, false);
		unordered_set<string> m(wordDict.begin(), wordDict.end());
		dp[0] = true;
		for (int i = 1; i <= s.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (dp[j] && m.find(s.substr(j, i - j)) != m.end())
				{
					dp[i] = true;
					break;
				}
			}
		}
		return dp[s.size()];
	}
};

//���е�dfs
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
		vector<int> visit(s.size(), -1);//-1:û���ʹ�,0:false,1:true
		return wordBreak(s, 0, wordSet, visit);
	}
private://[index, s.size())�Ƿ���Բ�ֳ�wordDict��Ĵ�
	bool wordBreak(const string& s, int index, unordered_set<string>& wordDict, vector<int>& visit) {
		if (index == s.size() - 1) return wordDict.count(string(1, s[index]));
		if (index == s.size()) return true;

		int& vis = visit[index];
		if (vis != -1) return vis;

		bool ans = false;
		string tmp = "";
		for (int i = index; i < s.size() && !ans; i++) {//!ans => if(ans)break;�Ѿ��ҵ��˾ͱ����ˡ�
			if (wordDict.count(tmp += s[i])) ans = ans || wordBreak(s, i + 1, wordDict, visit);
		}
		return vis = ans;//��ֵ����
	}
};