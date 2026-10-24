import sys

l= raw_input().strip()
l=int(l)
n=raw_input().strip()
n=int(n)
for i in xrange(n):
	w, h=raw_input().strip().split()
	w, h=[int(w), int(h)]
	if w<l or h<l:
		print 'UPLOAD ANOTHER'
	elif w==h:
		print 'ACCEPTED'
	else:
		print 'CROP IT'