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
  // i_mex_to_m(i, mex) gets m for a[0:i] with starting mex of mex
  map<pii, int> i_mex_to_m;
  for (int mex = 1; mex <= start_mex; mex ++) {
    i_mex_to_m[pii(0, mex)] = counts[0] * mex;
  }

  for (int i = 1; i < start_mex; i ++) {
    for (int mex = i + 1; mex <= start_mex; mex ++) {
      int with_i = mex * counts[i] + i_mex_to_m[pii(i - 1, i)];
      int without_i = i_mex_to_m[pii(i - 1, mex)];
      i_mex_to_m[pii(i, mex)] = with_i < without_i ? with_i : without_i;
    }
  }

  cout << i_mex_to_m[pii(start_mex - 1, start_mex)] - start_mex << "\n";
}

int main()
{
  int t;
  cin >> t;
  while(t --) solve();

  return 0;
}