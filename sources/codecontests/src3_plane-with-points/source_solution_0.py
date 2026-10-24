def constdr1(Points) :
	Droites = []	
	i = 0
	j = i + 1
	while j < len(Points) :
		S = True
		for D in Droites :
			if (Points[D[1]][0]-Points[D[0]][0])*(Points[j][1]-Points[i][1])-(Points[D[1]][1]-Points[D[0]][1])*(Points[j][0]-Points[i][0])== 0 :
				S=False
				if not (j in D) :
					D.append(j)
					break
		if S :
			Droites.append([i,j])
		j+=1
	return Droites

def sousparties(D) :
	N = len(D)
	D2 = D +[]
	if N==0 :
		return [[]]
	else :
		i =D2[0]
		D2.pop(0)
		Sol = sousparties(D2)
		Sol2 = []		
		for P in Sol :
			Sol2.append([i]+P)
		return Sol2 + Sol

def factorielle(n) :
	if n == 0 :
		return 1
	else :
		return n*factorielle(n-1)
								
def main(Points, d,nbp) :
	if len(Points)< 3 :
		nb= nbp + len(Points)
		k = (nb+1)/2
		if k > d :
			return [d,0]
		else :
			return [k,factorielle(2*k)/2**k]
	elif d == 0 :
		#print "plop2"
		return [0,0]
	else :
		Droites = constdr1(Points)
		i = 0
		sol = 0
		while i< len(Droites) :
			Droites[i].pop(0)
			for P in sousparties(Droites[i]) :
				if len(P) < 2 :
					continue
				j=1
				Points2 = []
				while j < len(Points) :
					if not j in P :
						Points2.append(Points[j])
					j+=1			
				A = main(Points2,d-1,nbp)
				if A[0]<d-1:
					d = A[0] +1
					sol = d*A[1]
				else :
					sol +=d*A[1]
			i+=1
		A = main(Points[1:],d, nbp+1)
		if A[0]<d:
			d = A[0]
			sol = A[1]
		else:
			sol +=A[1]
		#print sol
		return [d,int(sol %1000000007)]

T = map(eval, raw_input().split())					
i = 0
while i < T[0] :
	M = map(eval, raw_input().split())
	N= M[0]	
	j = 0
	points = []
	while j < N:
		X, Y = map(eval, raw_input().split())
		points += [[X,Y]]
		j+=1
	Sol = main(points, (N+1)/2,0)
	print Sol[0], Sol[1]
	i+=1