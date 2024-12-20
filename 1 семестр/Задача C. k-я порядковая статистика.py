def solve_tender(n, k, s, offers):
    dp = [[float('inf')] * (s + 1) for _ in range(n + 1)]
    dp[0][0] = 0
    for i in range(1, n + 1):
        t_i, a_i, c_i = offers[i - 1]
        for j in range(s + 1):
            if j >= a_i:
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - a_i] + c_i)
            else:
                dp[i][j] = dp[i - 1][j]
    for j in range(s, s + 1):
        if dp[n][j] != float('inf'):
            return dp[n][j]
    return -1
n, k, s = map(int, input().split())
offers = []
for _ in range(n):
    t_i, a_i, c_i = map(int, input().split())
    offers.append((t_i, a_i, c_i))
result = solve_tender(n, k, s, offers)
print(result)
