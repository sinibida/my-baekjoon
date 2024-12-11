#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string nh[500000];
string ns[500000];
string dbj[500000];

int n, m;
int nh_at;
int ns_at;
int dbj_len;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;

  for (size_t i = 0; i < n; i++) {
    cin >> nh[i];
  }
  for (size_t i = 0; i < m; i++) {
    cin >> ns[i];
  }

  sort(begin(nh), begin(nh) + n);
  sort(begin(ns), begin(ns) + m);

  ns_at = 0;
  nh_at = 0;
  while (true) {
    if (nh[nh_at] == ns[ns_at]) {
      dbj[dbj_len] = nh[nh_at];
      dbj_len++;
    }

    if (nh_at == n - 1 && ns_at == m - 1) {
      break;
    }

    if (nh_at == n - 1) {
      ns_at++;
    } else if (ns_at == m - 1) {
      nh_at++;
    } else {
      if (nh[nh_at] > ns[ns_at]) {
        ns_at++;
      } else {
        nh_at++;
      }
    }
  }

  cout << dbj_len << '\n';
  for (size_t i = 0; i < dbj_len; i++)
  {
    cout << dbj[i] << '\n';
  }
  
}
