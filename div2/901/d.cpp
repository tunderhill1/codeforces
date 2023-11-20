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
#include <climits>

typedef pair<int, int> pii;

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

  if (counts[0] == 0) {
    cout << 0 << "\n";
    return;
  }


  // gets start_mex
  int start_mex = 0;
  int curr_count = counts[0] + 1;
  bool erase = false;
  int to_erase = -1;
  for ( const auto &[i, c] : counts ) {
    if (erase) {
      counts.erase(to_erase);
    }
    if (i == start_mex) {
      start_mex ++;
      if (c >= curr_count) {
        to_erase = i;
        erase = true;
      } else {
        erase = false;
        curr_count = c;
      }
    } else {
      if (c >= curr_count) {
        counts.erase(i);
      }
      break;
    }
  }

  // gets i_mex_to_m 
  // i_mex_to_m(i, mex) gets m for a[0:i] with starting mex of mex 
  // and is your first turn

  // base case: i = 0
  map<pii, int> i_mex_to_m;
  for (int mex = 0; mex <= start_mex; mex ++) {
    i_mex_to_m[pii(0, mex)] = (counts[0] - 1) * mex;
  }

  // fill table
  int prev_i = 0;
  int lowest_m = i_mex_to_m[pii(0, start_mex)];
  counts.erase(0);
  for (const auto &[i, c] : counts ) {
    if (i < start_mex) {
      // time improvement: can just iterate over is which are in counts
      for (int mex = i + 1; mex <= start_mex; mex ++) {
        int with_i = mex * (c - 1) + i_mex_to_m[pii(prev_i, i)] + i;
        int without_i = i_mex_to_m[pii(prev_i, mex)];
        i_mex_to_m[pii(i, mex)] = with_i < without_i ? with_i : without_i;
      }
      if (i_mex_to_m[pii(i, start_mex)] < lowest_m) {
        lowest_m = i_mex_to_m[pii(i, start_mex)];
      }
      int prev_i = i;
    }
  }

  // subtract start_mex, because remove first, before point penalty
  cout << lowest_m << "\n";
}

int main()
{
  int t;
  cin >> t;
  while(t --) solve();

  return 0;
}