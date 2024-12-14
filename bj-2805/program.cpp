#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
long long m;
long long arr[1000000];

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  for (size_t i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  sort(begin(arr), begin(arr) + n);

  long long cur_y = arr[n-1];
  long long cur_rem = m;
    // cout << cur_rem << " " << cur_y << endl;
  for (size_t i = 0; i < n; i++)
  {
    long long w = i + 1;
    long long max_h;
    if (i == n-1) {
      max_h = arr[0];
    } else {
      max_h = arr[n-1-i] - arr[n-2-i];
    }
    

    long long max_got = w * max_h;
    if (cur_rem <= max_got) {
      if (cur_rem % w == 0) {
        cur_y -= cur_rem / w;
      } else {
        cur_y -= cur_rem / w + 1;
      }
    // cout << cur_rem << " " << cur_y << endl;
      break;
    }

    cur_rem -= max_got;
    cur_y -= max_h;
    // cout << cur_rem << " " << cur_y << endl;
  }
  
  cout << cur_y << endl;
}
