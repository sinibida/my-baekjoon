#include <iostream>
#include <string>

using namespace std;

int n;
char str[1000000];

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;
  cin >> str;

  int ans;
  int offset;
  for (offset = 1; offset <= n; offset++) {
    bool ok = true;
    for (size_t i = 0; i < n-offset; i++)
    {
      if (str[i] != str[i+offset]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans = offset;
      break;
    }
  }
  cout << ans << endl;
}
