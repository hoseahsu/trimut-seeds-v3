def isprime(number):
 if number==1:
  return 0
 if number==2:
  return 1
 if number%2==0:
  return 0
 N=long(number**0.5)+1
 for i in range(3,N,2):
  if number%i==0:
   return 0
 return 1

for t in range(input()):
 n=long(raw_input())
 summ=0
 while n>0:
  summ=summ+n%10
  n=n/10
 if isprime(summ):
  print "YES"
 else:
  print "NO"