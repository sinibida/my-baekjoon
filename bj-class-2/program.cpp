#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int n, m;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;

  int nn = n;
  int mm = m;
  int temp;
  while (mm > 0) {
    temp = mm;
    mm = nn % mm;
    nn = temp;
  }

  int gcd = nn;
  int lcm = n / gcd * m;
  cout << gcd << endl << lcm << endl;
}
