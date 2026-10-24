#!/usr/bin/env python3
"""Render L2 bound edits and L3 logical edits from full source-faithful Raw text."""
from pathlib import Path
import hashlib,json,re,sys
R=Path(__file__).resolve().parents[1]
P={
221:[(r'\min(',r'\max(')],
222:[('th smallest','th largest')],
223:[('increasing subsequence','nondecreasing subsequence')],
224:[('minimal $y$','maximal $y$')],225:[('minimal $y$','maximal $y$')],
226:[('The smallest element','The largest element')],227:[('minimum spanning tree','maximum spanning tree')],
228:[('that minimize','that maximize')],
229:[('the number of times $x$ occurs in $a_{l}, a_{l+1}, \\ldots, a_{r-1}$','the number of elements strictly smaller than $x$ in $a_{l}, a_{l+1}, \\ldots, a_{r-1}$')],
230:[(r'$B_i \gt B_j$',r'$B_i \geq B_j$')],231:[(r'\min_{l',r'\max_{l')],232:[(r'\min_{i',r'\max_{i')],
233:[(r'f_{r-1}(f_{r-2}(...f_l(x)))',r'f_l(f_{l+1}(...f_{r-1}(x)))')],
234:[(r'f _ {r-1}(f _ {r-2}(...f _ l(x)))',r'f _ l(f _ {l+1}(...f _ {r-1}(x)))')],
235:[(r'f _ {r - 1}(f _ {r - 2}(\dots (f _ l(x)) \dots))',r'f _ l(f _ {l+1}(\dots (f _ {r-1}(x)) \dots))')],
236:[(r'f _ {r - 1}(f _ {r - 2}(\dots (f _ l(x)) \dots))',r'f _ l(f _ {l+1}(\dots (f _ {r-1}(x)) \dots))')],
237:[(r'\sum_{i = l}^{r - 1}{a_i}',r'\max_{l \leq i < r} a_i')],
238:[('Print the sum of the values','Print the maximum of the values')],239:[('Print the sum of values','Print the maximum of values')],
240:[(r'\sum _ {i = l} ^ {r - 1} a _ i',r'\max(\{0\}\cup\{a_i:l\leq i<r\})')],
241:[(r'\sum_{i = l}^{r - 1} a_i',r'\sum_{i = l}^{r - 1} a_i^2')],
242:[('the number of distinct integers that occur in','the number of distinct integers that occur exactly once in')],
243:[('the $x$-th smallest element of $S$ in ascending order','the $x$-th largest element of $S$ in descending order')],
244:[('the smallest key which is greater than or equal to $k$','the smallest key which is strictly greater than $k$')],
245:[(r'$a[k] \gets v$',r'$a[k] \gets a[k]+v$')],
246:[('the majority element in $(a_l, a_{l+1}, ..., a_{r-1})$. If there is no majority element','an element whose occurrence count $f$ satisfies $3f>2(r-l)$ in $(a_l, a_{l+1}, ..., a_{r-1})$. If there is no such element')],
247:[('deleting the front element','deleting the back element')],
248:[(r'\And',r'\mathbin{|}'),('bitwise-AND','bitwise-OR')],
249:[(r'\oplus',r'\And'),('bitwise-XOR','bitwise-AND')],
250:[(r'\gcd(i,j)',r'\mathrm{lcm}(i,j)')],251:[(r'\mathrm{lcm}(i,j)',r'\gcd(i,j)')],
252:[(r'i \And j = 0, i | j = k',r'i | j = k')],253:[('floor((A','ceil((A')],254:[(r'\textrm{floor}',r'\textrm{ceil}'),(r'a^{1/k}',r'A^{1/K}')],
255:[(r'l \leq x < r',r'l \leq x \leq r')],256:[(r'l \leq x < r',r'l \leq x \leq r')],
257:[(r'[l_i,r_i)',r'[l_i,r_i]'),(r'l_i\leq x<r_i',r'l_i\leq x\leq r_i'),(r'[l,r)',r'[l,r]')],
258:[('distinct__ substrings of $S$','distinct__ nonempty substrings of even length of $S$')],
259:[('* $S\'_i$ = `*`\n','')],
260:[('is the Lyndon Factorization of $S$','is the Lyndon Factorization of $S$ under the alphabet order $z<y<\\cdots<a$. In this order a proper prefix is still smaller than the longer string. A nonempty string is Lyndon if it is strictly smaller than each of its nonempty proper suffixes; its Lyndon factorization is the unique decomposition into a lexicographically nonincreasing sequence of Lyndon strings')],
261:[('the area of the union set of these rectangles','the area of points covered by at least two of these rectangle instances (identical input rectangles count separately)')],
262:[('the number of distinct subsequence of $A$','the number of distinct nonempty subsequences of even length of $A$')],
263:[('a palindromic substring','a complementary-palindrome substring'),('the maximum palindrome centered there','the maximum complementary-palindrome centered there')],
264:[('the LCP(longest common prefix) of $S$ and $S.substr(i)$','the largest integer $k$ with $0\\leq k\\leq N-i$ such that $S_j$ and $S_{i+j}$ are complementary letters for every $0\\leq j<k$')],
265:[('the Euclidean distance between two points','the Manhattan distance $|x_i-x_j|+|y_i-y_j|$ between two points')],
266:[('the Euclidean distance between two points','the Manhattan distance $|x_i-x_j|+|y_i-y_j|$ between two points')],
267:[('the Euclidean distance','the Manhattan distance $|x_i-x_j|+|y_i-y_j|$')],
269:[('a mode of $a_{l}, a_{l+1}, \\ldots, a_{r-1}$, and the number of the occurrence of it. If there exists multiple modes','a value that occurs the least positive number of times in $a_{l}, a_{l+1}, \\ldots, a_{r-1}$, and its occurrence count. Values absent from the range are ineligible. If there are multiple eligible minimizing values')],
270:[('the minimum enclosing circle','the smallest axis-aligned enclosing rectangle'),('the circumference (boundary)','the boundary'),('on the the circumference','on the boundary')],
271:[('Print LCA of vertex $u$ and $v$','Treat the supplied parent edges as undirected edges, root the same tree at vertex $N-1$, and print the LCA of vertex $u$ and $v$ in this new rooting')],
272:[('from $s$ to $t$','from $t$ to $s$'),(r'($v_0 = s$, $v_k = t$)',r'($v_0 = t$, $v_k = s$)')],
273:[('Find a pair of vertices $(u, v)$ that are farthest apart, and output the path from $u$ to $v$.','For a simple path, define its score as the largest edge weight on it; the score of a singleton path is $0$. Find a simple path of maximum score and output it.'),('the sum of weights on the path','the largest edge weight on the path (or $0$ for a singleton path)')],
274:[('Classify them by isomorphism of rooted trees.','At every vertex, order its children by increasing original vertex index. Classify the subtrees by isomorphism of ordered rooted trees, which must preserve the order of children.'),('are isomorphic.','are isomorphic as ordered rooted trees.')],
275:[(r'f_{p_k}(...f_{p_2}(f_{p_1}(x)))',r'f_{p_1}(f_{p_2}(...f_{p_k}(x)))')],
276:[('the maximum independent set','a maximum clique (a largest set of pairwise adjacent vertices)'),('the size of MIS','the size of the maximum clique')],
277:[('the chromatic number $C$','the maximum clique size $C$, namely the largest number of pairwise adjacent vertices')],
278:[('the number of spanning trees of the graph','the number of pairs consisting of a spanning forest of the graph and one selected root vertex in each component. Parallel edge instances are distinct choices; self-loops cannot belong to a forest. Count these pairs')],
279:[('all the vertices have to be reachable from $r$','all the vertices have to be able to reach $r$')],
280:[('directed minimum spanning tree','directed maximum spanning tree'),('the directed MST','the directed maximum spanning tree')],
281:[('the number of times $x$ occurs in $a_{l}, a_{l+1}, \\ldots, a_{r-1}$','the number of elements strictly smaller than $x$ in $a_{l}, a_{l+1}, \\ldots, a_{r-1}$')],
282:[(r'\sum_{k=l_i}^{r_i-1} a_k',r'\sum_{k=l_i}^{r_i-1} (-1)^{k-l_i}a_k')],
283:[('not greater than $x$','not smaller than $x$')],
284:[(r'a_i \gets b \times a_i + c',r'a_i \gets b \times (a_i + c)')],
285:[(r'\min_{i',r'\max_{i')],286:[('longest increasing subsequence','longest strictly decreasing subsequence')],
287:[('in $[l,r)$','in $(l,r]$')],288:[('in $[l,r)$','in $(l,r]$')],
289:[('is minimized','is maximized'),('minimum value of $X$','maximum value of $X$')],
290:[(r'\mathrm{same}(i,j)x_ix_j',r'\mathrm{same}(i,j)(x_i-x_j)^2')],
291:[('Print the sum of values of vertices','Print the maximum value of vertices')],
292:[(r'f_{p_k}(...f_{p_2}(f_{p_1}(x)))',r'f_{p_1}(f_{p_2}(...f_{p_k}(x)))')],
293:[(r'\sum_{i = l}^{r - 1} a_i',r'\sum_{i = l}^{r - 1} a_i^2')],
294:[(r'\sum_{j = l} ^ {r - 1} a _ j',r'\sum_{j = l} ^ {r - 1} (a _ j)^2')],
295:[(r'\sum _ {i = l} ^ {r-1} a_i',r'\sum _ {i = l} ^ {r-1} a_i^2')],
296:[(r'f_{r-1}(f_{r-2}(...f_l(x)))',r'f_l(f_{l+1}(...f_{r-1}(x)))')],
297:[('Output the sum of values','Output the maximum value')],
298:[('Calculate the matching in which the sum of weights is maximized.','First maximize the number of edges in a matching. Among matchings with this maximum number of edges, minimize the sum of their original weights.'),('the maximum matching weight','the minimum weight among matchings with the maximum number of edges')],
299:[('decompose this graph into SCCs and print them in topological order','ignore edge directions and decompose this graph into weakly connected components, in any order'),('SCCs','weakly connected components'),('SCC','weakly connected component'),('For each edge $(a_i, b_i)$, the line that contains $b_i$ can not be earlier than the line that contains $a_i$.','There is no ordering requirement among distinct components.')],
300:[('the complement graph of $G$','the supplied graph $G$')],
}
ADD={
254:'Equivalently, output the least nonnegative integer $r$ such that $r^K\\geq A$; the root and ceiling are mathematical exact operations.',
223:'A nondecreasing subsequence uses strictly increasing indices and allows equal consecutive values.',
250:'Only indices $1\\leq i,j,k\\leq N$ occur. A pair whose least common multiple exceeds $N$ contributes to no output entry.',
259:'In this relation, an asterisk in the text is a literal character; it matches only a pattern asterisk. A pattern asterisk matches any single text character.',
263:'Two letters are complementary when they form one of the pairs a/z, b/y, ..., m/n. A complementary palindrome must have complementary letters at every pair of mirrored positions, including the central position if its length is odd. Consequently no odd-length substring qualifies.',
264:'Two letters are complementary when they form one of the pairs a/z, b/y, ..., m/n; no letter is complementary to itself.',
270:'Explicitly, the rectangle is $[\\min_i x_i,\\max_i x_i]\\times[\\min_i y_i,\\max_i y_i]$. A point is on its boundary exactly when either coordinate is an endpoint of the corresponding interval; this definition includes degenerate rectangles.',
}
HULL='''This problem has $T$ cases.

Given $N$ 2D points $(x_i,y_i)$, output every distinct input point on the boundary of their convex hull. For a nondegenerate hull, list them in counterclockwise boundary order; any cyclic rotation is accepted. For collinear input, list all distinct points in monotone order along the segment, in either direction. An empty input yields an empty list, and a single distinct point is listed once. Coincident input points must not be repeated in the output.'''
def sha(b):return hashlib.sha256(b).hexdigest()
def split_constraints(t):
 a=t.index('## Constraints');b=t.find('\n## ',a+3)
 assert b>=0;return t[:a],t[a:b],t[b:]
def l3_text(item):
 n=int(item['seed_id'][2:]);raw=(R/'tasks'/item['seed_id']/'raw.txt').read_text();prefix=raw.split('## Sample Input 1')[0]
 # Remove the empty Sample heading that precedes expanded sample sections.
 prefix=re.sub(r'\n## Sample\s*$', '\n',prefix)
 before,cons,after=split_constraints(prefix);parts=before+'@@CONSTRAINTS@@'+after;edits=[]
 if n==268:
  a=parts.index('## Problem Statement')+len('## Problem Statement');b=parts.index('@@CONSTRAINTS@@');old=parts[a:b];parts=parts[:a]+'\n\n'+HULL+'\n\n'+parts[b:];edits.append({'original':old,'replacement':HULL})
 else:
  for old,new in P[n]:
   assert old in parts,(n,'unmatched_patch',old);edits.append({'original':old,'replacement':new,'occurrences':parts.count(old)});parts=parts.replace(old,new)
 if n in ADD:parts=parts.replace('@@CONSTRAINTS@@',ADD[n]+'\n\n@@CONSTRAINTS@@')
 result=parts.replace('@@CONSTRAINTS@@',cons)
 # A distinct title avoids carrying an unqualified contradictory original objective name.
 result=re.sub(r'^# .*', '# '+item['l3_mutation_name'].split('→')[-1].strip(),result,count=1)
 native=R/'validation/library_native_domain'/item['id'];examples=[]
 for ix,name in enumerate(item['example_names'],1):
  out=native/'l3_fast'/(name+'.stdout');run=native/'l3_fast'/(name+'.run.json');oracle=native/'l3_oracle'/(name+'.stdout')
  assert out.exists()and json.loads(run.read_text())['status']=='OK',(n,'l3_sample_pending',name)
  inp=(R/'library_work/native_examples'/item['id']/(name+'.in')).read_text();ans=out.read_text()
  result+=f'\n## Sample Input {ix}\n\n```\n{inp.rstrip()}\n```\n\n## Sample Output {ix}\n\n```\n{ans.rstrip()}\n```\n'
  examples.append({'name':name,'input_sha256':sha(inp.encode()),'l3_output_sha256':sha(ans.encode()),'l3_output_path':str(out.relative_to(R))})
 assert split_constraints(result)[1]==cons
 return result,{'semantic_edits':edits,'additional_definitions':ADD.get(n),'native_constraints_identical':True,'samples':examples,'raw_sha256':sha(raw.encode())}
def main():
 rows=[]
 for x in json.loads((R/'library_work/native_strict_plan.json').read_text()):
  try:
   text,log=l3_text(x);p=R/'tasks'/x['seed_id'];(p/'l3.txt').write_text(text);log.update({'l3_sha256':sha(text.encode()),'source_id':x['id'],'seed_id':x['seed_id']});(p/'l3_render_provenance.json').write_text(json.dumps(log,indent=2,ensure_ascii=False)+'\n');rows.append({'seed_id':x['seed_id'],'id':x['id'],'l3_render':'ready'})
  except Exception as e:rows.append({'seed_id':x['seed_id'],'id':x['id'],'l3_render':'pending','error':repr(e)})
 (R/'library_work/l3_render_status.json').write_text(json.dumps(rows,indent=2)+'\n');print(json.dumps(rows,indent=2))
if __name__=='__main__':main()
