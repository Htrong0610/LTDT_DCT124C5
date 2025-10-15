#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	string s;
	cin >> s;
	int n = s.size();
	vector<vector<int>>dq(n, vector<int>(n, 0));

	for (int i = 0;i < n;i++) {
		dq[i][i] = 1;
	}
	for (int len = 2;len <= n;len++) {
		for (int l = 0;l + len - 1 < n;l++) {
			int r = l + len - 1;
			if (s[l] == s[r]) {
				dq[l][r] = dq[l+1][r - 1] + 2;
			}
			else {
				dq[l][r] = max(dq[l + 1][r], dq[l][r - 1]);
			}
		}
	}
	cout << "day palindrome dai nhay la " << dq[0][n - 1]<<endl;
	return 0;
}