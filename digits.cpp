#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n; cin >> n;
	vector<int>digits;
	for (int i = 0;i < n;i++) {
		int x;cin >> x;
		digits.push_back(x);
	}
	reverse(digits.begin(), digits.end());
	int i = 0;
	digits[i]++;
	while (digits[i] == 10) {
		digits[i] = 0;
		if (digits.back() == 9) {
			digits.push_back(1);
			break;
		}
		digits[i + 1]++;
		i++;
	}
	reverse(digits.begin(), digits.end());
	for (int x : digits) cout << x << " ";
}
