#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
  size_t n;
  cin >> n;
  vector<vector<int64_t>> dp(n, vector<int64_t>(n, 0));
  vector<string> grid(n);
  for (size_t i = 0; i < n; ++i) {
    cin >> grid[i];
  }
  bool vert_block = false;
  bool horz_block = false;
  for (size_t i = 0; i < n; ++i) {
    vert_block = (grid[i][0] == '*') ? true : vert_block;
    horz_block = (grid[0][i] == '*') ? true : horz_block;
    dp[i][0] = (vert_block) ? 0 : 1;
    dp[0][i] = (horz_block) ? 0 : 1;
  }
  for (size_t i = 1; i < n; ++i) {
    for (size_t j = 1; j < n; ++j) {
      if (grid[i][j] == '.') {
        dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
      }
    }
  }
  cout << dp[n - 1][n - 1] << endl;
}
