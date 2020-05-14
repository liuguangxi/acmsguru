from math import gcd

n = int(input())
v = [0] * (n + 1)
for i in range(n):
	v[gcd(n, i)] += 1
ans = 0
for i in range(1, n + 1):
	c = v[i]
	if c > 0:
		ans += 2**i * c
ans //= n
print(ans)
