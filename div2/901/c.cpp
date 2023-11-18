#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h> 
#include <map>

void solve() {
  int amount_left_tot;
  scanf("%d", &amount_left_tot);
  int num_of_people;
  scanf("%d", &num_of_people);

  double amount_left_pp = double(amount_left_tot) / num_of_people;
  long long cut_count = 0;
  amount_left_pp = amount_left_pp - int(amount_left_pp);
  amount_left_tot = amount_left_pp * num_of_people;

  for(int k = 1; k < 32 & amount_left_pp != 0.0; k ++) {
    // printf("%f\n", amount_left_pp);
    if (pow(2, -k) <= amount_left_pp) {
      int pieces = pow(2, k);
      if (num_of_people % pieces != 0) {
        printf("-1\n");
        return;
      } 

      int apples_to_cut = num_of_people / pieces; 
      amount_left_tot -= apples_to_cut;
      if (amount_left_tot < 0) {
        printf("-1\n");
        return;
      }
      cut_count += (pieces  - 1) * apples_to_cut;
      amount_left_pp -= pow(2, -k) ;
    }
  }

  printf("%lld\n", cut_count);
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