"""Structured maximum-L2 cases with independently derived exact answers.
These formulas are certificates for these inputs only, not exhaustive proofs.
Generated inputs are separately checked by the native/l2 grammar before running.
"""
from cc_b83 import CAPS,line
def certificate(k,l2=True):
 n=CAPS[k][bool(l2)];ones=lambda z:line([1]*z);zeros=lambda z:line([0]*z)
 if k==138:return f'{n}\n'+zeros(n),zeros(n)+'0\n','Equal elements cause no strict selection-sort swap.'
 if k==139:return f'1\n{n}\n'+ones(n),f'{n}\n','At segment i the minimum velocity is 1; initial velocity must reach N.'
 if k==140:return f'{n}\n'+'a'*n+'\n','NO\n','Reversing a constant string cannot improve it.'
 if k==141:
  s='+'.join(['1']*((n+1)//2))+'\n';return s,s,'All summands are identical.'
 if k==142:return f'{n}\n'+line([100]*n),'YES\n','The even number of identical apples splits equally.'
 if k==143:return f'2 {n}\n1 1\n'+ones(n),'0\n','Put the only requested book on top; every lift costs zero.'
 if k==144:return '+u\n'+'u:a\n'*(n-1),f'{n-1}\n','One recipient receives each one-byte message.'
 if k==145:return f'{n} 1\n'+line(range(1,n+1)),'1\n','The first pronounced identifier is robot one.'
 if k==146:return f'{n} 1\n'+line(range(1,n+1))+'1 1\n',line(range(1,n+1)),'Only a self-swap is allowed.'
 if k==147:return f'{n}\n'+'A'*n+'\n','AA\n','Exactly one two-gram occurs.'
 if k==148:return f'{n}\n'+ones(n),ones(n),'No student has a strictly greater mark.'
 if k==150:return '9'*n+'\n1\n',f'{9*n}\n','Choose one of N digit positions and one of nine nonzero digits.'
 if k==151:return f'{n}\n'+line(range(1,n+1))+ones(n)+ones(n-1),f'{2*n-1}\n','N base points and N-1 ascending adjacency bonuses.'
 if k==152:return f'1\n{n} 1\n'+line(range(1,n+1)),f'{n-1}\n','One jump must connect the two endpoints.'
 if k==153:return f'{n} 1\n'+'0\n'*n,f'{n}\n','The complete single column is zero.'
 if k==154:return f'{n} 1\n'+'a'*n+'\n','1\n','One stage a costs one.'
 if k==155:return f'{n} 1 1\n'+line(range(1,n+1))+ones(n)+f'{n}\n','0\n','The chosen student is already the unique strongest.'
 if k==156:return f'1\n{n} 1 {n}\n'+ones(n),'1\n','Every day broadcasts one identical show.'
 if k==157:return f'{n} {n}\n'+'1 1\n'*n,f'{n}\n','All N teams share all N ranks.'
 if k==158:return f'{n}\nH'+'T'*(n-1)+'\n','0\n','Both species already occupy one block.'
 if k==159:return f'1 1 {n}\n','Yes\n','N shots of a unit-damage gun suffice.'
 if k==160:return f'{n}\n'+ones(n),'0\n','All buy and sell prices coincide.'
 if k==161:return f'{n} 1\n'+ones(n)+'1\n',f'{n+1}\n','One empty pair plus N matching singleton pairs.'
 if k==162:return f'{n} 2\n'+line([2]*n),f'{n*(n+1)//2}\n','Every nonempty interval has even sum.'
 if k==163:return '1\n1\n'+f'{n}\n'+''.join('1 2\n'if i%2==0 else'2 1\n'for i in range(n)),''.join('2\n'if i%2==0 else'1\n'for i in range(n)),'One element alternates between two values.'
 if k==164:return f'1 {n}\n{n}\n','1\n','The sole child must receive exactly K candies.'
 if k==165:return f'{n} 1\n'+ones(n)+'2\n','1\n','The sole even key opens any one odd chest.'
 if k==166:return f'{n}\n'+ones(n)+ones(n),f'{(n*(n+1)*(n+2)//6)%998244353}\n','With unit arrays, sum all interval lengths = N(N+1)(N+2)/6.'
 if k==167:return f'{n}\n'+ones(n),f'{n}\n','No unit kangaroo fits into another unit kangaroo.'
 if k==168:return f'{n}\n'+ones(n)+'1\n1\n','1\n','Only one girl can be matched.'
 if k==169:return f'{n}\n'+'0 0\n'*n,zeros(n-1).strip()+' 1\n','Only point zero is covered, by all N segments.'
 if k==170:return f'{n}\n'+ones(n),f'0 {n*(n+1)//2}\n','Every product is positive.'
 if k==171:return f'1 {n}\n1\n'+'1 1\n'*n,f'{n}\n','Every suggested singleton contributes one; choose all.'
 if k==172:
  even=n*n//4;return 'a'*n+'\n',f'{even} {n*(n+1)//2-even}\n','Every substring is good; count intervals by length parity.'
 if k==173:return f'{n}\n'+zeros(n)+zeros(n),zeros(n),'Every modular sum is zero.'
 if k==174:return f'1\n{n} 1\n'+ones(n),zeros(n),'Reflecting a constant unit array about its maximum yields zero.'
 if k==175:return f'1 1 {n}\n1\n1 1\n'+'2 1\n'*(n-1),'YES\n'*(n-1),'The sole friend is online before every query.'
 if k==176:return f'{n} 1\n1 {n} 1\n',f'{n*(n+1)//2}\n','All N servers are initially idle and requested once.'
 if k==177:return f'{n} 1\nb\n'+'a\n'*(n-1),'b\n','The sole b is unique in its row and column; repeated a cells are removed.'
 if k==178:return f'{n}\n'+ones(n),'0\n','Unit heights already meet the ordering condition.'
 if k==179:return f'{n}\n'+ones(n),'0\n','The XOR of any equal pair is zero.'
 if k==180:return f'{n} 1\n'+'.\n'*n,'0\n'*n,'There are no bombs.'
 if k==181:return 'A'*n+'\n'+'B'*n+'\n','0\n','The alphabets are disjoint.'
 if k==182:return f'{n}\n'+line(range(1,n+1))+'1\n10000\n','1\n','The unique largest integral ratio uses front size one.'
 if k==183:return f'{n}\n'+'a\n'*n,f'{n}\n','All names can join in one closed chronological chain.'
 if k==184:return f'1\n{n}\n',f'{n//2048+(n%2048).bit_count()}\n','Use maximum denomination for the quotient and binary representation for the remainder.'
 if k==185:return f'{n}\n'+line([180]*n),('YES\n'if n%2==0 else'NO\n'),'The parity of the number of half-turns determines the final angle.'
 if k==186:return f'{n}\n'+zeros(n-1)+zeros(n-1),'YES\n'+zeros(n),'The all-zero sequence satisfies both relations.'
 if k==187:return f'1\n{n}\n'+line(range(1,n+1)),'YES\n','Students are already in increasing clockwise order.'
 if k==188:return f'1 1 {n}\n','1\n','The interval contains only the unit divisor.'
 if k==189:return f'{n} 1\n1 1\n0\n',f'{2**(n-1)}\n','The one connected switch is fixed off; the other switches are free.'
 if k==190:
  hi=n+1;prime=bytearray(b'\1')*(hi+1);prime[:2]=b'\0\0'
  for i in range(2,__import__('math').isqrt(hi)+1):
   if prime[i]:prime[i*i:hi+1:i]=b'\0'*((hi-i*i)//i+1)
  return f'1\n1 {hi}\n',''.join(f'{i}\n'for i in range(2,hi+1)if prime[i]),'Independent sieve of Eratosthenes over the full extended interval.'
 if k==191:return f'1\n{n} 1\n'+'a '*n+'\n1 a\n','YES '*n+'\n','Each dictionary word appears in the one phrase.'
 if k==192:return f'1 1 {n}\n',line(range(1,n)),'Every positive x up to N-1 satisfies divisibility by one.'
 if k==193:return f'{n}\n'+zeros(n),f'{n}\n','All zero CV entries already form a valid subsequence.'
 if k==194:return 'a'*n+'\n'+'a'*n+'\n','Yes\n','Zero rotations matches identical strings.'
 if k==195:return f'{n}\n'+ones(n)+ones(n),f'{n+1}\n','Every path visits exactly N+1 unit cells.'
 if k==196:return f'1\n{n} 1 1 1\n',f'{n-1}\n','Every position has a lantern, and exactly position one is blocked.'
 if k==197:return f'1\n{n}\n'+ones(n),'0\n','No later price is strictly lower.'
 if k==198:return '1\na\n'+'a'*n+'\n','YES\n','The one-letter password occurs.'
 if k==199:return f'{n}\n'+ones(n),'1\n','Equal beauties cannot bridge positive differences in city indices.'
 if k==200:return f'1\n\n{n} 1\n1\n1\n',line(range(1,n+1)),'There is one source of temperature one at position one.'
 if k==201:return f'1\n0\n{n}\n'+'1 1 1\n'*n,'0\n'*n,'Every sum query reads the unchanged zero singleton.'
 if k==202:return '('*n+'\n','0 1\n','There is no closing parenthesis.'
 if k==203:return f'1 {n}\n1\n1\n',f'{n+1}\n','Each cookie consumes one unit of the sole ingredient.'
 if k==204:return f'{n}\n'+'0 1\n'*n,'0\n','Every zero already is a multiple of one.'
 if k==205:return f'1\n{n} 1\n'+ones(n),f'{n}\n','All pairs are good and an even number of unit elements can all be selected.'
 if k==206:return f'1\n{n} 2 2\n'+ones(n),f'{n*(n-1)//2}\n','Every pair has sum exactly two.'
 if k==207:return f'{n}\n1\n1 {n}\n1\n1\n',f'{n}\n','One update gives every box exactly one coin.'
 if k==208:return f'{n}\n'+ones(n),'0\n','The even number of unit cards splits evenly.'
 if k==209:return f'2 1\n0 1\n{n}\n'+'0 1\n'*n,'yes\n'*n,'The queried users share an edge.'
 if k==210:return f'2 {n}\n1 -1\n'+'1 2\n'*n,'1\n'*n,'The full two-element segment sums to zero.'
 if k==211:return f'{n} 1 1\n'+ones(n),'1\n','Exactly one unit singleton must be selected.'
 if k==212:return f'1 {n}\n'+'1 1\n'*n,''.join(f'{i}\n'for i in range(1,n+1)),'All notifications remain unread.'
 if k==213:return f'{n}\n'+line(range(1,n+1))+'1\n1 1\n','even\n','Reversing a singleton preserves the identity permutation.'
 if k==214:return f'{n}\n'+'1\n'*n,f'{n*(n-1)//2}\n','Every pair multiplies to integer one.'
 if k==215:
  a,b=1,1
  for _ in range(n):a,b=b,a+b
  return f'{n}\n',f'{a}\n','Arbitrary-precision recurrence directly evaluates the stated bases.'
 if k==216:return f'1 {n}\n'+'CLICK 1\n'*n,''.join(f'{1-i%2}\n'for i in range(n)),'The sole tweet alternates open and closed.'
 if k==217:return f'{n}\n'+ones(2*n),'0\n','Every pair of equal weights has zero instability.'
 if k==218:return f'{n}\n'+ones(n),'1\n','An attack kills another unit monster; the surviving unit remains one.'
 if k==219:return '1\n'+'a'*n+'\n','1\n','The even-length whole string is already balanced.'
 if k==220:return f'{n} 1 3\n',line([n]+[n-k for k in range(2,n-1)]+[0]),'The graph is a triangle attached to a path; separate pairs inside path 2..N and pairs incident to vertex 1.'
 raise KeyError(k)

def l3_native_certificate(k):
 """Independent closed-form L3 answer on certificate(k, False)'s structure."""
 n=CAPS[k][0];inp,raw,proof=certificate(k,False)
 scalar={139:2*n-1,143:1,144:0,151:n,153:0,155:1,161:n,162:0,164:n+1,165:0,171:0,179:(n*(n-1)//2)%1000000007,183:0,184:-1,196:n,197:n-1,206:0,214:0,219:n//2}
 if k in scalar:return inp,f'{scalar[k]}\n','Specialized mutated rule evaluated on the homogeneous structured native boundary; see the source certificate plus operator definition.'
 if k==169:return inp,line([0]*n),'Every right-open degenerate interval is empty.'
 if k==177:return inp,'\n','A one-column row cannot contain a repeated letter; no cell meets both repetition requirements.'
 if k==185:return inp,('YES\n'if n%2 else'NO\n'),'Each signed half-turn is congruent to 180; odd cardinality reaches the target.'
 if k==190:
  hi=n+1;prime=bytearray(b'\1')*(hi+1);prime[:2]=b'\0\0'
  for i in range(2,__import__('math').isqrt(hi)+1):
   if prime[i]:prime[i*i:hi+1:i]=b'\0'*((hi-i*i)//i+1)
  return inp,''.join(f'{i}\n'for i in range(2,hi+1)if not prime[i]),'Independent sieve, selecting composite integers and excluding one.'
 if k==192:return inp,'-1\n','Remainder one modulo one is impossible.'
 if k==209:return inp,'no\n'*n,'The two-vertex graph is bipartite; all walks between distinct vertices have odd length.'
 if k==210:return inp,'0\n'*n,'The full array sum is zero under every rearrangement, never one.'
 if k==215:
  a,b=1,2
  for _ in range(n):a,b=b,a+b
  return inp,f'{a}\n','Direct arbitrary-precision recurrence with mutated base f(1)=2.'
 if k==220:return inp,line([n-d for d in range(1,n)]),'A cost-two edge from vertex one to three equals the existing path length, so all pair distances remain their index differences.'
 return inp,raw,'The structured case is invariant under this operator change: '+proof
