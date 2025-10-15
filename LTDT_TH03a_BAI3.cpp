#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<sstream>
using namespace std;

// Hàm liệt kê và đếm các thành phần liên thông trong đồ thị
void LietKeLienThong(vector<vector<int>> adjlist, int n) {
    vector<int> visited(n + 1, 0); // visited[i] = 1 nếu đỉnh i đã được thăm
    int soThanhPhan = 0;           // Biến đếm số thành phần liên thông
    vector<vector<int>> cacThanhPhan; // Lưu các thành phần liên thông

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) { // Nếu đỉnh i chưa được thăm thì bắt đầu BFS từ i
            soThanhPhan++; // Tăng số thành phần liên thông
            vector<int> ans; 
            queue<int> pq;
            pq.push(i);
            visited[i] = 1;

            // BFS
            while (!pq.empty()) {
                int u = pq.front();
                pq.pop();
                ans.push_back(u);

                // Duyệt các đỉnh kề với u
                for (int v : adjlist[u - 1]) {
                    if (!visited[v]) {
                        visited[v] = 1;
                        pq.push(v);
                    }
                }
            }
            cacThanhPhan.push_back(ans);
        }
    }

    // In số thành phần liên thông ở dòng đầu
    cout  << soThanhPhan << endl;

    // In ra các thành phần
    for (auto tp : cacThanhPhan) {
        for (int x : tp) cout << x << " ";
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n; // Nhập số đỉnh
    cin.ignore();

    vector<vector<int>> adjlist;

    // Nhập danh sách kề từ input
    for (int i = 0; i < n; i++) {
        vector<int> row;
        int x;
        string s;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> x) row.push_back(x);
        adjlist.push_back(row);
    }

    LietKeLienThong(adjlist, n);
    return 0;
}
