#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

vector<vector<int>> adjlist; // danh sách kề biểu diễn đồ thị
vector<int> visited;         // mảng đánh dấu đỉnh đã thăm
vector<int> ans;             // lưu đường đi Euler
int n = 5;                   // số đỉnh (mặc định 5 trong bài)
#define FOR(i,n) for(int i=0;i<n;i++)

// DFS kiểm tra tính liên thông
void dfs(int u) {
    visited[u] = 1;
    for (int v : adjlist[u]) {
        if (!visited[v]) dfs(v);
    }
}

// Kiểm tra xem đồ thị có liên thông hay không
bool CheckLienThong() {
    visited.assign(n, 0);
    int start = -1;

    // Tìm một đỉnh có cạnh để bắt đầu DFS
    FOR(i, n) {
        if (!adjlist[i].empty()) {
            start = i;
            break;
        }
    }
    if (start == -1) return false; // không có cạnh nào

    dfs(start);

    // nếu còn đỉnh có cạnh mà chưa thăm => không liên thông
    FOR(i, n) {
        if (!adjlist[i].empty() && !visited[i]) return false;
    }
    return true;
}

// Kiểm tra điều kiện tồn tại chu trình Euler
bool CheckEuler() {
    if (!CheckLienThong()) return false;

    // tất cả các đỉnh phải có bậc chẵn
    FOR(i, n) {
        if (adjlist[i].size() % 2 != 0) return false;
    }
    return true;
}

// Thuật toán Hierholzer — Tìm đường đi Euler
void DuongDi(int x) {
    vector<vector<int>> g = adjlist;  // tạo bản sao để không phá dữ liệu gốc
    stack<int> st;
    st.push(x);

    while (!st.empty()) {
        int u = st.top();
        if (!g[u].empty()) {
            int v = g[u].back();      // lấy 1 đỉnh kề v
            g[u].pop_back();          // xóa cạnh u-v
            g[v].erase(find(g[v].begin(), g[v].end(), u)); // xóa cạnh ngược lại
            st.push(v);               // đi tiếp
        }
        else {
            st.pop();                 // không còn cạnh → quay lại
            ans.push_back(u + 1);     // thêm đỉnh vào đường đi
        }
    }

    reverse(ans.begin(), ans.end()); // đảo ngược kết quả (do thêm ngược)
    for (int x : ans) cout << x << " ";
}

// Hàm chính
int main() {
    adjlist.assign(n, {}); // khởi tạo danh sách kề rỗng
    int m;
    cin >> m;              // số quân domino (số cạnh)

    // nhập m cạnh (m quân domino)
    FOR(i, m) {
        int u, v;
        cin >> u >> v;
        adjlist[u - 1].push_back(v - 1);
        adjlist[v - 1].push_back(u - 1);
    }

    // kiểm tra và in kết quả
    if (CheckEuler()) cout << "1\n";  // có chu trình Euler (xếp kín)
    else cout << "0\n";               // không có chu trình Euler

    DuongDi(0); // tìm đường đi bắt đầu từ đỉnh 0 (đỉnh 1)
    return 0;
}
