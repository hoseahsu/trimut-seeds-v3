"""Eight distinct Codeforces source problems; generated cases do not create new seeds."""
from collections import Counter
from pathlib import Path
import random

DATA = {
 'phone': ('1060_A','Phone Numbers','Maximum number of disjoint 11-digit numbers starting with digit 8, assembled by freely rearranging the n digit cards.','Replace the required leading digit 8 by 0.','n then one length-n decimal string. Output one integer.',{'n':100},{'n':1000000},'For c leading-digit cards, both upper bounds c and floor(n/11) are attainable. The independent oracle enumerates every allocation of leading and other digits to a number.'),
 'integer': ('1101_A','Minimum Integer','For each (l,r,d), return the smallest positive multiple of d outside closed interval [l,r].','Return the smallest positive multiple of d inside [l,r], or -1 if none exists.','q then q lines l r d. Output q integers.',{'q':20,'value':100},{'q':500,'value':1000000000000},'Outside: d if d<l, otherwise (floor(r/d)+1)d. Inside: ceil(l/d)d if at most r. The oracle enumerates positive multiples.'),
 'errors': ('519_B','A and B and Compilation Errors','Arrays a,b,c have lengths n,n-1,n-2. Each later multiset removes exactly one occurrence. Return the two removed values.','For each removal, return the smallest one-based index of the removed value in the immediately preceding array, rather than the value.','n>=3, then arrays a,b,c. Output two integers.',{'n':60,'value':100},{'n':200000,'value':1000000000},'Multiset differences identify one value per transition; earliest-index lookup is the new objective. The oracle tries each possible removed position and compares sorted remaining multisets.'),
 'bulbs': ('615_A','Bulbs','All m bulbs start off. Each of n buttons turns on every bulb in its connection set. Decide whether some presses can light every bulb.','A press toggles every bulb in its connection set instead of setting it on. Decide whether some presses can light all bulbs. Duplicate identifiers within a button describe one connection, not multiple toggles.','n m; each of n lines gives x followed by x bulb IDs in [1,m]. Output YES or NO.',{'n':100,'m':100},{'n':5000,'m':100000},'Raw is union coverage. With toggles, only press parity matters, and the all-one vector must lie in the GF(2) span of button vectors. Independent oracle enumerates subsets of buttons.'),
 'garden': ('915_A','Garden','Choose one bucket length a dividing k, and minimize the number of hours k/a needed to cover a segment of length k without overlap. At least one bucket is feasible.','Maximize the number of hours among feasible choices of one bucket.','n k, then n positive bucket lengths. Output one integer.',{'n':100,'k':100,'a':100},{'n':100,'k':10000000000,'a':10000000000},'Feasibility is divisibility. Optimize k/a in the declared direction. The oracle repeatedly covers one bucket-length segment until reaching or exceeding k.'),
 'elections': ('1043_A','Elections','Find minimum k>=max(a) such that sum(k-a_i)>sum(a_i).','Allow a tie: replace strict > by >=.','n then n positive integers a. Output k.',{'n':100,'a':100},{'n':100,'a':1000000000},'The inequality is nk>2S or nk>=2S. Intersect its integer lower bound with k>=max(a). Oracle increments k and sums both candidates votes explicitly.'),
 'games': ('268_A','Games','For each ordered pair of different teams, host uses home colour h_i and visitor uses away colour a_j. Count pairs where h_i=a_j. Each team has h_i!=a_i.','Visitors use their home colour h_j. Count ordered distinct-team pairs where h_i=h_j.','n then n lines h_i a_i, with distinct colours within each line. Output the count.',{'n':30,'colour':100},{'n':200000,'colour':100},'Histogram products count ordered equal-colour pairs. Raw self-pairs never match because h_i!=a_i; the new relation subtracts one self-pair per team. Oracle enumerates all ordered distinct pairs.'),
 'keys': ('830_A','Office Keys','Assign distinct keys to all people. Person a assigned key b incurs |a-b|+|b-p| travel time. Minimize the maximum travel time.','Minimize the sum of all assigned travel times instead of their maximum.','n k p, n distinct person coordinates, k distinct key coordinates; n<=k. Output one integer.',{'n':4,'k':7,'coordinate':100},{'n':12,'k':28,'coordinate':1000000000},'Sorted matching admits an uncrossing exchange for both bottleneck and total absolute-distance objectives; the office term is key-specific. DP chooses or skips each sorted key. Oracle enumerates all injective assignments without assuming ordered matching.'),
}

RECIPES={}
for key,(pid,title,raw,l3,io,weak,strong,proof) in DATA.items():
    def prog(file,mut):
        return {'path':'../assets/root_batch/'+file+'.cpp','args':[key,str(mut)]}
    RECIPES['cf_'+pid]={
      'source_id':'codeforces:'+pid,'source_dataset':'CodeContests','source_problem_id':pid,
      'title':title,'source_url':'https://codeforces.com/problemset/problem/'+pid.replace('_','/'),
      'raw_fast':prog('fast',0),'raw_oracle':prog('oracle',0),
      'l3_fast':prog('fast',1),'l3_oracle':prog('oracle',1),
      'slow_baseline':prog('slow' if key in ('phone','errors') else 'oracle',0),
      'budget_seconds':0.5,'memory_mb':512,'small_timeout_seconds':3,
      'independent_oracles':True,'oracle_independence_note':proof,
      'spec':{'raw_relation':raw,'l3_relation':l3,'io_protocol':io,
              'weak_bounds':weak,'strong_bounds':strong,'l3_bounds':'same as weak',
              'l2_changed_fields':list(strong),'proof_sketch':proof},
      'baseline_kind':'standardized_weak; source-original retained separately',
      'source_equivalence_review':'requires original-source sample and specification audit',
      'l3_operator':l3,'key':key,
    }

def text(values): return ' '.join(map(str,values))+'\n'

def gen(key,rng,mode):
    strong=mode=='stress'; weak=mode=='weak'
    if key=='phone':
        n=1000000 if strong else 66 if weak else rng.randint(1,44)
        return str(n)+'\n'+('8'*(n//2)+'0'*(n-n//2) if strong else ''.join(rng.choice('00888812345679') for _ in range(n)))+'\n'
    if key=='integer':
        triples=[(1,10**12,1)] if strong else [(rng.randint(1,40),rng.randint(41,100),rng.randint(1,30)) for _ in range(5)]
        return str(len(triples))+'\n'+''.join(text(t) for t in triples)
    if key=='errors':
        n=200000 if strong else 50 if weak else rng.randint(3,12)
        a=list(range(10,n+10)) if strong else [rng.randint(1,100) for _ in range(n)]
        b=a.copy();b.pop(rng.randrange(n));rng.shuffle(b)
        c=b.copy();c.pop(rng.randrange(n-1));rng.shuffle(c)
        return str(n)+'\n'+text(a)+text(b)+text(c)
    if key=='bulbs':
        if strong:
            n,m=5000,100000; groups=[list(range(i+1,m+1,n)) for i in range(n)]
        else:
            n=30 if weak else rng.randint(1,8);m=60 if weak else rng.randint(1,8)
            groups=[[rng.randint(1,m) for _ in range(rng.randint(0,m))] for _ in range(n)]
        return f'{n} {m}\n'+''.join(text([len(g)]+g) for g in groups)
    if key=='garden':
        k=10**10 if strong else rng.randint(1,100)
        a=[1,k] if strong else [1]+[rng.randint(1,100) for _ in range(rng.randint(1,12))]
        return f'{len(a)} {k}\n'+text(a)
    if key=='elections':
        a=[10**9]*100 if strong else [rng.randint(1,100) for _ in range(rng.randint(1,20))]
        return str(len(a))+'\n'+text(a)
    if key=='games':
        n=200000 if strong else 30 if weak else rng.randint(2,15)
        a=[]
        for _ in range(n):
            h=rng.randint(1,100);g=rng.randint(1,99);g+=g>=h;a.append((h,g))
        return str(n)+'\n'+''.join(text(t) for t in a)
    if key=='keys':
        n,k=(12,28) if strong else (3,6) if weak else (rng.randint(1,4),7)
        a=rng.sample(range(1,100),n);b=rng.sample(range(1,100),k);p=rng.randint(1,100)
        return f'{n} {k} {p}\n'+text(a)+text(b)
    raise KeyError(key)

BOUNDARIES={
 'phone':['11\n88888888888\n','11\n00000000000\n','1\n8\n','22\n'+'8'*22+'\n'],
 'integer':['3\n1 10 2\n5 7 8\n2 4 1\n','1\n1 1 1\n'],
 'errors':['4\n9 9 4 5\n5 4 9\n9 4\n','3\n2 2 2\n2 2\n2\n'],
 'bulbs':['2 3\n2 1 2\n2 2 3\n','1 1\n1 1\n','1 2\n2 1 1\n','1 1\n0\n'],
 'garden':['2 6\n1 3\n','1 1\n1\n'],
 'elections':['2\n1 1\n','1\n100\n'],
 'games':['2\n1 2\n1 2\n','2\n1 2\n2 1\n'],
 'keys':['2 3 50\n20 90\n10 40 80\n','1 1 1\n1\n1\n'],
}

def cases(id,mode,rng):
    key=RECIPES[id]['key']
    if mode=='boundary':
        for i,s in enumerate(BOUNDARIES[key]):yield 'boundary_%03d'%i,s
    else:
        for i in range(36 if mode=='small' else 2 if mode=='weak' else 1):
            yield mode+'_%03d'%i,gen(key,rng,mode)

def validate_input(id,input_text,condition):
    try:
        key=RECIPES[id]['key']; strong=condition=='l2'; vals=input_text.split()
        if key=='phone':
            n=int(vals[0]);return len(vals)==2 and 1<=n<=(1000000 if strong else 100) and len(vals[1])==n and vals[1].isascii() and vals[1].isdigit()
        v=list(map(int,vals))
        if key=='integer':
            q=v[0];return 1<=q<=500 and len(v)==1+3*q and all(1<=l<=r<=(10**12 if strong else 100) and 1<=d<=(10**12 if strong else 100) for l,r,d in zip(v[1::3],v[2::3],v[3::3]))
        if key=='errors':
            n=v[0]
            if not (3<=n<=(200000 if strong else 60) and len(v)==3*n-2 and all(1<=x<=(10**9 if strong else 100) for x in v[1:])):return False
            a=Counter(v[1:n+1]);b=Counter(v[n+1:2*n]);c=Counter(v[2*n:]);return sum((a-b).values())==sum((b-c).values())==1 and not b-a and not c-b
        if key=='bulbs':
            n,m=v[:2]
            if not(1<=n<=(5000 if strong else 100) and 1<=m<=(100000 if strong else 100)):return False
            pos=2
            for _ in range(n):
                k=v[pos];pos+=1
                if not 0<=k<=m or len(v[pos:pos+k])!=k or any(not 1<=x<=m for x in v[pos:pos+k]):return False
                pos+=k
            return pos==len(v)
        if key=='garden':
            n,k=v[:2];a=v[2:];lim=10**10 if strong else 100
            return 1<=n<=100 and len(a)==n and 1<=k<=lim and all(1<=x<=lim for x in a) and any(k%x==0 for x in a)
        if key=='elections':return len(v)==v[0]+1 and 1<=v[0]<=100 and all(1<=x<=(10**9 if strong else 100) for x in v[1:])
        if key=='games':return len(v)==2*v[0]+1 and 2<=v[0]<=(200000 if strong else 30) and all(1<=h<=100 and 1<=a<=100 and h!=a for h,a in zip(v[1::2],v[2::2]))
        if key=='keys':
            n,k,p=v[:3];a=v[3:3+n];b=v[3+n:];lim=10**9 if strong else 100
            return 1<=n<=(12 if strong else 4) and n<=k<=(28 if strong else 7) and len(v)==3+n+k and len(set(a))==n and len(set(b))==k and all(1<=x<=lim for x in a+b+[p])
    except (ValueError,IndexError,ZeroDivisionError):return False
    return False
