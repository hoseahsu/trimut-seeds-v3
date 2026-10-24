#!/usr/bin/env python3
"""Diagnostic native-source replay; this report alone never admits a seed.

All supplied upstream tests are retained. Invalid-domain and failed-output cases
are explicit findings, never silently removed from a passing release suite.
"""
import argparse
from collections import Counter
from datetime import datetime, timezone
import json
from pathlib import Path
import sys

BASE=Path(__file__).resolve().parents[1]
sys.path[:0]=[str(BASE/'recipes'),str(BASE/'assets')]
import validate

def main():
    ap=argparse.ArgumentParser();ap.add_argument('--start',type=int,default=1);ap.add_argument('--end',type=int,default=220);ap.add_argument('--max-findings',type=int,default=3)
    args=ap.parse_args()
    seeds=[json.loads(x)for x in (BASE/'curation/previous_seed_index.jsonl').read_text().splitlines()]
    sandbox=validate.Sandbox();assert sandbox.available,sandbox.probe
    modules={}
    for seed in seeds:
        number=int(seed['seed_id'][2:])
        if not args.start<=number<=args.end or seed['source']['source_dataset']!='CodeContests':continue
        sid=seed['seed_id'];out=BASE/'validation/native_raw_audit'/sid;report_path=out/'report.json'
        if report_path.exists():
            old=json.loads(report_path.read_text())
            if old.get('status')=='complete':print(json.dumps({'seed_id':sid,'cached':True,'summary':old.get('summary')}),flush=True);continue
        out.mkdir(parents=True,exist_ok=True)
        source=seed['source'];tests_path=BASE/source['source_tests'];tests=json.loads(tests_path.read_text())
        metadata=json.loads((BASE/source['source_package']/'source_metadata.json').read_text())
        native_limit=metadata.get('time_limit')or{}
        if isinstance(native_limit,dict):native_limit=float(native_limit.get('seconds',0))+float(native_limit.get('nanos',0))/1e9
        budget=max(5.0,float(native_limit or 0))
        report={'seed_id':sid,'source_identity':seed['source_identity'],'status':'running','admitted':False,
                'scope':'Diagnostic replay of existing reference on upstream tests. Not final qualification; native-domain validator and statement audit are separate.',
                'started_at_utc':datetime.now(timezone.utc).isoformat(),'tests_sha256':validate.file_hash(tests_path),
                'budget_seconds':budget,'memory_mb':2048,'upstream_test_count':sum(len(v['input'])for v in tests.values()),
                'runs':[],'findings':[]}
        validate.write_json(report_path,report)
        try:
            module_path=BASE/seed['recipe_module']
            if str(module_path)not in modules:modules[str(module_path)]=validate.load_recipe(module_path)
            m=modules[str(module_path)];rid=seed['recipe_id'];cfg={**m.RECIPES[rid],'memory_mb':2048,'max_output_bytes':128*1024**2}
            programs=validate.Programs(sandbox,module_path.parent,out,cfg);report['program']=programs.prepare('raw_fast')
            stop=False
            for kind,collection in tests.items():
                assert len(collection['input'])==len(collection['output'])
                for i,(inp,expected)in enumerate(zip(collection['input'],collection['output'])):
                    name=f'{kind}_{i:04d}';prefix=out/'cases'/name
                    item={'name':name,'input_sha256':validate.sha(inp.encode()),'upstream_expected_sha256':validate.sha(expected.encode())}
                    try:
                        if hasattr(m,'validate_version_input'):ok=m.validate_version_input(rid,inp,'source_original')
                        else:ok=m.validate_input(rid,inp,'raw')
                        item['legacy_native_validator']='accepted'if ok is True else'rejected'
                    except Exception as exc:item['legacy_native_validator']='error';item['validator_error']=repr(exc)
                    # Run even if the old validator rejects: the diagnostic may
                    # expose a weak-domain restriction or a permitted sample exception.
                    run=programs.run('raw_fast',inp,budget,prefix);item['run']=run
                    if run['status']=='OK':
                        try:passed=validate.accepted(m,rid,inp,validate.output(run),expected,'raw')
                        except Exception as exc:passed=False;item['checker_error']=repr(exc)
                        item['verdict']='MATCH'if passed else'OUTPUT_MISMATCH'
                    else:item['verdict']=run['status']
                    report['runs'].append(item)
                    if item['verdict']!='MATCH':report['findings'].append({'case':name,'verdict':item['verdict']})
                    if len(report['findings'])>=args.max_findings:stop=True;break
                validate.write_json(report_path,report)
                if stop:break
            report['summary']=dict(Counter(x['verdict']for x in report['runs']))
            report['all_upstream_cases_executed']=len(report['runs'])==report['upstream_test_count']
            report['native_validator_summary']=dict(Counter(x['legacy_native_validator']for x in report['runs']))
            report['status']='complete'
        except Exception as exc:report['status']='error';report['findings'].append({'error':repr(exc)})
        validate.write_json(report_path,report)
        print(json.dumps({k:report.get(k)for k in ['seed_id','status','summary','native_validator_summary','findings']},ensure_ascii=False),flush=True)

if __name__=='__main__':main()
