#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define MAX_LEN 10001

int n;
int q[MAX_LEN];
int q_a = 0;
int q_b = 0;
string cmd;
int arg;

int get_len() {
  if (q_b >= q_a) return q_b - q_a;
  else return MAX_LEN - (q_b - q_a);
}

bool empty() {
  return q_a == q_b;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;
  for (size_t i = 0; i < n; i++) {
    cin >> cmd;
    if (cmd == "push") {
      cin >> q[q_b++];
    } else if (cmd == "pop") {
      if (empty()) {
        cout << -1 << '\n';
      } else {
        cout << q[q_a++] << '\n';
      }
    } else if (cmd == "size") {
      cout << get_len() << '\n';
    } else if (cmd == "empty") {
      cout << empty() << '\n';
    } else if (cmd == "front") {
      if (empty()) {
        cout << -1 << '\n';
      } else {
        cout << q[q_a] << '\n';
      }
    } else if (cmd == "back") {
      if (empty()) {
        cout << -1 << '\n';
      } else {
        cout << q[q_b-1] << '\n';
      }
    }
  }
}
