#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

const i64 MOD = 1e9 + 7;


signed main(){
    i64 n;
    cin >> n;
    vector<i64> a(n);
    for(auto& x : a)
        cin >> x;
    vector<vector<i64>> edges(n), childs(n);
    for(i64 i = 0; i < n - 1; ++i){
        i64 s, t;
        cin >> s >> t;
        --s, --t;
        edges[s].emplace_back(t);
        edges[t].emplace_back(s);
    }
    vector<i64> flag(n, 0);

    vector<i64> score = a;
    vector<i64> score_back = a;

    function<void(i64)> f = [&](i64 from){
        vector<pair<i64,i64>> sc;
        for(auto& to : edges[from]){
            if(flag[to])
                continue;
            flag[to] = 1;
            childs[from].emplace_back(to);
            f(to);
            sc.emplace_back(max(0L, score_back[to] - 2), max(0L, score[to] - 1));
        }
        i64 dif_max = 0;
        i64 sum = 0;
        for(auto& scc : sc){
            dif_max = max(dif_max, scc.second - scc.first);
            sum += scc.first;
        }
        score_back[from] += sum;
        score[from] += sum + dif_max;
    };
    flag[0] = 1;
    f(0);

    vector<i64> ans(n, 0);

    function<void(i64,i64,i64)> g = [&](i64 from, i64 par_val, i64 par_val_back){
        vector<pair<i64,i64>> v_diff;
        i64 sum = 0;
        sum += max(0L, par_val_back);
        v_diff.emplace_back(max(0L, par_val) - max(0L, par_val_back), -1);
        for(auto& to : childs[from]){
            sum += max(0L, score_back[to] - 2);
            v_diff.emplace_back(max(0L, score[to] - 1) - max(0L, score_back[to] - 2), to);
        }
        sort(v_diff.begin(), v_diff.end(), greater<pair<i64,i64>>());

        ans[from] = a[from] + sum + v_diff[0].first;

        for(auto& to : childs[from]){
            i64 nex_v = sum - max(0L, score_back[to] - 2);
            i64 nex_v_diff = v_diff[v_diff[0].second == to].first;
            g(to, nex_v + a[from] + nex_v_diff - 1, nex_v + a[from] - 2);
        }
    };
    g(0, 0, 0);

    cout << *max_element(ans.begin(), ans.end()) << endl;

}

