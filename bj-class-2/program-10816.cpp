#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int n, m;
int narr[500000], marr[500000];

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
    int min;
    int max;
    int mid;

    min = 0;
    max = n;
    mid = (min + max) / 2;
    while (min < max) {
      if (narr[mid] < target) {
        min = mid + 1;
      } else {
        max = mid;
      }

      mid = (min + max) / 2;
    }
    int left = min;

    min = 0;
    max = n;
    mid = (min + max) / 2;
    while (min < max) {
      if (narr[mid] > target) {
        max = mid;
      } else {
        min = mid + 1;
      }

      mid = (min + max) / 2;
    }
    int right = min - 1;

    int count = right - left + 1;

    // cout << left << ' ' << right << endl;
    cout << count << '\n';
  }
}
