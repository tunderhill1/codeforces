def sum_digits(x):
  tot = 0
  for c in str(x):
    tot += int(c)
  return tot


t = int(input())
for i in range(t):
  
  x, k = list(map(int, input().split()))
  while (sum_digits(x) % k != 0):
    # print("here")
    x += 1
  print(x)