import math

t = int(input())
for i in range(t):
  n = int(input())
  arr = list(map(int, input().split()))
  
  sums = arr[:]
  max_sums = arr[:]
  valid_start = 0
  
  for i in range(1, n):
    if (arr[i - 1] % 2 != arr[i] % 2):
      # print(arr[i])
      for j in range(valid_start, i):
        sums[j] += arr[i]
        max_sums[j] = max(sums[j], max_sums[j])
    else:
      # print("here")
      valid_start = i
      
  # print(sums)
  # print(max_sums)
  print(max(max_sums))