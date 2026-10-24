"""Add strict weak-domain geometry witnesses without modifying batch4 evidence."""
from pathlib import Path
import importlib.util,json
ROOT=Path(__file__).resolve().parents[1]
spec=importlib.util.spec_from_file_location('library_batch4_reused',ROOT/'recipes/library_batch4.py')
base=importlib.util.module_from_spec(spec);spec.loader.exec_module(base)
IDS=['closest_pair','all_furthest_neighbors']
RECIPES={id:dict(base.RECIPES[id])for id in IDS}
WITNESSES=json.loads((ROOT/'curation/library_version_audit.json').read_text())
def cases(id,mode,rng):
 yield from base.cases(id,mode,rng)
 if mode=='boundary':yield 'strict_weak_domain_witness',WITNESSES[id]['witness']['input']
def validate_input(id,text,condition):return base.validate_input(id,text,condition)
def check_output(id,text,candidate,oracle,condition):return base.check_output(id,text,candidate,oracle,condition)
def distinguishes(id,text,raw,l3):return base.distinguishes(id,text,raw,l3)
