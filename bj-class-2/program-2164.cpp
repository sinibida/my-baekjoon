#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int n;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;

  int nn = n;
  bool throw_first = true;
  int x = 1;
  int e = 1;
  while (nn > 1) {
    if (throw_first) {
      x += e;
    }

    e *= 2;

    if (nn % 2 == 0) {
      nn /= 2;
    } else {
      if (throw_first) {
        nn = nn / 2;
      } else {
        nn = (nn+1) / 2;
      }
      throw_first = !throw_first;
    }
  }

  cout << x << endl;
}
