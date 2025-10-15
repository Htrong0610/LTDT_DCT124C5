#include<iostream>
#define max 100
using namespace std;
void insert_sort(int arr[], int n) {
	for (int i = 1;i < n;i++) {
		int x = arr[i];
		int key = i-1;
		while (key >= 0 && x<arr[key]) {
			arr[key + 1] = arr[key];
			key--;
		}
		arr[key + 1] = x;
	}
}
int main() {
	int arr[max];
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	insert_sort(arr, n);
	for (int i = 0;i < n;i++) {
		cout << arr[i] << " ";
	}
	return 0;
}