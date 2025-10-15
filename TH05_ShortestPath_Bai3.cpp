#include<iostream>
#include<vector>
#include<climits>
using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++) // Macro giúp viết gọn vòng lặp for

int main() {
    int n, m;
    cin >> n >> m; // Nhập số đỉnh (n) và số cạnh (m)

    // Ma trận khoảng cách, khởi tạo giá trị ban đầu là vô cực (INT_MAX)
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    // Khoảng cách từ 1 đỉnh đến chính nó = 0
    FOR(i, n) dist[i][i] = 0;

    // Nhập các cạnh của đồ thị
    FOR(i, m) {
        int u, v, w;
        cin >> u >> v >> w; // Cạnh (u, v) có trọng số w
        u--; v--; // Đưa về chỉ số 0-based

        // Nếu có nhiều cạnh giữa 2 đỉnh, lấy cạnh nhỏ nhất
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w); // Vì đồ thị vô hướng
    }
    // Thuật toán Floyd–Warshall
    FOR(k, n) { // Duyệt tất cả các đỉnh trung gian k
        FOR(i, n) {
            FOR(j, n) {
                // Nếu i->k và k->j đều tồn tại
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    int newdist = dist[i][k] + dist[k][j];
                    // Nếu đi qua k ngắn hơn thì cập nhật
                    if (dist[i][j] > newdist) dist[i][j] = newdist;
                }
            }
        }
    }

    // In ra ma trận khoảng cách ngắn nhất giữa mọi cặp đỉnh
    FOR(i, n) {
        FOR(j, n) {
            // Nếu không có đường đi, in ra -1 cho dễ nhìn (tuỳ chọn)
            if (dist[i][j] == INT_MAX) cout << "-1 ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
