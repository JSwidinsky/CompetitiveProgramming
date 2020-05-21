from fractions import Fraction as frac

n = input()
n = int(n)

A = []
for i in range(n) :
  A.append(input())

curr = frac(0)
p = 0
val = frac(4, 5)
for x in A:
  x = int(x)
  curr += (x * val**p)
  p += 1

print("{0:.8f}".format(float(curr*frac(1,5))))

average = frac(0)
for i in range(n) :
  p = 0
  ans = frac(0)
  for j in range(n) :
    if j != i :
      ans += (int(A[j]) * val**p)
      p += 1 

  average += frac(1,5)*ans

print ("{0:.8f}".format(float(average/n)))
