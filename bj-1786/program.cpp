#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX_LEN 1000001

char t[MAX_LEN];
int t_len;
char p[MAX_LEN];
int p_len;
int pat[MAX_LEN];

int calc[MAX_LEN];

int t_at;
int p_at;
int cnt;
vector<int> positions;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin.getline(t, MAX_LEN);
  t_len = cin.gcount() - 1;
  cin.getline(p, MAX_LEN);
  p_len = cin.gcount() - 1;

  // cout << t_len << endl << p_len << endl;

  pat[0] = -1;
  int pat_cur = -1;
  int pat_next = -1;
  for (size_t i = 1; i < p_len; i++) {
    if (p[i] == p[0]) {
      pat_next = i;
    }
    if (p[i] != p[i - pat_next]) {
      pat_next = -1;
    }

    if (pat_cur == -1) {
      if (p[i] == p[0]) {
        pat_cur = i;
        pat[i] = pat_cur;
      } else {
        pat[i] = -1;
      }
    } else {
      if (p[i] == p[i - pat_cur]) {
        pat[i] = pat_cur;
      } else {
        if (p[i] == p[i - pat_next]) {
          pat_cur = pat_next;
          pat[i] = pat_cur;
        } else {
          pat_cur = -1;
          pat[i] = -1;
        }
      }
    }
  }
  pat[p_len] = -1;  // For success

#ifndef ONLINE_JUDGE
  for (size_t i = 0; i <= p_len; i++) {
    cout << pat[i] << " ";
  }
  cout << endl;
#endif

  calc[0] = 0;
  for (size_t i = 1; i <= p_len; i++) {
    if (pat[i] == -1 && pat[i - 1] != -1) {
      calc[i] = pat[i - 1];
    } else if (pat[i] != -1) {
      calc[i] = calc[i - pat[i]] + pat[i];
    } else {
      calc[i] = i;
    }
  }
  for (size_t i = 0; i < p_len; i++) {
    if (p[i] == p[0]) calc[i]++;
  }

#ifndef ONLINE_JUDGE
  for (size_t i = 0; i <= p_len; i++) {
    cout << calc[i] << " ";
  }
  cout << endl;
#endif

  t_at = 0;
  p_at = 0;
  while (t_at < t_len) {
    if (t[t_at] == p[p_at]) {
      t_at++;
      p_at++;
      if (p_at == p_len) {
        cnt++;
        positions.push_back(t_at - p_len + 1);
        p_at -= calc[p_len];
      }
    } else {
      p_at -= calc[p_at];
      if (p_at == -1) {
        t_at++;
        p_at++;
      }
    }
  }

  cout << cnt << '\n';
  for (auto x : positions) {
    cout << x << " ";
  }
  cout << '\n';
}
