import math

# if we cut the minimum, then we will have 2 cuts left
# then, we will need to cut the remaining two in half, otherwise their too big
# then only case we cut minimum and still be ac is if theyr'e all same size to start
# so cutting minimum doesn't need to be considered

# 2 cases consider for 3 cuts:
# cut B once and C twice:
# then B will need to be cut in half
# and C will need to be cut in to thirds


# cut C three times:
# then A == B and cut C in quorters

# for 2 cuts:
# either cut B and C in half
# or cut C in thirds

# for 1 cut:
# cut C in half

t = int(input())
for i in range(t):
  
  ts = list(map(int, input().split()))
  ts.sort()
  A = ts[0]
  B = ts[1]
  C = ts[2]
  if ( (A == B / 2 and A == C / 3)
    or (A == B and A == C / 4)
    or (A == B / 2 and A == C / 2)
    or (A == B and A == C / 3)
    or (A == B and A == C / 2)
    or (A == B and A == C)):
    print("YES")
  else:
    print("NO")
    
        
  