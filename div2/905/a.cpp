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
  int n, k;
  string input_str;
  cin >> n;
  cin >> k;
  cin >> input_str;

  // vector<int> a(n);
  map<char, int> counts;
  // char x;
  for (char& c : input_str) {
    // x = getchar();
    // a[i] = x;
    counts[c]++;
  }

  int odd_count = 0;
  for ( const auto &[i, c] : counts ) {
    if (c % 2 == 1) {
      odd_count ++;
    }
  }

  if (k >= odd_count - 1) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }



}

int main()
{
  int t;
  cin >> t;
  while(t --) solve();

  return 0;
}