/*
	Reverse a stack using recursion
*/

#include<bits/stdc++.h>
using namespace std;

void insert_at_bottom(stack<int> st, int x) {
	if(st.size() == 0)
	    st.push(x);
	else {
		int a = st.top();
		st.pop();
		insert_at_bottom(st, x);
		st.push(a);
	}
}

void reverse(stack<int> st) {
	if(st.size() > 0) {
		int x = st.top();
		st.pop();
		reverse(st);
		insert_at_bottom(st, x);
	}
}

int main() {
    stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);

	reverse(st);
	cout << "Reversed Stack" << endl;

	while(!st.empty()) {
        int x = st.top();
        st.pop();
        cout << x << " ";
    }

	return 0;
}
