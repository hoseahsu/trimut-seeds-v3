tc=int(raw_input())
for case in range(tc):
	s=raw_input()
	l=len(s)
	z=s.count("0")
	o=s.count("1")
	if z<o:
		print l-z*2
	else:
		print l-o*2