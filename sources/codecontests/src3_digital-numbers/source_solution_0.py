digits=[6,2,5,5,4,5,6,3,7,6]
valids=[{} for i in xrange(11)]
st0={}
for i in xrange(10):
  valids[1][1<<i]=[digits[i],1]
for l in xrange(2,11):
  for k in xrange(10):
    for prev in valids[l-1]:
      if prev&(1<<k)==0:
        act=prev|(1<<k)
        prevdata=valids[l-1][prev]
        if k==0:
          st0[act]=st0[act]+prevdata[1] if act in st0 else prevdata[1]
        if act in valids[l]:
          valids[l][act][1]+=prevdata[1]
        else:
          valids[l][act]=[prevdata[0]+digits[k],prevdata[1]]
T=int(raw_input())
for iCase in xrange(T):
  L,M=map(int,raw_input().split())
  M/=7
  if L==0: # correction needed because of wrong judgement
    L=10
  total=0
  for i in xrange(1,L+1):
    for num in valids[i]:
      if valids[i][num][0]<=M:
        total+=valids[i][num][1]
        if num in st0:
          total-=st0[num]
  print total