#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int n, m;
int arr[100];
int x;
int ans;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;

  for (size_t i = 0; i < n; i++) {
    cin >> arr[i];
  }

  ans = 0;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = i + 1; j < n; j++) {
      for (size_t k = j + 1; k < n; k++) {
        x = arr[i] + arr[j] + arr[k];
        if (x <= m && x > ans) ans = x;
      }
    }
  }

  cout << ans << endl;
}
