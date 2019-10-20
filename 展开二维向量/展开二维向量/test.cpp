//方法仅供参考，使用两个变量反而比直接放到一个数组中慢
class Vector2D {
public:
	vector<vector<int>>::iterator i, iEnd;
	int j;
	Vector2D(vector<vector<int>>& v) {
		i = v.begin();
		iEnd = v.end();
		j = 0;
	}

	int next() {
		if (i != iEnd && j == (*i).size())
		{
			i++; j = 0;
		}
		return (*i)[j++];
	}

	bool hasNext() {
		while (i != iEnd && j == (*i).size()){ i++; j = 0; }
		return i != iEnd;
	}
};

/**
* Your Vector2D object will be instantiated and called as such:
* Vector2D* obj = new Vector2D(v);
* int param_1 = obj->next();
* bool param_2 = obj->hasNext();
*/

class Vector2D {
public:
	int index = 0;
	int cur = 0;
	unordered_map<int, int> mp;
	Vector2D(vector<vector<int>>& v) {
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = 0; j < v[i].size(); j++)
			{
				mp[index++] = v[i][j];
			}
		}
	}

	int next() {
		return mp[cur++];
	}

	bool hasNext() {
		return cur == index ? false : true;
	}
};

/**
* Your Vector2D object will be instantiated and called as such:
* Vector2D* obj = new Vector2D(v);
* int param_1 = obj->next();
* bool param_2 = obj->hasNext();
*/