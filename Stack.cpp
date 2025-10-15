#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main() {
	/*stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
	cout << st.size() << endl;
	if (st.empty() == NULL) {
		cout << "Empty";
	}*/
	stack<int>st;
	/*int n;
	cin >> n;
	while (n != 0) {
		st.push(n % 2);
		n /= 2;
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}*/
	string s;
	getline(cin, s);
	stringstream ss(s);
	string token;
	stack<string>stk;
	while (ss >> token) {
		stk.push(token);
	}
	while (!stk.empty()) {
		cout << stk.top() << " ";
		st.pop();
	}
	return 0;
}