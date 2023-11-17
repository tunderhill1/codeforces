import math

t = int(input())
for i in range(t):
  n = int(input())
  weights = list(map(int, input().split()))
  # weights.sort()
  # diff = 0
  max_possible = sum(weights)
  max_diff = 0
  for k in range(1, math.ceil(n/2) + 1):
    # print(k)
    if (n % k == 0):
      curr_tot = 0
      min_tot = max_possible
      max_tot = 0
      for i in range(0, n, k):
        curr_tot = sum(weights[i: i + k])
        min_tot = min(min_tot, curr_tot)
        max_tot = max(max_tot, curr_tot)
      max_diff = max(max_diff, max_tot - min_tot) 
      
      # print(weights[:k])
      # print(weights[n - k:])
      # diff = max(sum(weights[n - k:]) - sum(weights[:k]), diff)
      
  print (max_diff)