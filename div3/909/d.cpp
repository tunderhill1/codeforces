#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h> 
 
int a[2 * 10 ^ 5];
int b[2 * 10 ^ 5];

void solve() {
  int n;
  
  // get inputs
  scanf("%d", &n);
  for (int i = 0; i < n; i ++) {
    scanf("%d", &a[i]);
    b[i] = log2(a[i]);
  }

  int count = 0;
  for (int i = 0; i < n; i ++) {
    for (int j = i + 1; j < n; j ++) {
      if (a[j] + b[i] == a[i] + b[j]) {
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