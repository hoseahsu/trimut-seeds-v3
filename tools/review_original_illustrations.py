#!/usr/bin/env python3
"""Persist an explicit non-blind agent visual/text review of original images.

The observations below were authored after actual view_image calls for all PNG
and JPEG files. BMP files are explicitly unreviewed because the viewer rejected
that format. The review does not modify or re-encode any image or statement.
"""
from pathlib import Path
import hashlib,json
R=Path(__file__).resolve().parents[1];D=R/'sources/original_illustrations'
REVIEW={
'TM023':('decorative','Stylized animals form the digits 1, 3, 7, 8.','The prose explicitly specifies the base 1378, exponent n, and last-digit output; the drawing adds no mathematical requirement.'),
'TM030':('operation_illustration','A blue junction has one incoming upper pipe and four outgoing lower pipes.','The prose already defines a splitter with one input and k outputs and labels this as the four-output example.'),
'TM038':('sample_path_illustration','A 4-by-3 grid shows the downward first-column path and subsequent alternating horizontal traversal.','The prose defines the start, initial descent, alternating row traversal excluding the first column, and even row count; this is the stated 4-by-3 example.'),
'TM046':('decorative','A vegetable character holds utensils and a carrot.','No numeric data or rule appears in the drawing; the heights, arithmetic progression, and bite operation are stated in prose.'),
'TM062':('algorithm_demonstration','The JPEG shows bars with values 4,1,7,3,8,6,2,5 sorted into increasing order.','The text explicitly defines adjacent comparisons, strict swaps, the shrinking unsorted portion, and required swap-count output. The remaining five BMP step illustrations have not been visually reviewed.'),
'TM078':('sample_tree_illustration','The two diagrams show recursive maximum Cartesian trees for the two permutations printed in the surrounding prose.','The recursive root/subarray construction and edge-count depth are fully defined in text; neither diagram supplies an additional input restriction.'),
'TM090':('topological_example','Two colored wires connect fixed contacts; the diagrams show the crossing patterns for -++-, +-, ++, and -.','The prose explicitly fixes the left plus contact above minus, defines each crossing symbol, and forbids unplugging or moving the device. The notes describe the sample untangling outcomes; the diagrams clarify those examples without adding a condition missing from the text.'),
'TM103':('sample_array_illustration','The array 1,1,2,2,1,3,1,1 has positions 2 through 7 highlighted.','The same array, closed query endpoints, frequency counts, and squared-frequency weighted sum are given in the sample and note text.'),
'TM134':('sample_coloring_illustration','Four rows of three yellow/green bricks show the four two-color assignments with one adjacent color change.','The prose defines the brick count, colors, and adjacent-color-change count; the image only enumerates the stated second sample.'),
'TM143':('operation_and_sample_illustration','The first image shows lifting books above a selected book, extracting it, restoring the lifted stack, and placing it on top. The second gives the stack states for the five sample days.','The four operation steps are explicit in prose, and the sample supplies the complete request sequence and weights; the images add no extra ordering rule.'),
'TM169':('sample_interval_illustration','Two number-line drawings show the three closed segments of each corresponding sample.','All segment endpoints and lists of integer points with each coverage count are explicitly written in the samples and explanatory notes.'),
'TM185':('object_illustration','A circular degree scale has a red pointer at zero, with ticks labeled every ten degrees.','The text specifies the 360-degree scale, initial zero, selectable rotation direction, and final-zero condition.'),
'TM200':('sample_arrangement_illustration','A six-cell strip places air conditioners at cells 2 and 5 with labels t1=14 and t2=16.','The same n, k, locations, temperatures, and temperature formula are written in the adjacent prose.'),
}
def main():
 p=D/'index.json';a=json.loads(p.read_text());mapping={};review=[]
 for e in a['entries']:
  seed=e['associated_seed_ids'][0];classification,description,reason=REVIEW[seed]
  if e['status']!='downloaded':v={'status':'not_reviewed','reason':'Original source URL unavailable; no replacement searched or fabricated.'};assessment='not_assessed'
  elif e['detected_media_type']=='image/bmp':
   v={'status':'not_reviewed','reason':'The original BMP bytes were downloaded and preserved. view_image rejected this format; no redraw or re-encoding was performed.','text_context_reviewed':True,'text_context_assessment':'The surrounding Raw prose independently specifies the adjacent-comparison and swap procedure. Whether this particular unviewed bitmap contains any additional information has not been visually assessed.'};assessment='visual_exclusivity_not_assessed'
  else:
   v={'status':'reviewed','reviewer':'library_l3_audit','blind':False,'method':'direct visual inspection with view_image at original resolution plus Raw text review','description':description,'classification':classification,'reason':reason};assessment='no_text_exclusive_core_condition_found_in_visual_review'
  e['visual_review']=v;e['core_information_assessment']=assessment
  if e['status']=='downloaded':assert hashlib.sha256((R/e['local_path']).read_bytes()).hexdigest()==e['sha256']
  mapping[e['url']]={k:e[k]for k in('status','associated_seed_ids','core_information_assessment')}
  for key in('local_path','sha256','bytes','detected_media_type','reason'):
   if key in e:mapping[e['url']][key]=e[key]
  review.append({'url':e['url'],'seed_ids':e['associated_seed_ids'],'image_sha256':e.get('sha256'),'visual_review':v,'core_information_assessment':assessment})
 a['visual_review_summary']={'reviewed':sum(e['visual_review']['status']=='reviewed'for e in a['entries']),'not_reviewed':sum(e['visual_review']['status']!='reviewed'for e in a['entries']),'no_core_condition_missing_from_text_found_in_reviewed_images':True,'unreviewed_images_are_not_assumed_to_be_visually_redundant':True,'variant_alignment_reviewed':False,'variant_note':'These are original Raw illustrations. This archive does not certify that an original diagram remains semantically appropriate after a logical or narrative mutation; the four variant statements are not edited.'}
 p.write_text(json.dumps(a,indent=2,ensure_ascii=False)+'\n');(D/'url_map.json').write_text(json.dumps(mapping,indent=2,ensure_ascii=False)+'\n')
 (D/'review.json').write_text(json.dumps({'reviewer':'library_l3_audit','blind':False,'summary':a['visual_review_summary'],'entries':review},indent=2,ensure_ascii=False)+'\n')
 print(json.dumps(a['visual_review_summary'],ensure_ascii=False))
if __name__=='__main__':main()
