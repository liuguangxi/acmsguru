In(n) = 1 / (n + 1) - sum(k = 1, n \ 2, binomial(n, 2*k) * (2^(2*k-1)-1) * bernfrac(2*k) / (3*2^(2*k-1)-1) / (n-2*k+1))

{
N = 50;
print("In = [");
print("\"1/1\",");
for (n = 1, N,
    if (n < N, printf("\"%s\",\n", Str(In(n))), printf("\"%s\"\n", Str(In(n))));
);
print("]");
\\quit;
}
