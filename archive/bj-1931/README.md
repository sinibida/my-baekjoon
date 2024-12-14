https://www.acmicpc.net/problem/1931

끝자락부터 DP?

```pseudo-code
n = input()
# sorted by end_time(asc)
arr: {start_time, end_time} = input()
# sorted by end_time(desc)
dp: {end_time, cnt} = vec![]

sort arr by end_time
for ap in arr:
  choice_a = (binary search for dp[x] where
    dp[x].end_time is 'right before' from ap.start_time
  ).cnt + 1
  choice_b = last(dp).cnt
  dp.push({ap.end_time, max(choice_a , choice_b)});

print(last(dp).cnt)
```
