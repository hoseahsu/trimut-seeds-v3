from pathlib import Path
import importlib.util,json,re,hashlib
R=Path(__file__).resolve().parents[1]
a=json.loads((R/'library_work/native_inventory.json').read_text()); recipes={}
for f in sorted((R/'recipes').glob('library_batch*.py')):
 s=importlib.util.spec_from_file_location(f.stem,f);m=importlib.util.module_from_spec(s);s.loader.exec_module(m)
 for k,v in m.RECIPES.items():recipes[k]=(f,m,v)
risks={
 'range_kth_smallest':'Authored merge-sort-tree kth selection costs extra logarithmic factors; native time must be measured.',
 'static_range_inversions_query':'Mo/Fenwick implementation native N=Q=100000 requires native resource pilot.',
 'range_set_range_composite':'Authored lazy composition includes modular powers per tag; native resource pilot required.',
 'predecessor_problem':'Native N=10000000/Q=1000000 requires memory and initialization-time pilot.',
 'persistent_queue':'Authored binary-lifting table has 20 levels; native Q=500000 fits, expansions beyond 1048576 require capacity repair.',
 'subset_convolution':'2^N storage; expanding N from20 to21 doubles input and substantially increases rank-transform memory.',
 'wildcard_pattern_matching':'Two exact NTT moduli used; second transform supports at most2^21, so expanded text <=1048576 is structural limit without program repair.',
 'static_range_mode_query':'Authored L3 Mo ordered-frequency structure may not fit original5s at100000; unverified.',
 'maximum_independent_set':'Exponential search at native40; proposed42 requires adversarial pilot, not polynomial scalability claim.',
 'chromatic_number':'Exponential subset memory/time at native20; proposed21 requires native reference capacity and resource audit.',
 'minimum_enclosing_circle':'Native circle output uses floating checker tolerance; L3 bounding rectangle semantics must replace full output formula.',
 'general_weighted_matching':'Native implementation may have fixed capacity near500; expansion requires capacity-only source repair and revalidation.',
 'counting_spanning_tree_directed':'Cubic matrix computation; expand edge-count M only to retain native matrix dimension.',
 'counting_spanning_tree_undirected':'Cubic matrix computation; expand edge-count M only to retain native matrix dimension.',
}
literal={'point_set_range_composite':('N,Q',500000),'queue_operate_all_composite':('Q',500000),'deque_operate_all_composite':('Q',500000),'vertex_add_subtree_sum':('N,Q',500000),'sum_of_floor_of_linear':('T',100000),'rectangle_sum':('N,Q',200000),'number_of_substrings':('|S|',500000),'scc':('N,M',500000)}
rows=[]
for x in a:
 id=x['id'];f,m,c=recipes[id];p=x['native_params'];changes={}
 if id in literal:
  dim,b=literal[id];changes={'literal_upper_bound':{'dimension':dim,'native':b,'expanded':b*2}}
 else:
  keys=[k for k in p if any(t in k for t in ('N_MAX','Q_MAX','MAX_N','MAX_Q','T_MAX','SUM_N_MAX','S_LEN_MAX')) and 'SMALL' not in k]
  if id in ['counting_spanning_tree_directed','counting_spanning_tree_undirected']:keys=['M_MAX']
  if any('Q' in k for k in keys):keys=[k for k in keys if 'Q'in k]
  elif 'SUM_N_MAX'in keys:keys=['SUM_N_MAX']
  elif 'N_MAX'in keys:keys=['N_MAX']
  elif 'MAX_N'in keys:keys=['MAX_N']
  elif 'T_MAX'in keys:keys=['T_MAX']
  assert keys,(id,p)
  for k in keys:
   b=p[k];e=(b+1 if b==20 else b+2 if id=='maximum_independent_set' else b*2)
   changes[k]={'native':b,'expanded':e}
 tests=[t for t in x['tests']if t['name'].endswith('.cpp')]
 selected=[]
 def pick(t,seed,role):
  if not any(s['generator']==t['name']and s['seed']==seed for s in selected):selected.append({'generator':t['name'],'seed':seed,'role':role})
 small=next((t for t in tests if any(z in t['name']for z in ('small','tiny','mini'))),None)
 if small:pick(small,0,'native_small_structural')
 rand=next((t for t in tests if t['name']=='random.cpp'),None)
 if rand:pick(rand,0,'native_random')
 maxi=next((t for name in ['max_random.cpp','max.cpp','big.cpp','wide_max.cpp','random_max_1.cpp','max_convex.cpp','large_random.cpp','increasing.cpp']for t in tests if t['name']==name),None)
 if maxi:pick(maxi,0,'native_scale_candidate')
 elif rand:pick(rand,rand['number']-1,'native_scale_candidate')
 else:pick(tests[-1],tests[-1]['number']-1,'native_scale_candidate')
 structural=next((t for t in tests if any(z in t['name']for z in ('line.cpp','all_same','near_border','max_lazy','max_ans','dense','hack'))),None)
 if structural:pick(structural,0,'native_structural_boundary')
 rows.append({**x,'recipe_module':str(f.relative_to(R)),'l3_fast':c['l3_fast'],'l3_mutation_name':c['mutation_name'],'l3_mutation_specification':c['mutation_specification'],'l3_proof_sketch':c['proof_sketch'],'l2_proposed_changes':changes,'selected_upstream_generators':selected,'strict_status':{'raw_original_render':'verified_source_english_template_and_all_sample_hashes','raw_original_domain_tests':'pending_selected_subset','l1_same_test_manifest':'pending','l2_native_upper_bound_expansion':'candidate_not_validated','l2_algorithm_resource_separation':'not_established_old_weak_domain_evidence_not_transferable','l3_native_domain_correctness':'pending','l3_native_domain_resources':'pending'},'risk':risks.get(id,'Native-domain program correctness, capacities, and resource budget have not yet been measured; no transfer of old small-cap validation claims.'),'universal_correctness_claim':False})
(R/'library_work/native_strict_plan.json').write_text(json.dumps(rows,indent=2,ensure_ascii=False)+'\n')
print('wrote',len(rows),'plans')
