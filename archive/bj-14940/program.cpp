#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Point {
  int x;
  int y;
};

int n, m;
int map[1000][1000];
Point start;
// -1: not visited
int calc[1000][1000];
queue<Point> qu;

void try_visit(Point point, int xoff, int yoff) {
  Point cur = point;
  cur.x += xoff;
  cur.y += yoff;
  if (cur.x < 0 || cur.x >= m || cur.y < 0 || cur.y >= n) {
    return;
  }
  if (calc[cur.y][cur.x] != -1) {
    return;
  }
  if (map[cur.y][cur.x] == 0) {
    return;
  }

  qu.push(cur);
  calc[cur.y][cur.x] = calc[point.y][point.x] + 1;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      cin >> map[i][j];
      calc[i][j] = -1;
      if (map[i][j] == 2) {
        start.x = j;
        start.y = i;
        calc[i][j] = 0;
      }
    }
  }

  qu.push(start);

  Point cur;

  while (!qu.empty()) {
    cur = qu.front();
    qu.pop();
    // cout << cur << endl;

    try_visit(cur, 1, 0);
    try_visit(cur, -1, 0);
    try_visit(cur, 0, 1);
    try_visit(cur, 0, -1);
  }

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      int& val = calc[i][j];
      if (val == -1 && map[i][j] == 0) {
        cout << 0;
      } else {
        cout << val;
      }
      cout << ' ';
    }
    cout << '\n';
  }
}
