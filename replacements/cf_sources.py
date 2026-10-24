from pathlib import Path
import json,hashlib
from fetch_sources import ROOT,write_raw
DATA={
'TM001':('337_A','A. Puzzles',1,'''The end of the school year is near and Ms. Manana, the teacher, will soon have to say goodbye to a yet another class. She decided to prepare a goodbye present for her n students and give each of them a jigsaw puzzle (which, as wikipedia states, is a tiling puzzle that requires the assembly of numerous small, often oddly shaped, interlocking and tessellating pieces).

The shop assistant told the teacher that there are m puzzles in the shop, but they might differ in difficulty and size. Specifically, the first jigsaw puzzle consists of f_1 pieces, the second one consists of f_2 pieces and so on.

Ms. Manana doesn't want to upset the children, so she decided that the difference between the numbers of pieces in her presents must be as small as possible. Let A be the number of pieces in the largest puzzle that the teacher buys and B be the number of pieces in the smallest such puzzle. She wants to choose such n puzzles that A - B is minimum possible. Help the teacher and find the least possible value of A - B.

Input

The first line contains space-separated integers n and m (2 ≤ n ≤ m ≤ 50). The second line contains m space-separated integers f_1, f_2, ..., f_m (4 ≤ f_i ≤ 1000) — the quantities of pieces in the puzzles sold in the shop.

Output

Print a single integer — the least possible difference the teacher can obtain.

Examples

Input

4 6
10 12 10 7 5 22

Output

5

Note

Sample 1. The class has 4 students. The shop sells 6 puzzles. If Ms. Manana buys the first four puzzles consisting of 10, 12, 10 and 7 pieces correspondingly, then the difference between the sizes of the largest and the smallest puzzle will be equal to 5. It is impossible to obtain a smaller difference. Note that the teacher can also buy puzzles 1, 3, 4 and 5 to obtain the difference 5.
''',[('4 6\n10 12 10 7 5 22\n','5\n')]),
'TM017':('43_A','A. Football',2,'''One day Vasya decided to have a look at the results of Berland 1910 Football Championship’s finals. Unfortunately he didn't find the overall score of the match; however, he got hold of a profound description of the match's process. On the whole there are n lines in that description each of which described one goal. Every goal was marked with the name of the team that had scored it. Help Vasya, learn the name of the team that won the finals. It is guaranteed that the match did not end in a tie.

Input

The first line contains an integer n (1 ≤ n ≤ 100) — the number of lines in the description. Then follow n lines — for each goal the names of the teams that scored it. The names are non-empty lines consisting of uppercase Latin letters whose lengths do not exceed 10 symbols. It is guaranteed that the match did not end in a tie and the description contains no more than two different teams.

Output

Print the name of the winning team. We remind you that in football the team that scores more goals is considered the winner.

Examples

Input

1
ABC

Output

ABC

Input

5
A
ABA
ABA
A
A

Output

A
''',[('1\nABC\n','ABC\n'),('5\nA\nABA\nABA\nA\nA\n','A\n')])}
out={}
for sid,(pid,title,seconds,body,samples) in DATA.items():
 folder=ROOT/'sources'/'replacement_official'/('cf_'+pid);folder.mkdir(parents=True,exist_ok=True)
 raw='# '+title+'\n\n'+body
 (folder/'original_statement.md').write_text(raw)
 source={'source_identity':'codeforces:'+pid,'source_dataset':'Codeforces official','source_problem_id':pid,'source_url':'https://codeforces.com/problemset/problem/'+pid.replace('_','/'),'original_statement':str((folder/'original_statement.md').relative_to(ROOT)),'source_package':str(folder.relative_to(ROOT)),'source_tests':str((folder/'source_tests.json').relative_to(ROOT)),'title':title,'statement_sha256':hashlib.sha256(raw.encode()).hexdigest(),'native_budget_seconds':seconds,'source_reference':None,'license_note':'Original publisher copyright retained; official source snapshot for local research; no blanket redistribution licence asserted.'}
 (folder/'source_tests.json').write_text(json.dumps({'public_tests':{'input':[x[0]for x in samples],'output':[x[1]for x in samples]},'private_tests':{'input':[],'output':[]},'generated_tests':{'input':[],'output':[]}},indent=2)+'\n')
 (folder/'source_metadata.json').write_text(json.dumps({'source':source,'retrieval_method':'Official website visible DOM read with Chrome cua_repl; cross-checked with web.open official URL on 2026-10-22.','render_policy':'Complete problem statement through Note, with narrative, input, output, samples and explanation preserved. Source subscript typography rendered as underscores; site Copy buttons and navigation removed. Native resource limits stored separately.'},indent=2)+'\n')
 write_raw(sid,raw,source,'official_visible_dom_transcribed_with_typographic_formatting_only');out[sid]=source
(ROOT/'replacements'/'cf_sources.json').write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n')
print('Codeforces official original texts saved',list(out))
