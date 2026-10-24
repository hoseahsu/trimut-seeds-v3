"""Root baseline repair: bound weak-domain work without narrowing uint64 A."""
from pathlib import Path
import importlib.util
ROOT=Path(__file__).resolve().parents[1]
spec=importlib.util.spec_from_file_location('library_batch3_reused',ROOT/'recipes/library_batch3.py');base=importlib.util.module_from_spec(spec);spec.loader.exec_module(base)
IDS=['kth_root_integer'];RECIPES={'kth_root_integer':dict(base.RECIPES['kth_root_integer'])}
RECIPES['kth_root_integer']['slow_baseline']='../assets/library_repairs/kth_root_integer_slow.cpp'
RECIPES['kth_root_integer']['slow_baseline_explanation']='Probe integer roots up to100000, then fall back to exact binary search. This preserves the full uint64 A domain and makes weak T<=8 uniformly bounded; strong generator roots≈10000 remain on the scan path.'
RECIPES['kth_root_integer']['l2_design']=dict(RECIPES['kth_root_integer']['l2_design'],slow_complexity='O(T*K*(min(A^(1/K),100000)+log A))')
EXTREME='8\n18446744073709551615 2\n18446744073709551615 3\n18446744073709551615 64\n18446744073709551615 1\n0 64\n1 64\n999999999999999999 2\n10000000000 2\n'
def cases(id,mode,rng):
 yield from base.cases(id,mode,rng)
 if mode=='weak':
  yield 'full_uint64_domain_extremes',EXTREME
  yield 'eight_max_uint64_square_roots','8\n'+('18446744073709551615 2\n'*8)

def validate_input(id,text,condition):return base.validate_input(id,text,condition)
def check_output(id,text,candidate,oracle,condition):return candidate.split()==oracle.split()
def distinguishes(id,text,raw,l3):return raw.split()!=l3.split()
