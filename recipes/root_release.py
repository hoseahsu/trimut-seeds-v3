"""Standalone task contracts and executable version bounds for root batches.

This companion does not modify frozen recipe modules. Source-original is a
separate retained document; these are the standardized experimental versions.
"""
import importlib.util,json
from pathlib import Path

IO={
'phone':'Input n on the first line and a length-n decimal digit string on the second. Digits are individual cards that may be rearranged freely, and each card is used at most once. Output the maximum number of disjoint 11-digit phone numbers satisfying the stated leading-digit rule.',
'integer':'Input q; then q triples l r d. Each query concerns positive integer multiples of d. Output one answer per query.',
'errors':'Input n, array a of length n, array b of length n-1, and array c of length n-2. Each transition removes one occurrence and may reorder all remaining elements. Output two integers in transition order.',
'bulbs':'Input n m. Each of the next n lines contains x and then x bulb identifiers in [1,m]. A button is connected once to each listed identifier; repeated identifiers on one line do not create repeated connections. Initially all bulbs are off, and any button may be pressed any nonnegative number of times. Output YES if all bulbs can be on simultaneously, otherwise NO.',
'garden':'Input n k, then n positive bucket lengths. Repeatedly use a single chosen bucket to cover exactly length k without overlap; each use takes one hour. At least one listed length divides k. Output the optimum number of hours.',
'elections':'Input n followed by n positive vote counts a_i. Choose integer k>=max(a_i). One candidate receives sum(a_i) votes; the other receives sum(k-a_i). Output the minimum feasible k under the stated winning rule.',
'games':'Input n followed by n pairs h_i a_i of home/away colours. Every ordered pair of distinct teams plays once with the first team hosting. Output the number of ordered fixtures satisfying the stated colour equality.',
'keys':'Input n k p, n distinct person coordinates, and k distinct key coordinates, with n<=k. Assign different keys to the n people. Travel cost for person a and key b is |a-b|+|b-p|. Output the optimum value under the stated objective.',
'ocean':'Input N and N heights H_1,...,H_N, listed from west to east. Output the number of qualifying indices.',
'zeros':'Input N and N integers A_1,...,A_N. Distinct index intervals count separately even if their contents coincide. Output the number of qualifying nonempty contiguous subarrays.',
'knapsack':'Input N W, then N lines v_i w_i (value then weight). Each item can be selected at most once. Output the optimum total value or the specified impossibility token.',
'intersection':'Input n, n strictly increasing integers of A, then m and m strictly increasing integers of B. Output the result in increasing order, one integer per line; an empty result produces no tokens.',
'digits':'Input two decimal strings n and m on separate lines. n has no leading zero unless it is exactly 0; m may contain leading zeros. Output OK if m is exactly the required digit permutation string, otherwise WRONG_ANSWER. Preserve digit multiplicities; permutations of a nonzero n cannot have a leading zero.',
'counting':'Input t; each case starts a b q and then q pairs l r. Modulo denotes the nonnegative remainder. Output q interval counts per case in query order.',
'records':'Input n and n nonnegative scores in chronological order. Output the number of qualifying contests; contest1 never counts.',
'company':'Input n d, then n pairs m_i s_i of wealth and nonnegative friendship factor. Select any subset of friends satisfying the wealth-spread rule. Output the maximum friendship-factor sum.',
'monk':'Input t. Each case gives n, nonincreasing array A of length n, and nonincreasing array B of length n. Indices in the formula are zero-based, including n-1. Output one maximum index difference per case, or0 if no positive difference is feasible.',
'flat':'Input N K and N integers A_i. A subsequence preserves original order and may skip positions. Output the maximum possible length; a length-one subsequence is always allowed.',
'seven':'Input N. Inspect positive integers from1 through N in ordinary decimal notation without leading zeros. Output the count satisfying the digit condition.',
'playlist':'Input n k, then n pairs t_i b_i of length and beauty. Choose a nonempty subset of at most k songs. Output maximum pleasure under the stated aggregation rule.',
'ayoub':'Input t and then t pairs n m. Exactly m positions in a length-n binary string must be1. A substring is a nonempty contiguous interval. Output the optimal number of substrings containing at least one1.',
'agency':'Input t. Each case gives n k and n follower counts a_i. Select exactly k different indices; equal follower counts do not make indices identical. Output the number of optimal selections modulo1000000007.',
'power':'Input exponent n. Compute the stated residue of 1378^n; 1378^0=1. Output one integer in the canonical residue range, without zero padding.',
'histogram':'Input N and N nonnegative bar heights. Every bar has width1. Shapes have axis-parallel sides, lie on the histogram baseline, and must fit beneath all bars they cover. Output maximum area, allowing area0.',
'cars':'Input t. Each case gives n and n distinct positive maximum speeds in front-to-back order. Output the number of cars meeting the stated predecessor predicate.',
'elevator':'Input n and n resident counts a_i for floors1..n. A trip from floor a to b with rest floor x costs |x-a|+|a-b|+|b-x|. Every resident makes one trip i->1 and one trip1->i daily. Choose integer x in[1,n]. Output optimum total electricity.',
'parity':'Input t followed by t nonempty decimal strings. A legal operation swaps adjacent digits of different parity. Output the optimum reachable string for each case, retaining its full length and leading zeros.',
'tiles':'Input t. Each case gives n m x y followed by n grid rows of m characters. A dot is white; an asterisk is already-covered black. A1x1 tile costs x; an unrotated horizontal1x2 tile costs y. Cover every white cell exactly once and no black cell. Output optimum cost.',
'cypher':'Input n k and n positive array values. Count nonempty contiguous index intervals. Output the number satisfying the occurrence threshold.',
'pipeline':'Input n k. Initially there is one terminal pipe. For each x in2..k exactly one x-output splitter is available; using it replaces one terminal pipe by x terminal pipes, adding x-1. Reach exactly n terminal pipes. Output optimum number of splitters or-1.',
'powered':'Input t. Each case gives n and n integers a_i. At second x>=1 any subset of indices can each receive2^(x-1); choosing the empty subset is allowed. Output the least number of seconds for the required final order, possibly0.',
'regional':'Input t. Each case gives n, n university labels u_i in1..n, and n positive skills s_i. Apply the stated selection order independently within each university. For each k=1..n form as many full size-k teams as possible; leftovers are not sent. Output n total-skill values.',
'aqua':'Input t. Each case gives n and n positive shirt numbers. Friends are distinct even when numbers coincide. An adjacent swap flips the direction of both participants. All initially face right. Output YES or NO for the requested sorted final condition.',
'shift':'Input n and n integers. A right cyclic shift moves the last entry to the first position. Output minimum shifts in0..n-1 producing the required order, or-1.',
'substrings':'Input one uppercase string. Occurrences use their usual consecutive positions; nonoverlap means their two-position intervals are disjoint. Output YES or NO.',
'modulo':'Input n m and n nonnegative integers. A subsequence selects distinct positions in increasing order. Output YES iff a selection meeting the stated conditions exists, otherwise NO.',
'dance':'Input even n and q. Initially position i contains boy i (1-based). Each of q commands is either1 x (cyclic shift by x positions toward larger indices, wrapping at n) or2 (the specified simultaneous pair swaps). Negative x reverses the shift. Output n boy labels in final position order.',
'lara':'Input n m k. Coordinates are(row,column), both1-based. Start at(1,1), follow the prescribed nonrepeating traversal, and count each move to a neighboring cell as one. Output the coordinate after exactly k moves.',
'compositions':'Input t followed by t pairs N k. Count ordered length-N integer sequences with total k under the stated per-move lower bound. Output the exact integer count; no modulus.',
'payment':'Input positive integer N as a decimal string without leading zeros. Available banknotes have values1,10,100,... with unlimited copies for both parties. You pay some P>=N and receive change P-N. Minimize the stated cost across both banknote decompositions. Output the minimum integer cost.',
'taxi':'Input n m, then n+m strictly increasing coordinates x_i, then n+m flags t_i. A flag1 denotes a taxi and0 a rider; exactly m flags are1. Each rider is assigned independently. Output m rider counts in taxi-coordinate order.',
'doctor':'Input s b, then s attack values, then b pairs d_i g_i of defense and gold. Evaluate each ship independently with all bases initially available. Output s maximum-gold totals in ship order.',
'epic':'Input t. Each case gives n and n positive integers. Repeatedly delete any two different positions satisfying the stated value relation. Zero operations are allowed. Output the smallest achievable remaining length.',
'pocket':'Input n m followed by n uppercase words of length m. Apply the stated permissible permutations any number of times; consider a word appearing in any row afterward. Output the number of distinct obtainable words modulo1000000007.',
'languages':'Input n m, then one line per employee: k followed by k distinct language IDs in1..m. Lists may be empty. Teaching one language to one employee costs1. Output minimum total cost to achieve the stated communication condition.',
'tavas':'Input A B q. For each of q queries input l t m. The infinite progression is s_i=A+(i-1)B for i>=1. Output the largest r>=l satisfying both constraints in the task, or-1.',
'cellular':'Input n m, sorted nondecreasing city coordinates a_1..a_n, then sorted nondecreasing tower coordinates b_1..b_m. Duplicates are permitted. A tower covers distance at most radius r, inclusively. Output the least nonnegative integer radius for the required coverage condition.',
'magical':'Input n and n integers. Distinct nonempty contiguous index intervals count separately. Output the number satisfying the extrema relation.',
'pairs':'Input N>=2 and N nonnegative integers A_i. Sum the stated expression over unordered index pairs i<j. Output the residue modulo1000000007.',
'bricks':'Input N and N labels a_i in1..N. Delete at most N-1 positions, retaining relative order. Output minimum deletions to obtain the stated nonempty target form, or-1.',
'transform':'Input lowercase strings S and T of equal positive length. Letter substitutions act globally on all occurrences. Output Yes iff the stated class of renaming operations can transform S into T, otherwise No.',
'concat':'Input n L and n lowercase strings each of length L. Use every supplied string exactly once; duplicate strings remain separate items. Output the optimum concatenation.',
'consecutive':'Input one positive integer N per line, terminated by a line containing0 (not a dataset). Output one representation count for each preceding N. Each representation is determined by its first integer and its length>=2.',
'hotel':'Input t. Each case gives n, n arrival times a_i, then n departure times d_i, with a_i<d_i. Output maximum concurrent occupancy under the stated endpoint convention.',
'equation':'Input t and then t nonnegative integers a. XOR is bitwise exclusive OR on nonnegative integers. Output one exact solution count per a; no modulus.',
}

# Complete non-scale domains shared by the weak and strong profiles.
DOMAINS={
'phone':'n>=1. All characters are decimal digits.', 'integer':'1<=l<=r; d>=1; all values integral.',
'errors':'n>=3. All values positive; each successive multiset removes exactly one occurrence.',
'bulbs':'1<=n,m; each connection-list length is0..m, IDs1..m.',
'garden':'All bucket lengths positive; at least one divides k.', 'elections':'All a_i>=1.',
'games':'n>=2;1<=h_i,a_i<=100 and h_i!=a_i.', 'keys':'All coordinates positive; each of the two input lists is internally distinct.',
'ocean':'1<=H_i<=100.', 'zeros':'-10^9<=A_i<=10^9.',
'knapsack':'1<=W<=10^9,1<=v_i<=100,1<=w_i<=10^7.',
'intersection':'Set values0..10^9; each list is strictly increasing.',
'digits':'Both strings contain only decimal digits. n has canonical notation; m can have leading zeros.',
'counting':'1<=t<=10,1<=a,b<=200,1<=q<=20,1<=l<=r.',
'records':'0<=score<=10000.', 'company':'1<=d<=10^9,0<=m_i,s_i<=10^9.',
'monk':'1<=t<=10;1<=A_i,B_i<=10^12; both arrays nonincreasing.',
'flat':'0<=K,A_i<=300000.', 'seven':'N is a positive integer.',
'playlist':'1<=k<=n;1<=t_i,b_i<=10^6.', 'ayoub':'1<=t<=10;0<=m<=n.',
'agency':'1<=t<=10;1<=k<=n;1<=a_i<=n.', 'power':'n is nonnegative.',
'histogram':'0<=h_i<=10^9.', 'cars':'1<=t<=10; speeds1..2147483647, distinct within each case.',
'elevator':'0<=a_i<=100.', 'parity':'1<=t<=10; every string is nonempty and decimal.',
'tiles':'1<=t<=10,1<=n<=3,1<=x,y<=1000; grid alphabet is dot and asterisk.',
'cypher':'1<=k<=n;1<=a_i<=10^9.', 'pipeline':'1<=n<=10^18; k>=2.',
'powered':'1<=t<=10;-10^9<=a_i<=10^9.', 'regional':'1<=t<=10;1<=u_i<=n;1<=s_i<=10^9.',
'aqua':'1<=t<=10;1<=a_i<=100000.', 'shift':'n>=2;1<=a_i<=100000.',
'substrings':'Nonempty string of uppercase Latin letters.', 'modulo':'2<=m<=1000;0<=a_i<=10^9.',
'dance':'n is positive and even;1<=q;-n<=x<=n.', 'lara':'n is even;n,m>=2;0<=k<n*m.',
'compositions':'1<=t<=10;N,k>=1.', 'payment':'N is positive and in canonical decimal notation.',
'taxi':'1<=x_i<=10^9, strictly increasing; flags0/1 with exactly m taxis and n riders.',
'doctor':'0<=attack,defense<=10^9;0<=gold<=10000.', 'epic':'1<=t<=10;1<=a_i<=10^9.',
'pocket':'Uppercase Latin letters; all rows have the same positive length.',
'languages':'n>=2;2<=m<=6; per-person lists contain0..m distinct IDs in1..m.',
'tavas':'1<=A,B<=10^6;l,t,m positive.', 'cellular':'Coordinates in[-10^9,10^9], sorted within each list; duplicates allowed.',
'magical':'-10^9<=a_i<=10^9;n>=1.', 'pairs':'0<=A_i<=10^9;N>=2.',
'bricks':'1<=a_i<=N.', 'transform':'Lowercase Latin letters; equal, positive string lengths.',
'concat':'All strings lowercase, equal length1..5.', 'consecutive':'1..10 positive datasets followed by a single0 terminator.',
'hotel':'1<=t<=10;1<=a_i<d_i<=1000.', 'equation':'1<=t<=10;a is nonnegative.',
}
ROOT2_SCALE={
'ocean':('1<=N<=20','1<=N<=200000'),'zeros':('1<=N<=40','1<=N<=200000'),
'knapsack':('1<=N<=12','1<=N<=40'),'intersection':('1<=n,m<=40','1<=n,m<=200000'),
'digits':('Each string has1..8 digits','Each string has1..24 digits'),'counting':('r<=100','r<=10^12'),
'records':('1<=n<=40','1<=n<=200000'),'company':('1<=n<=12','1<=n<=40'),
'monk':('1<=n<=40','1<=n<=100000'),'flat':('1<=N<=40','1<=N<=300000'),
'seven':('N<=6000','N<=999999999'),'playlist':('1<=n<=12','1<=n<=40'),
'ayoub':('1<=n<=12','1<=n<=50'),'agency':('1<=n<=12','1<=n<=50'),
'power':('n<=1000','n<=1000000000'),'histogram':('1<=N<=40','1<=N<=100000'),
'cars':('1<=n<=40','1<=n<=100000'),'elevator':('1<=n<=40','1<=n<=200000'),
'parity':('Each length<=8,total length<=80','Total length<=1000000'),
'tiles':('1<=m<=10','1<=m<=80'),'cypher':('1<=n<=40','1<=n<=400000'),
'pipeline':('k<=12','k<=60'),
}

# Full replacement relations, not edit instructions attached to the old rule.
L3_RELATIONS={
'phone':'Maximize the number of disjoint 11-digit numbers starting with digit 0 that can be assembled by freely rearranging the supplied digit cards.',
'integer':'For each query (l,r,d), return the smallest positive multiple of d inside the closed interval [l,r], or -1 if none exists.',
'errors':'Each successive array removes exactly one occurrence and may reorder the rest. For each removal return the smallest one-based index of the removed value in the immediately preceding array.',
'bulbs':'All bulbs initially are off. Pressing a button toggles every bulb in its connection set. Decide whether some sequence of presses can make all bulbs on simultaneously.',
'garden':'Choose one listed bucket length a dividing k. Maximize the number of hours k/a to cover the whole segment using that bucket. At least one bucket is feasible.',
'elections':'Find the minimum integer k>=max(a_i) such that sum(k-a_i)>=sum(a_i).',
'games':'For every ordered pair of distinct teams, both the host and visitor use their home colours. Count the ordered pairs with h_i=h_j.',
'keys':'Assign distinct keys to all people. Person at a assigned key at b incurs |a-b|+|b-p| travel cost. Minimize the sum of these costs over all people.',
'ocean':'Count indices whose height is strictly greater than every earlier height; the first index counts.',
'zeros':'Count nonempty contiguous subarrays with strictly positive sum.',
'knapsack':'Select an odd number of items, each at most once, with total weight at most W. Maximize their total value; output -1 if no such subset exists.',
'intersection':'Print the symmetric difference of the two supplied sets in increasing order.',
'digits':'Decide whether the second string is exactly the lexicographically maximum permutation of the first string digits, with no leading zero unless the number is 0.',
'counting':'For each interval [l,r], count integers x with ((x%a)%b)==((x%b)%a).',
'records':'Count strict new record highs after the first contest: a score counts iff it is greater than every earlier score.',
'company':'Choose any subset of friends whose maximum wealth minus minimum wealth is at most d. Maximize the sum of their friendship factors; a singleton is feasible.',
'monk':'For the two nonincreasing arrays, maximize j-i over 0<=i<=j<n with B[j]>A[i]. Output 0 if no positive difference is feasible.',
'flat':'Find the longest subsequence in which every two consecutive selected values differ by strictly less than K in absolute value. A one-element subsequence is allowed.',
'seven':'Count positive integers at most N whose digits are all in {3,5,7} and which contain at least two distinct digits.',
'playlist':'Select a nonempty subset of at most k songs. Maximize the sum of selected lengths multiplied by the maximum selected beauty.',
'ayoub':'Among binary strings of length n having exactly m ones, minimize the number of nonempty substrings containing at least one 1.',
'agency':'Count the k-element index subsets with minimum total follower count. Output the count modulo 1000000007.',
'power':'Output 1378^n modulo 100 as an integer without zero padding.',
'histogram':'Find the maximum area of a square with axis-parallel sides and bottom on the baseline that fits under the supplied unit-width histogram.',
'cars':'Count cars for which at most one preceding car has a strictly smaller maximum speed. Preceding means earlier in the supplied front-to-back order.',
'elevator':'Choose a rest floor x in [1,n] to maximize the total daily electricity for all specified resident journeys.',
'parity':'Using any number of adjacent swaps of digits of different parity, obtain the lexicographically largest reachable string.',
'tiles':'Cover every white cell exactly once using 1x1 and horizontal 1x2 tiles, without covering black cells. Maximize the total tile cost.',
'cypher':'Count nonempty contiguous subarrays containing some value strictly more than k times.',
'pipeline':'Starting with one terminal pipe and at most one splitter of each size 2..k, reach exactly n terminal pipes. Maximize the number of splitters used; output -1 if impossible.',
'powered':'At second t>=1, add 2^(t-1) to any subset of array entries. Minimize elapsed seconds until the array is strictly increasing.',
'regional':'For every team size k=1..n, each university repeatedly sends its k weakest remaining students until fewer than k remain. Output the total skills sent for each k.',
'aqua':'All friends initially face right. An adjacent swap flips both participants directions. Decide whether some swaps can sort the shirt numbers nondecreasingly with every friend facing left.',
'shift':'Find the minimum number of right cyclic shifts making the array nonincreasing, or -1 if impossible.',
'substrings':'Decide whether the string contains an occurrence of AB followed by a nonoverlapping occurrence of BA.',
'modulo':'Decide whether an odd-cardinality subsequence has sum divisible by m. The chosen positions must be distinct.',
'dance':'Apply all commands to the circular arrangement. Type 1 x shifts all boys by x positions toward larger indices. Type 2 simultaneously swaps (2,3),(4,5),...,(n,1). Output the final arrangement.',
'lara':'Start at (1,1), traverse the first row rightward to (1,m), then traverse rows 2..n down the last column, up the preceding column, and so on, alternating vertical direction while moving left. Output the coordinate after k moves.',
'compositions':'Count ordered sequences of exactly N positive integers whose sum is k. Output the exact count.',
'payment':'Pay P>=N in decimal-power banknotes and receive P-N in change. Each paid note costs 1 and each returned note costs 2. Minimize the total cost over P and both note decompositions.',
'taxi':'Assign each rider to a nearest taxi, breaking distance ties toward the larger taxi coordinate. Output the number of riders assigned to each taxi.',
'doctor':'Each spaceship may loot every base whose defense is strictly less than its attack. For each ship independently, output the maximum total gold it can obtain.',
'epic':'Repeatedly delete any two positions having equal values. Minimize the number of remaining elements.',
'pocket':'Permute the whole rows of the supplied word table; individual letters cannot move between rows. Count distinct words that can appear in a row, modulo 1000000007.',
'languages':'A course teaches one language to one employee at cost 1. Minimize the cost until at least one language is known by every employee.',
'tavas':'For each query find the largest r>=l such that every progression term from l through r is at most t and their total is strictly less than m*t. Output -1 if no such r exists.',
'cellular':'Find the minimum nonnegative radius such that every city is within that radius of every tower.',
'magical':'Count nonempty contiguous subarrays whose maximum minus minimum is at most 1.',
'pairs':'Sum |A_i-A_j| over all pairs i<j, modulo 1000000007.',
'bricks':'Delete the fewest positions so the remaining nonempty sequence is K,K-1,...,1 for some K>=1. Output -1 if impossible.',
'transform':'Decide if one simultaneous letter-to-letter substitution can transform S into T. Every occurrence of a letter must have the same replacement, but different letters may share a replacement.',
'concat':'Concatenate all given strings in an order producing the lexicographically largest result.',
'consecutive':'Count representations of each N as the sum of at least two consecutive nonnegative integers.',
'hotel':'A guest occupies the hotel from its arrival time through its departure time, including both endpoints. Find the maximum simultaneous occupancy.',
'equation':'Count even nonnegative integers x satisfying a-(a XOR x)-x=0.',
}
ROOT1_SCALE={
'phone':('1<=n<=100','1<=n<=1000000'),
'integer':('1<=q<=20; 1<=l<=r<=100; 1<=d<=100','1<=q<=500; 1<=l<=r<=10^12; 1<=d<=10^12'),
'errors':('3<=n<=60; 1<=array values<=100','3<=n<=200000; 1<=array values<=10^9'),
'bulbs':('1<=n,m<=100; total listed connections<=10000','1<=n<=5000; 1<=m<=100000; total listed connections<=1000000'),
'garden':('1<=n<=100; 1<=k,a_i<=100','1<=n<=100; 1<=k,a_i<=10^10'),
'elections':('1<=n<=100; 1<=a_i<=100','1<=n<=100; 1<=a_i<=10^9'),
'games':('2<=n<=30','2<=n<=200000'),
'keys':('1<=n<=4; n<=k<=7; all coordinates in [1,100]','1<=n<=12; n<=k<=28; all coordinates in [1,10^9]'),
}

def load(name):
    p=Path(__file__).with_name(name+'.py');s=importlib.util.spec_from_file_location(name,p);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m

MODULES={name:load(name)for name in('root_batch','root_batch2','root_batch3')}
RELEASE={}
for name,m in MODULES.items():
    for id,r in m.RECIPES.items():
        key=r['key'];spec=r['spec']
        if name=='root_batch':
            weak,strong=ROOT1_SCALE[key]
        elif name=='root_batch2':weak,strong=ROOT2_SCALE[key]
        else:weak,strong=spec['weak_bounds'],spec['strong_bounds']
        RELEASE[id]={'module':name,'key':key,'title':r['title'],'canonical_raw':spec['raw_relation'],'canonical_l3':L3_RELATIONS[key],'io_protocol':IO[key],'shared_constraints':DOMAINS[key],'weak_constraints':weak,'strong_constraints':strong,
                     'l3_constraints':weak,'original_source_retained':True,'human_review_status':'not_performed','automated_review_scope':'recorded finite differential/source checks and measured complexity separation'}

def validate_version_input(id,text,condition):
    d=RELEASE[id];m=MODULES[d['module']]
    if condition=='source_original':raise ValueError('Use original source validator/test audit; standardized root validators intentionally do not certify every original bound.')
    if condition not in('raw','weak','l2','l3'):return False
    if not m.validate_input(id,text,condition):return False
    if d['module']=='root_batch'and d['key']=='integer'and condition!='l2':return int(text.split()[0])<=20
    if d['module']=='root_batch'and d['key']=='bulbs':
        v=list(map(int,text.split()));pos=2;total=0
        for _ in range(v[0]):total+=v[pos];pos+=v[pos]+1
        return total<=(1000000 if condition=='l2'else 10000)
    return True

if __name__=='__main__':
    out=Path(__file__).resolve().parents[1]/'curation/root_release.json';out.write_text(json.dumps(RELEASE,ensure_ascii=False,indent=2)+'\n');print(len(RELEASE))
