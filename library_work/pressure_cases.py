"""Native/L2 exact-upper-bound supplemental pressure inputs; independently checked by source-derived validators."""
import random

def pressure(id,params,literal=None,trial=0):
 rng=random.Random(20261022+trial)
 if id=='sum_of_floor_of_linear':
  t=literal or 100000
  return str(t)+'\n'+''.join(f'{10**9-i%97} 1000000000 {999999937-i%1000} {i%100000}\n'for i in range(t))
 if id=='wildcard_pattern_matching':
  n=params['S_LEN_MAX'];s=''.join(rng.choice('ab*')for _ in range(n));t=''.join(rng.choice('ab*')for _ in range(n//2));return s+'\n'+t+'\n'
 if id=='cartesian_tree':
  n=params['N_MAX'];return f'{n}\n'+' '.join(map(str,range(n)))+'\n'
 if id=='dynamic_sequence_range_affine_range_sum':
  n=q=params['N_AND_Q_MAX'];ops=[]
  for i in range(q):
   t=i%5
   if t==0:ops.append(f'3 0 {n} 998244352 998244352\n')
   elif t==1:ops.append(f'4 0 {n}\n')
   elif t==2:ops.append(f'2 0 {n}\n')
   elif t==3:ops.append('1 0\n')
   else:ops.append(f'0 {n-1} {i%998244353}\n')
  return f'{n} {q}\n'+' '.join(str(i%998244353)for i in range(n))+'\n'+''.join(ops)
 if id=='chromatic_number':
  n=params['MAX_N'];edges=[(i,j)for i in range(n)for j in range(i+1,n)if rng.random()<(0.35 if trial==0 else 0.65)]
  return f'{n} {len(edges)}\n'+''.join(f'{u} {v}\n'for u,v in edges)
 if id=='minimum_enclosing_circle':
  n=params['N_MAX'];return f'{n}\n'+''.join(f'{i%20001-10000} {i//20001-10000}\n'for i in range(n))
 if id=='minimum_spanning_tree':
  n=params['N_MAX'];return f'{n} {n-1}\n'+''.join(f'{i-1} {i} {(i*7919)%1000000001}\n'for i in range(1,n))
 if id=='directedmst':
  n=params['N_MAX'];return f'{n} {n-1} 0\n'+''.join(f'{i-1} {i} {(i*7919)%1000000001}\n'for i in range(1,n))
 if id=='persistent_queue':
  q=params['Q_MAX'];h=q//2;return f'{q}\n'+''.join(f'0 {i-1} {i}\n'for i in range(h))+''.join(f'1 {i-1}\n'for i in range(h,q))
 if id=='kth_root_integer':
  t=params['T_MAX'];return f'{t}\n'+''.join(f'{(2**64-1-i*104729)%(2**64)} {1+i%64}\n'for i in range(t))
 if id in ('number_of_substrings','lyndon_factorization','zalgorithm'):
  n=(literal or 500000) if id=='number_of_substrings' else params['N_MAX'];return ''.join(rng.choice('abcdefghijklmnopqrstuvwxyz')for _ in range(n))+'\n'
 return None
