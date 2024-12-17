#include <iostream>
#include <string>

using namespace std;

int n;
int a, b, temp;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;

  a = 0;
  b = 1;
  for (size_t i = 0; i < n; i++)
  {
    temp = (a + b) % 10007;
    a = b;
    b = temp;
  }
  
  cout << b << endl;
}
