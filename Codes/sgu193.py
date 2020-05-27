N = int(input())
r = N % 4
if r == 0:
    ans = N // 2 - 1
elif r == 2:
    ans = N // 2 - 2
else:
    ans = N // 2
print(ans)
