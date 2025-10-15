#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool hoangchinh(int a) {
	int tong = 0;
	for(int i = 1;i < a;i++) {
		if (a % i == 0) 
			tong += i;
	}
	if (tong == a)
		return true;
	else
		return false;
}
int tongchuso(int a) {
	int tong = 0;
	while (a > 0) {
		tong += a % 10;
		a /= 10;
	}
	return tong;
}
int main() {
	int dem = 0;
	int n;
	cout << "nhap so phan tu trong mang " << endl;
	cin >> n;
	vector <int> A(n);
	cout << "nhap cac phan tu trong mang " << endl;
	for (int i = 0;i < n;i++) {
		cin >> A[i];
	}
	for (int i = 0;i < n;i++) {
		if (hoangchinh(A[i]))
			dem++;
	}
	cout << "so hoang chinh co trong mang la " << dem << endl;
	cout << "tong chu so cua cac phan tu trong mang la " << endl;
	for (int i = 0;i < n;i++) {
		int tong = tongchuso(A[i]);
		cout << tong<<" ";
	}
	cout << endl;
	sort(A.begin(), A.end());
	cout << "mang sau khi duoc sap xep la " << endl;
	for (int i = 0;i < n;i++) {
		cout << A[i] << " ";
	}
}

