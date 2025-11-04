#include<iostream>
#include<vector>
using namespace std;

// Cấu trúc lưu cạnh (edge)
struct edge {
    int u, v; // u: đỉnh đầu, v: đỉnh cuối
    edge(int _u, int _v) { // Hàm khởi tạo
        u = _u;
        v = _v;
    }
};

int n, m; // n: số đỉnh, m: số cạnh
vector<int> visited; // Mảng đánh dấu đỉnh đã thăm (0: chưa, 1: đã thăm)
vector<int> parent;  // Mảng lưu đỉnh cha trong cây khung
vector<edge> adj;    // Danh sách cạnh của đồ thị (chưa phải danh sách kề)

// Hàm duyệt DFS để xây dựng cây khung
void SpanTreeDFS(int u) {
    visited[u] = 1; // Đánh dấu đỉnh u đã được thăm
    for (edge e : adj) { // Duyệt qua tất cả các cạnh trong danh sách cạnh
        if (e.u == u) { // Nếu cạnh xuất phát từ u
            int v = e.v; // Lấy đỉnh kề với u
            if (!visited[v]) { // Nếu v chưa được thăm
                parent[v] = u; // Gán cha của v là u
                SpanTreeDFS(v); // Gọi đệ quy DFS để thăm v
            }
        }
    }
}

int main() {
    cin >> n >> m; // Nhập số đỉnh và số cạnh

    visited.assign(n, 0); // Khởi tạo tất cả đỉnh chưa được thăm
    parent.resize(n);     // Cấp phát mảng cha với n phần tử

    // Nhập danh sách cạnh
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v; // Nhập đỉnh u và v (đồ thị có cạnh từ u đến v)
        u--; v--; // Chuyển từ chỉ số 1-based sang 0-based
        adj.push_back(edge(u, v)); // Thêm cạnh (u, v) vào danh sách cạnh
    }

    SpanTreeDFS(0); // Bắt đầu DFS từ đỉnh 0 (tức đỉnh 1 trong input)
    cout << n - 1 << endl;
    // In các cạnh thuộc cây khung
    for (int i = 1; i < parent.size(); i++) {
        cout << parent[i] + 1 << " " << i + 1 << endl;
        // Cộng lại 1 để in ra đúng theo chỉ số ban đầu (1-based)
    }

    return 0;
}
