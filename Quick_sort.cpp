#include<iostream>
#define max 100
using namespace std;
int partion(int arr[], int l, int r) {
	int pivot = arr[r];
	int i = l - 1;
	for (int j = l;j < r;j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	i++;
	swap(arr[i], arr[r]);
	return i;
}
void quick_sort(int arr[], int l, int r) {
	if (l >= r) {
		return;
	}
	int p = partion(arr, l, r);
	quick_sort(arr, l, p-1);
	quick_sort(arr, p + 1, r);
}
int main() {
	int n;
	int arr[max];
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	quick_sort(arr, 0,n-1);
	for (int i = 0;i < n;i++) {
		cout << arr[i] << " ";
	}
	return 0;
}