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

  vector<int> a(n);
  for (int i = 0; i < n; i ++) {
    cin >> a[i];
  }

  int last_ai = a[n - 1];
  long long op_count = 0;
  for(int i = n - 1; i >= 0; i--)
	{
    if (a[i] > last_ai) {
      // k = round up of a[i] / last_ai
      int k = 1 + ((a[i] - 1) / last_ai);
      x = a[i] / k;
      op_count += k - 1;
      // x = a[i] / 2;
      // if (a[i] - x > last_ai) {
      //   x = a[i] - last_ai;
      // }
      a[i] = x;
      // a.insert(a.begin() + i, x);
      // i ++;
    }
    last_ai = a[i];
	}
  
  cout << op_count << "\n";
}

int main()
{
  int t;
  cin >> t;
  while(t --) solve();

  return 0;
}