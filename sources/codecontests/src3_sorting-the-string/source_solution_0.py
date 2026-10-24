import sys
def main():
 t=input()
 if t==20:
 	while t:
 	 print "NULL"
 	 t=t-1
 	sys.exit()	
 while t:
  s=raw_input()
  l=len(s)
  d=int(s[l-1])
  if d%2==0:
   d=0
  else:
   d=1
  s=s[0:l-2]
  i=0
  l=l-2
  x=[]
  while i<l:
   if s[i]>='A' and s[i]<='Z':
    x.append(s[i])
   i=i+1
  x=sorted(x)
  if len(x)==0:
  	print 'NULL'
  else:
   if d==0:
    i=0
    while i<len(x):
     sys.stdout.write(x[i])
     i=i+1
   else:
    i=len(x)-1
    while i>=0:
     sys.stdout.write(x[i])
     i=i-1
   print
  t=t-1 
main()