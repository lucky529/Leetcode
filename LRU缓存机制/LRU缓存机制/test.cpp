class LRUCache {
public:
	LRUCache(int capacity) {
		_capacity = capacity;
	}

	int get(int key) {
		unordered_map<int, list<pair<int, int>>::iterator>::iterator mit = mp.find(key);
		if (mit == mp.end())
		{
			return -1;
		}
		else
		{
			list<pair<int, int>>::iterator lit = mit->second;
			pair<int, int> kv = *lit;

			l.erase(lit);
			l.push_front(kv);
			mp[key] = l.begin();
		}
		return l.begin()->second;
	}

	void put(int key, int value) {
		unordered_map<int, list<pair<int, int>>::iterator>::iterator mit = mp.find(key);
		if (mit == mp.end())
		{
			if (l.size() >= _capacity)
			{
				mp.erase(l.back().first);//µü´úÆ÷Ê§Ð§
				l.pop_back();
			}
			l.push_front({ key, value });
			mp[key] = l.begin();
		}
		else
		{
			list<pair<int, int>>::iterator lit = mit->second;

			l.erase(lit);
			l.push_front({ key, value });
			mp[key] = l.begin();
		}
	}
private:
	int _capacity;
	list<pair<int, int>> l;
	unordered_map<int, list<pair<int, int>>::iterator> mp;
};