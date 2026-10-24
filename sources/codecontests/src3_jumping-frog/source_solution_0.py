from collections import deque
class Frog():
	
	def __init__(self,n,stones):
		self.colors=[[] for _ in xrange(101)]
		self.N = n
		self.stones = stones
		for i,c in enumerate(stones):
			self.colors[c].append(i)
		self.l=[0]*self.N
		
		
			
	def bfsThrough(self,S,M,E):
		s1 = self.bfs(S,M)
		if s1==-1:
			return s1
		s2 = self.bfs(M,E)
		if s2==-1:
			return s2
		return s1+s2
		
	def bfs(self,A,B):
		if A==B:
			return 0
		v=[False]*self.N
		f=[False]*101
		#l=[0]*self.N
		
		q=deque()
		v[A]=True
		q.append(A)
		self.l[A]=0
		while(len(q)>0):
			cur = q.popleft()
			
			if not f[self.stones[cur]]:
				f[self.stones[cur]]=True
				for x in self.adjacentTo(cur):
					if x==B:
						return self.l[cur]+1
					if not v[x]:
						v[x]=True
						q.append(x)
						self.l[x]=self.l[cur]+1
			
			if cur>0:
				x=cur-1
				if x==B:
					return self.l[cur]+1
				if not v[x]:
					v[x]=True
					q.append(x)
					self.l[x]=self.l[cur]+1
				
		
		return -1
		
	def adjacentTo(self,v):
		return self.colors[self.stones[v]]
		
		
def main():
	N = int(raw_input())
	st = [int(x) for x in raw_input().split()]
	f = Frog(N,st)
	for _ in xrange(int(raw_input())):
		S,M,E=[int(x) for x in raw_input().split()]
		print f.bfsThrough(S,M,E)
	
main()