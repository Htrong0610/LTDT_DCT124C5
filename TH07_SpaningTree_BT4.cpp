#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;

// Cấu trúc cạnh có 3 thuộc tính: đỉnh đầu u, đỉnh cuối v, trọng số w
struct edge {
    int u, v, w;
    edge(int _u, int _v, int _w) {
        u = _u;
        v = _v;
        w = _w;
    }
    // Dùng cho priority_queue (sắp xếp theo trọng số tăng dần)
    bool operator>(const edge& other)const {
        return w > other.w;
    }
};

int n, m;
vector<edge> adj; // danh sách các cạnh

// Thuật toán Prim bắt đầu từ đỉnh x
void Prim(int x) {
    vector<int> dist(n, INT_MAX); // khoảng cách nhỏ nhất tới cây khung
    vector<int> parent(n);        // lưu cha của mỗi đỉnh trong cây khung
    vector<int> visited(n, 0);    // đánh dấu đỉnh đã thuộc cây khung
    priority_queue<edge, vector<edge>, greater<edge>> pq; // hàng đợi ưu tiên theo trọng số nhỏ
    vector<edge> mst;             // danh sách các cạnh thuộc cây khung
    int count = 0;                // tổng trọng số cây khung

    // Đưa đỉnh đầu tiên vào hàng đợi (v=-1 nghĩa là chưa có cha)
    pq.push(edge(x, -1, 0));

    while (!pq.empty()) {
        edge cur = pq.top();
        int u = cur.u;
        pq.pop();

        // Nếu đỉnh này đã được chọn thì bỏ qua
        if (visited[u]) continue;

        visited[u] = 1;     // đánh dấu đã chọn
        count += cur.w;     // cộng trọng số cạnh vào tổng
        if (cur.v != -1) mst.push_back(cur); // thêm cạnh vào cây khung (trừ đỉnh đầu tiên)

        // Duyệt tất cả cạnh kề u
        for (edge e : adj) {
            // Nếu có cạnh u → v
            if (e.u == u && !visited[e.v] && dist[e.v] > e.w) {
                parent[e.v] = u;
                dist[e.v] = e.w;
                pq.push(edge(e.v, u, e.w));
            }
            // Nếu có cạnh v → u (vì là đồ thị vô hướng)
            else if (e.v == u && !visited[e.u] && dist[e.u] > e.w) {
                parent[e.u] = u;
                dist[e.u] = e.w;
                pq.push(edge(e.u, u, e.w));
            }
        }
    }

    // In ra tổng trọng số cây khung
    cout<<n-1<<" "<< count << endl;
    // In các cạnh thuộc cây khung
    for (edge e : mst)
        cout << e.u + 1 << " " << e.v + 1 << " " << e.w << endl;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--; // chuyển sang chỉ số 0-based
        adj.push_back(edge(u, v, w));
    }
    Prim(0); // chạy Prim từ đỉnh 0 (tức là đỉnh 1 theo input)
    return 0;
}
