#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Cấu trúc cạnh (edge)
struct edge {
	int u, v, w; // u: đỉnh đầu, v: đỉnh cuối, w: trọng số
	edge(int _u, int _v, int _w) {
		u = _u;
		v = _v;
		w = _w;
	}
	// Toán tử so sánh để sắp xếp cạnh theo trọng số tăng dần
	bool operator<(const edge& other) const {
		return w < other.w;
	}
};

int n, m;                 // n: số đỉnh, m: số cạnh
vector<int> parent;       // Mảng cha phục vụ cho DSU (Disjoint Set Union)
vector<edge> adj;         // Danh sách cạnh

// Hàm "find" tìm gốc của một đỉnh (với nén đường)
int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

// Hàm "Union" hợp nhất 2 tập đỉnh, trả về true nếu nối được 2 tập khác nhau
bool Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false; // nếu cùng tập -> bỏ qua (tránh tạo chu trình)
	parent[b] = a;
	return true;
}

// Thuật toán Kruskal chính
void KrusKal() {
	parent.resize(n);
	vector<edge> mst; // chứa các cạnh trong cây khung nhỏ nhất
	int count = 0;    // tổng trọng số của MST

	// Khởi tạo: mỗi đỉnh là cha của chính nó
	for (int i = 0; i < n; i++) parent[i] = i;

	// Sắp xếp các cạnh theo trọng số tăng dần
	sort(adj.begin(), adj.end());

	// Duyệt từng cạnh
	for (edge e : adj) {
		if (Union(e.u, e.v)) { // nếu nối được 2 thành phần rời nhau
			mst.push_back(e);
			count += e.w;       // cộng trọng số vào tổng
		}
	}

	// In kết quả
	cout << n - 1 << " " << count << endl;  // số cạnh trong MST (n-1) và tổng trọng số
	for (edge e : mst)
		cout << e.u + 1 << " " << e.v + 1 << " " << e.w << endl; // in ra các cạnh
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--; // chuyển về chỉ số từ 0
		adj.push_back(edge(u, v, w));
	}
	KrusKal();
	return 0;
}
