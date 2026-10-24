#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll under[1000500];
ll over[1000500];
ll n, q, k, d;

void query(int now) {
    ll delta = (over[now+1] - under[now+1] + 1 + n) % n;
    if(delta * 2 >= n || delta == 0) {
        under[now] = 1;
        over[now] = n;
        return;
    }
    ll after = under[now+1];
    if(after > n / 2) after - n / 2;
    ll new_under = ((after-1) * 2 + 1) % n;
    under[now] = new_under;
    over[now] = (new_under + delta * 2 - 1 + n) % n;
    return;
}

bool isin(ll under, ll over, ll val) {
    if(under <= over) {
        if(((under <= val) && (val <= over))) {
            //cout << -1 << endl;
            return true;
        }
    } else {
        if(((val >= under) || (val <= over))) {
            //cout << -1 << endl;
            return true;
        }
    }
    //cerr << "FAILED " << under << " " << over << " " << val << endl;
    return false;
}

ll one(ll now) {
    if(now % 2 == 0) {
        return now / 2;
    }
    return n / 2 + (now + 1) / 2;
}

ll zero(ll now) {
    if(now % 2 == 0) {
        return n / 2 + now / 2;
    }
    return (now + 1) / 2;
}

int main() {
    cin >> n >> q >> k >> d;
    over[q] = d;
    under[q] = d;
    for(int i = q - 1; i >= 0; i--) {
        query(i);
    }
    for(int i = 0; i <= q; i++) {
        //cout << under[i] << " " << over[i] << endl;
    }
    /*
    if(under[0] < over[0]) {
        if(!((under[0] <= k) && (k <= over[0]))) {
            //cout << -1 << endl;
            return 0;
        }
    } else {
        if(!((k >= under[0]) || (k <= over[0]))) {
            //cout << -1 << endl;
            return 0;
        }
    }
    */
    if(!isin(under[0], over[0], k)) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans;
    ll now = k;
    for(int i = 1; i <= q; i++) {
        ll NEW = zero(now);
        //cout << i << " NEWNUMBER : " << NEW << endl;
        if(isin(under[i], over[i], NEW)) {
            ans.push_back(0);
            now = NEW;
            //cout << "0 " << now << endl;
            continue;
        }
        NEW = one(now);
        ans.push_back(1);
        now = NEW;
        //cout << "1 " << now << endl;
    }
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
