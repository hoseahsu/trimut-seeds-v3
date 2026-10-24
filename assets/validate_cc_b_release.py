"""Audit deterministic published version profiles and canonical text; execute no submissions."""
import importlib.util,json,random
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
report={'note':'Release input-profile audit; every advertised bound key is measured, missing metrics reject. No submitted/reference programs executed.','recipes':{},'errors':[]}
for name in ['codecontests_batch2','cc_b_batch3','cc_b_batch4','cc_b_batch5']:
 spec=importlib.util.spec_from_file_location(name,ROOT/'recipes'/f'{name}.py');mod=importlib.util.module_from_spec(spec);spec.loader.exec_module(mod)
 for id,cfg in mod.RECIPES.items():
  count=0
  for seed in [0,137,7131]:
   for mode in ['small','boundary','weak','stress']:
    for case,txt in mod.cases(id,mode,random.Random(seed)):
     conditions=['l2']if mode=='stress'else['raw','weak','l3','l2']
     for condition in conditions:
      if not mod.validate_version_input(id,txt,condition):report['errors'].append([id,seed,case,condition])
      count+=1
     if mode=='stress'and mod.validate_version_input(id,txt,'weak'):report['errors'].append([id,seed,'stress admitted as weak'])
  for bad in ['', 'garbage', '-1', '0\n']:
   if mod.validate_version_input(id,bad,'unknown'):report['errors'].append([id,'unknown condition admitted'])
  if cfg['canonical_statement_raw']==cfg['canonical_statement_l3']:report['errors'].append([id,'identical canonical statements'])
  report['recipes'][id]={'profile_checks':count,'canonical_statements_distinct':True,'invariant_constraints_present':bool(cfg.get('invariant_constraints'))}
(ROOT/'assets/cc_b_release_validation.json').write_text(json.dumps(report,indent=2));print('recipes',len(report['recipes']),'checks',sum(x['profile_checks']for x in report['recipes'].values()),'errors',report['errors'])
raise SystemExit(bool(report['errors']))
