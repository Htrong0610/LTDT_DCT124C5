#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

vector<vector<int>> adjlist;  // danh sách kề (adjlist[i] chứa các đỉnh kề với i+1)
int n;                        // số đỉnh
vector<int> visited;          // mảng đánh dấu đỉnh đã thăm
vector<int> ans;              // danh sách các đỉnh liên thông với target

// DFS đệ quy tìm thành phần liên thông bắt đầu từ target
void LienThong(int target) {
    visited[target] = 1;  // đánh dấu target đã thăm
    for (int v : adjlist[target - 1]) { // vì adjlist lưu từ 0, nên dùng target-1
        if (!visited[v]) {              // nếu đỉnh v chưa thăm
            ans.push_back(v);           // lưu vào kết quả
            LienThong(v);               // tiếp tục DFS từ v
        }
    }
}

int main() {
    int target;
    cin >> n >> target;  // nhập số đỉnh và đỉnh bắt đầu
    cin.ignore();

    visited.assign(n + 1, 0); // khởi tạo mảng visited = 0 (chưa thăm)

    // nhập danh sách kề
    for (int i = 0; i < n; i++) {
        vector<int> row;
        int x;
        string s;
        getline(cin, s);        // đọc cả dòng
        stringstream ss(s);     // tách số trong dòng
        while (ss >> x) row.push_back(x);
        adjlist.push_back(row);
    }

    // chạy DFS từ đỉnh target
    LienThong(target);
	cout<<ans.size()<<endl;
    // in các đỉnh liên thông với target
    for (int x : ans) cout << x << " ";
    return 0;
}
