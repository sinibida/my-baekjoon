#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int n;
int q[10000];
int s_len = 0;
string cmd;
int arg;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;
  for (size_t i = 0; i < n; i++) {
    cin >> cmd;
    if (cmd == "push") {
      cin >> q[s_len++];
    } else if (cmd == "pop") {
      if (s_len == 0) {
        cout << -1 << '\n';
      } else {
        cout << q[--s_len] << '\n';
      }
    } else if (cmd == "size") {
      cout << s_len << '\n';
    } else if (cmd == "empty") {
      cout << (s_len == 0) << '\n';
    } else if (cmd == "top") {
      if (s_len == 0) {
        cout << -1 << '\n';
      } else {
        cout << q[s_len - 1] << '\n';
      }
    }
  }
}
