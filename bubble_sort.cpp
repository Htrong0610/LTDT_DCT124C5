#include<iostream>
#define max 100
using namespace std;
void bubble_sort(int arr[], int n) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n-i- 1;j++) {
			if (arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
			}
		}
	}
}
int main() {
	int n;
	int arr[max];
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	bubble_sort(arr, n);
	for (int i = 0;i < n;i++) {
		cout << arr[i]<<" ";
	}
	return 0;
}