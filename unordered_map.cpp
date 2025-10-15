#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main() {
	int n,target;
	cin >> n>>target;
	vector<int> a(n);
	vector<int> ans;
	for (int i = 0;i < n;i++) cin >> a[i];
	unordered_map<int, int> mp;
	for (int i = 0;i < n;i++) {
		int need = target - a[i];
		if (mp.count(need)) {
			ans.push_back(mp[need]);
			ans.push_back(i);
		}
		mp[need] = i;
	}
	for (int x : ans) cout << x << " ";
	cout << endl;
}