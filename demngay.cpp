#include<iostream>
using namespace std;
int main() {
	int dem = 0;
	int ngay, thang, nam;
	cout << "moi ban nhap ngay" << endl;
	cin >> ngay;
	dem += ngay;
	cout << "moi ban ngap thang" << endl;
	cin >> thang;
	cout << "moi ban nhap nam" << endl;
	cin >> nam;
	for (int i = 0;i <= thang;i++) {
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			dem += 31;
		if (i == 4 || i == 6 || i == 9 || i == 11)
			dem += 30;
		if(i==2)
		{;
		if (nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0)
			dem += 29;
		else
			dem += 28;
		}
	}
	for (int i = 0;i <=nam ;i++) {
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
			dem += 366;
		else
			dem += 365;
	}
	cout << "tong so ngay tu 1/1/1 den ngay " << ngay << "/" << thang << "/" << nam << " la " << dem - (1 + 31 + 365) << endl;
}