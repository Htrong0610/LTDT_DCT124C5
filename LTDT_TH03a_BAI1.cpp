#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

void LienThong(vector<vector<int>> adjlist, int n, int target) {
    vector<int> visited(n + 1, 0); // mảng đánh dấu đỉnh đã thăm
    vector<int> ans;               // lưu các đỉnh liên thông với target
    queue<int> pq;                 // hàng đợi BFS

    visited[target] = 1;           // đánh dấu đỉnh target đã thăm
    pq.push(target);               // đưa target vào hàng đợi

    while (!pq.empty()) {          // lặp cho đến khi hết đỉnh trong hàng đợi
        int u = pq.front();        // lấy phần tử đầu hàng đợi
        pq.pop();
        for (int v : adjlist[u - 1]) { // duyệt tất cả đỉnh kề với u
            if (!visited[v]) {         // nếu chưa thăm
                visited[v] = 1;        // đánh dấu đã thăm
                ans.push_back(v);      // thêm vào kết quả
                pq.push(v);            // đưa v vào hàng đợi
            }
        }
    }

    // In số lượng và các đỉnh liên thông
    cout << ans.size() << endl;
    for (int x : ans) cout << x << " ";
}

int main() {
    int n, target;
    cin >> n >> target;
    cin.ignore();
    vector<vector<int>> adjlist;

    // Đọc danh sách kề từ input
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        int x;
        vector<int> row;
        while (ss >> x) row.push_back(x);
        adjlist.push_back(row);
    }

    // Tìm thành phần liên thông chứa đỉnh target
    LienThong(adjlist, n, target);
    return 0;
}
