#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h> 
#include <map>

int a[200000];
double k[200000];

void solve() {
  int n;
  
  std::map<double, int> my_map;
  // get inputs
  scanf("%d", &n);
  for (int i = 0; i < n; i ++) {
    scanf("%d", &a[i]);
    k[i] = a[i] - log2(a[i]);
    my_map[k[i]] = -1;
    // printf("%d, %f\n", a[i], k[i]);
  }

  for (int i = 0; i < n; i ++) {
    my_map[k[i]] += 1;

    // for (int j = i + 1; j < n; j ++) {
    //   if (a[j] + k[i] == a[i] + k[j]) {
    //     // printf("aj: %d, ki: %f ai: %d kj: %f\n", a[j], k[i], a[i], k[j]);
    //     count++;
    //   }
    // }
  }
  long long count = 0;
  for (const auto& [key, c] : my_map) {
    count += (c / 2.0) * (c + 1) ;
  }

  // return output
  printf("%lld\n", count);
}

int main()
{
  int num_test_cases;
  scanf("%d", &num_test_cases);

  for (int test_case = 0; test_case < num_test_cases; test_case ++) {
    solve();
  }

  return 0;
}