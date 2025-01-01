#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const char dir[] = {'U', 'D', 'L', 'R'};

struct PathPos {
  int startX;
  int startY;
  int endX;
  int endY;
};

bool inBound(int x, int y, vector<vector<char>> *g) {
  int szX = static_cast<int>((*g).size());
  int szY = static_cast<int>((*g)[0].size());
  return (x >= 0 && x < szX && y >= 0 && y < szY);
}

void bfs(struct PathPos &p, vector<vector<char>> &g, vector<vector<int>> &d,
         vector<vector<pair<int, int>>> &parent) {
  int x = p.startX;
  int y = p.startY;
  queue<pair<int, int>> q;
  d[x][y] = 0;
  q.push(make_pair(x, y));
  while (!q.empty()) {
    x = q.front().first;
    y = q.front().second;
    q.pop();
    if (x == p.endX && y == p.endY) {
      break;
    } else {
      for (int k = 0; k < 4; ++k) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (inBound(nx, ny, &g) && g[nx][ny] != '#' && d[nx][ny] == -1) {
          d[nx][ny] = d[x][y] + 1;
          parent[nx][ny] = make_pair(x, y);
          q.push(make_pair(nx, ny));
        }
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> grid(n, vector<char>(m));
  struct PathPos p;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> grid[i][j];
      if (grid[i][j] == 'A') {
        p.startX = i;
        p.startY = j;
      } else if (grid[i][j] == 'B') {
        p.endX = i;
        p.endY = j;
      }
    }
  }
  vector<vector<int>> distance(n, vector<int>(m, -1));
  vector<vector<pair<int, int>>> parent(
      n, vector<pair<int, int>>(m, make_pair(-1, -1)));
  bfs(p, grid, distance, parent);
  if (distance[p.endX][p.endY] == -1) {
    cout << "NO\n";
  } else {
    cout << "YES\n" << distance[p.endX][p.endY] << endl;
    stack<char> path;
    int x = p.endX;
    int y = p.endY;
    while (!(x == p.startX && y == p.startY)) {
      int px = parent[x][y].first;
      int py = parent[x][y].second;
      for (int k = 0; k < 4; ++k) {
        if (px + dx[k] == x && py + dy[k] == y) {
          path.push(dir[k]);
          break;
        }
      }
      x = px;
      y = py;
    }
    while (!path.empty()) {
      cout << path.top();
      path.pop();
    }
    cout << endl;
  }
}
