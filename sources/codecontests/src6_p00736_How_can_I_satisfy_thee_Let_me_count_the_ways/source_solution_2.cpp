#include <iostream>
#include <functional>
#include <cctype>
#include <cassert>
using namespace std;
typedef function<int(int[3])> node_t;
int sub[3]={2,1,0};
int mul[3][3]={{0,0,0},{0,1,1},{0,1,2}};
int add[3][3]={{0,1,2},{1,1,2},{2,2,2}};
string S;
int cur=0;
char readchar()
{
    assert(cur < S.size());
    char ret = S[cur];
    cur += 1;
    return ret;
}
node_t parse()
{
    char c=readchar();
    if(isdigit(c))
        return [ =](int[3]){return c-'0'; };
    if(isalpha(c))
        return [ =](int a[3]){return a[c-'P']; };
    node_t left=parse();
    if(c=='-')
        return [ =](int a[3]){return sub[left(a)]; };
    assert(c=='(');
    char op = readchar();
    node_t right = parse();
    ++cur;
    if(op=='*')
        return [ =](int a[3]){return mul[left(a)][right(a)]; };
    return [ =](int a[3]){return add[left(a)][right(a)]; };
}
int solve()
{
    cur = 0;
    auto tree = parse();
    int count = 0;
    for(int p:{0,1,2})
        for(int q:{0,1,2})
            for(int r:{0,1,2})
            {
                int a[] = {p, q, r};
                if(tree(a) == 2)
                    count++;
            }
    return count;
}

int main()
{
    cin >> S;
    while(S!=".")
    {
        cout << solve() << endl;
        cin >> S;
    } 
    return 0;
}

