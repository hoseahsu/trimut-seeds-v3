"""Record agent cross-review decisions and verify the reviewed frozen snapshot.

This records an already performed text/contract review. It does not automate
semantic review, certify every legal input, or claim independent human review.
"""
from pathlib import Path
import hashlib
import json
import sys
from datetime import datetime, timezone

B = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(B / 'native'))
import cc_a82

cache = {}
def sha(path):
    path = Path(path)
    if path not in cache:
        cache[path] = hashlib.sha256(path.read_bytes()).hexdigest()
    return cache[path]

def ref(path):
    path = Path(path)
    return {'path': str(path.relative_to(B)), 'sha256': sha(path)}

def check_refs(value):
    if isinstance(value, dict):
        if 'path' in value and 'sha256' in value:
            assert sha(B / value['path']) == value['sha256'], value['path']
        for child in value.values():
            check_refs(child)
    elif isinstance(value, list):
        for child in value:
            check_refs(child)

rows = []
for k in range(56, 138):
    if k == 70:
        continue
    sid = f'TM{k:03d}'
    folder = B / 'tasks' / sid
    cp = B / 'contracts/cc_a' / (sid + '.json')
    c = json.loads(cp.read_text())
    check_refs(c)
    assert c['admitted']
    assert (folder / 'raw_test_manifest.json').read_bytes() == (folder / 'l1_test_manifest.json').read_bytes()
    manifests = {q: json.loads((folder / (q + '_test_manifest.json')).read_text()) for q in ('raw', 'l2', 'l3')}
    assert [x['input_sha256'] for x in manifests['raw']['records']] == [x['input_sha256'] for x in manifests['l3']['records']]
    for q, manifest in manifests.items():
        assert manifest['cpu_budget_seconds'] == 5 and manifest['memory_mb'] == 2048
        for x in manifest['records']:
            assert sha(B / x['input_path']) == x['input_sha256']
            assert sha(B / x['expected_path']) == x['expected_sha256']
    rows.append({'seed_id': sid, 'raw': ref(folder / 'raw.txt'), 'l3': ref(folder / 'l3.txt'),
                 'contract': ref(cp), 'mutation': c['l3']['operator'],
                 'reviewed': ['complete statement and exact edit map', 'residual old objective or operator',
                              'inline examples and removed diagrams', 'retained input restrictions',
                              'empty or infeasible cases where applicable', 'output protocol'],
                 'result': 'no unresolved finding at this review snapshot'})

def statement(k):
    return (B / 'tasks' / f'TM{k:03d}' / 'l3.txt').read_text()
assert 'coincide at some admissible time t ≤ 0' in statement(56)
assert 'figure below' not in statement(62).lower()
assert not any(s in statement(62).lower() for s in ('green', 'white', 'blue'))
assert 'output no name lines' in statement(97)
assert 'gcd (greatest common divisor)' in statement(102)
assert 'complete set of M proposed bridges connects all N islands' in statement(120)

# Revalidate the one newly enforced query-existence condition without rerunning
# unchanged reference programs. Freeze also revalidates all CCA manifest inputs.
checked59 = []
for condition in ('raw', 'l2', 'l3'):
    manifest = json.loads((B / 'tasks/TM059' / (condition + '_test_manifest.json')).read_text())
    for case in manifest['records']:
        valid = cc_a82.validate(59, (B / case['input_path']).read_text(), condition)
        assert valid['valid'], (condition, case['name'], valid)
        checked59.append({'condition': condition, 'name': case['name'], 'valid': True})
c120 = json.loads((B / 'contracts/cc_a/TM120.json').read_text())
assert c120['l2']['axis'] == 'N_and_M'
assert c120['l2']['bound_changes'] == {'N': {'native': 100000, 'expanded': 300000}, 'M': {'native': 100000, 'expanded': 300000}}
r120 = json.loads((B / 'validation/strict_cc_a/TM120/report.json').read_text())
assert r120['status'] == 'complete' and not r120['failures']
assert r120['summary']['case_count'] == 35
s120 = next(x for x in json.loads((B / 'validation/cc_a_scale_audit.json').read_text())['records'] if x['seed_id'] == 'TM120')
assert s120['passed']

findings = [
 {'seed_id': 'TM056', 'component': 'L3 statement', 'finding': 'A following sentence still allowed coinciding at any moment after the objective was restricted to past time.', 'resolution': 'Every coincidence reference now explicitly uses admissible t <= 0.', 'resolved_by': '/root'},
 {'seed_id': 'TM062', 'component': 'L3 statement', 'finding': 'Removed old sorting diagrams left dangling figure and color references.', 'resolution': 'Removed only dangling illustration references; retained the descending bubble-sort procedure and all input/output restrictions.', 'resolved_by': '/root'},
 {'seed_id': 'TM097', 'component': 'L3 statement', 'finding': 'Filtering all repeated names can produce an empty output list.', 'resolution': 'Explicitly states zero name lines for an empty result.', 'resolved_by': '/root'},
 {'seed_id': 'TM102', 'component': 'L3 renderer', 'finding': 'Original mathematical gcd definition appeared after samples and was inadvertently dropped by truncation.', 'resolution': 'Retained the original gcd definition in a Note before the rewritten samples.', 'resolved_by': '/root'},
 {'seed_id': 'TM059', 'component': 'native input validator', 'finding': 'The original guarantee of at least one type-2 query was not enforced.', 'resolution': 'Added the query-existence predicate; every frozen Raw/L2/L3 input remains valid, so unchanged program results are retained.', 'resolved_by': '/root/strict_l1_construction', 'input_revalidation': checked59},
 {'seed_id': 'TM120', 'component': 'native input validator and L2 coupled bounds', 'finding': 'The original complete bridge set must be connected. A one-edge scale input was illegal, and expanding only N while retaining M <= 100000 could not reach connected N = 300000.', 'resolution': 'Enforced full-graph connectivity; jointly expanded N and M from 100000 to 300000; replaced the two scale cases by connected chains; reran only this task and independently checked disconnected-pair counts with closed-form chain expectations.', 'resolved_by': '/root/strict_l1_construction',
  'revalidation': ref(B / 'validation/strict_cc_a/TM120/report.json'), 'revalidation_summary': r120['summary'],
  'independent_scale': ref(B / 'validation/cc_a_scale_audit.json'),
  'previous_evidence_preserved': 'validation/strict_cc_a/TM120_before_connectivity_fix/report_original_bytes.json'}]

out = {'schema': 'trimut.agent-cross-review.v1', 'recorded_at_utc': datetime.now(timezone.utc).isoformat(),
       'reviewer_agent': '/root/strict_l1_construction', 'statement_author_agent': '/root',
       'human_review': False, 'blind_review': False,
       'reviewer_also_authored_native_validators_and_tests': True,
       'scope': '81 CCA original/L3 statements, exact text edit definitions and rendering; input-contract consistency when implicated by text review.',
       'method': 'Agent read-through and reasoning against the full original statements, existing reference algorithms and oracle evidence, followed by recorded corrective actions and frozen-file integrity checks. No unchanged full program suite was rerun.',
       'reviewed_implementation': [ref(B / p) for p in ('mutations/cc_a82_statements.py', 'tools/render_cc_a_l3.py', 'native/cc_a82.py', 'native/build_cc_a_l2.py')],
       'findings': [{**x, 'status': 'resolved'} for x in findings],
       'known_exceptions': [{'seed_id': 'TM101', 'note': 'Original short illustrative sample is preserved as an explicitly unscored exception to the formal 1440-character/day domain; full-domain scored tests obey the original bound.'}],
       'status': 'no_unresolved_findings_at_review_snapshot', 'records': rows,
       'limitations': ['This is an agent cross-review, not independent human review or blinded adjudication.', 'Finite execution and agent reasoning do not prove universal correctness or successful model mutation.', 'Assertions in this recorder verify hashes and named fixes, not the semantics of arbitrary future statement edits.']}
dest = B / 'review/cc_a_l3_cross_review.json'
dest.parent.mkdir(parents=True, exist_ok=True)
dest.write_text(json.dumps(out, ensure_ascii=False, indent=2) + '\n')
print(json.dumps({'reviewed': len(rows), 'resolved_findings': len(findings), 'checked_unique_files': len(cache), 'output': str(dest)}))
