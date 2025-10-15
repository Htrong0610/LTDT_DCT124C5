#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int n;                          // số đỉnh
vector<vector<int>> adjlist;    // danh sách kề
vector<int> color;              // mảng lưu màu (0 hoặc 1)
bool ok = true;                 // cờ để kiểm tra bipartite

// DFS để tô màu đồ thị
void dfs(int u, int c) {
    color[u] = c;               // tô đỉnh u màu c
    for (int v : adjlist[u]) {  // duyệt các đỉnh kề với u
        if (color[v] == -1) {   // nếu đỉnh v chưa được tô màu
            dfs(v, 1 - c);      // tô ngược màu với u
        }
        else if (color[v] == c) {
            ok = false;         // nếu v có cùng màu với u -> không bipartite
        }
    }
}

int main() {
    cin >> n;                   // nhập số đỉnh
    cin.ignore();
    color.assign(n + 1, -1);    // khởi tạo tất cả đỉnh chưa được tô màu (-1)

    // nhập danh sách kề
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        int x;
        vector<int> row;
        while (ss >> x) row.push_back(x);
        adjlist.push_back(row); // thêm danh sách kề của đỉnh i
    }

    // kiểm tra tất cả các thành phần liên thông
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {   // nếu đỉnh i chưa tô màu
            dfs(i, 0);          // bắt đầu tô màu từ đỉnh i với màu 0
        }
    }

    if (ok) cout << "Do thi phan doi\n";
    else cout << "Do thi khong phan doi.\n";

    return 0;
}
