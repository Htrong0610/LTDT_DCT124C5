#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;cin >> n;
	vector<int> arr;
	for (int i = 0;i < n;i++) {
		int m;cin >> m;
		arr.push_back(m);
	}
	int k;cin >> k;
	arr.erase(arr.begin() + k - 1);

	int p, q;
	cin >> p >> q;
	arr.erase(arr.begin() + q - 1, arr.begin() + p - 1);
	for (int x : arr) cout << x << " ";
}