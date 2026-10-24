"""25 further public originals with executable, finite-testable L2/L3 recipes."""
import json
from pathlib import Path

DATA={
'powered':('Make the array nondecreasing using arbitrary subsets of additions2^(t-1) at second t; minimize elapsed seconds.','Require a strictly increasing final array.','For strict order transform a_i to a_i-i. The maximum deficit from a prefix maximum is the needed total increment; its bit length is the minimum time. Oracle computes all predecessor constraints directly.','n<=40','n<=100000'),
'regional':('For each team size k, each university repeatedly sends its k strongest remaining students; return sum of skills sent.','Each university instead repeatedly sends its k weakest remaining students.','Sort university groups in the required order, then sum prefix lengths floor(size/k)*k. Oracle enumerates all subsets of the mandatory selected cardinality in each university.','n<=9','n<=100000'),
'aqua':('Adjacent friends may swap, flipping both directions; initially all face right. Decide if numbers can be sorted nondecreasing with all directions right.','Require all directions left at the end.','Direction flip parity equals displacement parity for each labeled friend. Match sorted destination-value counts by original parity, same for Raw and opposite for L3. Oracle enumerates labeled permutations and verifies both order and displacement parity.','n<=7','n<=14'),
'shift':('Minimum right cyclic shifts to obtain nondecreasing order; -1 if impossible.','Obtain nonincreasing order instead.','A feasible cyclic array has at most one strict descent (ascent for mutant); its location determines the shift. Oracle constructs/checks every rotation.','n<=40','n<=100000'),
'substrings':('Decide if string contains nonoverlapping AB and BA in either order.','Require AB strictly before BA, still nonoverlapping.','Find earliest occurrence of the first pattern and a later disjoint second. Raw checks both orders; L3 checks one. Oracle enumerates all occurrence-position pairs.','length<=40','length<=100000'),
'modulo':('Decide whether some nonempty subsequence has sum divisible by m.','Additionally require odd subsequence cardinality.','Residue/parity subset DP preserves a separate flag for a nonempty zero sum. Oracle enumerates every subset and directly tests sum and size.','n<=14','n<=40'),
'dance':('Apply cyclic shifts and simultaneous swaps of position pairs(1,2),(3,4),...,(n-1,n); output boy at each position.','Type2 swaps pairs(2,3),(4,5),...,(n,1) instead.','Each original position parity shares one cyclic offset; update two offsets per operation. Oracle materializes all positions at each command.','n<=20,q<=40','n<=100000,q<=100000'),
'lara':('Follow first column down, then snake right/left upward through columns2..m; output position after k moves.','Follow first row rightward, then snake down/up leftward through rows2..n.','Division by remaining row width yields the band and offset. Mutant is the transposed traversal with the same n-by-m grid. Oracle visits cells one at a time.','n,m<=20','n,m<=1000000000'),
'compositions':('Count sequences of exactly N nonnegative integer moves summing to k.','Every move must score at least1.','Stars-and-bars gives C(N+k-1,N-1); shifting positive parts gives C(k-1,N-1), or0. Oracle recursively enumerates every allowed composition.','N,k<=7','N,k<=19'),
'payment':('Minimize number of decimal-power banknotes paid plus notes returned as change.','A returned change note costs2 units; a paid note costs1; minimize total cost.','Digit DP tracks carry and chooses paying the current digit or overpaying one higher note and receiving change. Oracle enumerates every payment from N through N+10^digits(N)-1 and counts notes; larger payments have a cancellable note in both payment and change.','N<=3000','N<=10^18'),
'taxi':('Assign each rider to nearest taxi; distance ties choose smaller coordinate; output per-taxi counts.','Break ties toward larger coordinate.','Only the predecessor and successor taxis in coordinate order can be closest. Oracle scans all taxis.','riders,taxis<=30','riders,taxis<=100000'),
'doctor':('Each spaceship may loot every base with defense<=its attack; sum all available gold independently per ship.','Require defense<attack.','Sorted base-defense prefix sums answer upper/lower bound queries. Oracle evaluates every ship-base predicate.','ships,bases<=30','ships,bases<=100000'),
'epic':('Repeatedly delete two elements of different values; minimize remaining size.','Delete two elements of equal values instead.','Raw answer=max(n%2,2*maximum_frequency-n); mutant retains exactly odd multiplicities. Oracle explores all deletion states with memoization. Natural slow raw repeatedly scans frequencies to select two largest.','n<=9','n<=200000'),
'pocket':('Independently permute letters within each column of the n-by-m word table; count distinct possible words modulo1000000007.','Only whole rows may be permuted; count distinct possible words modulo1000000007.','Raw choices multiply independent column support sizes; mutant is the set of initial rows. Oracle enumerates every column-choice word or checks row equality directly.','n<=4,m<=6','n<=4,m<=40'),
'languages':('Minimum one-person-one-language courses making the employee correspondence graph connected; translators permitted.','Require at least one common language known to every employee; translators no longer suffice.','Raw language incidence DSU counts components (all-empty case costs n). Mutant chooses language with most speakers, costing n-max_count. Oracle builds explicit shared-language graph or enumerates target languages.','2<=n<=8,2<=m<=6','n<=100000,m<=6'),
'tavas':('For each query maximize r>=l with max height<=t and total height<=m*t in arithmetic progression A+(i-1)B; output-1 if none.','Require total height<m*t, retaining max height<=t (at least one capacity slot remains unused).','Both constraints are monotone in r; exact arithmetic-series sums support binary search. Oracle grows the interval one vegetable at a time.','queries<=4,l,t,m<=100','queries<=10000,l,t,m<=1000000'),
'cellular':('Minimum radius so each city is covered by at least one tower.','Minimum radius so each city is covered by every tower.','Raw takes maximum of nearest-tower distances found by binary search; mutant uses farthest endpoint tower. Oracle enumerates all city-tower distances.','n,m<=30','n,m<=100000'),
'magical':('Count nonempty subarrays whose minimum equals maximum.','Count subarrays whose maximum minus minimum is at most1.','Two monotone deques maintain a window with permitted value spread0/1; each right endpoint adds its valid starts. Oracle scans every interval and tracks extrema.','n<=40','n<=100000'),
'pairs':('Sum A_i*A_j over i<j modulo1000000007.','Sum |A_i-A_j| over i<j modulo1000000007.','Raw prefix sums collect products. Mutant sorts values and adds a_i*i-prefix_sum. Oracle directly enumerates pairs.','n<=40','n<=200000'),
'bricks':('Delete minimum bricks so remaining nonempty sequence is1,2,...,K; -1 if impossible.','Require remaining sequence K,K-1,...,1.','Raw greedily extends the next required value. Mutant DP at x extends the best chain ending in x+1, then reads the chain ending in1. Oracle enumerates every subsequence.','n<=14','n<=40'),
'transform':('Decide if S can become T by any global swaps of two letter identities (a bijective renaming).','Allow one simultaneous arbitrary letter-to-letter substitution, which need not be injective.','Raw requires a consistent map in both directions; mutant only forward consistency. Oracle checks equality-pattern equivalences or implications over all position pairs.','length<=40','length<=200000'),
'concat':('Concatenate all equal-length strings in an order giving the lexicographically smallest result.','Give the lexicographically largest result.','Equal block lengths make ascending/descending sorting optimal by adjacent exchange. Oracle enumerates all block permutations.','n<=7,length<=5','n<=14,length<=5'),
'consecutive':('Count representations of N as a sum of at least two consecutive positive integers; input datasets end with0.','Permit the first integer to be0 (all integers remain nonnegative).','For each feasible length, solve length*start+length*(length-1)/2=N and test divisibility/lower bound. Oracle enumerates starts and explicitly adds consecutive integers.','N<=1000','N<=1000000000'),
'hotel':('Maximum simultaneous guests with arrivals included and departures excluded.','Count a departing guest at its departure instant as well.','Sweep events; Raw departures precede arrivals at equal times, L3 arrivals precede departures. Oracle counts occupancy at each arrival.','n<=40','n<=100000'),
'equation':('Count nonnegative integer solutions x of a-(a xor x)-x=0.','Count only even nonnegative solutions x.','Solutions are precisely submasks of a, since the equation forbids borrowing. Count free set bits; L3 fixes bit0 to0. Oracle enumerates0<=x<=a and tests the arithmetic equation.','a<=1000','a<=2^30-1'),
}
SOURCES=json.loads((Path(__file__).resolve().parents[1]/'assets/root_batch3/source_rows.json').read_text())
RECIPES={}
for key,(raw,new,proof,weak,strong)in DATA.items():
    src=SOURCES[key];name=src['source_name'];platform=src['source_platform_enum'];sid='codeforces:'+name.split('.')[0]if platform==2 else f'codecontests:{platform}:{name}'
    def p(file,mut):return {'path':'../assets/root_batch3/'+file+'.cpp','args':[key,str(mut)]}
    RECIPES['root3_'+key]={**src,'key':key,'source_id':sid,'source_dataset':'CodeContests','original_source_identity':name,
       'raw_fast':p('fast',0),'raw_oracle':p('oracle',0),'l3_fast':p('fast',1),'l3_oracle':p('oracle',1),'slow_baseline':p('slow'if key in('regional','epic','languages')else'oracle',0),
       'budget_seconds':0.5,'small_timeout_seconds':4,'memory_mb':512,'independent_oracles':True,'oracle_independence_note':proof,
       'spec':{'raw_relation':raw,'l3_relation':new,'weak_bounds':weak,'strong_bounds':strong,'l3_bounds':weak,'proof_sketch':proof,'complete_constraints':'literal validate_input function; original I/O unchanged'},
       'baseline_kind':'standardized weak; source-original preserved separately','l2_changed_fields':'listed scale bounds only','l3_operator':new,'source_equivalence_review':'requires recorded source-test audit'}

def line(a):return ' '.join(map(str,a))+'\n'
def arr(a):return str(len(a))+'\n'+line(a)
B={
'powered':['1\n2\n1 1\n','1\n1\n-1000000000\n'],
'regional':['1\n3\n1 1 1\n1 2 3\n','1\n1\n1\n1\n'],
'aqua':['1\n2\n2 1\n','1\n1\n1\n','1\n4\n2 2 1 1\n'],
'shift':['3\n1 2 3\n','2\n2 1\n','3\n1 1 1\n'],
'substrings':['BAAB\n','ABA\n','ABCBA\n','A\n'],
'modulo':['2 2\n1 1\n','1 2\n0\n'],
'dance':['4 1\n2\n','2 2\n1 -1\n2\n'],
'lara':['4 3 2\n','2 2 0\n','4 3 11\n'],
'compositions':['2\n2 2\n3 1\n'],
'payment':['6\n','1\n','999\n','708\n'],
'taxi':['1 2\n1 3 5\n1 0 1\n','1 1\n1 2\n0 1\n'],
'doctor':['1 1\n5\n5 2\n','1 1\n0\n0 0\n'],
'epic':['1\n2\n1 1\n','1\n1\n5\n','1\n4\n1 2 3 4\n'],
'pocket':['2 2\nAB\nBA\n','1 1\nA\n'],
'languages':['3 2\n1 1\n2 1 2\n1 2\n','2 2\n0\n0\n'],
'tavas':['1 1 2\n1 1 1\n2 1 1\n'],
'cellular':['1 2\n0\n-1 5\n','1 1\n0\n0\n'],
'magical':['2\n1 2\n','1\n-1000000000\n'],
'pairs':['2\n2 3\n','2\n0 0\n'],
'bricks':['2\n1 2\n','1\n1\n','3\n2 2 2\n'],
'transform':['ab\naa\n','aaa\naab\n','a\nz\n'],
'concat':['2 1\na\nb\n','1 1\nz\n'],
'consecutive':['3\n9\n0\n','1\n0\n'],
'hotel':['1\n2\n1 2\n2 3\n','1\n1\n1\n1000\n'],
'equation':['3\n3\n0\n2\n'],
}

def gen(key,r,mode):
    big=mode=='stress';weak=mode=='weak'
    if key=='powered':return '1\n'+arr([0]*100000 if big else[r.randint(-20,20)for _ in range(40 if weak else r.randint(1,20))])
    if key=='regional':
        n=100000 if big else 9 if weak else r.randint(1,8);u=list(range(1,n+1))if big else[r.randint(1,n)for _ in range(n)];return '1\n'+arr(u)+line([r.randint(1,50)for _ in range(n)])
    if key=='aqua':
        a=[2,1]+list(range(3,15))if big else[r.randint(1,6)for _ in range(7 if weak else r.randint(1,7))];return '1\n'+arr(a)
    if key=='shift':
        a=list(range(1,100001))if big else[r.randint(1,30)for _ in range(40 if weak else r.randint(2,20))]
        if big:a[-1],a[-2]=a[-2],a[-1]
        return arr(a)
    if key=='substrings':return ('ABC'*33333 if big else''.join(r.choice('ABC')for _ in range(40 if weak else r.randint(1,30))))+'\n'
    if key=='modulo':
        n=40 if big else 14 if weak else r.randint(1,12);m=1000 if big else r.randint(2,15);return f'{n} {m}\n'+line([1]*n if big else[r.randint(0,50)for _ in range(n)])
    if key=='dance':
        n=100000 if big else 20 if weak else 2*r.randint(1,10);q=100000 if big else 40 if weak else r.randint(1,30);ops=['2\n'if big or r.randrange(2)else f'1 {r.randint(-n,n)}\n'for _ in range(q)];return f'{n} {q}\n'+''.join(ops)
    if key=='lara':
        n=1000000000 if big else 2*r.randint(1,10);m=1000000000 if big else r.randint(2,20);k=n*m-1 if big else r.randrange(n*m);return f'{n} {m} {k}\n'
    if key=='compositions':return f'1\n{19 if big else 7 if weak else r.randint(1,7)} {19 if big else 7 if weak else r.randint(1,7)}\n'
    if key=='payment':return str(333333333333333333 if big else 3000 if weak else r.randint(1,3000))+'\n'
    if key=='taxi':
        n=100000 if big else 30 if weak else r.randint(1,20);m=n if big else r.randint(1,30);x=list(range(1,n+m+1))if big else sorted(r.sample(range(1,1000),n+m));t=[1]*m+[0]*n;r.shuffle(t);return f'{n} {m}\n'+line(x)+line(t)
    if key=='doctor':
        n=100000 if big else 30 if weak else r.randint(1,20);m=n if big else r.randint(1,30);return f'{n} {m}\n'+line([r.randint(0,100)for _ in range(n)])+''.join(line((r.randint(0,100),r.randint(0,100)))for _ in range(m))
    if key=='epic':return '1\n'+arr(list(range(1,200001))if big else[r.randint(1,8)for _ in range(9 if weak else r.randint(1,8))])
    if key=='pocket':
        n=2 if big else r.randint(1,4);m=40 if big else 6 if weak else r.randint(1,6);a=['A'*m,'B'*m]if big else[''.join(r.choice('ABC')for _ in range(m))for _ in range(n)];return f'{n} {m}\n'+'\n'.join(a)+'\n'
    if key=='languages':
        n=100000 if big else 8 if weak else r.randint(2,8);m=2 if big else r.randint(2,6);a=[[i%2+1]for i in range(n)]if big else[r.sample(range(1,m+1),r.randint(0,m))for _ in range(n)];return f'{n} {m}\n'+''.join(line([len(v)]+v)for v in a)
    if key=='tavas':
        q=10000 if big else 4;A,B=(1,1)if big else(r.randint(1,20),r.randint(1,10));return f'{A} {B} {q}\n'+('1 1000000 1000000\n'*q if big else''.join(line((r.randint(1,20),r.randint(1,100),r.randint(1,100)))for _ in range(q)))
    if key=='cellular':
        n=100000 if big else 30 if weak else r.randint(1,20);m=n if big else r.randint(1,30);return f'{n} {m}\n'+line(sorted(r.randint(-10**9,10**9)for _ in range(n)))+line(sorted(r.randint(-10**9,10**9)for _ in range(m)))
    if key in('magical','pairs'):
        n=(100000 if key=='magical'else 200000)if big else 40 if weak else r.randint(2,25);return arr([1]*n if big else[r.randint(0,20)for _ in range(n)])
    if key=='bricks':
        n=40 if big else 14 if weak else r.randint(1,12);return arr([2]*n if big else[r.randint(1,n)for _ in range(n)])
    if key=='transform':
        n=200000 if big else 40 if weak else r.randint(1,25);a='a'*n if big else''.join(r.choice('abcd')for _ in range(n));b=a if big else''.join(r.choice('abcd')for _ in range(n));return a+'\n'+b+'\n'
    if key=='concat':
        n=14 if big else 7 if weak else r.randint(1,7);l=3 if big else r.randint(1,5);a=[chr(97+i)+'ab'for i in range(n)]if big else[''.join(r.choice('abc')for _ in range(l))for _ in range(n)];return f'{n} {l}\n'+'\n'.join(a)+'\n'
    if key=='consecutive':return str(1000000000 if big else 1000 if weak else r.randint(1,1000))+'\n0\n'
    if key=='hotel':
        n=100000 if big else 40 if weak else r.randint(1,25);a=[r.randint(1,999)for _ in range(n)];d=[r.randint(x+1,1000)for x in a];return '1\n'+arr(a)+line(d)
    if key=='equation':return '4\n1073741823\n1073741822\n1073741821\n1073741820\n'if big else '1\n'+str(1000 if weak else r.randint(0,1000))+'\n'
    raise KeyError(key)

def cases(id,mode,rng):
    key=RECIPES[id]['key']
    if mode=='boundary':yield from((f'boundary_{i}',s)for i,s in enumerate(B[key]));return
    for i in range(36 if mode=='small'else 2 if mode=='weak'else 1):yield f'{mode}_{i}',gen(key,rng,mode)

def validate_input(id,text,condition):
    try:
        key=RECIPES[id]['key'];big=condition=='l2';tokens=text.split();pos=0
        def num():
            nonlocal pos
            x=int(tokens[pos]);pos+=1;return x
        def word():
            nonlocal pos
            x=tokens[pos];pos+=1;return x
        def seq(n,lo,hi):
            a=[num()for _ in range(n)];assert all(lo<=x<=hi for x in a);return a
        def count(lo,hi):
            n=num();assert lo<=n<=hi;return n
        if key in('powered','regional','aqua','epic'):
            t=count(1,10)
            cap={'powered':(40,100000),'regional':(9,100000),'aqua':(7,14),'epic':(9,200000)}[key][big]
            for _ in range(t):
                n=count(1,cap)
                if key=='regional':seq(n,1,n);seq(n,1,10**9)
                else:seq(n,-10**9 if key=='powered'else 1,10**9 if key in('powered','epic')else 100000)
        elif key=='shift':n=count(2,100000 if big else 40);seq(n,1,100000)
        elif key=='substrings':s=word();assert 1<=len(s)<=(100000 if big else 40)and all('A'<=c<='Z'for c in s)
        elif key=='modulo':n=count(1,40 if big else 14);m=count(2,1000);seq(n,0,10**9)
        elif key=='dance':
            n=count(2,100000 if big else 20);q=count(1,100000 if big else 40);assert n%2==0
            for _ in range(q):
                t=count(1,2)
                if t==1:seq(1,-n,n)
        elif key=='lara':
            n=count(2,10**9 if big else 20);m=count(2,10**9 if big else 20);k=num();assert n%2==0 and 0<=k<n*m
        elif key=='compositions':
            t=count(1,10)
            for _ in range(t):count(1,19 if big else 7);count(1,19 if big else 7)
        elif key=='payment':s=word();assert s.isascii()and s.isdigit()and s[0]!='0'and 1<=int(s)<=(10**18 if big else 3000)
        elif key=='taxi':
            n=count(1,100000 if big else 30);m=count(1,100000 if big else 30);a=seq(n+m,1,10**9);t=seq(n+m,0,1);assert all(a[i]<a[i+1]for i in range(n+m-1))and sum(t)==m
        elif key=='doctor':
            n=count(1,100000 if big else 30);m=count(1,100000 if big else 30);seq(n,0,10**9)
            for _ in range(m):seq(1,0,10**9);seq(1,0,10000)
        elif key=='pocket':
            n=count(1,4);m=count(1,40 if big else 6)
            for _ in range(n):s=word();assert len(s)==m and all('A'<=c<='Z'for c in s)
        elif key=='languages':
            n=count(2,100000 if big else 8);m=count(2,6)
            for _ in range(n):k=count(0,m);a=seq(k,1,m);assert len(set(a))==k
        elif key=='tavas':
            A=count(1,10**6);B=count(1,10**6);q=count(1,10000 if big else 4);seq(3*q,1,10**6 if big else 100)
        elif key=='cellular':
            n=count(1,100000 if big else 30);m=count(1,100000 if big else 30)
            for size in(n,m):a=seq(size,-10**9,10**9);assert a==sorted(a)
        elif key in('magical','pairs'):
            n=count(1 if key=='magical'else 2,(100000 if key=='magical'else 200000)if big else 40);seq(n,-10**9 if key=='magical'else 0,10**9)
        elif key=='bricks':n=count(1,40 if big else 14);seq(n,1,n)
        elif key=='transform':
            a,b=word(),word();assert 1<=len(a)<=(200000 if big else 40)and len(a)==len(b)and all('a'<=c<='z'for c in a+b)
        elif key=='concat':
            n=count(1,14 if big else 7);l=count(1,5)
            for _ in range(n):s=word();assert len(s)==l and all('a'<=c<='z'for c in s)
        elif key=='consecutive':
            n=num();seen=0
            while n:assert 1<=n<=(10**9 if big else 1000);seen+=1;n=num()
            assert 1<=seen<=10
        elif key=='hotel':
            t=count(1,10)
            for _ in range(t):n=count(1,100000 if big else 40);a=seq(n,1,1000);d=seq(n,1,1000);assert all(x<y for x,y in zip(a,d))
        elif key=='equation':t=count(1,10);seq(t,0,2**30-1 if big else 1000)
        else:return False
        return pos==len(tokens)
    except(ValueError,IndexError,AssertionError):return False
