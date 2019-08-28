class Solution {
public:
	void push(int value) {
		st.push(value);
		if (stm.empty()) {
			stm.push(value);
		}
		else if (value <= stm.top()) {
			stm.push(value);
		}
	}
	void pop() {
		int tmp = st.top();
		st.pop();
		if (tmp == stm.top()) {
			stm.pop();
		}
	}
	int top() {
		return st.top();
	}
	int min() {
		return stm.top();
	}
private:
	stack<int> st;
	stack<int> stm;
};