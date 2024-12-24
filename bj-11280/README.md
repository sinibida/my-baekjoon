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
-1 -1
```
=> 0

## * 2

using group_label instead

## ...

기존 풀이([https://www.acmicpc.net/source/85699032](https://www.acmicpc.net/source/85699032))를 활용해 해결했다.

```cpp
stack<int> s;

// ...

if (num[from] == low[from]) {
  vector<int> scc = vector<int>();

  int top;
  while (true) {
    top = s.top();
    scc.push_back(top);
    // sort(scc.begin(), scc.end());

    s.pop();
    working[top] = false;

    if (top == from) {
      break;
    }
  }

  sccs.push_back(scc);
}
```
이러한 스캑을 활용하지 않으면 안 되는 듯 하다...

```cpp
if (id[cur] == order[cur]) {
  for (auto x: scc)
    working[x] = false;

  sccs.push_back(scc);
  vector<int>().swap(scc);
}
```

일반적인 벡터를 사용해보려고 했는데 안됨...

왜? 왜? 왜? 왜????
