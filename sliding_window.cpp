#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main() {
	int total = 0;
	int L = 0;
	int result = 0;
	int n,target;
	cin >> n>>target;
	vector<int> a(n);																																	
	priority_queue<int, vector<int>, greater<int>> ans;
	for (int i = 0;i < n;i++) cin >> a[i];
	for (int R = 0;R < n;R++) {
		result += a[R];
		while (result >= target) {
			total = R - L;
			ans.push(total+1);
			result -= a[L];
			L++;
			total--;

		}
	}
	cout << ans.top();
	return 0;
}