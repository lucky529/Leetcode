//使用一个辅助数组，但是程序的扩展性不好，如果有多个数组就要重新更改代码
class ZigzagIterator {
public: vector<int> v; int pos = 0;

		ZigzagIterator(vector<int> &v1, vector<int> &v2) {
			int pos = 0;
			int len1 = v1.size();
			int len2 = v2.size();
			bool end = false;
			while (pos < len1 && pos < len2) {
				v.push_back(v1[pos]);
				v.push_back(v2[pos]);
				pos++;
			}
			while (pos < len1) {
				v.push_back(v1[pos++]);
			}
			while (pos < len2) {
				v.push_back(v2[pos++]);
			}
		}

		int next() {
			if (hasNext()) {
				return v[pos++];
			}
			return 0;
		}

		bool hasNext() {
			return pos < v.size();
		}
};