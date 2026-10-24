'''
# Read input from stdin and provide input before running code

name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''
N,M=map(int,raw_input().split())
inic=map(int,raw_input().split())
targ=map(int,raw_input().split())
done=False
try:
  good=targ.index(inic[0])
except ValueError:
  print -1
  done=True
goodOK=True  
for i in xrange(N):
  if targ[(i+good)%N]!=inic[i]:
  	goodOK=False
#if not goodOK:
#  print -1
#  done=True
act=0
for i in xrange(1,M+1):
  if not done:
    step=raw_input().split()
    if step[0]=='R':
  	  act=(act+int(step[1]))%N
    else:
  	  act=(act+N-int(step[1]))%N
    if good==act:
  	  print i
  	  done=True
if not done:
  print -1