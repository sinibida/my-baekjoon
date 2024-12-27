#include <algorithm>
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

  sort(begin(narr), begin(narr) + n);

  for (size_t i = 0; i < m; i++) {
    int& target = marr[i];
    int min = 0;
    int max = n - 1;
    int mid = (min + max) / 2;
    while (max > min) {
      //cout << min << " " << mid << "(" << narr[mid] << ")" << " " << max << endl;
      if (target < narr[mid]) {
        max = mid - 1;
      } else if (target > narr[mid]) {
        min = mid + 1;
      } else {
        break;
      }

      mid = (min + max) / 2;
    }

    bool found = narr[mid] == target;

    cout << found << '\n';
  }
}
