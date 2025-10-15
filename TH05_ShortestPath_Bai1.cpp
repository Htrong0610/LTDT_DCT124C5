#include<iostream>
#include<vector>
#include<set>
#include<climits>
#include<algorithm>
using namespace std;

// Cấu trúc cạnh (Vertex): chứa đỉnh kề 'v' và trọng số 'w'
struct Vertex {
    int v, w;
    Vertex(int vertex, int weight) {
        v = vertex;
        w = weight;
    }
};

int n, m;
vector<int> ans; // Lưu đường đi kết quả
vector<vector<Vertex>> adjlist; // Danh sách kề

// Hàm Dijkstra tìm đường đi ngắn nhất từ 'first' đến 'last'
void dijkstra(int first, int last) {
    vector<int> visited(n, 0);    // Đánh dấu đỉnh đã thăm
    vector<int> parent(n, -1);    // Lưu đỉnh cha để truy vết đường đi
    vector<int> dist(n, INT_MAX); // Lưu khoảng cách ngắn nhất tạm thời
    set<pair<int, int>> s;        // (khoảng cách, đỉnh) — dùng để lấy đỉnh có dist nhỏ nhất

    dist[first] = 0;
    s.insert({0, first});

    while (!s.empty()) {
        pair<int, int> cur = *s.begin(); // Lấy đỉnh có khoảng cách nhỏ nhất
        int u = cur.second;
        s.erase(s.begin());
        if (visited[u]) continue; // Nếu đã thăm thì bỏ qua
        visited[u] = 1;

        // Duyệt tất cả các đỉnh kề của u
        for (Vertex e : adjlist[u]) {
            int v = e.v;
            int w = e.w;

            // Nếu có đường đi ngắn hơn -> cập nhật
            if (!visited[v] && dist[v] > dist[u] + w) {
                if (dist[v] != INT_MAX) s.erase({dist[v], v});
                parent[v] = u;
                dist[v] = dist[u] + w;
                s.insert({dist[v], v});
            }
        }
    }

    // Nếu không có đường đi
    if (dist[last] == INT_MAX) return;

    // Truy ngược từ đỉnh đích -> đầu để lấy đường đi
    for (int cur = last; cur != -1; cur = parent[cur])
        ans.push_back(cur + 1); // +1 vì chỉ số đỉnh nhập từ 1

    reverse(ans.begin(), ans.end()); // Đảo lại thứ tự

    // In kết quả
    cout << ans.size() << " " << dist[last] << endl;
    for (int x : ans) cout << x << " ";
}

int main() {
    cin >> n >> m;
    adjlist.assign(n, {});
    int first, last;
    cin >> first >> last;

    // Nhập danh sách cạnh
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjlist[u - 1].push_back(Vertex(v - 1, w));
        adjlist[v - 1].push_back(Vertex(u - 1, w)); // đồ thị vô hướng
    }

    dijkstra(first - 1, last - 1);
    return 0;
}
