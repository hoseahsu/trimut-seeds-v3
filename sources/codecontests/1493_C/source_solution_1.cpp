#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
//#include <ext/pb_ds/hash_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
//typedef gp_hash_table<int, int> hashmap;
//typedef tree<pii, null_type, std::less<pii>, splay_tree_tag, tree_order_statistics_node_update> splaytree;
//typedef tree<pii, null_type, std::less<pii>, rb_tree_tag, tree_order_statistics_node_update> rbtree;
//typedef __gnu_pbds::priority_queue<int, std::greater<int>, __gnu_pbds::binary_heap_tag> binheap;
//typedef __gnu_pbds::priority_queue<int, std::greater<int>, __gnu_pbds::pairing_heap_tag> pairingheap;

template <typename T>
inline void read(T &x)
{
    T data = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        data = (data << 3) + (data << 1) + ch - '0';
        ch = getchar();
    }
    x = f * data;
}
template <typename T, typename... Args>
inline void read(T &t, Args &...args)
{
    read(t);
    read(args...);
}

//mt19937 rnd(time(0));
const ll inf = 0;
const double eps = 1e-8;
const int maxn = 1e5 + 9;
const ll mod = 1e9 + 7;
int n, k, sum[maxn][30], tmp[30];
char s[maxn], ans[maxn];

void print()
{
    for (int i = 1; i <= n; ++i)
        putchar(ans[i]);
    putchar('\n');
}
bool work(int pos)
{
    int cnt = 0;
    for (int i = s[pos] - 'a' + 2; i <= 26; ++i)
    {
        int tot = 0;
        memset(tmp, 0, sizeof(tmp));
        sum[pos][i]++;
        sum[pos][s[pos] - 'a' + 1]--;
        assert(sum[pos][s[pos] - 'a' + 1] >= 0);
        // cerr << sum[pos][s[pos] - 'a' + 1] << endl;
        for (int j = 1; j <= 26; ++j)
        {
            tmp[j] = (k - (sum[pos][j] % k)) % k;
            tot += tmp[j];
        }
        sum[pos][i]--;
        sum[pos][s[pos] - 'a' + 1]++;
        if ((n - pos - tot) % k != 0 || tot > n - pos)
            continue;
        int res = 0;
        for (int j = 1; j <= pos - 1; ++j)
        {
            ans[j] = s[j];
            cnt++;
        }
        cnt++;
        ans[pos] = i + 'a' - 1;
        int now = pos + 1;
        int t = n - pos - tot;
        // assert(t >= 0);
        while (now <= n && t > 0)
        {
            ans[now++] = 'a';
            cnt++, t--;
        }
        // cerr << t << endl;
        for (int j = 1; j <= 26; ++j)
        {
            while (tmp[j] && now <= n)
            {
                tmp[j]--, tmp[0]++;
                ans[now] = j - 1 + 'a';
                cnt++, now++;
            }
            // cerr << tmp[0] << endl;
        }
        // cerr << cnt << endl;
        return true;
    }
    // cerr << cnt << endl;
    return false;
}

signed main()
{
    //freopen("in.txt","r",stdin);
    //freopen("data.txt","j",stdout);
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
    //std::cout.tie(0);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &k);
        scanf("%s", s + 1);
        if (n % k != 0)
        {
            puts("-1");
            continue;
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= 26; ++j)
                sum[i][j] = sum[i - 1][j];
            sum[i][s[i] - 'a' + 1]++;
        }
        bool flag = true;
        for (int i = 1; i <= 26; ++i)
        {
            if (sum[n][i] % k != 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            puts(s + 1);
            continue;
        }
        for (int i = n; i >= 1; --i)
        {
            if (work(i))
            {
                print();
                break;
            }
        }
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}