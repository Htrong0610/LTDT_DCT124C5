#include<iostream>
#include<vector>
using namespace std;

#define MAXN 100
#define FOR(i,n) for(int i=0;i<n;i++)

int n;                   // số đỉnh
int a[MAXN][MAXN];       // ma trận kề
vector<int> visited;     // mảng đánh dấu đỉnh đã đi qua
vector<int> ans;         // lưu đường đi hiện tại
int found = 0;           // cờ đánh dấu đã tìm thấy chu trình Hamilton

// Hàm quay lui
void Hamilton(int u, int count) {
	if (found) return;   // Nếu đã tìm thấy rồi thì dừng luôn (tối ưu)

	// Nếu đã đi qua n đỉnh và có cạnh quay về đỉnh đầu → tìm thấy chu trình
	if (count == n && a[u][ans[0]] == 1) {
		cout << "1\n";   // Có chu trình
		for (int x : ans) cout << x + 1 << " ";  // In đường đi (đổi về 1-based)
		cout << ans[0] + 1 << endl;             // Quay lại đỉnh đầu
		found = 1;      // Đánh dấu đã tìm thấy
		return;
	}

	// Thử các đỉnh kề
	FOR(v, n) {
		if (a[u][v] && !visited[v]) {   // Nếu có cạnh và chưa thăm
			visited[v] = 1;
			ans.push_back(v);
			Hamilton(v, count + 1);     // Gọi đệ quy
			ans.pop_back();             // Quay lui
			visited[v] = 0;
		}
	}
}

int main() {
	cin >> n;
	FOR(i, n) FOR(j, n) cin >> a[i][j]; // Nhập ma trận kề

	visited.assign(n, 0);
	ans.clear();

	ans.push_back(0);    // Bắt đầu từ đỉnh 0 (tức là đỉnh 1 trong output)
	visited[0] = 1;

	Hamilton(0, 1);      // Gọi hàm quay lui

	if (!found) cout << "0\n";  // Không có chu trình Hamilton
}
