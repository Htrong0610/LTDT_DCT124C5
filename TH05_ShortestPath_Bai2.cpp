#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<climits>
using namespace std;

// Cấu trúc lưu cạnh (đỉnh kề v và trọng số w)
struct Vertex {
    int v, w;
    Vertex(int vertex, int weight) {
        v = vertex;
        w = weight;
    }
};

int n, m;
vector<vector<Vertex>> adjlist; // Danh sách kề
vector<int> dis; // Lưu độ dài các chặng đường (first -> target, target -> last)

// Hàm Dijkstra tìm đường đi ngắn nhất giữa hai đỉnh: first -> last
vector<int> dijkstra(int first, int last) {
    vector<int> visited(n, 0);     // Đánh dấu đỉnh đã thăm
    vector<int> dist(n, INT_MAX);  // Lưu khoảng cách ngắn nhất tạm thời
    vector<int> parent(n, -1);     // Lưu đỉnh cha để truy vết đường đi
    set<pair<int, int>> s;         // (khoảng cách, đỉnh) — dùng để chọn đỉnh có dist nhỏ nhất

    dist[first] = 0;
    s.insert({0, first});          // Bắt đầu từ đỉnh đầu tiên

    // Vòng lặp chính của Dijkstra
    while (!s.empty()) {
        pair<int, int> cur = *s.begin(); // Lấy phần tử đầu tiên (dist nhỏ nhất)
        s.erase(s.begin());
        int u = cur.second;
        if (visited[u]) continue;        // Nếu đã thăm thì bỏ qua
        visited[u] = 1;

        // Duyệt tất cả đỉnh kề của u
        for (Vertex e : adjlist[u]) {
            int v = e.v;
            int w = e.w;

            // Nếu tìm thấy đường đi ngắn hơn
            if (!visited[v] && dist[v] > dist[u] + w) {
                if (dist[v] != INT_MAX) s.erase({dist[v], v}); // Xóa khoảng cách cũ
                parent[v] = u;
                dist[v] = dist[u] + w; // Cập nhật khoảng cách
                s.insert({dist[v], v}); // Thêm lại vào set
            }
        }
    }

    vector<int> ans;
    if (dist[last] == INT_MAX) return ans; // Không có đường đi thì trả về rỗng

    dis.push_back(dist[last]); // Lưu khoảng cách vừa tính được

    // Truy ngược từ last về first để khôi phục đường đi
    for (int cur = last; cur != -1; cur = parent[cur])
        ans.push_back(cur + 1); // +1 để trả về chỉ số đỉnh

    reverse(ans.begin(), ans.end()); // Đảo ngược để thành first -> last
    return ans;
}

int main() {
    cin >> n >> m; // Nhập số đỉnh và cạnh
    adjlist.assign(n, {}); // Khởi tạo danh sách kề rỗng

    int first, last, target;
    cin >> first >> last >> target; // Nhập 3 đỉnh: bắt đầu, kết thúc, trung gian

    // Nhập danh sách cạnh (đồ thị vô hướng)
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjlist[u - 1].push_back(Vertex(v - 1, w));
        adjlist[v - 1].push_back(Vertex(u - 1, w));
    }

    // Tính đường đi từ first -> target
    vector<int> path1 = dijkstra(first - 1, target - 1);
    // Tính đường đi từ target -> last
    vector<int> path2 = dijkstra(target - 1, last - 1);

    // Nếu một trong hai đoạn không tồn tại → không có đường đi đầy đủ
    if (path1.empty() || path2.empty()) return 0;

    // Xóa đỉnh đầu tiên của path2 (tránh lặp lại đỉnh target)
    path2.erase(path2.begin());
    // Nối path2 vào cuối path1 → tạo đường đi tổng hợp first → target → last
    path1.insert(path1.end(), path2.begin(), path2.end());

    // In ra kết quả
    cout << path1.size() << " "; // Số lượng đỉnh trong đường đi

    int total = 0; // Tổng trọng số của toàn bộ đường đi
    for (int x : dis) total += x;
    cout << total << endl;

    for (int x : path1) cout << x << " "; // In ra các đỉnh trong đường đi

    return 0;
}
