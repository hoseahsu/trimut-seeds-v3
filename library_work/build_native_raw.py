#!/usr/bin/env python3
"""Faithful English template expansion; source-reference runs occur only in bwrap."""
from pathlib import Path
import argparse,hashlib,json,re,resource,sys,tomllib
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'tools'))
from validate import Sandbox,write_json,file_hash
KEYWORDS={'statement':'Problem Statement','constraints':'Constraints','input':'Input','output':'Output','sample':'Sample'}

def english_template(source):
    language=None;out=[];last=0
    for match in re.finditer(r'@\{lang\.(en|ja|end)\}',source):
        if language!='ja':out.append(source[last:match.start()])
        language=None if match[1]=='end'else match[1];last=match.end()
    if language!='ja':out.append(source[last:])
    return ''.join(out)

def render(item):
    package=ROOT/item['package'];info=tomllib.loads((package/'info.toml').read_text())
    source=(package/'task.md').read_text();text=english_template(source)
    def replace_param(m):
        assert m[1]in info.get('params',{}),(item['id'],m[1]);return str(info['params'][m[1]])
    text=re.sub(r'@\{param\.([^}]+)\}',replace_param,text)
    text=re.sub(r'@\{keyword\.([^}]+)\}',lambda m:KEYWORDS[m[1]],text)
    samples=[]
    def example(m):
        name=m[1];folder=ROOT/'library_work/native_examples'/item['id'];record=json.loads((folder/(name+'.record.json')).read_text())
        assert record['input_matches_official_hash']and record['output_matches_official_hash']
        inp=(folder/(name+'.in')).read_text();out=(folder/(name+'.out')).read_text();samples.append(record)
        i=len(samples);return f'## Sample Input {i}\n\n```\n{inp.rstrip()}\n```\n\n## Sample Output {i}\n\n```\n{out.rstrip()}\n```'
    text=re.sub(r'@\{example\.([^}]+)\}',example,text)
    assert '@{'not in text,(item['id'],'unresolved template')
    assert not re.search(r'[\u3040-\u30ff]',text),(item['id'],'unfiltered Japanese kana')
    result='# '+info['title']+'\n\n'+text.strip()+'\n'
    dest=ROOT/'tasks'/item['seed_id'];dest.mkdir(parents=True,exist_ok=True);(dest/'raw.txt').write_text(result)
    provenance={'seed_id':item['seed_id'],'source_id':item['id'],'source_identity':'library-checker:'+item['id'],'source_task_path':str((package/'task.md').relative_to(ROOT)),'source_task_sha256':file_hash(package/'task.md'),'source_info_path':str((package/'info.toml').relative_to(ROOT)),'source_info_sha256':file_hash(package/'info.toml'),'source_hash_path':str((package/'hash.json').relative_to(ROOT)),'source_hash_sha256':file_hash(package/'hash.json'),'source_title':info['title'],'native_params':info.get('params',{}),'native_time_seconds':info['timelimit'],'native_memory_limit':'not specified in repository info.toml; no invented original memory limit','render_policy':'Select original English language blocks, preserve shared original text, substitute source params and English section headings, expand original sample input/output; no task summarization, weakening, or mathematical rule changes.','render_program_sha256':file_hash(Path(__file__)),'raw_path':str((dest/'raw.txt').relative_to(ROOT)),'raw_sha256':file_hash(dest/'raw.txt'),'samples':samples,'original_language':'en','raw_domain_status':'source_native','validation_status':'original_examples_hash_reconstructed'}
    write_json(dest/'raw_provenance.json',provenance)
    return provenance

def main():
    arg=argparse.ArgumentParser();arg.add_argument('--ids',nargs='*');arg.add_argument('--render-only',action='store_true');args=arg.parse_args()
    items=json.loads((ROOT/'library_work/native_inventory.json').read_text());items=[x for x in items if not args.ids or x['id']in args.ids or x['seed_id']in args.ids]
    sandbox=None if args.render_only else Sandbox()
    if sandbox and not sandbox.available:
        write_json(ROOT/'library_work/sandbox_probe.json',sandbox.probe);raise RuntimeError(sandbox.probe)
    if sandbox:write_json(ROOT/'library_work/sandbox_probe.json',sandbox.probe)
    # Upstream generate.py explicitly sets a 256 MiB stack for reference runs.
    resource.setrlimit(resource.RLIMIT_STACK,(256*1024**2,256*1024**2))
    status=[]
    for item in items:
        try:
            package=ROOT/item['package'];hashes=json.loads((package/'hash.json').read_text());folder=ROOT/'library_work/native_examples'/item['id'];folder.mkdir(parents=True,exist_ok=True)
            complete=all((folder/(n+'.record.json')).exists()and json.loads((folder/(n+'.record.json')).read_text()).get('output_matches_official_hash')for n in item['example_names'])
            if not complete:
                assert sandbox is not None
                runroot=ROOT/'validation/library_native_examples'/item['id'];build=runroot/'build';build.mkdir(parents=True,exist_ok=True);reference=package/'sol/correct.cpp';binary=build/'program'
                cmd=['/usr/bin/g++','-std=c++17','-O2','-pipe','-include','cstdio','-I','/common','/src/correct.cpp','-o','/work/program']
                mounts=['--ro-bind',str(reference.parent),'/src','--ro-bind',str(ROOT/'sources/library-checker-problems-master/common'),'/common','--bind',str(build),'/work']
                compile_result=sandbox.execute(cmd,mounts,b'',120,2048,64*1024**2,runroot/'compile/reference')
                assert compile_result['status']=='OK',(item['id'],'compile_failed',compile_result['stderr_path'])
                for name in item['example_names']:
                    input_path=package/'gen'/(name+'.in');inp=input_path.read_bytes();assert hashlib.sha256(inp).hexdigest()==hashes[name+'.in'],(item['id'],name,'input hash')
                    result=sandbox.execute(['/program'],['--ro-bind',str(binary),'/program'],inp,item['native_time_seconds'],1024,64*1024**2,runroot/'examples'/name)
                    assert result['status']=='OK',(item['id'],name,result['status'])
                    out=Path(result['stdout_path']).read_bytes();(folder/(name+'.in')).write_bytes(inp);(folder/(name+'.out')).write_bytes(out)
                    record={'example':name,'input_path':str((folder/(name+'.in')).relative_to(ROOT)),'input_sha256':hashlib.sha256(inp).hexdigest(),'output_path':str((folder/(name+'.out')).relative_to(ROOT)),'output_sha256':hashlib.sha256(out).hexdigest(),'official_input_sha256':hashes[name+'.in'],'official_output_sha256':hashes[name+'.out'],'input_matches_official_hash':hashlib.sha256(inp).hexdigest()==hashes[name+'.in'],'output_matches_official_hash':hashlib.sha256(out).hexdigest()==hashes[name+'.out'],'reference_source_path':str(reference.relative_to(ROOT)),'reference_source_sha256':file_hash(reference),'reference_binary_sha256':file_hash(binary),'compiler_policy':'g++ -std=c++17 -O2 -pipe -include cstdio; source bytes unchanged; cstdio compatibility include only','execution_report':str((runroot/'examples'/(name+'.run.json')).relative_to(ROOT)),'sandbox':'bubblewrap','memory_limit_for_reconstruction_mb':1024,'memory_limit_is_original_claim':False}
                    write_json(folder/(name+'.record.json'),record)
                    assert record['output_matches_official_hash'],(item['id'],name,'official output hash mismatch')
            provenance=render(item);row={'id':item['id'],'seed_id':item['seed_id'],'status':'ready','raw_sha256':provenance['raw_sha256'],'samples':len(item['example_names'])}
        except Exception as exc:
            row={'id':item['id'],'seed_id':item['seed_id'],'status':'blocked','error':repr(exc)}
        status.append(row);print(json.dumps(row),flush=True);write_json(ROOT/'library_work/native_raw_build_status.json',status)
    return 0 if all(x['status']=='ready'for x in status)else 1
if __name__=='__main__':raise SystemExit(main())
