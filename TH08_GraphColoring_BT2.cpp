#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
vector<vector<int>> adjlist; // Danh sách kề (adjacency list)

// ====================== THUẬT TOÁN THAM LAM + SẮP THỨ TỰ ======================
void ToMau_ThamLam_SapThuTu() {
    vector<int> color(n, -1);      // color[i]: màu của đỉnh i (ban đầu chưa tô)
    vector<int> degree(n);         // degree[i]: bậc của đỉnh i
    for (int i = 0; i < n; i++) degree[i] = adjlist[i].size();

    //Sắp xếp các đỉnh theo bậc giảm dần
    vector<int> order(n);
    for (int i = 0; i < n; i++) order[i] = i;
    sort(order.begin(), order.end(), [&](int a, int b) {
        return degree[a] > degree[b]; // đỉnh có nhiều cạnh sẽ được tô trước
        });

    //Thuật toán tô màu tham lam
    for (int u : order) {
        vector<bool> used(n, false); // used[c] = true nếu màu c đã bị đỉnh kề dùng
        for (int v : adjlist[u]) {
            if (color[v] != -1)
                used[color[v]] = true;
        }

        // Gán cho đỉnh u màu nhỏ nhất chưa bị chiếm
        int c;
        for (c = 0; c < n; c++) {
            if (!used[c]) break;
        }
        color[u] = c;
    }

    int maxColor = *max_element(color.begin(), color.end());

    // Xuất kết quả
    cout << "\n--- To mau tham lam + sap thu tu ---\n";
    cout << "So mau su dung: " << maxColor + 1 << endl;
    for (int c = 0; c <= maxColor; c++) {
        cout << "Mau " << c + 1 << ": ";
        for (int i = 0; i < n; i++) {
            if (color[i] == c) cout << i + 1 << " ";
        }
        cout << endl;
    }
}

// ====================== THUẬT TOÁN TỐI ƯU (BACKTRACKING) ======================
int minColor = INT_MAX;      // số màu nhỏ nhất tìm được
vector<int> bestColor;       // lưu lại cách tô màu tối ưu

//  Kiểm tra đỉnh u có thể tô màu c hợp lệ không
bool HopLe(int u, int c, const vector<int>& color) {
    for (int v : adjlist[u])
        if (color[v] == c)
            return false; // có đỉnh kề cùng màu → không hợp lệ
    return true;
}

//  Hàm quay lui để thử các cách tô
void TryToColor(int u, vector<int>& color, int soMauDangDung) {
    if (u == n) { // tô xong tất cả đỉnh
        minColor = min(minColor, soMauDangDung);
        bestColor = color;
        return;
    }

    // Thử các màu hiện có
    for (int c = 0; c < soMauDangDung; c++) {
        if (HopLe(u, c, color)) {
            color[u] = c;
            TryToColor(u + 1, color, soMauDangDung);
            color[u] = -1;
        }
    }

    // Nếu chưa đủ → thêm màu mới
    if (soMauDangDung < minColor) {
        color[u] = soMauDangDung;
        TryToColor(u + 1, color, soMauDangDung + 1);
        color[u] = -1;
    }
}

//  Gọi thực hiện thuật toán tối ưu
void ToMau_ToiUu() {
    vector<int> color(n, -1);
    minColor = INT_MAX;
    TryToColor(0, color, 0);

    cout << "\n--- To mau toi uu ---\n";
    cout << "So mau nho nhat: " << minColor << endl;
    for (int c = 0; c < minColor; c++) {
        cout << "Mau " << c + 1 << ": ";
        for (int i = 0; i < n; i++) {
            if (bestColor[i] == c)
                cout << i + 1 << " ";
        }
        cout << endl;
    }
}

// ====================== HÀM CHÍNH ======================
int main() {
    cin >> n >> m;
    adjlist.assign(n, {});
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    ToMau_ThamLam_SapThuTu();
    ToMau_ToiUu();

    return 0;
}
