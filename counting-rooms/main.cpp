#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

bool inBound(int x, int y, int n, int m) {
  return (x >= 0 && x < n && y >= 0 && y < m);
}

void dfs(size_t i, size_t j, vector<string> &grid,
         vector<vector<bool>> &visited) {
  visited[i][j] = true;
  for (int k = 0; k < 4; ++k) {
    int nx = i + dx[k];
    int ny = j + dy[k];
    if (inBound(nx, ny, static_cast<int>(grid.size()),
                static_cast<int>(grid[0].size())) &&
        grid[nx][ny] == '.' && !visited[nx][ny]) {
      dfs(nx, ny, grid, visited);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }
  uint32_t answer = 0;
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '.' && !visited[i][j]) {
        dfs(i, j, grid, visited);
        ++answer;
      }
    }
  }
  cout << answer << endl;
}
