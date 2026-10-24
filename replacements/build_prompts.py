from pathlib import Path
import json,re,hashlib,difflib,itertools,math,sys
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'recipes'))
import replacements as recipe

def sha(t):return hashlib.sha256(t.encode()).hexdigest()
def edits(a,b):
 return [{'raw_start':i,'raw_end':j,'before':a[i:j],'after':b[x:y]}for tag,i,j,x,y in difflib.SequenceMatcher(None,a,b,autojunk=False).get_opcodes()if tag!='equal']
def replace_once(t,a,b):assert t.count(a)==1,(a,t.count(a));return t.replace(a,b,1)
def mutate_sample(t,k,answer,explanation=None):
 pat=r'(## Sample Output '+str(k)+r'\s*\n\s*```\n)([\s\S]*?)(\n```)([\s\S]*?)(?=\n## Sample Input |\Z)'
 m=re.search(pat,t);assert m,('sample',k)
 tail=m.group(4)if explanation is None else '\n\n'+explanation+'\n'
 return t[:m.start()]+m.group(1)+answer.strip()+m.group(3)+tail+t[m.end():]

def expected(key,s,mutant):
 z=s.split()
 if key=='sums':
  N,A,B=map(int,z);return str(sum(x for x in range(1,N+1)if A<=sum(map(int,str(x)))<=(B-1 if mutant else B)))+'\n'
 if key=='puzzles':
  n,m=map(int,z[:2]);a=sorted(map(int,z[2:]));return str(a[-1]-a[0]if mutant else min(a[i+n-1]-a[i]for i in range(m-n+1)))+'\n'
 if key=='football':
  a=z[1:];return (min if mutant else max)(sorted(set(a)),key=a.count)+'\n'
 if key=='average':
  a=list(map(int,z));n=a[0];p=list(zip(a[1::2],a[2::2]));d=lambda u,v:math.hypot(p[u][0]-p[v][0],p[u][1]-p[v][1]);v=[sum(d(q[i],q[i+1])for i in range(n-1))for q in itertools.permutations(range(n))];return f'{min(v)if mutant else sum(v)/len(v):.12f}\n'
 if key=='coins':
  A,B,C,X=map(int,z);return str(sum(500*a+100*b+50*c<=X if mutant else 500*a+100*b+50*c==X for a in range(A+1)for b in range(B+1)for c in range(C+1)))+'\n'

sources={**json.loads((ROOT/'replacements/cf_sources.json').read_text()),**json.loads((ROOT/'replacements/atcoder_sources.json').read_text())}
old={x['seed_id']:x for x in map(json.loads,(ROOT/'curation/previous_seed_index.jsonl').read_text().splitlines())}
out=[]
for rid,cfg in recipe.RECIPES.items():
 sid=cfg['seed_id'];key=cfg['key'];p=ROOT/'tasks'/sid;raw=(p/'raw.txt').read_text();l2=raw;l3=raw
 if key=='sums':
  l2=replace_once(l2,r'1 \leq N \leq 10^4',r'1 \leq N \leq 1000000000')
  assert l3.count('is between $A$ and $B$ (inclusive)')==2
  l3=l3.replace('is between $A$ and $B$ (inclusive)','is at least $A$ and strictly less than $B$')
  l3=mutate_sample(l3,1,expected(key,recipe.source_samples(rid)[0][0],True),'The upper endpoint is excluded. The qualifying integers are 2, 3, 4, 11, 12, 13, and 20; their sum is 65.')
  for j,(inp,answer)in enumerate(recipe.source_samples(rid),1):l3=mutate_sample(l3,j,expected(key,inp,True))
 elif key=='puzzles':
  l2=replace_once(l2,'2 ≤ n ≤ m ≤ 50','2 ≤ n ≤ m ≤ 200000')
  l3=l3.replace("doesn't want to upset the children","wants the children to receive a varied selection").replace('as small as possible','as large as possible').replace('minimum possible','maximum possible').replace('least possible','greatest possible')
  l3=replace_once(l3,'Output\n\n5\n\nNote','Output\n\n17\n\nNote')
  l3=l3.split('\nNote\n',1)[0]+'\nNote\n\nThe largest possible difference is 17. For example, select puzzles 1, 2, 5, and 6, with 10, 12, 5, and 22 pieces. No selection can exceed the difference between 22 and 5.\n'
 elif key=='football':
  l2=replace_once(l2,'1 ≤ n ≤ 100','1 ≤ n ≤ 200000')
  l3=replace_once(l3,'Help Vasya, learn the name of the team that won the finals.','Help Vasya find the name with the fewest recorded goals among the team names appearing in the description.')
  l3=replace_once(l3,'Print the name of the winning team. We remind you that in football the team that scores more goals is considered the winner.','Print the team name that occurs the fewest times among names present in the input. If only one team name occurs, print that name. The no-tie guarantee makes the requested name unique.')
  assert l3.endswith('Output\n\nA\n');l3=l3[:-len('A\n')]+'ABA\n'
 elif key=='average':
  l2=replace_once(l2,r'2 \leq N \leq 8',r'2 \leq N \leq 2000')
  l3=l3.replace('Average Length','Minimum Length').replace('average length','minimum length')
  l3=mutate_sample(l3,1,'2.000000000000','The minimum length is 2, attained by the path from Town 2 through Town 1 to Town 3. The distance formula and the requirement to visit every town exactly once remain as stated.')
  for k,(s,a)in enumerate(recipe.source_samples(rid),1):l3=mutate_sample(l3,k,expected(key,s,True))
 elif key=='coins':
  l2=replace_once(l2,r'0 \leq A, B, C \leq 50',r'0 \leq A, B, C \leq 200000')
  l2=replace_once(l2,r'$50 \leq X \leq 20$ $000$',r'$50 \leq X \leq 130000000$')
  l3=replace_once(l3,'they are $X$ yen in total?','they are at most $X$ yen in total? The empty selection is allowed.')
  l3=mutate_sample(l3,1,'4','There are four choices: take no coins; take one 50-yen coin; take two 50-yen coins; or take one 100-yen coin.')
  l3=mutate_sample(l3,2,'2','The total need not equal X. The empty selection and the selection of one 100-yen coin are both valid.')
  for k,(s,a)in enumerate(recipe.source_samples(rid),1):l3=mutate_sample(l3,k,expected(key,s,True))
 for condition,t in [('l2',l2),('l3',l3)]:
  (p/(condition+'.txt')).write_text(t)
  cert={'seed_id':sid,'source_identity':cfg['source_id'],'condition':condition,'raw_sha256':sha(raw),'mutated_sha256':sha(t),'edits':edits(raw,t),'test_domain':'expanded_native_bounds'if condition=='l2'else'original_native_bounds','changes':cfg['spec']['l2_changed_fields']if condition=='l2'else cfg['l3_operator'],'l1_independent':True}
  (p/(condition+'_certificate.json')).write_text(json.dumps(cert,ensure_ascii=False,indent=2)+'\n')
 samples=[{'name':f'public_sample_{i+1}','input':s,'raw_output':a,'l3_output':expected(key,s,True)}for i,(s,a)in enumerate(recipe.source_samples(rid))]
 for sample in samples:assert recipe.check_output(rid,sample['input'],expected(key,sample['input'],False),sample['raw_output'],'raw')
 (p/'native_samples.json').write_text(json.dumps(samples,ensure_ascii=False,indent=2)+'\n')
 out.append({'seed_id':sid,'replaces_source_identity':old[sid]['source_identity'],'replacement_reason':'Original source contains unresolved contradictory semantic or numerical statements.','source_identity':cfg['source_id'],'source':sources[sid],'recipe_id':rid,'recipe_module':'recipes/replacements.py','prompts':{v:f'tasks/{sid}/{v}.txt'for v in ['raw','l1','l2','l3']},'native_bounds':cfg['spec']['native_bounds'],'l2_bounds':cfg['spec']['strong_bounds'],'l3_operator':cfg['l3_operator'],'native_samples':f'tasks/{sid}/native_samples.json','validation_directory':'validation/replacement5_cpu2'if key=='sums'else'validation/replacements_cpu2','status':'awaiting_execution_report'})
(ROOT/'replacements/index.json').write_text(json.dumps({'records':out,'previous_seed_index_modified':False,'all_source_identities_distinct':len({x['source_identity']for x in out})==len(out)},ensure_ascii=False,indent=2)+'\n')
print('built replacement L2/L3 full prompts',len(out))
