#include<iostream>
#include<queue>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

// Cấu trúc cạnh (Vertex)
struct Vertex {
    int v, w; // v: đỉnh kề, w: trọng số
    Vertex(int vertex, int weight) {
        v = vertex;
        w = weight;
    }
};

// Cấu trúc lưu thông tin khoảng cách (Distance)
// Dùng cho priority_queue để sắp xếp theo khoảng cách nhỏ nhất
struct Distance {
    int v, d; // v: đỉnh, d: khoảng cách tạm thời
    Distance(int vertex, int distance) {
        v = vertex;
        d = distance;
    }
    // Toán tử so sánh để priority_queue hiểu rằng "d nhỏ hơn có độ ưu tiên cao hơn"
    bool operator>(const Distance& other) const {
        return d > other.d;
    }
};

int n, m; // n: số đỉnh, m: số cạnh
vector<vector<Vertex>> adjlist; // Danh sách kề
vector<int> ans; // Lưu đường đi ngắn nhất

// Hàm Dijkstra: tìm đường đi ngắn nhất từ 'first' đến 'last'
void dijkstra(int first, int last) {
    vector<int> visited(n, 0);    // Đánh dấu đỉnh đã thăm
    vector<int> dist(n, INT_MAX); // Lưu khoảng cách ngắn nhất tạm thời
    vector<int> parent(n, -1);    // Lưu đỉnh cha để truy vết đường đi

    // priority_queue lưu (đỉnh, khoảng cách), sắp xếp theo khoảng cách nhỏ nhất
    priority_queue<Distance, vector<Distance>, greater<Distance>> pq;

    dist[first] = 0;
    pq.push(Distance(first, 0)); // Bắt đầu từ đỉnh 'first'

    // Vòng lặp chính của Dijkstra
    while (!pq.empty()) {
        Distance cur = pq.top(); // Lấy đỉnh có khoảng cách nhỏ nhất
        pq.pop();
        int u = cur.v;

        if (visited[u]) continue; // Nếu đã thăm, bỏ qua
        visited[u] = 1;

        // Duyệt các đỉnh kề của u
        for (Vertex e : adjlist[u]) {
            int v = e.v;
            int w = e.w;

            // Nếu tìm được đường đi ngắn hơn thì cập nhật
            if (!visited[v] && dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w; // Cập nhật khoảng cách ngắn hơn
                parent[v] = u;         // Ghi nhớ đỉnh cha
                pq.push(Distance(v, dist[v])); // Đưa vào hàng đợi ưu tiên
            }
        }
    }

    // Nếu không có đường đi đến đỉnh 'last'
    if (dist[last] == INT_MAX) return;

    // Truy ngược từ đỉnh 'last' về 'first' để khôi phục đường đi
    for (int cur = last; cur != -1; cur = parent[cur])
        ans.push_back(cur + 1); // +1 vì input đỉnh đánh số từ 1

    cout << ans.size() << " " << dist[last] << endl;

    // Đảo ngược thứ tự để in từ 'first' → 'last'
    reverse(ans.begin(), ans.end());
    for (int x : ans) cout << x << " ";
}

// Hàm main
int main() {
    cin >> n >> m;
    adjlist.assign(n, {}); // Khởi tạo danh sách kề trống

    int first, last;
    cin >> first >> last; // Nhập đỉnh bắt đầu và đỉnh kết thúc

    // Nhập danh sách cạnh
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // Vì đồ thị vô hướng nên thêm cả 2 chiều
        adjlist[u - 1].push_back(Vertex(v - 1, w));
        adjlist[v - 1].push_back(Vertex(u - 1, w));
    }

    // Gọi hàm Dijkstra
    dijkstra(first - 1, last - 1);

    return 0;
}
