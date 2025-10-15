#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

int n;
vector<vector<int>> adjlist; // danh sách kề
vector<int> ans;             // lưu kết quả đường đi
vector<int> visited;         // mảng đánh dấu
vector<int> parent;          // mảng cha để dựng đường đi
int fount = 0;               // biến cờ: 1 = đã tìm thấy đường đi

// DFS tìm đường đi từ first đến last
void DuongDi(int first, int last) {
    if (fount == 1) return;      // nếu đã tìm thấy thì dừng
    visited[first] = 1;          // đánh dấu đã thăm

    if (first == last) {         // nếu đến đỉnh đích
        fount = 1;               // tìm thấy
        return;
    }

    for (int v : adjlist[first - 1]) { // duyệt các đỉnh kề
        if (!visited[v]) {             // nếu chưa thăm
            parent[v] = first;         // lưu cha
            DuongDi(v, last);          // đệ quy DFS
        }
    }
}

// Hàm dựng và in đường đi
void LietKeDuongDi(int first, int last) {
    if (fount == 0) { // nếu không tìm thấy
        cout << "khong co duong di" << endl;
        return;
    }

    // dựng lại đường đi bằng cách lần ngược từ last về first
    for (int cur = last; cur != -1; cur = parent[cur]) {
        ans.push_back(cur);
    }
    reverse(ans.begin(), ans.end()); // đảo ngược để có đúng thứ tự

    // in ra đường đi
	cout<<ans.size()<<endl;
    for (int x : ans) cout << x << " ";
}

int main() {
    int first, last;
    cin >> n >> first >> last;
    cin.ignore();

    visited.assign(n + 1, 0);
    parent.assign(n + 1, -1);

    // nhập danh sách kề
    for (int i = 0; i < n; i++) {
        vector<int> row;
        int x;
        string s;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> x) row.push_back(x);
        adjlist.push_back(row);
    }

    // tìm đường đi
    DuongDi(first, last);

    // in kết quả
    LietKeDuongDi(first, last);

    return 0;
}
