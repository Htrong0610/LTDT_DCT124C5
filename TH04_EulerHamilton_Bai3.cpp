#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 100
#define FOR(i, n) for (int i = 0; i < n; i++)

int n;
int a[MAXN][MAXN];
vector<int> euler, odd, visited;

void dfs(int u) {
    visited[u] = 1;
    FOR(v, n) {
        if (a[u][v] && !visited[v]) {
            dfs(v);
        }
    }
}

bool CheckLienThong() {
    visited.assign(n, 0);
    int start = -1;
    FOR(i, n) {
        int deg = 0;
        FOR(j, n) deg += a[i][j];
        if (deg > 0) {
            start = i;
            break;
        }
    }
    if (start == -1) return false; // không có cạnh nào
    dfs(start);
    FOR(i, n) {
        int deg = 0;
        FOR(j, n) deg += a[i][j];
        if (deg > 0 && !visited[i]) return false; // có đỉnh có cạnh mà chưa thăm
    }
    return true;
}

bool CheckNuaEuler() {
    odd.clear();
    if (!CheckLienThong()) return false;
    FOR(i, n) {
        int deg = 0;
        FOR(j, n) deg += a[i][j];
        if (deg % 2 != 0) odd.push_back(i);
    }
    // Nếu có 0 đỉnh bậc lẻ => chu trình Euler
    // Nếu có 2 đỉnh bậc lẻ => đường đi Euler
    return (odd.size() == 0 || odd.size() == 2);
}

void Euler(int u) {
    FOR(v, n) {
        if (a[u][v]) {
            a[u][v] = a[v][u] = 0; // xóa cạnh
            Euler(v);
        }
    }
    euler.push_back(u + 1);
}

int main() {
    cin >> n;
    FOR(i, n) {
        FOR(j, n) cin >> a[i][j];
    }

    if (!CheckNuaEuler()) {
        cout << "0\n"; // không có đường đi hoặc chu trình Euler
        return 0;
    }

    cout << "1\n"; // có

    int start;
    if (odd.size() == 2) start = odd[0]; // nếu có 2 đỉnh lẻ -> bắt đầu từ 1 trong 2 đỉnh đó
    else start = 0; // nếu không -> chọn đỉnh 0 (hoặc bất kỳ đỉnh có cạnh)

    Euler(start);

    reverse(euler.begin(), euler.end());
    for (int x : euler) cout << x << " ";
    cout << endl;
}
