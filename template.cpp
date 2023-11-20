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
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i ++) {
    cin >> a[i];
  }



  cout << output << "\n";
}

int main()
{
  int t;
  cin >> t;
  while(t --) solve();

  return 0;
}