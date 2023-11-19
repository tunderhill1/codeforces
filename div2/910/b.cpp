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
  int op_count = 0;
  for(auto i = a.end() - 1; i >= a.begin(); i--)
	{
    if (*i > last_ai) {
      op_count ++;
      // if (*i / 2 >= last_ai) {
      //   x = *i / 2;
      // } else {
      //   x = 
      // }
      x = *i / 2;
      *i = *i - x;
      auto i_to_insert = i;
      a.insert(i_to_insert, x);
      // i = i_to_restore_to;
    }
    last_ai = *i;
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