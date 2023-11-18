using namespace std;
#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <queue>
#include <unordered_set>
#include <random>

typedef pair<int, int> pii;
typedef pair<int, bool> pib;

int get_m(int i);

void solve() {
  int n, x;
  cin >> n;

  // gets input array and counts mapping 
  int mex = 0;
  vector<int> a(n);
  map<int, int> counts;
  for (int i = 0; i < n; i ++) {
    cin >> x;
    a[i] = x;
    counts[x]++;
  }

  // gets start_mex
  int start_mex = 0;
  for ( const auto &[i, c] : counts ) {
    if (i == start_mex) {
      start_mex ++;
    } else {
      break;
    }
  }

  // gets i_mex_to_m 
  // i_to_m(i, true) gets m for a[0:i] with starting mex of i + 1
  // i_to_m(i, false) gets m for a[0:i] with starting mex of start_mex

  map<pib, int> i_to_m;
  i_to_m[pib(0, true)] = counts[0] - 1;
  i_to_m[pib(0, false)] = (counts[0] - 1) * start_mex;
  get_m(start_mex);

  for (int i = 1; i < start_mex; i ++) {
    int without_i = i_to_m[pib(i - 1, false)];

    int with_i_and_next_mex = (i + 1) * (counts[i] - 1) + i_to_m[pib(i - 1, true)] + i;
    i_to_m[pib(i, true)] = with_i_and_next_mex < without_i ? with_i_and_next_mex : without_i;

    int with_i_and_start_mex = start_mex * (counts[i] - 1) + i_to_m[pib(i - 1, true)] + i;
    i_to_m[pib(i, false)] =  with_i_and_start_mex < without_i ? with_i_and_start_mex : without_i;

    // for (int mex = i + 1; mex <= start_mex; mex ++) {
    //   int with_i = mex * counts[i] + i_to_m[pib(i - 1, true)];
    //   int without_i = i_to_m[pib(i - 1, false)];
    //   i_to_m[pib(i, mex)] = with_i < without_i ? with_i : without_i;
    // }
  }

  cout << i_to_m[pib(start_mex - 1, true)] << "\n";
}

int get_m(int i, int last_mex) {
  int with_i = last_mex * (counts[i]) + get_mex(i - 1, i);
  int without_i = get_mex(i - 1, last_mex);
  return with_i < without_i ? with_i : without_i;
}

struct sub_a {
  int m;
  int curr_mex;
  
}

int main()
{
  int t;
  cin >> t;
  while(t --) solve();

  return 0;
}