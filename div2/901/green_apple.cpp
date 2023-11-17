#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h> 
#include <set>

void solve() {
  int amount_left, num_of_people;
  
  scanf("%d", &amount_left);
  scanf("%d", &num_of_people);

  double amount_per_person = amount_left / num_of_people;

  if (num_of_people % 2 == 1 && amount_left % num_of_people != 0) {
    printf("%d\n", (-1));
    return;
  }
  
  std::set<int> seen;
  long cut_count = 0;
  const double double_num_of_people = (double) num_of_people;
  while (amount_left % num_of_people != 0) {
    if (seen.contains(amount_left)) {
      printf("%d\n", (-1));
      return;
    }
    seen.insert(amount_left);

    amount_left = amount_left % num_of_people;
    int shift = ceil(log(double_num_of_people / amount_left));

    cut_count += (amount_left << shift) - amount_left; 
    amount_left = amount_left << shift;

    // if (cut_count > 100) {
    //   printf("Too much");
    //   return;
    // }
  }

  printf("%ld\n", cut_count);
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