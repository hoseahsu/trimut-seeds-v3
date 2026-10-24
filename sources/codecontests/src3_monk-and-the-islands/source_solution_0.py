'__author__'=='deepak Singh Mehta(learning to code :) ) '
 
'''
    Hard work beats Talent when Talent doesn't work hard. :)
 
'''

int_max = 10000000

if __name__=='__main__':
    tests = int(raw_input())
    for _ in range(tests):
        n,m = map(int,raw_input().split())
        graph =[[] for i in range(n+1)]
        for _ in range(m):
            x,y = map(int,raw_input().split())
            graph[x].append(y)
            graph[y].append(x)
        vis = [ False for i in range(n+1)]
        dist = [ -1 for i in range(n+1)]
        #bfs
        s = 1
        que = list()
        que.append(s)
        vis[s] = True
        dist[s] = 0
        while len(que)!=0:
            u = que[0]
            del que[0]
            for v in range(len(graph[u])):
                if not vis[graph[u][v]]:
                    dist[graph[u][v]] = dist[u] + 1
                    vis[graph[u][v]]=True
                    que.append(graph[u][v])
        print dist[n] if dist[n]!=-1 else -1