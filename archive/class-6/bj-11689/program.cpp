#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

int64_t n;
int64_t nn;
int64_t nrt;
list<int64_t> factors;
list<int64_t>::iterator at;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;

  nrt = ceil(sqrt(n));
  at = factors.begin();
  for (int64_t i = 1; i <= nrt; i++) {
    if (n % i == 0) {
      factors.insert(at, i);
      if (i == nrt) break;
      factors.insert(at, n / i);
      at--;
    }
  }
  factors.erase(factors.begin()); // 1

  at = factors.begin();
  while (at != factors.end()) {
    auto att = at;
    att++;
    while (att != factors.end()) {
      if (*att % *at == 0)
        att = factors.erase(att);
      else
        att++;
    }
    at++;
  }

#ifndef ONLINE_JUDGE
  // Factors
  for (auto x : factors) {
    cout << x << " ";
  }
  cout << endl;
  cout << factors.size();
  cout << endl;
#endif

  nn = n;
  for (auto x : factors) {
    nn = nn - (nn + (x - 2)) / x;
  }

  cout << nn << endl;
}
