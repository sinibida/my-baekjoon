#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int n, m;
int arr[100];
int x;
int ans;
int cnt;

void fn(int from) {
  x += arr[from];
  cnt++;

  if (x > m) {
    x -= arr[from];
    return;
  }

  cout << from << "\t" << x << endl;
  ans = max(ans, x);

  for (size_t i = from + 1; i < n; i++) {
    fn(i);
  }

  x -= arr[from];
  cnt--;
}

void fn_start() {
  x = 0;
  cnt = 0;
  ans = -1;

  for (size_t i = 0; i < n; i++) {
    fn(i);
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;

  for (size_t i = 0; i < n; i++) {
    cin >> arr[i];
  }

  fn_start();

  cout << ans << endl;
}
