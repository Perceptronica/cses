#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector<vector<int>> &g, vector<bool> &visited) {
  visited[v] = true;
  for (const auto &k : g[v]) {
    if (!visited[k]) {
      dfs(k, g, visited);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph(n + 1);
  int a, b;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  vector<bool> visited(n + 1, false);
  vector<int> components;

  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      components.push_back(i);
      dfs(i, graph, visited);
    }
  }
  int answer = components.size() - 1;
  cout << answer << endl;
  for (int i = 1; i <= answer; ++i) {
    cout << components[i - 1] << ' ' << components[i] << "\n";
  }
}
