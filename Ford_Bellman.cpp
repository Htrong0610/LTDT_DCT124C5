#include<iostream>
#include<vector>
#include<climits>
using namespace std;
struct Vertex {
	int v, w;
	Vertex(int vertex, int weight) {
		v = vertex;
		w = weight;
	}
};
vector<vector<Vertex>>adjlist;
int n, m;
bool found = false;
void Ford_Bellman(int first) {
	vector<int> dist(n, INT_MAX);
	dist[first] = 0;
	for (int i = 0;i < n - 1;i++) {
		for (int u = 0;u < n;u++) {
			for (Vertex e : adjlist[u]) {
				int v = e.v;
				int w = e.w;
				if (dist[u] != INT_MAX && dist[u] + w < dist[v]) dist[v] = dist[u] + w;
			}
		}
	}
	for (int u = 0;u < n;u++) {
		for (Vertex e : adjlist[u]) {
			int v = e.v;
			int w = e.w;
			if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
				found = true;
				return;
			}
		}
	}
	for (int x : dist) cout << x << " ";
}
int main() {
	cin >> n >> m;
	adjlist.assign(n, {});
	int first;cin >> first;first--;
	for (int i = 0;i < m;i++) {
		int u, v, w;
		cin >> u >> v >> w;u--;v--;
		adjlist[u].push_back(Vertex(v - 1, w));
	}
	Ford_Bellman(first);
	return 0;
}