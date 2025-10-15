#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
bool nt(int n) {
	if (n < 2)
		return false;
	for (int i = 2;i <= sqrt(n);i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}
int timmax(const vector<int>& A) {
	int n = A.size();
	int max = A[0];
	for (int i = 0;i < n;i++) {
		if (A[i] > max)
			max = A[i];
	}
	return max;
}
int ntdoixung(const vector<int>& A) {
	int n = A.size();
	int dem = 0;
	for (int i = 0;i < n;i++) {
		if (nt(A[i])) {
			int upper = A[i] + 1;
			int lower = A[i] - 1;
			while (!nt(upper))
				upper++;
			while (!nt(lower))
				lower--;
			if (n = (lower + upper) / 2)
				dem++;
		}
	}
	return dem;
}
int main() {
	int n;
	cout << "so phan tu cua mang la " << endl;
	cin >> n;
	vector<int> A(n);
	cout << "nhap cac phan tu cua mang " << endl;
	for (int i = 0;i < n;i++) {
		cin >> A[i];
	}
	int max = timmax(A);
	cout << "phan tu lon nhat trong mang la " << max << endl;
	int dem = ntdoixung(A);
	cout << "so nguyen to doi xung trong mang la " << dem << endl;
	return 0;
}