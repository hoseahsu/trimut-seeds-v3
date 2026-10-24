#include<cstdio>
#include<cstring>

char s[1000003];

int main() {
    scanf("%s", &s[1]);
    int n = strlen(&s[1]), ans = 0;
    for (int i = n; i > 0; i--) {
        if (s[i] > '5' || (s[i] == '5' && s[i - 1] >= '5')) {
            s[i - 1]++;
            ans += ':' - s[i];
        }
        else ans += s[i] - '0';
    }
    ans += s[0];
    printf("%d\n", ans);
    return 0;
}
