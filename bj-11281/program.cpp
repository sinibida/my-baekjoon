// https://www.acmicpc.net/source/85699032

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define N_MAX 10000
#define M_MAX 100000
#define V_MAX (N_MAX * 2 + 1)
#define min(x, y) (x) < (y) ? (x) : (y)
#define NOT(x) (n + (x) - 1) % (n * 2) + 1

vector<vector<int> > sccs;
int num[V_MAX];
int low[V_MAX];
bool working[V_MAX];
stack<int> s;
int id;

int n, m;
vector<int> adj[V_MAX];

int inp_a, inp_b;

int group_cnt = 0;
int group_label[V_MAX];

void dfs(int from) {
  num[from] = id++;
  low[from] = num[from];

  s.push(from);
  working[from] = true;

  for (auto to : adj[from]) {
    if (!num[to]) {
      dfs(to);
      low[from] = min(low[from], low[to]);
    } else if (working[to]) {
      low[from] = min(low[from], num[to]);
    }
  }

  if (num[from] == low[from]) {
    vector<int> scc = vector<int>();

    int top;
    while (true) {
      top = s.top();
      scc.push_back(top);
      // sort(scc.begin(), scc.end());

      s.pop();
      working[top] = false;

      if (top == from) {
        break;
      }
    }

    sccs.push_back(scc);
  }
}

// bool sccs_comp(vector<int> v, vector<int> w) { return v.at(0) < w.at(0); }

void get_sccs() {
  for (int i = 1; i <= n * 2; i++) {
    num[i] = 0;
    low[i] = 0;
    working[i] = false;
    id = 1;
  }

  for (int i = 1; i <= n * 2; i++) {
    if (!num[i]) dfs(i);
  }

  // sort(sccs.begin(), sccs.end(), sccs_comp);
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

  get_sccs();

  // for (size_t i = 1; i <= n * 2; i++) {
  //   cout << i << "] ";
  //   for (auto x : adj[i]) cout << x << " ";
  //   cout << endl;
  // }

  // for (size_t i = 1; i <= n * 2; i++) {
  //   cout << i << ": " << order[i] << endl;
  // }

  // for (size_t i = 1; i <= n * 2; i++)
  // {
  //   cout << i << "] " << group_label[i] << endl;
  // }

  for (auto scc : sccs) {
    for (auto x : scc) {
      group_label[x] = group_cnt;
    }
    group_cnt++;
  }

  bool ok = true;
  for (size_t i = 1; i <= n; i++)
  {
    if (group_label[i] == group_label[i + n]) {
      ok = false;
      break;
    }
  }
  

  cout << (ok ? '1' : '0') << endl;
}
