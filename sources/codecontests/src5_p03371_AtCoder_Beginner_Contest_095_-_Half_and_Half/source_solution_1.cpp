#include <iostream>

using namespace std;

int main(){
        int a,b,c,x,y;

        cin>>a>>b>>c>>x>>y;

        int min_num=min(x,y);

        cout<<min(a*min_num+b*min_num,c*2*min_num)+min(a*(x-min_num)+b*(y-min_num),c*2*max(x-min_num,y-min_num))<<endl;

        return 0;
}
