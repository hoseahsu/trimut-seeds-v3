for mat_ in range(int(raw_input())):
	mat = {}
	N = int(raw_input())
	row_weight = {}
	col_weight = {}
	for each_mat in range(N):
		elems = (str(raw_input())).split()
		elems = [int(i) for i in elems]
		mat[each_mat+1] = elems
		for index, elem in enumerate(elems):
			try:
				row_weight[each_mat+1] += elem
			except KeyError:
				row_weight[each_mat+1] = elem
			try:
				col_weight[index+1] += elem
			except KeyError:
				col_weight[index+1] = elem

	val = {}
	for i in range(1,N+1):
		val[i] = row_weight[i] + col_weight[i]

	captured = {}
	for i in range(N):
		max_ = -1
		idx = -1
		for j in range(1, N+1):
			if j not in captured and val[j] > max_:
				max_ = val[j]
				idx = j
		captured[idx] = i%2

	alt_f4 = ctrl_f4 = 0
	for i in range(1, N+1):
		for j in range(1, N+1):
			if captured[i] == captured[j]:
				if captured[j]:
					ctrl_f4 += mat[i][j-1]
				else:
					alt_f4 += mat[i][j-1]
	print alt_f4, ctrl_f4