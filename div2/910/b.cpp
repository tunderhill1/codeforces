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

  int last_ai = a[0];
  int op_count = 0;
  for(auto i = a.begin(); i < a.end(); i++)
	{
    if (*i < last_ai) {
      op_count ++;
      *i = *i - last_ai;
      a.insert(i, last_ai);
      i ++;
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