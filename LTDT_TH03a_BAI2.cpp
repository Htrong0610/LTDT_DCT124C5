#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<sstream>
#include<algorithm> // để dùng reverse
using namespace std;

void DuongDi(vector<vector<int>> adjlist, int n, int first, int last) {
    vector<int> visited(n + 1, 0);   // đánh dấu đã thăm
    vector<int> parent(n + 1, -1);   // lưu cha để truy vết đường đi
    queue<int> pq;                   // hàng đợi BFS

    pq.push(first);
    visited[first] = 1;

    // BFS tìm đường đi
    while (!pq.empty()) {
        int u = pq.front();
        pq.pop();
        for (int v : adjlist[u - 1]) { // duyệt các đỉnh kề
            if (!visited[v]) {
                parent[v] = u;        // gán cha của v là u
                visited[v] = 1;
                pq.push(v);
            }
        }
    }

    // Nếu không tìm thấy đỉnh last
    if (!visited[last]) {
        cout << "khong co duong di" << endl;
        return;
    }

    // Truy vết đường đi từ last về first
    vector<int> ans;
    for (int cur = last; cur != -1; cur = parent[cur]) {
        ans.push_back(cur);
    }
    reverse(ans.begin(), ans.end()); // đảo ngược lại đúng thứ tự

    // In kết quả
    cout << ans.size() << endl;      
    for (int x : ans) cout << x << " ";
    cout << endl;
}

int main() {
    int n, first, last;
    cin >> n >> first >> last;
    cin.ignore();

    vector<vector<int>> adjlist;
    for (int i = 0; i < n; i++) {
        vector<int> row;
        int x;
        string s;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> x) row.push_back(x); // đọc danh sách kề cho mỗi đỉnh
        adjlist.push_back(row);
    }

    DuongDi(adjlist, n, first, last);
    return 0;
}
