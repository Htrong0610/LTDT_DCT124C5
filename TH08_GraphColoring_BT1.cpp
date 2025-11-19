#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<vector<int>> adjlist; // Danh sách kề
vector<int> color;           // Màu của mỗi đỉnh
vector<vector<int>> ans;     // Các nhóm đỉnh theo màu

void GraphColoring() {
    color.assign(n, 0);  // Gán tất cả đỉnh chưa có màu (0)

    // Gán màu cho từng đỉnh
    for (int u = 0; u < n; u++) {
        vector<bool> used(n + 1, false); // Đánh dấu màu đã dùng ở các đỉnh kề

        // Duyệt tất cả đỉnh kề với u
        for (int v : adjlist[u]) {
            if (color[v] != 0) used[color[v]] = true; // Màu này không thể dùng
        }

        // Tìm màu nhỏ nhất chưa dùng
        int c = 1;
        while (used[c]) c++;
        color[u] = c; // Gán màu cho u
    }

    // Tìm số màu tối đa đã dùng
    int maxColor = *max_element(color.begin(), color.end());
    cout << maxColor << endl;

    // Gom các đỉnh theo màu
    ans.assign(maxColor + 1, {});
    for (int i = 0; i < n; i++) {
        ans[color[i]].push_back(i);
    }

    // In ra từng nhóm đỉnh theo màu
    for (int c = 1; c <= maxColor; c++) {
        for (int v : ans[c]) cout << v + 1 << " ";
        cout << endl;
    }
}

int main() {
    cin >> n >> m;
    adjlist.assign(n, {});

    // Nhập danh sách cạnh
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    GraphColoring();
    return 0;
}
