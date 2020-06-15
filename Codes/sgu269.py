n, k = map(int, input().split())
b = list(map(int, input().split()))
if k > n:
    print(0)
else:
    b.sort()
    f = [[0 for i in range(k + 1)] for j in range(n + 1)]
    f[n][1] = b[n - 1] - k + 1
    for i in range(n - 1, 0, -1):
        f[i][1] = b[i - 1] - k + 1 + f[i + 1][1]
    for m in range(2, k + 1):
        for i in range(n - m + 1, 0, -1):
            f[i][m] = (b[i - 1] - k + m) * f[i + 1][m - 1] + f[i + 1][m]
    print(f[1][k])
