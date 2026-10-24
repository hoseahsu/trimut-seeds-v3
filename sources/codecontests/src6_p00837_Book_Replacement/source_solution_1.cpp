#include<iostream>
#include<cstdio>
#include<deque>
#include<vector>
#include<algorithm>
#include<cassert>
#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define inf (1<<29)
#define MAX 110
using namespace std;

struct P
{
  int id; 
  bool ex;
  P(int id=-inf,bool ex=true):id(id),ex(ex){}
};

int CNT[MAX];
deque<P> desk[MAX];
deque<int> Person[MAX];
int m,c,n,ans,rem;

int getNext(int index)
{
  while(Person[index].empty())index = (index+1)%n;
  return index;
}

void take(int index)
{
  bool ok = false;
  rep(i,m)
    {
      rep(j,desk[i].size())
	{
	  //cout << "desk[" << i << "][" << j << "] = " << desk[i][j].id << " : " << desk[i][j].ex << endl;
	  if(!desk[i][j].ex)continue;
	  if(desk[i][j].id == index)
	    {
	      desk[i][j].ex = false,ans += (i+1);
	      CNT[i]--;
	      ok = true;
	      //cout << "take from desk:" << i << " +" << (i+1) << endl;
	      return;
	    }
	}
      while(!desk[i].empty() && !desk[i].front().ex)desk[i].pop_front();
    }
  //cout << "take from shelf +" << m+1 << endl;
  ans += (m+1);
}

bool check(int index)
{
  //cout << "CNT[0]+1 = " << CNT[0]+1 << " <= " << c << endl;
  if(CNT[0]+1 <= c)
    {
      //cout << "book : " << index << " is able to put desk : " << 0 << endl;
      ans++;
      CNT[0]++;
      desk[0].push_back(P(index,true));
      return true;
    }
  return false;
}

void put(int index)
{

  if(check(index))return;
  
  //put 
  int pre=-inf;
  bool ok = false;
  rep(i,m)
    if(CNT[i]+1 <= c)
      {
	//cout << "一時的にdesk" << i << "におく　＆　そこから再度取り出す" << endl;
	CNT[i]++;
	pre = i;
	ans += (i+1)*2;
	ok = true;
	break;
      }
  if(!ok)ans += (m+1)*2;

  //take from desk 1
  ans++;
  while(!desk[0].empty() && !desk[0].front().ex)desk[0].pop_front();
  P p = desk[0].front(); desk[0].pop_front();
  CNT[0]--;
  assert(CNT[0] >= 0);
  //cout << "0番の本 " << p.id << " をとる" << endl;

  //put
  ok = false;
  REP(i,1,m)
    if(CNT[i]+1 <= c)
      {
	//cout <<"0番からの本 " << p.id << "を机" << i << "におく" << endl;  
	CNT[i]++;
	ans += (i+1);
	p.ex = true;
	desk[i].push_back(p);
	ok = true;
	break;
      }
  if(!ok)ans += (m+1);
  if(pre != -inf)CNT[pre]--;
  
  ans++;
  CNT[0]++;
  desk[0].push_back(P(index,true));
  
}

int main()
{

  while(cin >> m >> c >> n,m|n|c)
    {
      rem = n;
      ans = 0;
      rep(i,m+1)desk[i].clear(),CNT[i] = 0;
      rep(i,n)Person[i].clear();
      rep(i,n)
	{
	  int k,b;
	  cin >> k;
	  rep(j,k)
	    {
	      cin >> b;
	      Person[i].push_back(b);
	    }
	}

      int index = 0;
      while(rem)
	{
	  //cout << endl;
	  //rep(i,m)cout << "desk[" << i << "] = "<< CNT[i] << " ";
	  //cout << endl;

	  index = getNext(index);
	  //cout << "index = " << index << endl;
	  int target = Person[index].front(); Person[index].pop_front();
	  //cout << "target = " << target << endl; 
	  if(Person[index].empty())rem--;

	  take(target);
	  //cout << "after take, ans = " << ans << endl;
	  put(target);
	  //cout << "after put, ans = "<< ans << endl;
	  index = (index+1)%n;
	}
      cout << ans << endl;
    }
  return 0;
}