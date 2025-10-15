#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> ans;                  // Kết quả chu trình Euler
vector<vector<int>> adjlist;      // Danh sách kề
int n;                            // Số đỉnh

void Euler(int x) {
    stack<int> st;                // Dùng stack thay cho đệ quy
    st.push(x);

    while (!st.empty()) {
        int u = st.top();

        if (!adjlist[u].empty()) {
            // Nếu còn cạnh kề: lấy đỉnh v cuối danh sách
            int v = adjlist[u].back();
            adjlist[u].pop_back();  // Xóa cạnh u-v khỏi u

            // Xóa cạnh u khỏi danh sách kề của v
            auto it = find(adjlist[v].begin(), adjlist[v].end(), u);
            if (it != adjlist[v].end())
                adjlist[v].erase(it);

            // Đi tiếp đến v
            st.push(v);
        }
        else {
            // Nếu không còn cạnh nào kề: thêm u vào kết quả
            st.pop();
            ans.push_back(u + 1);  // +1 vì in ra theo dạng 1-based
        }
    }

    reverse(ans.begin(), ans.end()); // Đảo ngược để có thứ tự đúng

    for (int x : ans)
        cout << x << " ";
}
