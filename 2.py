N = int(input())
AElements = input().split()

A=[]
for i in range(0, len(AElements)):
    A.append(int(AElements[i]))
A.sort()

if N == 3:
    print(max(A[0] * A[2], max(A[0] * A[1], A[1] * A[2])))
elif N > 3:
    print(max(A[0] * A[1], A[-1] * A[-2]))
else:
    print(A[0] * A[1])