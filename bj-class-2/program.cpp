#include <iostream>
#include <string>

using namespace std;

int n, m;
int narr[100000], marr[100000];

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;
  for (size_t i = 0; i < n; i++) {
    cin >> narr[i];
  }

  cin >> m;
  for (size_t i = 0; i < m; i++) {
    cin >> marr[i];
  }

  for (size_t i = 0; i < m; i++) {
    int found = false;
    for (size_t j = 0; j < n; j++) {
      if (marr[i] == narr[j]) {
        found = true;
        break;
      }
    }

    cout << found << '\n';
  }
}
