#include<iostream>
#include<vector>
#define max 100
using namespace std;
void megre(int arr[], int m, int l, int r) {
	vector<int>x(arr + l,arr+ m + 1);
	vector<int>y(arr + m + 1, arr + r+1);
	int i = 0, j = 0;
	while (i < x.size() && j < y.size()) {
		if (x[i] <= y[j]) {
			arr[l] = x[i];
			l++;
			i++;
		}
		else
		{
			arr[l] = y[j];
			l++;
			j++;
		}
	}
	while (i < x.size()) {
		arr[l] = x[i];
		l++;
		i++;
	}
	while (j < y.size()) {
		arr[l] = y[j];
		l++;
		j++;
	}
}
void merge_sort(int arr[], int l, int r) {
	if (l >= r) {
		return;
	}
	int mid = (r + l) / 2;
	merge_sort(arr, l, mid);
	merge_sort(arr, mid + 1, r);
	megre(arr, mid, l, r);
}
int main() {
	int arr[max];
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	merge_sort(arr, 0, n-1);
	for (int i = 0;i < n;i++) {
		cout << arr[i] << " ";
	}
	return 0;
}