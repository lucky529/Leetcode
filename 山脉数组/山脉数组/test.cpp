//二分查找
class Solution {
public:
	int peakIndexInMountainArray(vector<int>& A) {
		int lo = 1, hi = A.size() - 2;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (A[mid] < A[mid + 1]) {
				lo = mid + 1;
			}
			else if (A[mid] < A[mid - 1]) {
				hi = mid - 1;
			}
			else {
				return mid;
			}
		}
		throw logic_error("Unreachable code path");
	}
};
//遍历一遍
class Solution {
public:
	int peakIndexInMountainArray(vector<int>& A) {
		for (int i = 1; i < A.size() - 1; i++) {
			if (A[i] >= A[i - 1] && A[i] >= A[i + 1])
				return i;
		}
		return 0;
	}
};