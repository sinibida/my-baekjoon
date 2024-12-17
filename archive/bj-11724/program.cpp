#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001];
queue<int> qu;
int ret;

int inp_a, inp_b;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;

  for (size_t i = 0; i < n; i++) {
    visited[i] = false;
  }

  for (size_t i = 0; i < m; i++) {
    cin >> inp_a >> inp_b;

    adj[inp_a].push_back(inp_b);
    adj[inp_b].push_back(inp_a);
  }

  ret = 0;

  for (size_t i = 1; i < n + 1; i++) {
    if (visited[i]) continue;

    // cout << "[" << i << "]" << endl;

    qu.push(i);
    visited[i] = true;

    int cur;

    while (!qu.empty()) {
      cur = qu.front();
      qu.pop();
      // cout << cur << endl;

      for (int next : adj[cur]) {
        if (visited[next]) continue;
        qu.push(next);
        visited[next] = true;
      }
    }

    ret++;
  }

  cout << ret << endl;
}
