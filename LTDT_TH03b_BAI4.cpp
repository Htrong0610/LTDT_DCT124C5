#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int n;                          // số đỉnh
vector<vector<int>> adjlist;    // danh sách kề

// DFS dạng iterative (dùng stack)
void dfs_iterative(int start) {
    vector<int> visited(n + 1, 0); // mảng đánh dấu đỉnh đã thăm, ban đầu = 0 (chưa thăm)
    stack<int> st;                 // stack để mô phỏng DFS

    st.push(start);                // đưa đỉnh bắt đầu vào stack
    visited[start] = 1;            // đánh dấu đã thăm

    while (!st.empty()) {          // khi stack còn phần tử
        int u = st.top();          // lấy đỉnh trên cùng stack
        st.pop();                  // xóa đỉnh đó khỏi stack

        cout << u << " ";          // in ra đỉnh đang duyệt

        // duyệt tất cả đỉnh kề với u
        for (int v : adjlist[u]) {
            if (!visited[v]) {     // nếu v chưa được thăm
                visited[v] = 1;    // đánh dấu đã thăm
                st.push(v);        // đưa v vào stack để duyệt tiếp
            }
        }
    }
}
