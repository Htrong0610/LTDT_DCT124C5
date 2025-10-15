#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAXN 100
#define FOR(i,n) for(int i=0;i<n;i++)

int n;                   // số đỉnh
int a[MAXN][MAXN];       // ma trận kề
vector<int> ans;         // lưu kết quả đường đi Euler
vector<int> visited;     // mảng đánh dấu đỉnh đã thăm
//Hàm DFS — kiểm tra liên thông
void dfs(int u) {
    visited[u] = 1;
    FOR(v, n) {
        if (a[u][v] && !visited[v]) {  // có cạnh u-v và v chưa thăm
            dfs(v);
        }
    }
}
//Kiểm tra tính liên thông
bool CheckLienThong() {
    visited.assign(n + 1, 0);
    int start = -1;

    // Tìm một đỉnh có cạnh để bắt đầu DFS
    FOR(i, n) {
        int dem = 0;
        FOR(j, n) dem += a[i][j];
        if (dem > 0) {
            start = i;
            break;
        }
    }
    if (start == -1) return false; // Không có cạnh nào → không liên thông

    dfs(start);

    // Kiểm tra các đỉnh có cạnh đều đã được thăm
    FOR(i, n) {
        int dem = 0;
        FOR(j, n) dem += a[i][j];
        if (dem > 0 && !visited[i]) return false;
    }
    return true;
}
//Kiểm tra điều kiện tồn tại chu trình Euler
bool CheckEuler() {
    if (!CheckLienThong()) return false;

    // Tất cả các đỉnh phải có bậc chẵn
    FOR(i, n) {
        int dem = 0;
        FOR(j, n) {
            if (a[i][j]) dem++;
        }
        if (dem % 2 != 0) return false;
    }
    return true;
}
//Tìm chu trình Euler bằng đệ quy
void DuongDi(int u) {
    FOR(v, n) {
        if (a[u][v]) {           // nếu có cạnh u-v
            a[u][v] = a[v][u] = 0;  // xóa cạnh đã đi
            DuongDi(v);             // đệ quy đi tiếp
        }
    }
    ans.push_back(u+1);           // thêm đỉnh vào kết quả (sau khi hết đường đi)
}

int main() {
    cin >> n;
    FOR(i, n) {
        FOR(j, n) cin >> a[i][j];
    }

    if (CheckEuler()) {
        DuongDi(0);  // bắt đầu từ đỉnh 0 (tức đỉnh 1)
        cout << "1\n";  // Có chu trình Euler
        reverse(ans.begin(), ans.end());
        for (int x : ans) cout << x << " ";
    }
    else cout << "0\n"; // Không có chu trình Euler
    return 0;
}