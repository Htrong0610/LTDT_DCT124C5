#include<iostream>
#define MAX 100
using namespace std;
int max(int arr[], int n) {
	int max = INT_MIN;
	for (int i = 0;i < n;i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}
int cont[10000001];

int main() {
	int arr[MAX];
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
		cont[arr[i]]++;
	}
	int m = max(arr, n);
	for (int i = 0;i <= m;i++) {
		if (cont[i] != 0) {
			for (int j = 0;j < cont[i];j++) {
				cout << i << " ";
			}
		}
	}
	return 0;
}