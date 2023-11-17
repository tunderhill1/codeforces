import math

t = int(input())
for i in range(t):
  
  x_len, s_len = list(map(int, input().split()))
  x = input()
  s = input()
  min_appends = 0
  while(x_len < s_len):
    min_appends += 1
    x += x
    x_len *= 2
  if (s in x):
    print(min_appends)
  else:
    x += x
    if (s in x):
      print(min_appends + 1)
    else:
      print (-1)
