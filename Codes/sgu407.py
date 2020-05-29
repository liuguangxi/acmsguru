n, m = map(int, input().split())
if m == 0:
    print(1)
else:
    s0, sn = 1, 0
    for i in range(m - 1):
        s0, sn = sn, s0 * n + sn * 2
    print(sn)
