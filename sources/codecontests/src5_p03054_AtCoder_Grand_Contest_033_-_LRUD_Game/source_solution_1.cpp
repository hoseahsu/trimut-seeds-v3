#include<bits/stdc++.h>
using namespace std;
char a[3][101010 * 2];
int rem[101010 * 2];

bool deal(char x, char y, const int p, const int w, const int n){
    int l = 1, r = w;
    for(int i = n; i > 0; i --){
        if(a[2][i] == x){
            r ++;
            r = min(r, w);
        }
        else if(a[2][i] == y){
            l --;
            l = max(l, 1);
        }
        if(a[1][i] == x){
            l ++;
        }
        else if(a[1][i] == y){
            r --;
        }
        if(l > r) return true;
    }
    if(p < l || r < p) return true;
    return false;
}
int main(){
    int h, w, n, x, y;
    scanf("%d%d%d%d%d", &h, &w, &n, &x, &y);
    scanf("%s%s", a[1] + 1, a[2] + 1);
    bool flag = false;
    flag = flag | deal('L', 'R', y, w, n);
    flag = flag | deal('U', 'D', x, h, n);
    printf("%s\n", flag ? "NO" : "YES");
}