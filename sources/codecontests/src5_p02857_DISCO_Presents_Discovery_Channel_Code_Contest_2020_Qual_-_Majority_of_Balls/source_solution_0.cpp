#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v1,v2;
char s[5],res[666];
inline char Q1(int l,int r) {
    printf("? ");
    for (int i=l;i<=r;++i)
        printf("%d%c",i,i==r?'\n':' ');
    fflush(stdout);
    char s[5];scanf("%s",s);
    return s[0];
}
inline char Q2(vector<int> &vec) {
    printf("? ");
    for (int i=0;i<(int)vec.size();++i)
        printf("%d%c",vec[i],i+1==(int)vec.size()?'\n':' ');
    fflush(stdout);
    char s[5];scanf("%s",s);
    return s[0];
}
int main()
{
    scanf("%d",&n);
    char a=Q1(1,n);
    char b=(a=='R')?'B':'R';
    int left=1,right=n+1;
    while (left+1<right) {
        int mid=(left+right)>>1;
        int c=Q1(mid,mid+n-1);
        if (a==c) left=mid;
        else right=mid;
    }
    res[left]=a;
    res[left+n]=b;
    for (int i=1;i<=n+n;++i) {
        if (i>=right&&i<=left+n-1) v1.push_back(i);
        if (i+1<right||i>left+n) v2.push_back(i);
    }
    for (int i=1;i<=n+n;++i) if (!res[i]) {
        if (i>=right&&i<=left+n-1) {
            v2.push_back(i);
            res[i]=Q2(v2);
            v2.pop_back();
        } else {
            v1.push_back(i);
            res[i]=Q2(v1);
            v1.pop_back();
        }
    }
    printf("! ");
    puts(res+1);
    fflush(stdout);
    return 0;
}
