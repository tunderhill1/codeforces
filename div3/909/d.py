import math

t = int(input())
for i in range(t):
  n = int(input())
  a = list(map(int, input().split()))
  # b = [1 << i for i in a]
  b = [i - math.log(i, 2) for i in a]
  dictionary = {}
  # print(dictionary)
  
  for i in range(n):
    if (b[i] in dictionary):
      dictionary[b[i]] += 1
    else:
      dictionary[b[i]] = 0
    # target = a[i] + b[j] - b[i]
    # for j in range(i + 1, n):
    #   # if (a[i] * b[j] == a[j] * b[i]):
    #   #   count += 1
    #   if (a[j] == target):
    #     count += 1
  
  # print(dictionary)
  count = 0
  for c in dictionary.values():
    count += int((c / 2) * (c + 1))
    
  
  print(count)