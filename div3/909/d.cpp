#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h> 
 
int a[200000];
double k[200000];

void solve() {
  int n;
  
  // get inputs
  scanf("%d", &n);
  for (int i = 0; i < n; i ++) {
    scanf("%d", &a[i]);
    k[i] = log2(a[i]);
    // printf("%d, %f\n", a[i], k[i]);
  }

  int count = 0;
  for (int i = 0; i < n; i ++) {
    for (int j = i + 1; j < n; j ++) {
      if (a[j] + k[i] == a[i] + k[j]) {
        // printf("aj: %d, ki: %f ai: %d kj: %f\n", a[j], k[i], a[i], k[j]);
        count++;
      }
    }
  }

  // return output
  printf("%d\n", count);
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