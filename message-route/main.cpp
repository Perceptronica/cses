#include <bits/stdc++.h>
using namespace std;

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
  vector<int> distance(n + 1, -1);
  vector<int> parent(n + 1, -1);
  queue<int> q;

  q.push(1);
  distance[1] = 1;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    if (x == n) {
      break;
    } else {
      for (int v : graph[x]) {
        if (distance[v] == -1) {
          q.push(v);
          distance[v] = distance[x] + 1;
          parent[v] = x;
        }
      }
    }
  }
  if (distance[n] == -1) {
    cout << "IMPOSSIBLE\n";
  } else {
    stack<int> path;
    int u = n;
    while (u != -1) {
      path.push(u);
      u = parent[u];
    }
    cout << distance[n] << "\n";
    while (!path.empty()) {
        cout << path.top() << ' ';
        path.pop();
    }
    cout << endl;
  }
}
