#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h> 
#include <limits.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

void solve() {
  int n, m, k;
  int a[50];
  int b[50];
  
  // get inputs
  scanf("%d", &n);
  scanf("%d", &m);
  scanf("%d", &k);

  long long final_sum_of_a = 0;
  int max_a = INT_MIN;
  int max_b = INT_MIN;
  int min_a = INT_MAX;
  int min_b = INT_MAX;
  for (int i = 0; i < n; i ++) {
    scanf("%d", &a[i]);
    final_sum_of_a += a[i];
    max_a = MAX(max_a, a[i]);
    min_a = MIN(min_a, a[i]);
  }

  for (int i = 0; i < m; i ++) {
    scanf("%d", &b[i]);
    max_b = MAX(max_b, b[i]);
    min_b = MIN(min_b, b[i]);
  }

  // printf("final_sum_of_a: %lld\n", final_sum_of_a);
  // first move of a
  if (max_b > min_a) {
    // printf("here");
    final_sum_of_a += max_b - min_a;
  }

  
  // printf("final_sum_of_a: %lld", final_sum_of_a);
  // b makes final move
  if (k % 2 == 0) { 
    // printf("here2");
    final_sum_of_a += MIN(min_a, min_b) - MAX(max_a, max_b);
  } 

  // return output
  printf("%lld\n", final_sum_of_a);
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