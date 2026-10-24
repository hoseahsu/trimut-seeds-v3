#include<bits/stdc++.h>
using namespace std;
/*vector<int>v;
void SieveOfEratosthenes(int n) 
{ 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          v.push_back(p);
}

int binarySearch( int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
        if (v[mid] == x) 
            return mid; 
        if (v[mid] > x) 
            return binarySearch( l, mid - 1, x); 

        return binarySearch( mid + 1, r, x); 
    } 

} */

/*
    // adjacency matrix
bool adjMatrixBool[N][N];			// boolean relation
int adjMatrix[N][N];
 
vector<int>	adjMatrixAll[N][N];		// Keep all edges for a given pair of nodes
 
 
// Adjacency lists
vector< vector<int> > adjList1;
vector< vector< pair<int, int> > > adjList2;	// cost relation (node, cost): Select 1
     of multiple edges
 
*/
 
/*
void DFS_Mat(int u) {
    vis[u] = 1;
    for(int v=0;v<=n;v++)
        if(adjMat[u][v] == 1 && vis[v] == 0)
            DFS_Mat(v);
 
}
 
void DFS_List(int u) {
    vis[u] = 1;
    for( int v : adjList[u]){
        if (vis[v] == 0)
            DFS_List(v);
    }
 
}
 
*/
 
/*
vector<int> BFS2(int s) {
	vector<int> len(adjList.size(), 1e6);
	queue<int> q;
	q.push(s), len[s] = 0;
 
	int dep = 0, cur = s, sz = 1;
	for ( ; !q.empty(); ++dep, sz = q.size()) {
		while (sz--) {
			cur = q.front(), q.pop();
			for(int i=0;i< adjList[cur].size();)
if (len[adjList[cur][i]] == 1e6)
				q.push(adjList[cur][i]), len[adjList[cur][i]] = dep+1;
		} }
	return len;	//cur is the farthest node from s with depth dep
}
 
*/
/*
Backtracking(state)
 
 *		if invalid(state)	//e.g. the location is already visited or we reached to the end
 * 			return
 *
 * 		if found_solution(state)
 * 			mark_solution_found
 * 			return
 *
 * 		for each child_state of state
 * 			state' = do changes in state
 *
 * 			Backtracking(state')
 *
 * 			state = undo changes in state'
 
*/
 
/*
bool isPrime(long long n){
   if(n < 2)
       return false;
   //Check all numbers from 2->root(N)
   //If it is a divisor of n
   for (long long i=2; i*i <= n; i++) // O(root(N))
       if (n % i == 0)
           return false;
   return true;
}
vector<int>Primes;
void Sieve(int n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
 
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
    for (int p=2; p<=n; p++)
       if (prime[p])
          Primes.push_back(p);
}
*/
/*
int GCD (int a,int b){
   if (b==0)
       return a;
   return GCD (b, a % b);
}
int LCM(int a,int b){
 
   return a / GCD(a, b) * b;
 // Avoid (a*b) / GCD(a,b) may overflow
}
 
*/
/*
int BinarySearch(int num) {
   int st = 0, en = v.size() - 1;
 
   while(st <= en) {
       int mid = (st + en) >> 1;
       if(v[mid] == num)
           return mid;
       if(v[mid] < num)
           st = mid + 1;
       else if(v[mid] > num)
           en = mid - 1;
   }
   return -1;
}
*/
/*
Count Number of ones in binary representation
int cntBits = __builtin_popcount(num);
 __builtin_popcountll(num) for long long
Check bit (Zero or One):
if(((mask >> bitIndx) & 1) == 1)
 
Set bit to One:
mask |= (1 << bitIndx);
 
Set bit to Zero:
mask &= ~(1 << bitIndx);
 
Toggle bit :
mask ^= (1 << bitIndx);
 
Check if number is Even or Odd:
 
if(num & 1 == 1)			(num & 1) = num%2
   cout << "ODD";
 
if(num & 1 == 0)
   cout<<"EVEN";
 
*/
 
/*
char xyz[n];
 
for(int msk = 0; msk < (1 << n); msk++) {
 
for(int ind = 0; ind < n; ind++)
 
if((msk >> ind) & 1)
 
  cout << xyz[ind];
 
      cout << endl;
 
}
if(mp.count(str))
        {   
            mp[str]++;
        }
        else {
            mp[str]++;
            
        }
        
        priority_queue<int>pq;
        priority_queue <int, vector<int>, greater<int>>pq2;
*/
/*
map<int,int>mpp;
 
for(cin>>N;i<N;i++){
      cin>>arr[i];
      r=mpp[arr[i]]=mpp[arr[i]-1]+1;
      if(r>k)k=r,last=arr[i];
}
cout<<k<<endl,t=last-k+1;
for(i=0;i<N;i++)
if(arr[i]==t)cout<<i+1<<" ",t++;
 
*/
/*

vector<int> adjList1[10];
vector<int> len(10, 1e6);
void BFS2(int s) {
    	
	queue<int> q;
	q.push(s), len[s] = 0;
 
	int dep = 0, cur = s, sz = 1;
	for ( ; !q.empty(); ++dep, sz = q.size()) {
		while (sz--) {
			cur = q.front(), q.pop();
			for(int i=0;i< adjList1[cur].size();i++)
                if (len[adjList1[cur][i]] == 1e6)
				    q.push(adjList1[cur][i]), len[adjList1[cur][i]] = dep+1;
		} }
	
}
*/
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int x[n],y[n];
        for(int i=0;i<n;i++){
            cin>>x[i]>>y[i];
        }
        int d=0,cx=0,cy=0;int v=0;
        for(int i=0;i<n;i++){
            cx=0,cy=0;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                d=abs(x[i]-x[j]);
                d+=abs(y[i]-y[j]);
                if(d>k){
                    v++;break;}
                
            }
            
        }
        if(v!=n)
        cout<<1<<endl;
        else cout<<-1<<endl;
}
}