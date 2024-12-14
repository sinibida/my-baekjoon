#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef unsigned int uint;

struct Appointment {
  uint start_time;
  uint end_time;
};

struct DP {
  uint end_time;
  uint cnt;
};

int n;
Appointment arr[100000];
vector<DP> dp;

uint inp_st;
uint inp_et;

uint choice_a;
uint choice_b;

int ap_comp(Appointment& a, Appointment& b) {
  return a.end_time < b.end_time;
}

uint bin_search(uint start_time) {
  if (dp.size() == 0) {
    return 0;
  }

  int min = 0;
  int max = dp.size() - 1;  // inclusive
  int mid = (min + max + 1) / 2;
  while (max > min) {
    if (dp.at(mid).end_time < start_time) {
      min = mid;
    } else {
      max = mid - 1;
    }
    mid = (min + max + 1) / 2;
  }

  return dp.at(mid).cnt;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;
  for (size_t i = 0; i < n; i++) {
    cin >> inp_st >> inp_et;
    arr[i].start_time = inp_st;
    arr[i].end_time = inp_et;
  }

  sort(begin(arr), begin(arr)+n, ap_comp);
  for (size_t i = 0; i < n; i++) {
    Appointment& ap = arr[i];

    if (dp.size() == 0) {
      DP item = {ap.end_time, 1};
      dp.push_back(item);
    }

    choice_a = bin_search(ap.start_time) + 1;
    choice_b = (*--dp.end()).cnt;
    DP item = {ap.end_time, max(choice_a, choice_b)};
    dp.push_back(item);
  }

  cout << (*--dp.end()).cnt << '\n';
}
