#include<stdio.h>
int* smaller(int* p1, int* p2);
int main(void) {
	int a;
	int b;
	int* p;
	scanf ("%d %d",& a, &b);
	p = smaller(&a, &b);
}
int* smaller(int* px, int* py) {
	return (*px < *py ? px : py);
}