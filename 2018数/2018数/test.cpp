#include<iostream>
#include<windows.h>
#include<unordered_map>
#include<unordered_set>
#include<sstream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<list>
#include<set>
#include<stdlib.h>
#include<time.h>
#include<stack>
using namespace std;

//vector<string> findRelativeRanks(vector<int>& nums) {
//	map<int, int> mp;
//	vector<string> v(nums.size());
//	for (int i = 0; i < nums.size(); i++)
//	{
//		mp[nums[i]] = i;
//	}
//	int rank = 0, flag = 0;
//	auto it = mp.begin();
//	while (it != mp.end())
//	{
//		if (rank == 0 && flag == 0)
//		{
//			v[it->second] = "Gold Medal";
//			flag = 1; rank++;
//			it++;
//		}
//		if (rank == 1 && flag == 0)
//		{
//			v[it->second] = "Silver Medal";
//			flag = 1; rank++;
//			it++;
//		}
//		if (rank == 2 && flag == 0)
//		{
//			v[it->second] = "Bronze Medal";
//			flag = 1; rank++;
//			it++;
//		}
//		else
//		{
//			v[it->second] = to_string(rank++);
//			it++;
//		}
//		flag = 0;
//	}
//	return v;
//}
//// 1 1 3 4 5
//
//int findPairs(vector<int>& nums, int k) {
//	sort(nums.begin(), nums.end());
//	int start = 0, size = nums.size(), end = size-1, count = 0;
//	while (start < nums.size())
//	{
//		if (start < end && nums[end] - nums[start] == k)
//		{
//			count++;
//			end = size-1;
//			int tmp = nums[start];
//			while (start < size && tmp == nums[start])
//			{
//				start++;
//			}
//			if (start == end && end == size - 1)
//			{
//				break;
//			}
//			continue;
//		}
//		else
//		{
//			if (start+1 == end)
//			{
//				int tmp = nums[start];
//				while (start < size && tmp == nums[start])
//				{
//					start++;
//				}
//				end = size - 1;
//				if (start == end && end == size - 1)
//				{
//					break;
//				}
//			}
//			else
//			{
//				--end;
//			}
//		}
//	}
//	return count;
//}
//#define ofsetoff(s,m) (size_t)&(((s*)0)->m)
//struct A
//{
//	int a;
//	char c;
//};
//int main()
//{
//	cout << ofsetoff(A, a) << endl;
//	system("pause");
//	return 0;
//}

//如 0, 1, 6, 8, 9 旋转 180° 以后，得到了新的数字 0, 1, 9, 8, 6 。

//2, 3, 4, 5, 7 旋转 180° 后, 得到的不是数字。
//int main()
//{
//	int num = 11;
//	int flag = num;
//	vector<int> v;
//	while (num != 0)
//	{
//		int tmp = num % 10;
//		if (tmp == 2 || tmp == 3 || tmp == 4 || tmp == 5 || tmp == 7)
//		{
//			return false;
//		}
//		if (tmp == 0 && !v.empty())
//		{
//			v.push_back(0);
//		}
//		else if (tmp == 1)
//		{
//			v.push_back(1);
//		}
//		else if (tmp == 6)
//		{
//			v.push_back(9);
//		}
//		else if (tmp == 8)
//		{
//			v.push_back(8);
//		}
//		else if (tmp == 9)
//		{
//			v.push_back(6);
//		}
//		num /= 10;
//	}
//	int ret = 0;
//	for (int i = 0; i < v.size(); i++)
//	{
//		ret = ret*10 + v[i];
//	}
//	if (ret != flag)
//		return true;
//	else
//		return false;
//	system("pause");
//	return 0;
//}
//class Person {
//public:
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//class Student : public Person {
//public:
//	virtual ~Student() { cout << "~Student()" << endl; }
//};
// 只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函数，才能构成多
//态，才能保证p1和p2指向的对象正确的调用析构函数。

//int maximumProduct(vector<int>& nums) {
//	int map[2001] = { 0 };
//	for (int i = 0; i < nums.size(); i++)
//	{
//		map[1000 + nums[i]]++;
//	}
//	int a = INT_MAX, b = INT_MAX, c = INT_MAX, d = INT_MAX, e = INT_MAX, flag1 = 0, flag2 = 0;
//	for (int i = 0; i < 2001; i++) {
//		if (flag1 == 2) break;
//		while (map[i] > 0) {
//			if (a == INT_MAX)
//			{
//				flag1++;
//				a = i - 1000; map[i]--; continue;
//			}
//			if (b == INT_MAX)
//			{
//				 flag1++;
//				 b = i - 1000; map[i]--; continue;
//			}
//			if (flag1 == 2) break;
//		}
//	}
//	memset(map, 0, sizeof(int)* 2001);
//
//	for (int i = 0; i < nums.size(); i++)
//	{
//		map[1000 + nums[i]]++;
//	}
//	for (int i = 2001; i >= 0; i--) {
//		if (flag1 == 3) break;
//		while (map[i] > 0) {
//			if (c == INT_MAX)
//			{
//				flag2++;
//				c = i - 1000; map[i]--; continue;
//			}
//			if (d == INT_MAX)
//			{
//				flag2++;
//				d = i - 1000; map[i]--; continue;
//			}
//			if (e == INT_MAX)
//			{
//				 flag2++;
//				 e = i - 1000; map[i]--; continue;
//			}
//			if (flag2 == 3) break;
//		}
//	}
//	return a*b*c > c*d*e ? a*b*c : c*d*e;
//}
//int arr[3] = { 2, 6, 7 };
//int avg(int* A, int N)
//{
//	int ans = 0, res = 0;
//	for (int i = 0; i<N; i++)
//	{
//		ans += A[i] / N;
//		res += A[i] % N;
//		ans += res / N;
//		res = res%N;
//	}
//	return ans;
//}

//int findShortestSubArray(vector<int>& nums) {
//	unordered_map<int, vector<int>> m;
//	for (int i = 0; i < nums.size(); i++){
//		m[nums[i]].push_back(i);
//	}
//	int nums_du = 0, min_len = nums.size();
//	for (auto iter = m.begin(); iter != m.end(); iter++){
//		int size = iter->second.size();
//		if (size >= nums_du){
//			int temp = iter->second[size - 1] - iter->second[0] + 1;
//			if (size > nums_du){
//				nums_du = size;
//				min_len = temp;
//			}
//			else{
//				min_len = min(min_len, temp);
//			}
//		}
//	}
//	return min_len;
//}

//string longestWord(vector<string>& words) {
//	sort(words.begin(), words.end());
//	set<string> s;
//	string ret = "";
//	for (auto str : words)
//	{
//		string tmp = str.substr(0, str.size()-1);
//		if (str.size() == 1 || s.find(str.substr(0, str.size()-1)) != s.end())
//		{
//
//			ret = str.size() > ret.size() ? str : ret;
//			s.insert(str);
//		}
//	}
//	return ret;
//}

//int myrand()
//{
//	srand((unsigned)time(0));
//	int number = rand() % 6 + 1;
//	cout << number << endl;
//	return number;
//}
//int reachNumber(int target) {
//
//	if (1)
//	{
//		;
//	}
//	else
//	{
//		cout << "hello word" << endl;
//	}
//	return 0;
//}

//vector<string> subdomainVisits(vector<string>& cpdomains) {
//	map<string, int> mp;
//	vector<string> v;
//	for (auto& e : cpdomains)
//	{
//		int num = atoi(e.c_str()), cur = 0;
//		string str = "";
//		istringstream tmp(e);
//		while (tmp >> str){}
//		mp[str] += num;
//		while (cur < str.size())
//		{
//			string s = "";
//			while (cur < str.size() && str[cur] != '.')
//			{
//				cur++;
//			}
//			if (cur + 1 < str.size())
//				s = str.substr(++cur);
//			mp[s] += num;
//		}
//	}
//	for (auto it = (++mp.begin()); it != mp.end(); it++)
//	{
//		v.push_back(to_string(it->second) + " " + it->first);
//	}
//	return v;
//}
//bool hasGroupsSizeX(vector<int>& deck) {
//	map<int, int> mp;
//	for (auto& e : deck)
//	{
//		mp[e]++;
//	}
//	if (mp.size() == 1 && mp.begin()->second >= 2)
//		return true;
//	else
//		return false;
//
//	auto cur = (++mp.begin()), pre = mp.begin();
//	while (cur != mp.end())
//	{
//		if (pre->second < 2 || cur->second < 2) return false;
//		if (cur->second % pre->second != 0) return false;
//		cur++; pre++;
//	}
//	return true;
//}

//string formatString(string A, int n, vector<char> arg, int m) {
//	string ret = "";
//	int flag = 0, length = arg.size(), cur = 0;
//	for (auto& e : A) {
//		if (e == '%') {
//			flag = 1; continue;
//		}
//		else if (e == 's' && flag == 1) {
//			ret += arg[cur];
//			cur++; flag = 0;
//			if (cur == length) break;
//		}
//		else {
//			ret += e;
//		}
//	}
//	while (cur < length)
//	{
//		ret += arg[cur++];
//	}
//	return ret;
//}

//int getValue(vector<int> gifts, int n) {
//	map<int, int> mp;
//	int tmp;
//	for (auto& e : gifts)
//	{
//		mp[e]++;
//	}
//	for (auto it = mp.begin(); it != mp.end(); it++)
//	{
//		if (it->second > (n / 2))
//			tmp = it->first;
//	}
//	return 0;
//}


	//string largestTimeFromDigits(vector<int>& A) {
	//	sort(A.begin(),A.end());
	//	for (int i = 3; i >= 0; i--){
	//		if (A[i]>2) continue;
	//		for (int j = 3; j >= 0; j--) {
	//			if (j == i || A[i] == 2 && A[j]>3) continue;
	//			for (int k = 3; k >= 0; k--) {
	//				if (k == i || k == j || A[k]>5) continue;
	//				return "" + A[i] + A[j] + ':' + A[k] + A[6 - i - j - k];
	//			}
	//		}
	//	}
	//	return "";
	//}

//vector<int> powerfulIntegers(int x, int y, int bound) {
//	vector<int> xv;
//	vector<int> yv;
//	vector<int> v;
//	for (int i = 0;; i++)
//	{
//		if (pow(x, i) <= bound)
//			xv.push_back(pow(x, i));
//		else if (x == 1)
//		{
//			xv.push_back(1);
//			break;
//		}
//		else
//			break;
//	}
//	for (int i = 0;; i++)
//	{
//		if (pow(y, i) <= bound)
//			yv.push_back(pow(y, i));
//		else if (y == 1)
//		{
//			yv.push_back(1);
//			break;
//		}
//		else
//			break;
//	}
//	for (int i = 0; i < xv.size(); i++)
//	{
//		for (int j = 0; j < yv.size(); j++)
//		{
//			if (xv[i] + yv[j] <= bound && find(v.begin(), v.end(), xv[i] + yv[j]) == v.end())
//			{
//				v.push_back(xv[i] + yv[j]);
//			}
//		}
//	}
//	sort(v.begin(), v.end());
//	return v;
//}

//int largestPerimeter(vector<int>& A) {
//	sort(A.begin(), A.end());
//	int a, b, c;
//	for (int i = A.size() - 1; i >= 0; i--)
//	{
//		a = i;
//		for (int j = A.size() - 1; j >= 0; j--)
//		{
//			if (i != j) {
//				b = j;
//			}
//			else
//				continue;
//			for (int k = A.size() - 1; k >= 0; k--)
//			{
//				if (k != j && k != i)
//					c = k;
//				else
//					continue;
//				if (A[k] + A[j] > A[i] && i > k && k > j)
//					return A[k] + A[j] + A[i];
//			}
//		}
//	}
//	return 0;
//}

//string removeOuterParentheses(string S) {
//	int flag = 0;
//	stack<char> st;
//	string ret = "";
//	for (auto& e : S)
//	{
//		while (st.empty() || flag != 0)
//		{
//			if (e == '(')
//			{
//				st.push(e); flag++;
//			}
//			else
//			{
//				st.push(e); flag--;
//			}
//		}
//		st.pop();
//		while (!st.empty())
//		{
//			ret += st.top(); st.pop();
//		}
//		ret.pop_back();
//	}
//	return ret;
//}

	//vector<string> commonChars(vector<string>& A) {
	//	vector<string> v;
	//	vector<vector<int>> vv(A.size(), vector<int>(26, 0));
	//	for (int i = 0; i < A.size(); i++)
	//	{
	//		for (auto& e : A[i])
	//		{
	//			vv[i][e - 'a']++;
	//		}
	//	}
	//	for (int i = 0; i < 26; i++)
	//	{
	//		int flag = INT_MAX, ff = 1;
	//		for (int j = 1; j < vv.size(); j++)
	//		{
	//			if (vv[j - 1][i] == 0 || vv[j][i] == 0)
	//			{
	//				ff = 0; break;
	//			}
	//			flag = min(flag, vv[j][i]);
	//		}
	//		for (; flag != 0 && ff == 1; flag--)
	//		{
	//			string tmp = "";
	//			tmp += ('a' + i);
	//			v.push_back(tmp);
	//		}
	//	}
	//	return v;
	//}

//int numPairsDivisibleBy60(vector<int>& time) {
//	map<int, int> mp;
//	int ret = 0;
//	for (auto& e : time)
//	{
//		mp[e]++;
//	}
//	int flag = 1;
//	for (auto i = mp.begin(); i != mp.end(); flag++, i++)
//	{
//		
//		auto j = mp.begin();
//		int ff = flag; while (ff--) j++;
//		for (; j != mp.end(); j++)
//		{
//			if ((i->first + j->first) % 60 == 0)
//			{
//				ret += min(i->second, j->second);
//			}
//		}
//	}
//	if (mp.size() == 1 && mp.begin()->first % 60 == 0) ret += mp.begin()->second;
//
//	return ret;
//}
//bool canThreePartsEqualSum(vector<int>& A) {
//	int sum = 0, cur = 0, flag = 0, nowsum = 0;
//	for (auto& e : A)
//	{
//		sum += e;
//	}
//	sum /= 3;
//	//if((sum - (int)sum) > DBL_EPSILON) return false;
//	while (cur < A.size())
//	{
//		while (cur < A.size() && nowsum != sum)
//		{
//			nowsum += A[cur++];
//			while (cur + 1 < A.size() && A[cur + 1] == 0)
//				cur++;
//		}
//		flag++; nowsum = 0;
//	}
//	if (cur == A.size() && flag == 3)
//		return true;
//	else
//		return false;
//}

//int twoCitySchedCost(vector<vector<int>>& costs) {
//	int rea = 0;
//	sort(costs.begin(), costs.end(),
//		[](const vector<int> a1, const vector<int> b1){
//		return ((a1[1] - a1[0]) < (b1[1] - b1[0]));
//	});
//	for (int i = 0; i < costs.size() / 2; ++i){
//		rea += costs[i][1];
//	}
//	for (int i = costs.size() / 2; i < costs.size(); ++i){
//		rea += costs[i][0];
//	}
//	return rea;
//}


//string longestPalindrome(string s) {
//	if (s.size() <= 1) return s;
//	string str = "@#";
//	for (int i = 0; i < s.size(); i++) {
//		str += s[i];
//		str += '#';
//	}
//
//	vector<int> p(str.size(), 0);
//	int mx = 0, id = 0, start = 0, maxlen = 0;
//	for (int i = 1; str[i] != '\0'; i++) {
//		p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
//		while (str[i + p[i]] == str[i - p[i]]) p[i]++;
//		if (i + p[i] > mx) {
//			mx = i + p[i] - 1;
//			id = i;
//		}
//		if (p[i] - 1 > maxlen)
//		{
//			start = (i - p[i] + 1) / 2;
//			maxlen = p[i] - 1;
//		}
//	}
//	return s.substr(start, maxlen);
//}

//vector<vector<int>> threeSum(vector<int>& nums) {
//	int n = nums.size();
//	vector<vector<int>> vv;
//	for (int i = 0; i < n; i++)
//	{
//		if (i > 0 && nums[i - 1] == nums[i]) continue;
//		int start = i + 1, end = n - 1;
//		while (start < end)
//		{
//			int tmp = nums[start] + nums[end] + nums[i];
//			if (tmp == 0)
//			{
//				vv.push_back(vector<int>{nums[start], nums[end], nums[i]});
//				while (start < end && nums[start] == nums[start + 1]) start++;
//				while (start < end && nums[end] == nums[end - 1]) end--;
//				start++; end--;
//			}
//			else if (tmp > 0) end--;
//			else start++;
//		}
//	}
//	return vv;
//}

//int threeSumClosest(vector<int>& nums, int target) {
//	sort(nums.begin(), nums.end());
//	int closestNum = nums[0] + nums[1] + nums[2];
//	for (int i = 0; i < nums.size() - 2; i++) {
//		int l = i + 1, r = nums.size() - 1;
//		while (l < r){
//			int threeSum = nums[l] + nums[r] + nums[i];
//			if (abs(threeSum - target) < abs(closestNum - target)) {
//				closestNum = threeSum;
//			}
//			if (threeSum > target) {
//				r--;
//			}
//			else if (threeSum < target) {
//				l++;
//			}
//			else {
//				// 如果已经等于target的话, 肯定是最接近的
//				return target;
//			}
//		}
//	}
//	return closestNum;
//}

//vector<vector<int>> fourSum(vector<int>& nums, int target) {
//	sort(nums.begin(), nums.end());
//	int n = nums.size();
//	vector<vector<int>> vv;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			if (i > 0 && nums[i - 1] == nums[i]) continue;
//			int start = j + 1, end = n - 1;
//			while (start < end)
//			{
//				int tmp = nums[start] + nums[end] + nums[i] + nums[j];
//				if (tmp == target && i != j)
//				{
//					vv.push_back(vector<int>{nums[start], nums[end], nums[i], nums[j]});
//					while (start < end && nums[start] == nums[start + 1]) start++;
//					while (start < end && nums[end] == nums[end - 1]) end--;
//					start++; end--;
//				}
//				else if (tmp > 0) end--;
//				else start++;
//			}
//		}
//	}
//	return vv;
//}

//int barsearch(vector<int>& nums, int s, int e, int target) {
//	int start = s;
//	int end = e;
//	while (start < end)
//	{
//		int mid = (start + end) / 2;
//		if (nums[mid] == target)
//		{
//			return mid;
//		}
//		else if (nums[mid] > target)
//		{
//			end = mid;
//		}
//		else
//		{
//			start = mid + 1;
//		}
//	}
//	return -1;
//}
//int search(vector<int>& nums, int target) {
//	if (nums.size() == 0) return -1;
//	if (nums.size() == 1 && nums[0] != target) return -1;
//	else if (nums.size() == 1 && nums[0] == target) return 0;
//	int start = 0, end = nums.size() - 1, mid = 0;
//	while (nums[start] >= nums[end])
//	{
//		if (end - start == 1)
//		{
//			mid = start; break;
//		}
//		mid = start + ((end - start) >> 1);
//		if (nums[mid] > nums[start])
//			start = mid;
//		else if (nums[mid] < nums[end])
//			end = mid;
//	}
//	if (target >= nums[0] && target <= nums[mid])
//		return barsearch(nums, 0, mid, target);
//	else if (target >= nums[mid + 1] && target <= nums[nums.size() - 1])
//		//cout << "heh" <<endl;
//		return barsearch(nums, mid + 1, nums.size() - 1, target);
//	else
//		return -1;
//}
//vector<int> searchRange(vector<int>& nums, int target) {
//	vector<int> v = { -1, -1 };
//	if (nums.size() == 0) return v;
//	int start = 0, end = nums.size() - 1;
//	while (start < end)
//	{
//		int mid = (start + end) / 2;
//		if (nums[mid] > target) end = mid - 1;
//		else if (nums[mid] < target) start = mid + 1;
//		else if (nums[mid] == target) {
//			if (mid == 0 || nums[mid - 1] < target) {
//				v[0] = mid; break;
//			}
//			start = mid - 1;
//		}
//	}
//	start = 0, end = nums.size() - 1;
//	while (start < end)
//	{
//		int mid = (start + end) / 2;
//		if (nums[mid] > target) end = mid - 1;
//		else if (nums[mid] < target) start = mid + 1;
//		else if (nums[mid] == target) {
//			if (mid == 0 || nums[mid + 1] > target) {
//				v[1] = mid; break;
//			}
//			end = mid + 1;
//		}
//	}
//	return v;
//}

//bool isValidSudoku(vector<vector<char>>& nums) {
//	unordered_map<int, vector<char>> row;
//	unordered_map<int, vector<char>> col;
//	for (int i = 0; i < nums.size(); i++)
//	{
//		for (int j = 0; j < nums.size(); j++)
//		{
//			if (nums[i][j] == '.') continue;
//			if (find(row[i].begin(), row[i].end(), nums[i][j]) != row[i].end()) return false;
//			else {
//				row[i].push_back(nums[i][j]);
//			}
//			if (find(col[j].begin(), col[j].end(), nums[i][j]) != col[j].end()) return false;
//			else {
//				col[j].push_back(nums[i][j]);
//			}
//			if (i % 3 == 0 && j % 3 == 0)
//			{
//				vector<char> cc;
//				for (int r = i; r < i + 3; r++)
//				{
//					for (int c = j; c < j + 3; c++)
//					{
//						if (nums[r][c] == '.')
//							continue;
//						if (find(cc.begin(), cc.end(), nums[r][c]) != cc.end())
//							cc.push_back(nums[r][c]);
//						else return false;
//					}
//				}
//			}
//		}
//	}
//	return true;
//}

//vector<int> spiralOrder(vector<vector<int>>& nums) {
//	if (nums.size() == 0) return{};
//	vector<int> v;
//	int cur = 0, row = nums[0].size(), col = nums.size(), nx = 0, ny = 0, count = row*col;
//	int dx[4] = { 0, 1, 0, -1 };
//	int dy[4] = { 1, 0, -1, 0 };
//	while (count != 0)
//	{
//		while (nx < row && nx >= 0 && ny >= 0 && ny < col && nums[nx][ny] != INT_MAX && count != 0)
//		{
//			v.push_back(nums[nx][ny]);
//			nums[nx][ny] = INT_MAX;
//			nx += dx[cur]; ny += dy[cur];
//			count--;
//		}
//		cur = (cur + 1) % 4;
//		if (ny == col)
//		{
//			ny--;
//			nx += dx[cur];
//		}
//		if (nx == row)
//		{
//			nx--;
//			ny += dy[cur];
//		}		
//	}
//	return v;
//}

//int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//	for (int i = 0; i < obstacleGrid.size(); i++)
//	{
//		for (int j = 0; j < obstacleGrid[i].size(); j++)
//		{
//			if ((i == 0 && obstacleGrid[i][j] != 1) || (j == 0 && obstacleGrid[i][j] != 1))
//			{
//				obstacleGrid[i][j] = -1;
//			}
//			else if (obstacleGrid[i][j] == 1)
//			{
//				continue;
//			}
//			else if (obstacleGrid[i][j - 1] != 1 && obstacleGrid[i - 1][j] == 1)
//			{
//				obstacleGrid[i][j] = obstacleGrid[i][j - 1];
//			}
//			else if (obstacleGrid[i][j - 1] == 1 && obstacleGrid[i - 1][j] != 1)
//			{
//				obstacleGrid[i][j] = obstacleGrid[i - 1][j];
//			}
//			else if (obstacleGrid[i][j - 1] == 1 && obstacleGrid[i - 1][j] == 1)
//			{
//				obstacleGrid[i][j] = 1;
//			}
//			else
//			{
//				obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
//			}
//		}
//	}
//	return abs(obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size()-1]);
//}

//void setZeroes(vector<vector<int>>& matrix) {
//	unordered_set<int> row;
//	unordered_set<int> col;
//	for (int i = 0; i < matrix.size(); i++)
//	{
//		for (int j = 0; j < matrix[i].size(); j++)
//		{
//			if (matrix[i][j] == 0)
//			{
//				row.insert(i);
//				col.insert(j);
//			}
//		}
//	}
//	for (auto& e : row)
//	{
//		for (int j = 0; j < matrix[0].size(); j++)
//			matrix[e][j] = 0;
//	}
//	for (auto& e : col)
//	{
//		for (int j = 0; j < matrix.size(); j++)
//			matrix[e][j] = 0;
//	}
//}

//#define min(a,b) (a<b?a:b)
//int Binary_find_Kth(int* array1, int len1, int* array2, int len2, int k)
//{
//	//    /**在这里始终认为len1<len2**/
//	if (len1>len2) return Binary_find_Kth(array2, len2, array1, len1, k);
//	if (len1 == 0) return array2[k - 1];
//	if (k == 1) return max(array1[len1-1], array2[len2-1]);
//
//	//    /**将k分为两部分，分别在array1和array2数组上查找**/
//	int k1 = min(k / 2, len1);
//	int k2 = k - k1;
//
///////**
////		        说明array2的k2-1前部分一定在第k大元素之前，因此：
////				        1）将k2-1这部分全跳过:更新数组首位地址索引，同时更新数组长度；
////						        2）将这k2元素纳入已找到的第k大元素范围内，更新k值：k-k2
////								    **/
//	if (array1[len1- k1 - 1] > array2[len2 - k2 - 1])
//		return Binary_find_Kth(array1, len1, array2 + k2, len2 - k2, k - k2);
//
//	else if (array1[len1 - k1 - 1] < array2[len2 - k2 - 1])
//		return Binary_find_Kth(array1+k1, len1 - k1, array2, len2, k - k1);
//
//	else
//		return array1[len1- k1 - 1];
//}
#include<queue>

//vector<vector<int>> updateMatrix(vector<vector<int>>& nums) {
//	int dx[4] = { 0, 1, 0, -1 };
//	int dy[4] = { 1, 0, -1, 0 };
//	int m = nums.size(), n = nums[0].size();
//	vector<vector<bool>> flag(m, vector<bool>(n, false));
//	queue<pair<int, int>> q;
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (nums[i][j] == 1)
//			{
//				q.push(make_pair(i, j));
//			}
//			else
//			{
//				flag[i][j] = true;
//			}
//		}
//	}
//	while (!q.empty())
//	{
//		auto& cur = q.front(); q.pop();
//		int Min = INT_MAX;
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = cur.first + dx[i], ny = cur.second + dy[i];
//			if (nx >= 0 && nx < m && ny >= 0 && ny < n)
//			{
//				Min = min(Min, nums[nx][ny]);				
//			}
//		}
//		nums[cur.first][cur.second] = Min + 1;
//	}
//	return nums;
//}

//int minimumTotal(vector<vector<int>>& nums) {
//	if (nums.size() == 1) return nums[0][0];
//	for (int i = 1; i < nums.size(); i++)
//	{
//		for (int j = 0; j < nums[i].size(); j++)
//		{
//			if (j == nums[i].size() - 1)
//			{
//				nums[i][j] += nums[i - 1][j - 1];
//				continue;
//			}
//			int up = nums[i - 1][j];
//			int upl, upr;
//			if (j - 1 >= 0) upl = nums[i - 1][j - 1];
//			else upl = INT_MAX;
//			if (j + 1 < nums[i - 1].size()) upr = nums[i - 1][j + 1];
//			else upr = INT_MAX;
//
//			nums[i][j] += min(up, min(upl, upr));
//		}
//	}
//	int ret = INT_MAX;
//	for (int i = 0; i < nums[nums.size() - 1].size(); i++)
//	{
//		if (nums[nums.size() - 1][i] < ret) ret = nums[nums.size() - 1][i];
//	}
//	return ret;
//}

//bool wordBreak(string s, vector<string>& wordDict) {
//	vector<bool> dp(s.size() + 1, false);
//	unordered_set<string> m(wordDict.begin(), wordDict.end());
//	dp[0] = true;
//	for (int i = 1; i <= s.size(); ++i){
//		for (int j = 0; j < i; ++j){
//			if (dp[j] && m.find(s.substr(j, i - j)) != m.end()){
//				dp[i] = true;
//				break;
//			}
//		}
//	}
//	return dp[s.size()];
//}
//int main()
//{	
//	string str = "leetcode";
//	vector<string> v = { "leet", "code" };
//	wordBreak(str,v);
//	
//	system("pause");
//	return 0;
//}

//using namespace std;
//int dfs(vector<int> v, int capacity, int index)
//{
//	if (capacity < 0 || index >= v.size()) return 0;
//	if (index < v.size() && capacity > 0)
//		return 1;
//	return dfs(v, capacity, index + 1) + dfs(v, capacity - v[index], index + 1);
//}
//int main()
//{
//	vector<int> v = { 2, 2, 3 ,3,1};
//	int num = v[0], Min = INT_MAX;
//	for (int i = 1; i < v.size(); i++)
//	{
//		if (num > 0)
//			num = v[i];
//		else
//			num += v[i];
//		Min = min(Min, num);
//	}
//	cout << Min << endl;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<unordered_map>
//using namespace std;
//
//int main()
//{
//	int num; cin >> num;
//	vector<int> v(num * 3);
//	for (int i = 0; i < (num * 3); i++)
//	{
//		cin >> v[i];
//	}
//	sort(v.begin(), v.end());
//	int cur = v.size() - 2, sum = 0;
//	while (num--)
//	{
//		sum += v[cur];
//		cur -= 2;
//	}
//	cout << sum << endl;
//
//	system("pause");
//	return 0;
//}

//1 2 5 5 5 8
//int main()
//{
//	string str; getline(cin, str);
//	string s; getline(cin, s);
//	unordered_map<char, int> mp;
//	for (auto& e : s)
//	{
//		mp[e]++;
//	}
//	string ret = "";
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (mp.find(str[i]) != mp.end() && mp[str[i]] > 0)
//		{
//			mp[str[i]]--;
//			continue;
//		}
//		ret += str[i];
//	}
//	cout << ret << endl;
//	system("pause");
//	return 0;
//}
//string GetPassWordLevel(string& s)
//{
//	int sum = 0;
//	if (s.size() <= 4) sum += 5;
//	else if (s.size() >= 5 && s.size() <= 7) sum += 10;
//	else sum += 25;
//
//	unordered_map<char, int> mp;
//	for (auto& e : s)
//	{
//		mp[e]++;
//	}
//	int numflag = 0, bigchar = 0, smchar = 0, other = 0;
//	for (auto& kv : mp)
//	{
//		if (kv.first >= '0' && kv.first <= '9')
//			numflag += kv.second;
//		else if (kv.first >= 'A' && kv.first <= 'Z')
//			bigchar += kv.second;
//		else if (kv.first >= 'a' && kv.first <= 'z')
//			smchar += kv.second;
//		else
//			other += kv.second;
//	}
//	if ((bigchar != 0 && smchar == 0) || (bigchar == 0 && smchar != 0)) sum += 10;
//	else if (bigchar != 0 && smchar != 0) sum += 20;
//
//	if (numflag == 1) sum += 10;
//	else if (numflag > 1) sum += 20;
//
//	if (other == 1) sum += 10;
//	else if (other > 1) sum += 25;
//
//	if ((bigchar || smchar) && numflag) sum += 2;
//	else if (bigchar && smchar && numflag && other) sum += 5;
//	else if ((bigchar || smchar) && numflag && other) sum += 3;
//
//	if (sum >= 90) return string("VERY_WEAK");
//	else if (sum >= 80) return string("WEAK");
//	else if (sum >= 70) return string("AVERAGE");
//	else if (sum >= 60) return string("STRONG");
//	else if (sum >= 50) return string("Average");
//	else if (sum >= 25) return string("Weak");
//	else if (sum >= 0) return ("VERY_SECURE");
//}
//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		string tmp = GetPassWordLevel(str);
//		cout << tmp << endl;
//	}
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;

//int cmp(int x, int y) {
//	if (x == y)
//		return 0;
//	else if (x > y)
//		return 1;
//	else
//		return -1;
//}
//int isMonotonic(vector<int>& A) {
//	int flag = 0, sum = 0;
//	for (int i = 0; i < A.size() - 1; i++) {
//		int c = cmp(A[i], A[i + 1]);
//		if (c != 0) {
//			if (c != flag && flag != 0)
//			{
//				sum++;
//				flag = -flag;
//				continue;
//			}
//
//			flag = c;
//		}
//	}
//	return sum;
//}
//int main()
//{
//	int num; 
//	cin >> num;
//	vector<int> v(num);
//	for (int i = 0; i < num; i++)
//	{
//		cin >> v[i];
//	}
//	cout << isMonotonic(v) << endl;
//	system("pause");
//	return 0;
//}
//
//链接：https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471
//来源：牛客网
//
//import java.util.Scanner;
//
//
//
////校招模拟：排序子序列
//
//public class Main {
//
//
//
//	public static void main(String[] args) {
//
//		// TODO Auto-generated method stub
//
//		Scanner scanner = new Scanner(System.in);
//		int n = scanner.nextInt();
//		int[] data = new int[n];
//		for (int i = 0; i < n; i++) {
//			data[i] = scanner.nextInt();
//		}
//		int flag = 0;
//		int result = 1;
//		for (int i = 1; i < n; i++) {
//			if (data[i]>data[i - 1]) {
//				if (flag == 0) {++++++
//					flag = 1;
//				}
//				if (flag == -1) {
//					flag = 0;
//					result++;
//				}
//			}
//			else if (data[i]<data[i - 1]){
//				if (flag == 0) {
//					flag = -1;
//				}
//				if (flag == 1) {
//					flag = 0;
//					result++;
//				}
//			}
//		}
//		System.out.println(result);
//		scanner.close();
//	}
//}

//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	string num1; string num2; string tmp;
//	
//	int n1 = num1.size(), n2 = num2.size(), carry = 0;
//	vector<int> v(max(n1, n2) + 1);
//	int k = n1 + n2 - 2;
//	for (int i = 0; i < n1; i++)
//	{
//		for (int j = 0; j < n2; j++)
//		{
//			v[k - j - i] += (num1[i] - '0')*(num2[j] - '0');
//		}
//	}
//	string ret = "";
//	for (int i = 0; i < v.size(); i++)
//	{
//		carry += v[i];
//		ret = to_string(carry % 10) + ret;
//		carry /= 10;
//	}
//	int cur = 0;
//	while (ret[cur] == '0')
//	{
//		cur++;
//	}
//	ret.substr(cur);
//	cout << ret << endl;
//	system("pause");
//	return 0;
//}
//
//链接：https://www.nowcoder.com/questionTerminal/ab900f183e054c6d8769f2df977223b5
//来源：牛客网
//
//#include<iostream>
//#include<string>
//#include<set>
//#include<math.h>
//using namespace std;
//int main(){    
//	string x;    
//	cin>>x;    
//	int i,j,n=x.length();    
//	for(i=1;i<=n;i++){        
//		set<string> s;        
//		for(j=0;j<=n-i;j++) 
//			s.insert(x.substr(j,i));        
//		if(s.size()<(int)pow(4,i))
//		{            
//			printf("%d",i); return 0;        
//		}    
//	}
//}

//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//bool cheackstr(string& ss)
//{
//	string tmp(ss);
//	reverse(tmp.begin(), tmp.end());
//	return ss == tmp ? true : false;
//}

//class A
//{
//public:
//	void test(float a)
//	{
//		cout << "1" << endl;
//	}
//};
//
//class B:public A
//{
//public:
//	void test(int b)
//	{
//		cout << "2" << endl;
//	}
//};

//int minSubArrayLen(int s, vector<int>& nums) {
//	if (nums.size() == 0) return 0;
//	int cur = 0, pre = 0, ret = INT_MAX, sum = 0, flag = 0;
//	while (cur < nums.size())
//	{
//		if (cur < nums.size() && sum < s)
//		{
//			sum += nums[cur++];
//		}
//		if (sum >= s)
//		{
//			flag = 1;
//			sum -= nums[pre++];
//			ret = min(ret, cur - pre);
//		}
//	}
//	return flag == 1 ? ret : 0;
//}

//bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
//	unordered_set<long> s;
//	for (int i = 0; i < nums.size(); i++)
//	{
//		auto it = s.lower_bound((long)nums[i] + (long)t);
//		if (it != s.end() && *it >= (long)nums[i] - (long)t)
//			return true;
//		s.insert(nums[i]);
//		if (s.size() == k + 1)
//		{
//			s.erase((long)nums[i - k]);
//		}
//	}
//	return false;
//}

//bool chkParenthesis(string A, int n) {
//	stack<char> st;
//	for (auto& e : A)
//	{
//		if (e != '(' && e != ')')
//			return false;
//		else if (!st.empty() && st.top() == '(' && e == ')')
//			st.pop();
//		else
//			st.push(e);
//	}
//	return st.empty() ? true : false;
//}
//int main()
//{
//	string s = "()()(";
//	cout << chkParenthesis(s, 6);
//	system("pause");
//	return 0;
//}

#include<iostream>
#include<string>
#include<vector>
using namespace std;



//int threeSumSmaller(vector<int>& nums, int target) {
//	sort(nums.begin(), nums.end());
//	int n = nums.size(), count = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (i > 0 && nums[i - 1] == nums[i]) continue;
//		int start = i + 1, end = n - 1;
//		while (start < end)
//		{
//			int tmp = nums[i] + nums[start] + nums[end];
//			if (tmp < target)
//			{
//				count += end - start;
//				start++;
//			}
//			if (tmp >= target)
//				end--;
//		}
//	}
//	return count;
//}
//#include<iostream>
//#include<string>
//#include<vector>
//#include<sstream>
//using namespace std;
//int main()
//{
//	string str, tmp; getline(cin, str);
//	vector<string> v;
//	vector<string> ret;
//	istringstream ss(str);
//	while (ss >> tmp) v.push_back(tmp);
//	int cur = 0, pre = 0;
//	while (cur < v.size())
//	{
//		if (v[cur][0] != '\"')
//		{
//			ret.push_back(v[cur]); cur++; pre = cur;
//			continue;
//		}
//		while (cur < v.size() && v[cur][v[cur].size() - 1] != '\"')
//		{
//			cur++;
//		}
//		string ss;
//		for (int i = pre; i <= cur; i++)
//		{
//			ss += v[i] + " ";
//		}
//		ss.erase(ss.begin());
//		ss.pop_back();
//		ss.pop_back();
//		ret.push_back(ss);
//		cur++; pre = cur;
//	}
//	for (int i = 0; i < ret.size(); i++)
//	{
//		cout << ret[i] << endl;
//	}
//	
//	system("pause");
//	return 0;
//}
//
//#include<iostream>
//#include<algorithm>
//using namespace std;

//int minCost(vector<vector<int>>& costs) {
//	for (int i = 1; i < costs.size(); i++)
//	{
//		for (int j = 0; j < costs[i].size(); j++)
//		{
//			if (j == 0)
//				costs[i][j] += min(costs[i - 1][1], costs[i - 1][2]);
//			else if (j == 1)
//				costs[i][j] += min(costs[i - 1][0], costs[i - 1][2]);
//			else if (j == 2)
//				costs[i][j] += min(costs[i - 1][0], costs[i - 1][0]);
//		}
//	}
//	int ret = INT_MAX;
//	for (int i = 0; i < costs[0].size(); i++)
//	{
//		if (costs[costs.size() - 1][i] < ret)
//			ret = costs[costs.size() - 1][i];
//	}
//	return ret;
//}
//
//int lengthOfLIS(vector<int>& nums) {
//	vector<int> dp(nums.size(), 0);
//	for (int num : nums) {
//		// 二分法查找, 也可以调用库函数如binary_search
//		int lo = 0, hi = nums.size()-1;
//		while (lo <= hi) {
//			int mid = lo + (hi - lo) / 2;
//			if (dp[mid] < num)
//				lo = mid + 1;
//			else
//				hi = mid -1;
//		}
//	}
//	return dp.size();
//}
//int main()
//{
//	vector<int> vv = { 10, 9, 2, 5, 3, 7, 101, 18 };
//	cout << lengthOfLIS(vv) << endl;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//int falg = 0;
//void dfs(vector<int>& v, int index, int sum, int mul)
//{
//	if (index == v.size())
//	{
//		if (sum > mul)
//			falg++;
//		return;
//	}
//	if (index == 0 || )
//		dfs(v, index + 1, sum, mul);
//	dfs(v, index + 1, sum + v[index], mul*v[index]);
//}
//int main()
//{
//	int n; cin >> n;
//	vector<int> v(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> v[i];
//	}
//	dfs(v, 0, 0, 1);
//	cout << falg << endl;
//	system("pause");
//	return 0;
//}

//class NumMatrix {
//public:
//	NumMatrix(vector<vector<int>>& matrix) {
//		nums.resize(matrix.size(), vector<int>(matrix[0].size()));
//		for (int i = matrix.size() - 1; i >= 0; i--)
//		{
//			for (int j = matrix[i].size() - 1; j >= 0; j--)
//			{
//				nums[i][j] = matrix[i][j];
//				if (i < matrix.size() - 1)
//					nums[i][j] += matrix[i + 1][j];
//				if (j < matrix[i].size() - 1)
//					nums[i][j] += matrix[i][j + 1];
//				if (i < matrix.size() - 1 && j < matrix[i].size() - 1)
//					nums[i][j] += matrix[i + 1][j + 1];
//			}
//		}
//	}
//
//	int sumRegion(int row1, int col1, int row2, int col2) {
//		int flag1 = 0, flag2 = 0;
//		if (row2 == nums.size() - 1) flag1 = 1;
//		if (col2 == nums[0].size() - 1) flag2 = 1;
//		if (flag1 && flag2)
//			return nums[row1][col1];
//		else if (flag1 && !flag2)
//			return nums[row1][col1] - nums[row1][col2 + 1];
//		else if (!flag1 && flag2)
//			return nums[row1][col1] - nums[row1 + 1][col1];
//		else if (!flag1 && !flag2)
//			return nums[row1][col1] - nums[row1 + 1][col2] - nums[row1][col2 + 1] + nums[row2 + 1][col2 + 1];
//	}
//private:
//	vector<vector<int>> nums;
//};
//
//int main()
//{
//	vector<vector<int>> vv = { { 1, 2 }, { 1, 2 } };
//	NumMatrix* obj = new NumMatrix(vv);
//	cout << obj->sumRegion(1, 1, 1, 1) << endl;
//	system("pause");
//	return 0;
//}

//class A
//{
//public:
//	void fun();
//};
//void A::fun()
//{
//	delete this;
//}
//int main()
//{
//	A* p = new A;
//	p->fun();
//	system("pause");
//	return 0;
//}
//

//#include<iostream>
//#include<string>
//#include<vector>
//#include<unordered_map>
//#include<sstream>
//
//int main()
//{
//	unordered_map<string, int> mp{ { "3", 0 }, { "4", 1 }, { "5", 2 }, { "6", 3 }, { "7", 4 },
//	{ "8", 5 }, { "9", 6 }, { "10", 7 }, { "J", 8 }, { "Q", 9 }
//	, { "K", 10 }, { "2", 11 }, { "joker", 12 }, { "JOKER", 13 } };
//	string str; getline(cin, str);
//	auto pos = find(str.begin(), str.end(), '-');
//	string left = str.substr(0, pos-str.begin());
//	string right = str.substr(pos - str.begin() + 1);
//
//	vector<string> l, r;
//	string tmp; istringstream ls(left), lr(right);
//	while (ls >> tmp) l.push_back(tmp);
//	while (lr >> tmp) r.push_back(tmp);
//
//	if (l.size() == 1)
//	{
//		if (r.size() == 1)
//		{
//			cout << (l[0] > r[0]) ? l[0] : r[0];
//			return 0;
//		}
//		else if (r.size() == 2)
//		{
//			if (mp[r[0]] + mp[r[1]] == 25)
//			{
//				string ret;
//				ret += (r[0] + " ") + r[1];
//				cout << ret << endl;
//				return 0;
//			}
//		}
//		else if (r.size() == 4)
//		{
//			string ret;
//			for (int i = 0; i < r.size(); i++)
//				ret += r[i] + " ";
//			ret.pop_back();
//			cout << ret << endl;
//			return 0;
//		}
//		else
//			cout << "ERROR" << endl;
//	}
//	else if (l.size() == 2)
//	{
//		if (mp[l[0]] + mp[l[1]] == 25)
//		{
//			string ret;
//			ret += (l[0] + " ") + l[1];
//			cout << ret << endl;
//			return 0;
//		}
//		if (r.size() == 2)
//		{
//			if (mp[r[0]] + mp[r[1]] == 25)
//			{
//				string ret;
//				ret += (r[0] + " ") + r[1];
//				cout << ret << endl;
//				return 0;
//			}
//			else
//			{
//				string ret = l[0] > r[0] ? l[0] + " " + l[1] : r[0] + " " + r[1];
//				cout << ret << endl;
//				return 0;
//			}
//		}
//		else if (r.size() == 4)
//		{
//			string ret;
//			for (int i = 0; i < r.size(); i++)
//				ret += r[i] + " ";
//			ret.pop_back();
//			cout << ret << endl;
//			return 0;
//		}
//		else{
//			cout << "ERROR" << endl;
//		}
//	}
//	else if (l.size() == 3)
//	{
//		if (r.size() == 2)
//		{
//			if (mp[r[0]] + mp[r[1]] == 25)
//			{
//				string ret;
//				ret += (r[0] + " ") + r[1];
//				cout << ret << endl;
//				return 0;
//			}
//		}
//		else if (r.size() == 3)
//		{
//			string ret = l[0] > r[0] ? l[0] + " " + l[1] + " " + l[2] : r[0] + " " + r[1] + " " + r[2];
//			cout << ret << endl;
//			return 0;
//		}
//		else if (r.size() == 4)
//		{
//			string ret;
//			for (int i = 0; i < r.size(); i++)
//				ret += r[i] + " ";
//			ret.pop_back();
//			cout << ret << endl;
//			return 0;
//		}
//		else{
//			cout << "ERROR" << endl;
//		}
//	}
//	else if (l.size() == 4)
//	{
//		if (r.size() == 2)
//		{
//			if (mp[r[0]] + mp[r[1]] == 25)
//			{
//				string ret;
//				ret += (r[0] + " ") + r[1];
//				cout << ret << endl;
//				return 0;
//			}
//		}
//		else if (r.size() == 4)
//		{
//			if (r[0] > l[0])
//			{
//				string ret;
//				for (int i = 0; i < r.size(); i++)
//					ret += r[i] + " ";
//				ret.pop_back();
//				cout << ret << endl;
//				return 0;
//			}
//			else{
//				string ret;
//				for (int i = 0; i < l.size(); i++)
//					ret += l[i] + " ";
//				ret.pop_back();
//				cout << ret << endl;
//				return 0;
//			}
//		}
//		else{
//			cout << "ERROR" << endl;
//		}
//	}
//	else if (l.size() == 5)
//	{
//		if (r.size() == 2)
//		{
//			if (mp[r[0]] + mp[r[1]] == 25)
//			{
//				string ret;
//				ret += (r[0] + " ") + r[1];
//				cout << ret << endl;
//				return 0;
//			}
//		}
//		else if (r.size() == 4)
//		{
//			string ret;
//			for (int i = 0; i < r.size(); i++)
//				ret += r[i] + " ";
//			ret.pop_back();
//			cout << ret << endl;
//			return 0;
//		}
//		else if (r.size() == 5)
//		{
//			int flag1 = 0, flag2 = 0;
//			for (int i = 0; i < 5; i++)
//			{
//				if (l[i] < r[i])
//					flag2 = 1;
//				if (l[i] > r[i])
//					flag1 = 1;
//			}
//			if (flag1)
//			{
//				string ret;
//				for (int i = 0; i < l.size(); i++)
//					ret += l[i] + " ";
//				ret.pop_back();
//				cout << ret << endl;
//				return 0;
//			}
//			if (flag2)
//			{
//				string ret;
//				for (int i = 0; i < r.size(); i++)
//					ret += r[i] + " ";
//				ret.pop_back();
//				cout << ret << endl;
//				return 0;
//			}
//		}
//	}
//	cout << "ERROR" << endl;
//	return 0;
//}

//class A
//{
//private:
//	//virtual void fun();
//};
//
//class B :public A
//{
//private:
//	virtual void fun();
//};

//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int num;
//	while (cin >> num)
//	{
//		vector<int> up(num * 2 - 1, 0);
//		vector<int> down(num * 2 - 1, 0);
//		up[up.size() / 2] = 1;
//		while (num--)
//		{
//			for (int i = 0; i < up.size(); i++)
//			{
//				int sum = up[i];
//				if (i - 1 >= 0)
//					sum += up[i - 1];
//				if (i + 1 < up.size() - 1)
//					sum += up[i+1];
//				down[i] = sum;
//			}
//			up.swap(down);
//		}
//		for (auto& e : down)
//		if (e % 2 == 0){
//			cout << e << endl; return 0;
//		}
//		cout << -1 << endl; return 0;
//	}
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string num1, num2;
//	while (cin >> num1 >> num2)
//	{
//		int n1 = num1.size() - 1, n2 = num2.size() - 1, carry = 0;
//		string ret = "";
//		while (n1 >= 0 || n2 >= 0)
//		{
//			int s1 = n1 >= 0 ? (num1[n1--] - '0') : 0;
//			int s2 = n2 >= 0 ? (num2[n2--] - '0') : 0;
//			int tmp = s1 + s2 + carry;
//			ret = to_string(tmp % 10) + ret;
//			carry = tmp/10;
//		}
//		if (carry != 0)
//			ret = to_string(carry) + ret;
//		cout << ret << endl;
//	}
//	return 0;
//}
//
//class A
//{
//
//public:
//	void fun();
//};
//
//class B:
//{
//public:
//	void fun();
//	
//};
//class C :public A, public B
//{
//	void fun1()
//	{}
//};
//
//int main()
//{
//	C* p = new C;
//	p->fun();
//	return 0;
//}

//void bfs(vector<vector<int>>& rooms, vector<vector<int>> nums, pair<int, int> kv)
//{
//	int dx[4] = { 1, 0, -1, 0 };
//	int dy[4] = { 0, 1, 0, -1 };
//	queue<pair<int, int>> q; q.push(kv);
//	while (!q.empty())
//	{
//		auto it = q.front(); q.pop();
//		int x = it.first / rooms[0].size(), y = it.first % rooms[0].size();
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = dx[i] + x;
//			int ny = dy[i] + y;
//			if (ny >= 0 && ny < rooms[0].size()
//				&& nx >= 0 && nx < rooms.size() && nums[nx][ny] == INT_MAX)
//			{
//				nums[nx][ny] = it.second + 1;
//				rooms[nx][ny] = min(rooms[nx][ny], it.second + 1);
//				q.push({ nx*rooms.size() + ny, it.second + 1 });
//			}
//		}
//	}
//}
//void wallsAndGates(vector<vector<int>>& rooms) {
//	vector<vector<int>> nums(rooms.size(), vector<int>(rooms[0].size()));
//	queue<pair<int, int>> q;
//	for (int i = 0; i < rooms.size(); i++)
//	{
//		for (int j = 0; j < rooms[i].size(); j++)
//		{
//			if (rooms[i][j] == INT_MAX) nums[i][j] = INT_MAX;
//			else if (rooms[i][j] == -1) nums[i][j] = -1;
//			else if (rooms[i][j] == 0)
//			{
//				q.push({ i* rooms[i].size() + j, 0 });
//				nums[i][j] = 0;
//			}
//		}
//	}
//	while (!q.empty())
//	{
//		bfs(rooms, nums, q.front());
//		q.pop();
//	}
//}
//int main()
//{
//	vector<vector<int>> vv = { { 2147483647, 0, 2147483647, 2147483647, 0, 2147483647, -1, 2147483647 } };
//	wallsAndGates(vv);
//	system("pause");
//	return 0;
//}
//
//[[0, 1, -1, 2, 1, -1, -1, 0, 0, -1, 1, 1, 0, -1, 2, 2, 2, 1, 0, 1, 0, -1, -1, -1, -1, 2147483647, -1, -1, 1, 2, -1, -1, 0, 0, -1, 0, 0, 0, 1, 0, 1, -1, -1, 0, -1, 0, 0, 0, 1], 
//[1, 0, -1, 1, 0, -1, -1, -1, -1, 0, 0, 1, 1, -1, -1, 3, -1, -1, 1, 2, -1, 0, -1, 1, 0, 1, -1, 1, 0, 1, 0, 1, -1, 1, 0, 1, -1, 1, 0, 1, 1, 0, -1, 1, -1, -1, -1, 0, 1]]
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<signal.h>
//void handler(int signo, siginfo_t* info, void* p)
//{
//	printf("signo = : %d\n", signo);
//	printf("sender pid = : %d\n", info->si_code);//使用第二个参数打印更多信息
//}
//int main()
//{
//	struct sigaction act, oact;
//	act.sa_sigaction = handler;
//	sigempty(&act.sa_mask);//这个函数后面介绍，用来初始化sa_mask的
//	act.sa_flags = SA_SIGINFO;
//	sigaction(2, &act, &oact);
//	while (1)
//	{
//		printf("...");
//		sleep(1);
//	}
//	return 0;
//}
//
//struct sigqueue
//{
//	struct sigqueue* next;
//	siginfo_t info;
//};

//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	int num; cin >> num;
//	while (num--)
//	{
//		int n, k;
//		while (cin >> n >> k)
//		{
//			vector<int> left(2 * n);
//			vector<int> right(2 * n);
//			for (int i = 0; i < 2*n; i++)
//			{
//				cin >> left[i];
//			}
//			for (int i = n; i < 2 * n; i++)
//			{
//				right[i] = left[i];
//			}
//			vector<int> ret;
//			while (k--)
//			{
//				int index1 = 0, index2 = n;
//				while (index1 < n && index2 <2 * n)
//				{
//					ret.push_back(left[index1++]);
//					ret.push_back(right[index2++]);
//				}
//				left = ret;
//				right = ret;
//			}
//			for (int i = 0; i < ret.size(); i++)
//			{
//				cout << ret[i] << " ";
//			}
//			ret.clear();
//		}
//	}
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int num;
//	while (cin >> num)
//	{
//		if (num >= 4)
//		{
//			vector<int> v(num);
//			for (int i = 1; i <= num; i++)
//			{
//				v[i - 1] = i;
//			}
//			vector<int> wdo(4);
//			for (int i = 0; i < 4; i++)
//			{
//				wdo[i] = i + 1;
//			}
//
//			string cmd; cin >> cmd;
//			int cur = 0;
//			for (auto& e : cmd)
//			{
//				if (e == 'U' && cur == 0) {
//					cur = v.size() - 1;
//					for (int i = 0; i < 4; i++)
//					{
//						wdo[i] = v[cur - 3 + i];
//					}
//				}
//				else if (e == 'U' && cur != 0)
//				{
//					cur--;
//					if (find(wdo.begin(), wdo.end(), v[cur]) == wdo.end())
//					{
//						for (int i = 1; i < 4; i++)
//						{
//							wdo[i] = wdo[i - 1];
//						}
//						wdo[0] = cur + 1;
//					}
//				}
//				if (e == 'D' && cur == v.size() - 1) {
//					cur = 0;
//					for (int i = 0; i < 4; i++)
//					{
//						{
//							wdo[i] = v[cur + i];
//						}
//					}
//				}
//				else if (e == 'D' && cur != v.size() - 1)
//				{
//					cur++;
//					if (find(wdo.begin(), wdo.end(), v[cur]) == wdo.end())
//					{
//						for (int i = 0; i < 3; i++)
//						{
//							wdo[i] = wdo[i + 1];
//						}
//						wdo[3] = cur + 1;
//					}
//				}
//			}
//			for (int i = 0; i < 4; i++)
//			{
//				cout << wdo[i] << " ";
//			}
//			cout << endl;
//			cout << cur + 1 << endl;
//		}
//		else if (num <= 3)
//		{
//			vector<int> v(num);
//			for (int i = 0; i < num; i++)
//			{
//				v[i] = i + 1;
//			}
//			string cmd; cin >> cmd;
//			int cur = 0;
//			for (auto& e : cmd)
//			{
//				if (e == 'U' && cur == 0)
//				{
//					cur = num - 1;
//				}
//				else if (e == 'U' && cur != 0)
//				{
//					cur--;
//				}
//				if (e == 'D' && cur == num - 1)
//				{
//					cur = 0;
//				}
//				else if (e == 'D' && cur != num - 1)
//				{
//					cur++;
//				}
//			}
//			for (int i = 0; i < num; i++)
//			{
//				cout << v[i] << " ";
//			}
//			cout << endl;
//			cout << cur + 1 << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<vector>
//
//int isbignum(int up, int down)
//{
//	while (up%down)
//	{
//		int tmp = up%down;
//		up = down;
//		down = tmp;
//	}
//	return down;
//}
//int main()
//{
//	int n, cur;
//	while (cin >> n >> cur)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			int tmp; cin >> tmp;
//			if (tmp < cur)
//				cur += tmp;
//			else
//			{
//				cur += isbignum(cur, tmp);
//			}
//		}
//		cout << cur << endl;
//	}
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int main()
//{
//	string str1, str2;
//	while (cin >> str1 >> str2)
//	{
//		if (str1.size() < str2.size())
//			swap(str1, str2);
//		vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
//		for (int i = 1; i <= str1.size(); i++)
//		{
//			for (int j = 1; j <= str2.size(); j++)
//			{
//				if (str1[i-1] == str2[j-1])
//					dp[i][j] = dp[i - 1][j - 1] + 1;
//				else
//					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//			}
//		}
//		cout << str1.size() - dp.back().back() << endl;
//	}
//	system("pause");
//	return 0;
//}


//class NumArray {
//public:
//	vector<int> C;
//	vector<int> nums;
//
//	NumArray(vector<int> &nums) : nums(nums) {
//		for (int i = 0; i <= nums.size(); ++i) {
//			C.push_back(0);
//		}
//		for (int i = 0; i < nums.size(); ++i) {
//			add(i, nums[i]);
//		}
//	}
//
//	int lowbit(int x) {
//		return x & (-x);
//	}
//
//	void add(int i, int val) {
//		for (int k = i + 1; k <= nums.size(); k += lowbit(k)) {
//			C[k] += val;
//		}
//	}
//
//	void update(int i, int val) {
//		int add = val - nums[i];
//		nums[i] = val;
//		for (int k = i + 1; k <= nums.size(); k += lowbit(k)) {
//			C[k] += add;
//		}
//	}
//
//	int getSum(int i) {
//		int sum = 0;
//		for (int k = i; k > 0; k -= lowbit(k)) {
//			sum += C[k];
//		}
//		return sum;
//	}
//
//	int sumRange(int i, int j) {
//		return getSum(j + 1) - getSum(i);
//	}
//};

//int maxProduct(vector<string>& words) {
//	vector<int> hash(words.size());
//	for (int i = 0; i < words.size(); i++)
//	{
//		int sum = 0;
//		for (int j = 0; j < words[i].size(); j++)
//		{
//			int index = words[i][j] - 'a';
//			if (((sum >> index) & 1) == 0)
//				hash[i] = hash[i] + (1 << index);
//		}
//	}
//	int ret = 0;
//	for (int i = 0; i < hash.size(); i++)
//	{
//		for (int j = i + 1; j < hash.size(); j++)
//		{
//			if ((hash[i] & hash[j]) == 0)
//			{
//				int tmp = words[i].size()*words[j].size();
//				ret = max(ret, tmp);
//			}
//		}
//	}
//	return ret;
//}

int partsort(vector<int>& a, int start, int end)
{
	int key = start;
	int cur = start + 1;
	int pre = start;
	while (cur <= end)
	{
		if (a[cur] <= a[key] && ++pre != cur)
		{
			swap(a[cur], a[pre]);
		}
		cur++;
	}
	swap(a[pre], a[key]);
	return pre;
}
void QuickSort(vector<int>& a, int start, int end)
{
	if (end <= start)
	{
		return;
	}
	int index = partsort(a, start, end);
	QuickSort(a, start, index - 1);
	QuickSort(a, index + 1, end);
}
//int main()
//{
//	vector<int> nums = { 2, 6, 3, 5, 9, 5, 6, 2, 5 };
//	QuickSort(nums, 0, nums.size() - 1);
//	for (auto& e : nums)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0
//}
//
//int Add(int num1, int num2)
//{
//	return ((num1&num2) << 1) + (num1^num2);
//}
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;

//void oddInOddEvenInEven(vector<int>& arr, int len) {
//	int pre = 0;
//	int cur = 1;
//	while (cur < arr.size() && pre < arr.size())
//	{
//		while (cur < arr.size() && arr[cur] % 2 != 0)
//			cur += 2;
//		while (pre < arr.size() && arr[pre] % 2 == 0)
//			pre += 2;
//		if (cur < arr.size() && pre < arr.size())
//			swap(arr[cur], arr[pre]);
//	}
//}
//int getFirstUnFormedNum(vector<int> arr, vector<int> v,int len) {
//	int i, j;
//	int mi = arr[0], sum = 0;
//	for (i = 0; i<len; i++)
//	{
//		sum  += arr[i];
//		if (arr[i]< mi)
//			mi = arr[i];
//	}
//	vector <int>  dp(sum + 1, 0);
//	for (i = 0; i < len; i++)
//	for (j = sum; j >= arr[i]; j--)
//	{
//		if (dp[j - arr[i]] + arr[i]> dp[j])
//			dp[j] = dp[j - arr[i]] + arr[i];
//		else
//			dp[j] = dp[j];
//	}
//	for (i = mi; i <= sum; i++)
//	{
//		if (i != dp[i])
//			return  i;
//	}
//	return  i;
//}

//double myPow(double x, int n) {
//	double res = 1.0;
//	for (int i = n; i != 0; i /= 2){
//		if (i % 2 != 0){
//			res *= x;
//		}
//		x *= x;
//	}
//	return  n < 0 ? 1 / res : res;
//}

string SubStr(string a, string b)
{
	if (a.size() == 0 || b.size() == 0) return "";
	int len1 = a.size();
	int len2 = b.size();
	int ret = INT_MIN,start = 0;
	vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;

			if (dp[i][j] > ret)
			{
				ret = dp[i][j];
				start = i;
			}
		}
	}
	return a.substr(start-ret,ret);
}
//int main()
//{
//	string ret = SubStr("abcddddsd","abcdsadasddsd");
//	cout << ret << endl;
//	system("pause");
//	return 0;
//}

//void replaceSpace(char *str, int length) {
//	int count = 0;
//	for (int i = 0; i < length; i++)
//	{
//		if (str[i] == ' ')
//			count++;
//	}
//	int newlen = length + 2 * count;
//	char* newstr = (char*)malloc(newlen*sizeof(char));
//	int cur = 0, index = 0;
//	while (cur < length)
//	{
//		if (str[cur] != ' ')
//		{
//			newstr[index++] = *str;
//		}
//		else
//		{
//			newstr[index++] = '%';
//			newstr[index++] = '2';
//			newstr[index++] = '0';
//		}
//		cur++;
//	}
//	str = newstr;
//}
//
//int main()
//{
//	char arr[] = "hh hh hh";
//	replaceSpace(arr, 8);
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//int main()
//{
//	int n; cin >> n;
//	vector<vector<int>> vv(n, vector<int>(2, 0));
//	for (int i = 0; i < n; i++)
//	{
//		int num; cin >> num;
//		cin >> vv[i][0];
//		cin >> vv[i][1];
//	}
//	sort(vv.begin(), vv.end(), [](vector<int> v1, vector<int> v2)
//	{
//		return v1[0] < v2[0];
//	});
//	vector<int> dp(n, 1);
//	int ret = INT_MIN;
//	for (int i = 1; i < n; i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if ((vv[j][1] < vv[i][1] && vv[j][0] < vv[i][0]) || (vv[j][1] == vv[i][1]
//				&& vv[i][0] == vv[j][0]) || (vv[j][0] <  vv[i][0] && vv[j][1] == vv[i][1]))
//			{
//				dp[i] = max(dp[i], dp[j] + 1);
//			}
//			if (dp[i] > ret)
//				ret = dp[i];
//		}
//	}
//	cout << ret << endl;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<string> v(n);
//		for (int i = 0; i < n; i++)
//		{
//			cin >> v[i];
//		}
//		sort(v.begin(), v.end());
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = i + 1; j < n; j++)
//			{
//				auto it = v.begin(); int tmp = j;
//				while (j--)it++;
//				if (find(it, v.end(), v[i]) != v.end())
//				{
//					v[i] = "";
//				}
//			}
//		}
//		for (auto& e : v)
//		{
//			if (e != "")
//				cout << "mkdir -p " << e << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}

//#include<queue>
//#include<vector>
//using namespace std;
//int dx[4] = { 0, 1, 0, -1 };
//int dy[4] = { 1, 0, -1, 0 };
//int bfs(int row, int col, int x, int y, vector<vector<char>>& vv, vector<vector<bool>>& flag)
//{
//	queue<int> q;
//	int count = 1;
//	q.push(x*col + y);
//	flag[x][y] = true;
//	while (!q.empty())
//	{
//		int num = q.front(); q.pop();
//		int nx = num / col, ny = num%col;
//		for (int i = 0; i < 4; i++)
//		{
//			int xx = nx + dx[i];
//			int yy = ny + dy[i];
//			if (xx >= 0 && xx < row && yy >= 0 && yy < col && !flag[xx][yy] && vv[xx][yy] == '.')
//			{
//				flag[xx][yy] = true;
//				count++;
//				q.push(xx*col + yy);
//			}
//		}
//	}
//	return count;
//}
//int main()
//{
//	int row, col;
//	while (cin >> row >> col && (row*col))
//	{
//		vector<vector<char>> vv(row, vector<char>(col));
//		vector<vector<bool>> flag(row, vector<bool>(col, 0));
//		int x, y, tmp = 1;
//		for (int i = 0; i < row; i++)
//		{
//			for (int j = 0; j < col; j++)
//			{
//				cin >> vv[i][j];
//				flag[i][j] = false;
//				if (vv[i][j] == '@')
//				{
//					x = i; y = j;
//				}
//			}
//		}
//		flag[x][y] = true;
//		tmp = bfs(row, col, x, y, vv, flag);
//		cout << tmp << endl;
//	}
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<string>
//#include<set>
//using namespace std;
//
//void dfs(int index, vector<char>& v, vector<string>& ret, string& str1, string& str2, int l, int r, string tmp)
//{
//	if (index >= v.size()) return;
//	if (tmp.size() > r) return;
//	if (tmp.size() >= l && tmp.size() <= r)
//	if (tmp >= str1 && tmp <= str2)
//		ret.push_back(tmp);
//	for (int i = index; i<v.size(); i++)
//	{
//		dfs(i, v, ret, str1, str2, l, r, tmp + v[i]);
//	}
//}
//int main()
//{
//	string str1, str2;
//	int n1, n2;
//	while (cin >> str1 >> str2)
//	{
//		cin >> n1 >> n2;
//		vector<char> v = { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm' };
//		sort(v.begin(), v.end());
//
//		vector<string> ret;
//		dfs(0, v, ret, str1, str2, n1, n2, "");
//		cout << ret.size() % 1000007 << endl;
//	}
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<stack>
//#include<cstdlib>
//#include<algorithm>
//using namespace std;
//
//int fun(vector<char>& v)
//{
//	stack<int> st;
//	for (int i = 0; i < v.size(); i++)
//	{
//		if (v[i] == ' ') continue;
//		if (v[i] == '+')
//		{
//			int right = st.top(); st.pop();
//			int left = st.top(); st.pop();
//			int num = left + right;
//			st.push(num);
//		}
//		else if (v[i] == '-')
//		{
//			int right = st.top(); st.pop();
//			int left = st.top(); st.pop();
//			int num = left - right;
//			st.push(num);
//		}
//		else if (v[i] == '*')
//		{
//			int right = st.top(); st.pop();
//			int left = st.top(); st.pop();
//			int num = left * right;
//			st.push(num);
//		}
//		else if (v[i] == '/')
//		{
//			int right = st.top(); st.pop();
//			int left = st.top(); st.pop();
//			int num = left / right;
//			st.push(num);
//		}
//		else
//		{
//			int num = v[i] - '0';
//			st.push(num);
//		}
//	}
//	return st.top();
//}
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<char> v(n);
//		for (int i = 0; i < n; i++)
//		{
//			cin >> v[i];
//		}
//		cout << fun(v) << endl;
//	}
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//bool BoolBlack(vector<vector<string>>& vv, int i, int j)
//{
//	if (i + 4 < 20 && vv[i + 1][j] == "*"&& vv[i + 2][j] == "*"&& vv[i + 3][j] == "*"&& vv[i + 4][j] == "*")
//		return true;
//	if (i + 4 < 20 && vv[i][j + 1] == "*"&& vv[i][j + 2] == "*"&& vv[i][j + 3] == "*"&& vv[i][j + 4] == "*")
//		return true;
//	if (i + 4 < 20 && j + 4 < 20 && vv[i + 1][j + 1] == "*"
//		&& vv[i + 2][j + 2] == "*"&& vv[i + 3][j + 3] == "*"&& vv[i + 4][j + 4] == "*")
//		return true;
//	if (i + 4 < 20 && j - 4 >=0 && vv[i + 1][j -1] == "*"
//		&& vv[i + 2][j - 2] == "*"&& vv[i + 3][j - 3] == "*"&& vv[i + 4][j - 4] == "*")
//		return true;
//	return false;
//}
//bool BoolWhite(vector<vector<string>>& vv, int i, int j)
//{
//	if (i + 4 < 20 && vv[i + 1][j] == "+"&& vv[i + 2][j] == "+"&& vv[i + 3][j] == "+"&& vv[i + 4][j] == "+")
//		return true;
//	if (i + 4 < 20 && vv[i][j + 1] == "+"&& vv[i][j + 2] == "+"&& vv[i][j + 3] == "+"&& vv[i][j + 4] == "+")
//		return true;
//	if (i + 4 < 20 && j + 4 < 20 && vv[i + 1][j + 1] == "+"
//		&& vv[i + 2][j + 2] == "+"&& vv[i + 3][j + 3] == "+"&& vv[i + 4][j + 4] == "+")
//		return true;
//	if (i + 4 < 20 && j - 4 >= 0 && vv[i + 1][j - 1] == "+"
//		&& vv[i + 2][j - 2] == "+"&& vv[i + 3][j - 3] == "+"&& vv[i + 4][j - 4] == "+")
//		return true;
//	return false;
//}
//int main()
//{
//	vector<vector<string>> vv(20, vector<string>(20));
//	for (int i = 0; i < 20; i++)
//	{
//		for (int j = 0; j < 20; j++)
//		{
//			cin >> vv[i][j];
//		}
//	}
//	bool flag = false;
//	for (int i = 0; i < 20; i++)
//	{
//		if (flag) break;
//		for (int j = 0; j < 20; j++)
//		{
//			if (vv[i][j] == "*" && BoolBlack(vv, i, j))
//			{
//				flag = true;
//				cout << "Yes" << endl; break;
//			}
//			else if (vv[i][j] == "+" && BoolWhite(vv, i, j))
//			{
//				flag = true;
//				cout << "Yes" << endl; break;
//			}
//		}
//	}
//	if (!flag) cout << "No" << endl;
//	system("pause");
//	return 0;
//}

#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<char>>& vv, int x, int y, int& tmp, int& ret)
{
	tmp += 1;
	vv[x][y] = '#';
	if (tmp < ret)
	{
		if (x == 9 && y == 8)
		{
			ret = tmp;
		}
	}
	if (x + 1 < 10 && vv[x + 1][y] == '.') 
		dfs(vv, x + 1, y, tmp, ret);
	if (y + 1 < 10 && vv[x][y + 1] == '.') 
		dfs(vv, x, y + 1, tmp, ret);
	if (x - 1 >= 0 && vv[x - 1][y] == '.') 
		dfs(vv, x - 1, y, tmp, ret);
	if (y - 1 >= 0 && vv[x][y - 1] == '.') 
		dfs(vv, x, y - 1, tmp, ret);

	vv[x][y] = '.';
}
int main()
{
	while (1)
	{
		int r = 0, ret = 100000000;
		vector<vector<char>> vv(10, vector<char>(10));
		for (int i = 0; i<10; i++)
		{
			for (int j = 0; j< 10; j++)
			{
				if (scanf_s("%c", &vv[i][j]) == EOF)
					return 0;
			}
			getchar();
		}
		dfs(vv, 0, 1, r, ret);
		cout << ret << endl;
	}
	system("pause");
	return 0;
}