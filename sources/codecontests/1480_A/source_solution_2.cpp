///Fix the cause, not the symptom.

#include<bits/stdc++.h>
using namespace std;
#define ll           long long
#define ull          unsigned long long
#define db           double
#define sf           scanf
#define pf           printf
#define pb           push_back
#define pi           acos(-1)
#define MOD          1000000007
#define pii          pair<ll,ll>
#define time_save    ios_base::sync_with_stdio(false); cin.tie(NULL);

#define D(x)         cerr << __LINE__ << ": " << #x << " = " << (x) << '\n'
#define DD(x,y)      cerr << __LINE__ << ": " << #x << " = " << x << "   " << #y << " = " << y << '\n'
#define DDD(x,y,z)   cerr << __LINE__ << ": " << #x << " = " << x << "   " << #y << " = " << y << "   " << #z << " = " << z << '\n'
#define DBG          cerr << __LINE__ << ": Hi" << '\n'



/*----------------------Graph Moves----------------*/
//const ll dx[]={+1,-1,+0,+0};
//const ll dy[]={+0,+0,+1,-1};
//const ll dx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const ll dy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const ll dx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const ll dy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N  (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/

int main()
{
    //#ifndef ONLINE_JUDGE
    ///   freopen("in.txt","r",stdin);
    ///   freopen("out.txt","w",stdout);
    //#endif

    //time_save;

    ll t;
    cin>>t;
    while(t--){
        string s,ss="";
        cin>>s;
        ll n=s.size();
        s="#"+s;
        for(ll i=1;i<=n;i++){
            if(i%2==1){
                if(s[i]!='a')
                    ss+='a';
                else
                    ss+='b';
            }
            else{
                if(s[i]!='z')
                    ss+='z';
                else
                    ss+='y';
            }
        }
        cout<<ss<<endl;
    }
    return 0;
}



