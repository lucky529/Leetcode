//给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
//
//说明：
//
//拆分时可以重复使用字典中的单词。
//你可以假设字典中没有重复的单词。
//示例 1：
//
//输入 : s = "leetcode", wordDict = ["leet", "code"]
// 输出 : true
//  解释 : 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
//	   示例 2：
//
//   输入 : s = "applepenapple", wordDict = ["apple", "pen"]
//	输出 : true
//	 解释 : 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
//		  注意你可以重复使用字典中的单词。
//		  示例 3：
//
//	  输入 : s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
//	   输出 : false

//这实际上可以转化一个完全背包问题
//思路：1.使用动态规划的思想判度单词的前i个是否可以切分出字典中的单词
//      2.以leetcode为例 如果leetcode的前一部分leet处于字典中 那么后半部分code也只要处于字典中就可以了

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

//大佬的dfs
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
		vector<int> visit(s.size(), -1);//-1:没访问过,0:false,1:true
		return wordBreak(s, 0, wordSet, visit);
	}
private://[index, s.size())是否可以拆分成wordDict里的词
	bool wordBreak(const string& s, int index, unordered_set<string>& wordDict, vector<int>& visit) {
		if (index == s.size() - 1) return wordDict.count(string(1, s[index]));
		if (index == s.size()) return true;

		int& vis = visit[index];
		if (vis != -1) return vis;

		bool ans = false;
		string tmp = "";
		for (int i = index; i < s.size() && !ans; i++) {//!ans => if(ans)break;已经找到了就别找了。
			if (wordDict.count(tmp += s[i])) ans = ans || wordBreak(s, i + 1, wordDict, visit);
		}
		return vis = ans;//赋值返回
	}
};