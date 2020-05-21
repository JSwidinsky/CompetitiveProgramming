#The approach here is to convert each partial quotient of the input into a fraction, then
# do +, -, *, and /, then convert back to continued fraction form
#Had to learn python for this one, which was pretty nasty

from fractions import Fraction as Frac

def getInput(n) :
  a = [int(x) for x in input().split()]

  ret = Frac(1, a[n-1])
  a.pop()

  for x in reversed(a) :
    ret = ret + x
    ret = 1 / ret

  return 1 / ret

#produces and prints the partial quotients of the fraction f
def convert(f) :
  while f != 0:
    print(int(f), end=' ')
    f = f - int(f)

    if f != 0:
      f = 1 / f

  print()




n, m = [int(c) for c in input().split()]

A = getInput(n)
B = getInput(m)

convert(A+B)
convert(A-B)
convert(A*B)
convert(A/B)

