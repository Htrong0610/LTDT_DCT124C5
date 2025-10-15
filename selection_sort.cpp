#include<iostream>
#define max 30
using namespace std;
void selection_sort(int a[],int n) {
	for (int i = 0;i < n-1;i++) {
		int min = i;
		for (int j = i + 1;j < n;j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		swap(a[i], a[min]);
	}
}
int main() {
	int a[10];
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	selection_sort(a, n);
	for (int i = 0;i < n;i++) {
		cout << a[i]<<" ";
	}
	return 0;
}