def returnAnswer(a):
  n = len(a)
  length = 0
  arr = []
  for i in range(0, n):
    arr.append(0)

  i = 1
  while(i<n):
    if(a[i] == a[length]):
      length += 1
      arr[i] = length
      i += 1
    else:
      if(length != 0):
        length = arr[length-1]
      else:
        arr[i] = 0
        i += 1

  return max(arr)

t = int(raw_input())
while t>0:
  t -= 1
  n = int(raw_input())
  a = list(map(int, raw_input().split()))
  print(returnAnswer(a))