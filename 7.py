values = input()
ver, hor, X1, Y1, X2, Y2 = (int(horizontal) for horizontal in values.split())

diff1 = abs(int(X1) - int(X2))
diff2 = abs(int(Y1) - int(Y2))

if diff1 == diff2:
    print("NO")
else:
    print("YES")