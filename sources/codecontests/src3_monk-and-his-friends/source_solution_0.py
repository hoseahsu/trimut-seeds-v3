t = int(raw_input())
for _ in xrange(t):
	n, m = map(int, raw_input().split())
	students = map(int, raw_input().split())
	seated = set(students[:n])
	res = []
	for student in students[n:]:
		res.append("YES" if student in seated else "NO")
		seated.add(student)
	print "\n".join(res)