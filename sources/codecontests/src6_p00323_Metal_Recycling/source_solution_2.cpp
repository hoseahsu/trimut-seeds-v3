#include <stdio.h>
#include <set>
using namespace std;
int main(){
    int n,a,b;
    set<int> s;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&a,&b);
        a+=b;
        while(s.find(a)!=s.end()){
            s.erase(a);
            a++;
        }
        s.insert(a);
    }
    for(int i:s){
        printf("%d %d\n",i,0);
    }
}
