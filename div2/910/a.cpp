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

  int a_count = 0;
  int b_count = 0;

  for (char& c : input_str) {
    if (c == 'A') {
      a_count ++;
    } else {
      b_count ++;
    }
  }

  k = k - b_count;
  if (k == 0) {
    cout << 0 << "\n";
  } else if (k > 0) {
    cout << 1 << "\n";
    for (int i = 0; i < n; i++) {
      if (input_str[i] == 'A') {
        k --;
      }
      if (k == 0){
        cout <<  (i + 1) << " B\n";
        return;
      }
    }
  } else {
    cout << 1 << "\n";
    for (int i = 0; i < n; i++) {
      if (input_str[i] == 'B') {
        k ++;
      }
      if (k == 0){
        cout <<  (i + 1) << " A\n";
        return;
      }
    }
  }

}

int main()
{
  int t;
  cin >> t;
  while(t --) solve();

  return 0;
}