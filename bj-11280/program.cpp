#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define N_MAX 10000
#define M_MAX 100000

#define NOT(x) (n + (x) - 1) % (n * 2) + 1

int n, m;
vector<int> adj[N_MAX * 2 + 1];
int order[N_MAX * 2 + 1];
int cur_order = 0;
vector<int> group;
vector<vector<int> > groups;

bool working[N_MAX * 2 + 1];
bool visited[N_MAX * 2 + 1];

int ret;

int inp_a, inp_b;

bool group_check[N_MAX * 2 + 1];

void dfs(int cur) {
  visited[cur] = true;
  working[cur] = true;

  int original_order = cur_order;
  order[cur] = cur_order;
  int min_order = cur_order;
  cur_order++;

  for (int next : adj[cur]) {
    if (!visited[next]) {
      dfs(next);
    }
    order[cur] = min(order[next], order[cur]);
  }

  group.push_back(cur);

  //cout << "a " << cur << " " << original_order << " " << order[cur] << endl;
  if (original_order == order[cur]) {
    groups.push_back(group);
    group.clear();
  }

  working[cur] = false;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;

  for (size_t i = 0; i < m; i++) {
    cin >> inp_a >> inp_b;

    if (inp_a < 0) inp_a = -inp_a + n;
    if (inp_b < 0) inp_b = -inp_b + n;

    adj[NOT(inp_a)].push_back(inp_b);
    adj[NOT(inp_b)].push_back(inp_a);
  }
  
  for (size_t i = 1; i <= n * 2; i++) {
    visited[i] = false;
    working[i] = false;
  }

  for (size_t i = 1; i <= n * 2; i++) {
    if (visited[i]) continue;

    // cout << "[" << i << "]" << endl;

    dfs(i);

    ret++;
  }

  // for (size_t i = 1; i <= n * 2; i++) {
  //   for (auto x : adj[i]) cout << x << " ";
  //   cout << endl;
  // }

  // for (size_t i = 1; i <= n * 2; i++) {
  //   cout << i << ": " << order[i] << endl;
  // }

  // for (auto group : groups) {
  //   for (auto x : group) cout << x << " ";
  //   cout << endl;
  // }

  bool ok = true;
  for (vector<int> group : groups) {
    for (auto x : group) {
      int at = x;
      if (at > n) at = NOT(at);

      if (group_check[at]) {
        ok = false;
        break;
      }
      group_check[at] = true;
    }

    if (!ok) {
      break;
    }

    for (auto x : group) {
      int at = x;
      if (at > n) at = NOT(at);

      group_check[at] = false;
    }
  }

  cout << (ok ? '1' : '0') << endl;
}
