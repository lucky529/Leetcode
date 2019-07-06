//����ͨ��11/13 ǰ׺������dfs���ɽ��
const int MAXN = 27;
class Trie {
public:
	bool is_str; // ��ʶ��ǰ����Ƿ�Ϊһ���������ַ���
	Trie *next[MAXN]; // ��һ������ָ������
	Trie() {
		is_str = NULL;
		memset(next, 0, sizeof(next));
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		Trie *cur = this; // cur��ʼ��Ϊ�����ָ��
		for (char w : word){ // ����word�е�ÿһ���ַ�
			if (cur->next[w - 'a'] == NULL){ // ��һ����㲻���ڣ�����һ�����
				Trie *new_node = new Trie();
				cur->next[w - 'a'] = new_node;
				if (cur->next[26]== nullptr)
					cur->next[26] = new_node;
			}
			cur = cur->next[w - 'a'];
		}
		cur->is_str = true; // ��ǰ����Ѿ���һ���������ַ�����
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		Trie *cur = this;
		for (char& w : prefix){
			if (cur != NULL)
			{
				if (w != '.')
					cur = cur->next[w - 'a'];
				else
					cur = cur->next[26];
			}
		}
		return (cur != NULL && cur->is_str);
	}
};

class WordDictionary {
public:
	/** Initialize your data structure here. */
	WordDictionary() {

	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		tr.insert(word);
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return tr.startsWith(word);
	}
private:
	Trie tr;
};

//109msͨ��

class WordNode {
public:
	WordNode() {
		for (auto &i : next) {
			i = nullptr;
		}
		isString = false;
	}

	WordNode *next[26];
	bool isString;
};

class WordDictionary {
public:
	/** Initialize your data structure here. */
	WordDictionary() {
		root = new WordNode();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		WordNode *p = root;
		for (char i : word){
			if (!p->next[i - 'a']){
				p->next[i - 'a'] = new WordNode();
			}
			p = p->next[i - 'a'];
		}
		p->isString = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		WordNode *p = root;
		return search(word, 0, p);
	}

	bool search(const string& word, int pos, WordNode *cur){
		if (pos == word.size()) return cur->isString;
		if (word[pos] == '.'){
			for (auto & i : cur->next) {
				if (i && search(word, pos + 1, i)) return true;
			}
			return false;
		}
		if (cur->next[word[pos] - 'a']){
			return search(word, pos + 1, cur->next[word[pos] - 'a']);
		}
		return false;
	}

private:
	WordNode *root;
};