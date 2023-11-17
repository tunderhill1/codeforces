import math

t = int(input())
for i in range(t):
  n = int(input())
  arr = list(map(int, input().split()))
  
  curr_sum = arr[0]
  biggest_sum = arr[0]
  
  for i in range(1, n):
    if (arr[i - 1] % 2 != arr[i] % 2 and curr_sum > 0):
      curr_sum += arr[i]
      # print(arr[i])
        
    else:
      curr_sum = arr[i]
      # print("here")
    
    if (curr_sum > biggest_sum):
      biggest_sum = curr_sum
      
  # if (curr_sum > biggest_sum):
  #   biggest_sum = curr_sum
  print(biggest_sum)