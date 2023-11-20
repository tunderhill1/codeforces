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
  int n, m, k;
  cin >> n;
  cin >> m;
  cin >> k;

  if ((n - 1) + (m - 1) > k) {
    cout << "NO\n";
    return;
  }
  if (((k - (n - 1) + (m - 1)) % 2) == 1) {
    cout << "NO\n";
    return;
  }

  cout << "YES\n";

  // horizontal bars
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < (m - 2); j ++) {
      if (j % 2 == 0) {
        cout << "R ";
      } else {
        cout << "B ";
      }
    }
    if (i == 0) {
      if ((m - 2) % 2 == 0) {
        cout << "R ";
      } else {
        cout << "B ";
      }
    } else {
      if ((m - 2 + n - 1 - 1) % 2 == 0) {
        cout << "B ";
      } else {
        cout << "R ";
      }

    }
    cout << "\n";
  }

  // vert bars
  // bool start_vert_red = (m - 1) % 2 == 0;
  for (int i = 0; i < (n - 1); i ++) {
    // if (i == 0) {
    //   if (j % 2 == 1) {
    //     cout << "R ";
    //   } else {
    //     cout << "B ";
    //   }
    // }
    for (int j = 0; j < (m - 2); j ++) {
      // if (i % 2 == 1) {
      //   cout << "R ";
      // } else {
      //   cout << "B ";
      // }
      cout << "B ";
    }
    if ((m - 2) % 2 != i % 2) {
      cout << "B ";
    } else {
      cout << "R ";
    }
    if ((m - 2) % 2 == i % 2) {
      cout << "B ";
    } else {
      cout << "R ";
    }
    cout << "\n";
  }
}

int main()
{
  int t;
  cin >> t;
  while(t --) solve();

  return 0;
}