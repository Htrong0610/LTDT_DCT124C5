#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
};
typedef struct Node* node;
node makeNode(int x) {
	node tmp = new Node();
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}
bool empty(node a) {
	return a == NULL;
}
int Size(node a) {
	int cnt = 0;
	while (a != NULL) {
		cnt++;
		a = a->next;
	}
	return cnt;
}
void insertFisrt(node &a, int x) {
	node temp = makeNode(x);
	if (a->next == NULL) {
		a = temp;
	}
	else
	{
		temp->next = a;
		a = temp;
	}
}
void insertLast(node& a, int x) {
	node temp = makeNode(x);
	if (a == NULL) {
		a = temp;
	}
	else
	{
		node p = a;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = temp;
	}
}
void insertMid(node& a, int x, int pos) {
	int n = Size(a);
	if (pos <= 0 || pos >n +1) {
		cout << "vi tri chen khong hop le" << endl;
	}
	if (pos == 1) {
		insertFisrt(a, x);
		return;
	}
	else if(pos==n +1)
	{
		insertLast(a, x);
		return;
	}
	else
	{
		node temp = makeNode(x);
		node p = a;
		for (int i = 0;i < pos - 1;i++) {
			p = p->next;
		}
		temp->next = p->next;
		p->next = temp;
	}
}
void deleteFirst(node& a) {
	if (a == NULL) {
		return;
	}
	a = a->next;
}
void deleteLast(node& a) {
	if (a == NULL) {
		return;
	}
	node truoc = NULL, sau = a;
	while (sau->next != NULL) {
		truoc = sau;
		sau = sau->next;
	}
	if (truoc == NULL) {
		a = NULL;
	}
	else {
		truoc->next = NULL;
	}
}
void deleteMid(node& a, int pos) {
	if (pos <= 0 || pos > Size(a)) {
		return;
}
	node truoc = NULL, sau = a;
	for (int i = 0;i < pos;i++) {
		truoc = sau;
		sau = sau->next;
	}
	if (a == NULL) {
		deleteFirst(a);
	}
	else
	{
		truoc->next = sau->next;
	}
}
void print(node a) {
	cout << "______________________________\n";
	while (a != NULL) {
		cout << a->data << " ";
		a = a->next;
	}
	cout << "______________________________\n";
}
void xapsep(node &a) {
	for (node p = a;p->next != NULL;p = p->next) {
		node min = p;
		for (node j = p->next;j != NULL;j=j->next) {
			if (j->data > min->data) {
				j = min;
			}
		}
		int temp = p->data;
		p->data = min->data;
		min->data = temp;
	}
}
int main() {
	node head = NULL;
	int choice;
	
	do {
		cout << "\n=====MENU=====\n";
		cout << "moi ban nhap vao cac thao tac sau \n";
		cout << "1.chen phan tu vao dau\n";
		cout << "2.chen phan tu vao cuoi \n";
		cout << "3.chen phan tu vao giua \n";
		cout << "4.xoa phan tu o dau \n";
		cout << "5.xoa phan tu o cuoi \n";
		cout << "6.xoa phan tu o gia \n";
		cout << "7.duyet danh sach lien ket \n";
		cout << "8.sap xap cac phan tu danh sach \n";
		cout << "9.thoat chuong trinh \n";
		cout << "\n_________________________________________\n";
		cin >> choice;
		switch (choice)
		{
			case(1):
				int x;
				cout << "nhap phan tu ban muon chen \n";
				cin >> x;
				insertFisrt(head, x);
				break;
			case(2):
				int x1;
				cout << "nhap phan tu ban muon chen \n";
				cin >> x1;
				insertLast(head, x1);
				break;
			case(3):
				int x2;
				cout << "nhap phan tu ban muon chen \n";
				int pos1;
				cin >> x2;
				cout << "nhap vi tri ban muon chen \n";
				cin >> pos1;
				insertMid(head, x2,pos1);
				break;
			case(4):
				deleteFirst(head);
				break;
			case(5):
				deleteLast(head);
				break;
			case(6):
				int pos;
				cout << "nhap vi tri ban muon xoa \n";
				cin >> pos;
				deleteMid(head, pos);
				break;
			case(7):
				print(head);
				break;
			case(8):
				xapsep(head);
				break;
			case(9):
				break;
			default:
				cout << "lua chon khong hop le \n";
		}
	} while (choice != 9);
	return 0;
}