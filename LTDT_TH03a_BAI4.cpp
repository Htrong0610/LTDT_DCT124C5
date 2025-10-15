#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<sstream>
using namespace std;
int n;                       // n = số đỉnh, m = số cạnh
vector<vector<int>> adjlist;        // danh sách kề
vector<int> visited;            // mảng đánh dấu đã thăm (0 = chưa, 1 = đã thăm)

// Hàm BFS: duyệt từ đỉnh start, có thể "bỏ qua" 1 cạnh hoặc 1 đỉnh
void bfs(int start, int ban_u = -1, int ban_v = -1, int ban_node = -1) {
    queue<int> q;
    visited[start] = 1;         // đánh dấu đỉnh start đã thăm
    q.push(start);              // đưa start vào hàng đợi

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adjlist[u]) {
            // Nếu cạnh (u,v) là cạnh bị loại bỏ thì bỏ qua
            if ((u == ban_u && v == ban_v) || (u == ban_v && v == ban_u)) continue;

            // Nếu v chính là đỉnh bị loại bỏ thì bỏ qua
            if (v == ban_node) continue;

            // Nếu v chưa được thăm thì thăm nó
            if (!visited[v]) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}

// Kiểm tra cạnh (u,v) có phải là cạnh cầu không
bool isBridge(int u, int v) {
    visited.assign(n + 1, 0);   // reset mảng visited về 0
    int comp = 0;               // đếm số thành phần liên thông

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {      // nếu i chưa thăm
            bfs(i, u, v);       // BFS nhưng bỏ cạnh (u,v)
            comp++;             // tăng số thành phần
        }
    }
    // Nếu sau khi bỏ cạnh mà số thành phần tăng lên → (u,v) là cầu
    return comp > 1;
}

// Kiểm tra z có phải đỉnh khớp không
bool isArticulation(int x) {
    visited.assign(n + 1, 0);   // reset visited
    visited[x] = 1;             // "coi như" x bị loại bỏ
    int comp = 0;               // đếm số thành phần liên thông

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {      // nếu i chưa thăm
            bfs(i, -1, -1, x);  // BFS bỏ qua đỉnh x
            comp++;
        }
    }
    // Nếu số thành phần tăng lên → x là đỉnh khớp
    return comp > 1;
}

int main() {
    cin >> n;
    int x, y, z; // nhập cạnh (x,y) và đỉnh z để kiểm tra
    cin >> x >> y >> z;

       // khởi tạo danh sách kề

    for (int i = 0;i < n;i++) {
        int x;
        vector<int> row;
        string s;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> x) row.push_back(x);
        adjlist.push_back(row);
    }

            

    // Kiểm tra cạnh cầu
    if (isBridge(x, y)) cout << "canh cau\n";
    else cout << "khong la canh cau\n";

    // Kiểm tra đỉnh khớp
    if (isArticulation(z)) cout << "dinh khop\n";
    else cout << "khong la dinh khop\n";

    return 0;
}