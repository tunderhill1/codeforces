#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h> 
void solve() {
  int a, b, n;
  int x[100];
  
  // get inputs
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &n);
  for (int i = 0; i < n; i ++) {
    scanf("%d", &x[i]);
  }

  // calculate output
  long long max_time = b; // b is the init time
  for (int i = 0; i < n; i ++) {
    max_time += ((1 + x[i]) < a) ? x[i] : (a - 1);
  }

  // return output
  printf("%lld\n", max_time);
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