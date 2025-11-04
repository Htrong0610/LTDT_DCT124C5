#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Cấu trúc lưu cạnh của đồ thị (đồ thị vô hướng)
struct edge {
	int u, v;
	edge(int _u, int _v) {
		u = _u;
		v = _v;
	}
};

int n, m;               // n: số đỉnh, m: số cạnh
vector<edge> adj;       // Danh sách các cạnh

// Hàm tạo cây khung bằng BFS (xuất phát từ đỉnh x)
void SpanTreeBFS(int x) {
	vector<int> visited(n, 0);  // Đánh dấu các đỉnh đã thăm
	vector<int> parent(n, -1);  // Lưu cha của mỗi đỉnh trong cây khung
	queue<int> q;               // Hàng đợi dùng cho BFS

	q.push(x);          // Bắt đầu BFS từ đỉnh x
	visited[x] = 1;     // Đánh dấu đỉnh đầu tiên đã thăm

	// Duyệt BFS
	while (!q.empty()) {
		int u = q.front();  // Lấy đỉnh đầu hàng đợi
		q.pop();

		// Duyệt qua tất cả các cạnh có đầu là u
		for (edge e : adj) {
			if (e.u == u) {
				int v = e.v;  // Đỉnh kề của u
				if (!visited[v]) {     // Nếu v chưa được thăm
					parent[v] = u;     // Ghi nhận cha của v là u
					visited[v] = 1;    // Đánh dấu đã thăm
					q.push(v);         // Thêm v vào hàng đợi
				}
			}
		}
	}

	cout << n - 1 << endl; // In số cạnh của cây khung (luôn là n - 1 nếu đồ thị liên thông)

	// In ra danh sách các cạnh của cây khung
	for (int i = 1; i < parent.size(); i++) {
		if (parent[i] != -1) // Chỉ in những đỉnh có cha
			cout << parent[i] + 1 << " " << i + 1 << endl; // +1 để chuyển lại về chỉ số từ 1 đến n
	}
}

int main() {
	cin >> n >> m; // Nhập số đỉnh và cạnh

	// Nhập các cạnh
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--; // Giảm chỉ số để dùng mảng 0-based
		adj.push_back(edge(u, v));
		adj.push_back(edge(v, u)); // Vì đồ thị vô hướng nên thêm cả chiều ngược lại
	}

	// Gọi hàm BFS tạo cây khung bắt đầu từ đỉnh 0 (tức là đỉnh 1 trong input)
	SpanTreeBFS(0);
	return 0;
}
