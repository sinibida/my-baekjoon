#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

typedef pair<int, string> p;

int n;
p dat[100000];
p* map[100000];
p* temp[100000];

int inp_a;
string inp_b;

bool comp(p* a, p* b) { return a->first < b->first; }

void merge(int from, int to) {
  if (to - from <= 1) {
    return;
  }

  int mid = (from + to) / 2;
  merge(from, mid);
  merge(mid, to);

  int x = from;
  int y = mid;
  int z = from;
  while (x < mid && y < to) {
    if (comp(map[y], map[x])) {
      temp[z] = map[y];
      z++;
      y++;
    } else {
      temp[z] = map[x];
      z++;
      x++;
    }
  }
  while (x < mid) {
    temp[z] = map[x];
    z++;
    x++;
  }
  while (y < n) {
    temp[z] = map[y];
    z++;
    y++;
  }

  z = from;
  while (z < to) {
    map[z] = temp[z];
    z++;
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;

  for (size_t i = 0; i < n; i++) {
    cin >> inp_a >> inp_b;
    dat[i].first = inp_a;
    dat[i].second = inp_b;
    map[i] = dat + i;
  }

  merge(0, n);

  for (size_t i = 0; i < n; i++) {
    cout << map[i]->first << " " << map[i]->second << '\n';
  }
}
