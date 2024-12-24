https://www.acmicpc.net/problem/11280

1. scc사용

`group-check` 배열을 활용해서 모순 발견

# 오답 노트

## fix 1

order min으로 재설정 -> working인 vertex에만 적용해야 함

반례
```
2 3
1 -2
1 2
1 1
```
=> 0

## * 2

using group_label instead

