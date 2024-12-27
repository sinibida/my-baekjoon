n = int(input())


def g(xx, mag):
  x = max(xx - mag + 1, 0)
  global arr
  num = x % (mag * 10) // mag
  loop = x // (mag * 10)
  rem = 0 if mag == 1 else (x % mag)
  for i in range(10):
    arr[i] += loop * mag
  for i in range(num):
    arr[i] += mag
  arr[num] += rem

arr = [0] * 10

mm = 1
for _ in range(10):
  g(n, mm)
  mm *= 10


print(str(arr[9]), ' '.join(str(x) for x in arr[:9]))
