"""22 source-distinct tasks. Weak and L3 share constraints; L2 changes scale only.

Source-original statements/tests are immutable under sources/codecontests.
All answer algorithms here were authored locally; acceptance requires the
separate source audit and the formal isolated verification report.
"""
from pathlib import Path
import json

# key, source row, title, original relation, mutated relation, weak/strong scale,
# proof and independence argument. The literal validator defines all bounds.
DATA=[
('ocean',914,'Great Ocean View','Count indices with height at least every earlier height; the first counts.','Require height strictly greater than every earlier height.',20,200000,'A prefix maximum suffices; the oracle compares each index with every predecessor. Strong n extends the public limit20.'),
('zeros',916,'Zero-Sum Ranges','Count nonempty contiguous subarrays with sum0.','Count nonempty contiguous subarrays with strictly positive sum.',40,200000,'Zero sums correspond to equal prefix sums; positive sums correspond to strictly increasing prefix pairs, counted by a Fenwick tree. Oracle sums every interval.'),
('knapsack',936,'0-1 Knapsack Problem II','Maximize selected value with total weight<=W, allowing empty selection.','Require an odd number of selected items; output -1 if no such feasible subset exists.',12,40,'DP stores minimum weight for each value and cardinality parity; the oracle enumerates subsets without this decomposition.'),
('intersection',937,'Set Intersection','Print intersection of the two strictly increasing sets, in ascending order.','Print their symmetric difference in ascending order.',40,200000,'Two-pointer merge classifies equal/unequal elements. Oracle performs independent membership scans.'),
('digits',958,'Correct Solution?','Decide whether second decimal string is the minimum digit permutation of the first without leading zeros; 0 is allowed.','Decide whether it is the maximum digit permutation without leading zeros.',8,24,'Sorting plus moving the first nonzero digit gives the minimum; descending order gives maximum. Oracle enumerates unique digit permutations. L2 extends decimal-string length beyond original numeric bound.'),
('counting',960,'Yet Another Counting Problem','For each interval[l,r], count x satisfying ((x%a)%b)!=((x%b)%a).','Count x satisfying equality instead.',100,10**12,'For L=lcm(a,b), residues from max(a,b) to L-1 satisfy inequality. Periodic prefix counts answer queries; the oracle evaluates both nested remainders for every integer.'),
('records',969,'I_love_%username%','Count strict record highs or lows, excluding the first contest.','Count strict record highs only, excluding the first contest.',40,200000,'Maintain prefix extrema; oracle compares all predecessor scores. L2 extends public n<=1000.'),
('company',987,'Kefa and Company','Maximize sum of nonnegative friendship factors among friends with wealth spread<d.','Allow wealth spread<=d.',12,40,'After wealth sorting, an optimal group can include every point in its feasible interval. Two pointers maximize the sum. Independent oracle enumerates all subsets.'),
('monk',1014,'The Old Monk','For two nonincreasing arrays, maximize j-i over0<=i<=j<n with B[j]>=A[i], or0 if none.','Require B[j]>A[i].',40,100000,'Monotonicity permits two pointers; oracle enumerates all index pairs. Dataset statement says i,j<n-1 in one line; sample and source tests establish intended full range0..n-1, explicitly repaired here.'),
('flat',1015,'Flat Subsequence','Longest subsequence whose adjacent absolute differences are<=K.','Require adjacent absolute differences<K.',40,300000,'DP for each ending value queries the allowed value interval with a segment tree. Oracle uses predecessor-index DP; no segment tree or value compression.'),
('seven',1020,'755','Count positive integers<=N using only3,5,7 and containing all three digits.','Require at least two distinct digits among3,5,7.',6000,999999999,'Enumerating the ternary digit tree visits only candidate numerals; oracle scans every integer and checks its digits.'),
('playlist',1055,'Playlist','Choose at most k songs to maximize total length times minimum beauty.','Use maximum beauty instead of minimum beauty.',12,40,'Sort by descending/raw or ascending/mutant beauty and force the current song as the extremal-beauty anchor. Maintain k-1 largest previous lengths. Oracle enumerates every subset.'),
('ayoub',1063,"Ayoub's function",'Among length-n binary strings with exactly m ones, maximize number of substrings containing a one.','Minimize that number.',12,50,'Subtract zero-only substrings. Convexity balances zero runs for maximum; one zero block minimizes. Oracle enumerates all allowed binary strings and directly counts every substring.'),
('agency',1071,'Advertising Agency','Count k-element subsets with maximum sum, modulo1000000007.','Count k-element subsets with minimum sum, modulo1000000007.',12,50,'Only the multiplicity at the sorted cutoff is ambiguous; a binomial coefficient counts choices. Oracle enumerates k-subsets and compares their sums.'),
('power',1099,"Arpa's hard exam",'Print1378^n modulo10.','Print1378^n modulo100 as an integer without padding.',1000,1000000000,'Binary exponentiation works for either modulus. Oracle performs n individual multiplications.'),
('histogram',1146,'Largest Rectangle in a Histogram','Maximum rectangle area under unit-width histogram bars.','Maximum square area under the same histogram, with axis-parallel sides.',40,100000,'A monotone stack gives each limiting bar its maximal span. Rectangle score=h*w; square score=min(h,w)^2. Oracle scans all intervals.'),
('cars',1148,'CARVANS','Count cars with no earlier car of lower maximum speed; all speeds are distinct.','Count cars with at most one earlier car of lower maximum speed (one slower predecessor may be bypassed).',40,100000,'Raw needs prefix minimum; new predicate needs second-smallest predecessor. Oracle counts every earlier lower speed. L2 extends public n<=10000. Distinct speeds are preserved.'),
('elevator',1157,'The Fair Nut and Elevator','Minimize total daily electricity over elevator rest floor x. Each resident makes the specified two return-to-x journeys.','Maximize electricity over x instead.',40,200000,'Per-resident cost2*a_i*(|x-i|+i-1+x-1) is nondecreasing in x. Endpoints1/n optimize; oracle enumerates every rest floor and resident floor. L2 extends public n<=100.'),
('parity',1165,'Minimize The Integer','Lexicographically minimize the digit string using adjacent swaps of different parity, preserving length and leading zeros.','Lexicographically maximize it under the same swaps.',8,1000000,'Within each parity the order is invariant; every merge of the two subsequences is reachable. Greedy extreme-head merge is optimal. Oracle explores the adjacent-swap state graph; slow raw uses quadratic front erasure.'),
('tiles',1170,'New Theatre Square','Minimum cost exact cover of white cells using1x1 and horizontal1x2 tiles; black cells cannot be covered.','Maximum cost exact cover under the same rules.',10,80,'Each white run is independent. Choose pairs iff their price improves the objective over two singles. Oracle recursively enumerates every tiling without memoization.'),
('cypher',1180,'Non-Secret Cypher','Count subarrays in which some value occurs at least k times.','Require some value to occur strictly more than k times.',40,400000,'Sliding window maintains all frequencies below threshold and counts valid starting positions. Oracle maintains counts for every interval.'),
('pipeline',1184,'Pipeline','Using at most one splitter of each output count2..k, minimize splitters needed for exactly n terminal pipes, or-1.','Maximize splitters used for exactly n terminal pipes, or-1.',12,60,'Choosing c distinct increments from1..k-1 realizes every integer between c(c+1)/2 and c(2k-c-1)/2. Binary search first feasible c for minimum and last feasible c for maximum. Oracle enumerates splitter subsets.'),
]
# Exact mapping is generated separately from immutable imported metadata, not guessed platform IDs.
_names={914:'p03072 AtCoder Beginner Contest 124 - Great Ocean View',916:'p03363 AtCoder Grand Contest 023 - Zero-Sum Ranges',936:'p02319 0-1 Knapsack Problem II',937:'p02464 Set Intersection',958:'12_B. Correct Solution?',960:'1342_C. Yet Another Counting Problem',969:'155_A. I_love_%username%',987:'580_B. Kefa and Company',1014:'the-old-monk',1015:'p02537 ACL Beginner Contest - Flat Subsequence',1020:'p03212 AtCoder Beginner Contest 114 - 755',1055:'1140_C. Playlist',1063:"1301_C. Ayoub's function",1071:'1475_E. Advertising Agency',1099:'742_A. Arpa’s hard exam and Mehrdad’s naive cheat',1146:'p02328 Largest Rectangle in a Histogram',1148:'carvans',1157:'1084_A. The Fair Nut and Elevator',1165:'1251_C. Minimize The Integer',1170:'1359_B. New Theatre Square',1180:'190_D. Non-Secret Cypher',1184:'287_B. Pipeline'}
_platform={914:5,916:5,936:6,937:6,958:2,960:2,969:2,987:2,1014:3,1015:5,1020:5,1055:2,1063:2,1071:2,1099:2,1146:6,1148:1,1157:2,1165:2,1170:2,1180:2,1184:2}
RECIPES={}
for key,row,title,raw,new,weak,strong,proof in DATA:
    name=_names[row];source=('codeforces:'+name.split('.')[0])if _platform[row]==2 else f'codecontests:{_platform[row]}:{name}'
    def p(file,mut):return {'path':'../assets/root_batch2/'+file+'.cpp','args':[key,str(mut)]}
    RECIPES['root2_'+key]={'source_id':source,'source_row_index':row,'source_dataset':'CodeContests','source_name':name,'original_source_identity':name,'title':title,'key':key,
       'raw_fast':p('fast',0),'raw_oracle':p('oracle',0),'l3_fast':p('fast',1),'l3_oracle':p('oracle',1),'slow_baseline':p('slow'if key=='parity'else'oracle',0),
       'budget_seconds':0.5,'small_timeout_seconds':3,'memory_mb':512,'independent_oracles':True,
       'spec':{'raw_relation':raw,'l3_relation':new,'weak_scale_limit':weak,'strong_scale_limit':strong,'l3_bounds':'identical to weak; full literal constraints in validate_input','proof_sketch':proof},
       'baseline_kind':'standardized_weak; original retained separately','l2_changed_fields':'only indicated scale limit; see literal validator','oracle_independence_note':proof,
       'l3_operator':new,'source_equivalence_review':'pending separate source-test audit'}

def line(a):return ' '.join(map(str,a))+'\n'
def arr(a):return str(len(a))+'\n'+line(a)
BOUNDARY={
 'ocean':['3\n5 5 4\n','1\n100\n'], 'zeros':['3\n0 1 -1\n','1\n0\n'],
 'knapsack':['2 10\n2 1\n3 1\n','1 1\n5 2\n'], 'intersection':['2\n1 2\n2\n2 3\n','1\n0\n1\n0\n'],
 'digits':['1033\n1033\n','0\n0\n','123\n00321\n'], 'counting':['1\n4 6 2\n1 10\n12 12\n','1\n1 1 1\n1 1\n'],
 'records':['3\n3 2 4\n','1\n0\n'], 'company':['2 5\n0 3\n5 4\n','1 1\n0 0\n'],
 'monk':['1\n3\n5 5 5\n5 5 5\n','1\n1\n1\n1\n'], 'flat':['3 0\n5 5 5\n','1 0\n0\n'],
 'seven':['35\n','357\n','1\n'], 'playlist':['2 2\n5 1\n2 4\n','1 1\n1 1\n'],
 'ayoub':['3\n3 1\n4 0\n4 4\n'], 'agency':['2\n3 1\n1 1 2\n1 1\n1\n'], 'power':['1\n','0\n','2\n'],
 'histogram':['3\n1 1 1\n','1\n0\n','3\n3 3 3\n'], 'cars':['1\n3\n1 2 3\n','1\n1\n9\n'],
 'elevator':['2\n1 1\n','1\n0\n'], 'parity':['1\n12\n','1\n000\n','1\n246432\n'],
 'tiles':['1\n1 2 10 1\n..\n','1\n1 1 1 2\n*\n'], 'cypher':['3 2\n1 1 2\n','1 1\n1\n'],
 'pipeline':['4 5\n','1 2\n','8 4\n'],
}

def generate(key,r,mode):
    big=mode=='stress';weak=mode=='weak'
    if key in ('ocean','records','elevator','histogram'):
        n={'ocean':200000,'records':200000,'elevator':200000,'histogram':100000}[key]if big else (20 if weak else r.randint(1,18))
        a=[7]*n if big else[r.randint(1,20)for _ in range(n)]
        return arr(a)
    if key=='zeros':return arr([0]*200000 if big else[r.randint(-5,5)for _ in range(40 if weak else r.randint(1,25))])
    if key=='knapsack':
        n=40 if big else 12 if weak else r.randint(1,11);return f'{n} {1000000 if big else r.randint(1,60)}\n'+''.join(line((r.randint(1,100),r.randint(1,20)))for _ in range(n))
    if key=='intersection':
        n=200000 if big else 40 if weak else r.randint(1,20);m=n if big else r.randint(1,20)
        a=list(range(n))if big else sorted(r.sample(range(100),n));b=list(range(n,2*n))if big else sorted(r.sample(range(100),m));return arr(a)+arr(b)
    if key=='digits':
        a='123456789012345678901234'if big else str(r.randint(1,9999999));s=sorted(a);z=next(i for i,c in enumerate(s)if c!='0');s[0],s[z]=s[z],s[0];b=''.join(s)if r.randrange(2)else''.join(reversed(sorted(a)));return a+'\n'+b+'\n'
    if key=='counting':
        a,b=(199,200)if big else(r.randint(1,12),r.randint(1,12));q=1 if big else 4;return f'1\n{a} {b} {q}\n'+('1 1000000000000\n'if big else''.join(line((r.randint(1,40),r.randint(41,100)))for _ in range(q)))
    if key=='company':
        n=40 if big else 12 if weak else r.randint(1,11);return f'{n} {r.randint(1,20)}\n'+''.join(line((r.randint(0,30),r.randint(0,20)))for _ in range(n))
    if key=='monk':
        n=100000 if big else 40 if weak else r.randint(1,25);a=[5]*n if big else sorted([r.randint(1,15)for _ in range(n)],reverse=True);b=a if big else sorted([r.randint(1,15)for _ in range(n)],reverse=True);return f'1\n{n}\n'+line(a)+line(b)
    if key=='flat':
        n=300000 if big else 40 if weak else r.randint(1,25);k=2 if big else r.randint(0,10);a=[5]*n if big else[r.randint(0,20)for _ in range(n)];return f'{n} {k}\n'+line(a)
    if key=='seven':return str(999999999 if big else 6000 if weak else r.randint(1,6000))+'\n'
    if key=='playlist':
        n=40 if big else 12 if weak else r.randint(1,11);k=n//2 if big else r.randint(1,n);return f'{n} {k}\n'+''.join(line((r.randint(1,20),r.randint(1,20)))for _ in range(n))
    if key=='ayoub':
        n=50 if big else 12 if weak else r.randint(1,11);return f'1\n{n} {n//2 if big or weak else r.randint(0,n)}\n'
    if key=='agency':
        n=50 if big else 12 if weak else r.randint(1,11);return f'1\n{n} {n//2 if big or weak else r.randint(1,n)}\n'+line([r.randint(1,n)for _ in range(n)])
    if key=='power':return str(1000000000 if big else 1000 if weak else r.randint(0,1000))+'\n'
    if key=='cars':
        n=100000 if big else 40 if weak else r.randint(1,25);return '1\n'+arr(r.sample(range(1,2147483647),n))
    if key=='parity':return '1\n'+('12'*500000 if big else''.join(r.choice('0123456789')for _ in range(8 if weak else r.randint(1,8))))+'\n'
    if key=='tiles':
        n=1 if big else r.randint(1,3);m=80 if big else 10 if weak else r.randint(1,8);return f'1\n{n} {m} {r.randint(1,20)} {r.randint(1,20)}\n'+''.join(('.'*m if big else''.join(r.choice('..*')for _ in range(m)))+'\n'for _ in range(n))
    if key=='cypher':
        n=400000 if big else 40 if weak else r.randint(1,25);return f'{n} {n//2 if big else r.randint(1,n)}\n'+line([1]*n if big else[r.randint(1,8)for _ in range(n)])
    if key=='pipeline':
        k=60 if big else 12 if weak else r.randint(2,12);n=k*(k-1)//4+1 if big else r.randint(1,k*(k-1)//2+3);return f'{n} {k}\n'
    raise KeyError(key)

def cases(id,mode,rng):
    key=RECIPES[id]['key']
    if mode=='boundary':yield from((f'boundary_{i}',s)for i,s in enumerate(BOUNDARY[key]));return
    for i in range(36 if mode=='small'else 2 if mode=='weak'else 1):yield f'{mode}_{i}',generate(key,rng,mode)

def validate_input(id,text,condition):
    try:
        key=RECIPES[id]['key'];big=condition=='l2';tok=text.split();pos=0
        def num():
            nonlocal pos
            v=int(tok[pos]);pos+=1;return v
        def word():
            nonlocal pos
            s=tok[pos];pos+=1;return s
        def read(n):return[num()for _ in range(n)]
        if key in ('ocean','records','elevator','histogram','zeros'):
            caps={'ocean':(20,200000),'records':(40,200000),'elevator':(40,200000),'histogram':(40,100000),'zeros':(40,200000)}
            n=num();assert 1<=n<=caps[key][big];a=read(n)
            lower=-10**9 if key=='zeros'else 1 if key=='ocean'else 0;upper=100 if key in('ocean','elevator')else 10000 if key=='records'else 10**9
            assert all(lower<=x<=upper for x in a)
        elif key=='knapsack':
            n,W=num(),num();assert 1<=n<=(40 if big else 12)and 1<=W<=10**9
            for _ in range(n):v,w=num(),num();assert 1<=v<=100 and 1<=w<=10000000
        elif key=='intersection':
            for _ in range(2):
                n=num();assert 1<=n<=(200000 if big else 40);a=read(n);assert all(0<=x<=10**9 for x in a)and all(a[i]<a[i+1]for i in range(n-1))
        elif key=='digits':
            a,b=word(),word();limit=24 if big else 8;assert 1<=len(a)<=limit and 1<=len(b)<=limit and all('0'<=c<='9'for c in a+b)and(a=='0'or a[0]!='0')
        elif key=='counting':
            t=num();assert 1<=t<=10
            for _ in range(t):
                a,b,q=num(),num(),num();assert 1<=a<=200 and 1<=b<=200 and 1<=q<=20
                for _ in range(q):l,r=num(),num();assert 1<=l<=r<=(10**12 if big else 100)
        elif key=='company':
            n,d=num(),num();assert 1<=n<=(40 if big else 12)and 1<=d<=10**9
            for _ in range(n):m,s=num(),num();assert 0<=m<=10**9 and 0<=s<=10**9
        elif key in('monk','cars'):
            t=num();assert 1<=t<=10
            for _ in range(t):
                n=num();assert 1<=n<=(100000 if big else 40)
                for _ in range(2 if key=='monk'else 1):
                    a=read(n);assert all(1<=x<=(10**12 if key=='monk'else 2147483647)for x in a)
                    assert all(a[i]>=a[i+1]for i in range(n-1))if key=='monk'else len(set(a))==n
        elif key=='flat':
            n,k=num(),num();assert 1<=n<=(300000 if big else 40)and 0<=k<=300000;assert all(0<=x<=300000 for x in read(n))
        elif key in('seven','power'):
            n=num();assert(1 if key=='seven'else 0)<=n<=((999999999 if key=='seven'else 10**9)if big else 6000 if key=='seven'else 1000)
        elif key=='playlist':
            n,k=num(),num();assert 1<=k<=n<=(40 if big else 12);assert all(1<=x<=10**6 for x in read(2*n))
        elif key in('ayoub','agency'):
            t=num();assert 1<=t<=10
            for _ in range(t):
                n,k=num(),num();assert 1<=n<=(50 if big else 12)and(0 if key=='ayoub'else 1)<=k<=n
                if key=='agency':assert all(1<=x<=n for x in read(n))
        elif key=='parity':
            t=num();assert 1<=t<=10;total=0
            for _ in range(t):
                s=word();total+=len(s);assert 1<=len(s)<=(1000000 if big else 8)and all('0'<=c<='9'for c in s)
            assert total<=(1000000 if big else 80)
        elif key=='tiles':
            t=num();assert 1<=t<=10
            for _ in range(t):
                n,m,x,y=num(),num(),num(),num();assert 1<=n<=3 and 1<=m<=(80 if big else 10)and 1<=x<=1000 and 1<=y<=1000
                for _ in range(n):s=word();assert len(s)==m and set(s)<=set('.*')
        elif key=='cypher':
            n,k=num(),num();assert 1<=k<=n<=(400000 if big else 40);assert all(1<=x<=10**9 for x in read(n))
        elif key=='pipeline':
            n,k=num(),num();assert 1<=n<=10**18 and 2<=k<=(60 if big else 12)
        else:return False
        return pos==len(tok)
    except(ValueError,IndexError,AssertionError,OverflowError):return False
