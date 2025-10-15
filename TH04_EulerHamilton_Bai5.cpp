#include<iostream>
#include<stack>
#include<vector>
#include<algorithm> // để dùng reverse
using namespace std;

#define MAXN 100
#define FOR(i,n) for(int i=0;i<n;i++)

int n;
int a[MAXN][MAXN];   // Ma trận kề
vector<int> ans;     // Lưu kết quả chu trình Euler

void Euler(int x) {
    stack<int> st;   // Stack để duyệt thay cho đệ quy
    st.push(x);

    while (!st.empty()) {
        int u = st.top();  // Đỉnh hiện tại
        int v;

        // Tìm đỉnh kề với u còn cạnh chưa đi
        for (v = 0; v < n; v++) {
            if (a[u][v]) break;
        }

        if (v == n) {
            // Không còn cạnh nào kề với u → thêm u vào kết quả
            ans.push_back(u + 1);  // +1 vì in theo 1-based
            st.pop();
        }
        else {
            // Còn cạnh (u, v): xóa cạnh và đi tiếp
            a[u][v] = a[v][u] = 0;  // Xóa cạnh (vô hướng)
            st.push(v);             // Đi đến v
        }
    }

    // Đảo ngược vì ta thêm đỉnh vào ans khi quay lui
    reverse(ans.begin(), ans.end());

    // In chu trình Euler
    for (int x : ans) cout << x << " ";
}
