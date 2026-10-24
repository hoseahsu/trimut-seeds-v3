#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int> pii;
#define X first
#define Y second

//AOJ0333の改造
struct segmentTree{
    vector<vector<pii> > node;
    int n;
    
    segmentTree(int s){
        n = 1;
        while(n < s) n*=2;
        node = vector<vector<pii> >(2*n -1);
    }
    segmentTree(){}

    //区間(l, r)に高さvalの線分を追加
    void Insert(pii val, int l, int r){
        if(l+1 == r) return;
        _set(val, l+1, r, 0, 0, n);
    }
    void _set(pii val, int l, int r, int k, int cl, int cr){
    	if(cr <= l || r <= cl) return;
    	if(l <= cl && cr <= r){
    		node[k].push_back(val);
    		return;
    	}
    	int m = (cl +cr)/2;
    	_set(val, l, r, 2*k +1, cl, m);
    	_set(val, l, r, 2*k +2, m, cr);
    }

    void Sort(){
        for(auto &vec: node){
            sort(vec.begin(), vec.end());
        }
    }

    //位置posについて、高さbから最も早くぶつかるid(second要素)を返す
    int IntersectID(int pos, int b, bool forward){
        int idx = n-1 + pos;
        pii ret = forward? pii(1e9, -1) : pii(-1e9, -1);
        while(1){
            vector<pii> &vec = node[idx];
            auto itr = lower_bound(vec.begin(), vec.end(), pii(b, 0));
            if(forward){
                if(itr != vec.end()){
                    ret = min(ret, *itr);
                }
            }else{
                if(itr != vec.begin()){
                    ret = max(ret, *(itr -1));
                }
            }
        	if(idx == 0) break;
        	idx = (idx -1) /2;
        }
        return ret.second;
    }
};

void compress(vector<vector<pii> > &s, vector<vector<pii> > &t){
    int n = s[0].size();
	map<int, int> convx, convy;
    for(int d=0; d<4; d++){
        for(int i=0; i<n; i++){
            convx[s[d][i].X] = 0;
            convx[t[d][i].X] = 0;
            convy[s[d][i].Y] = 0;
            convy[t[d][i].Y] = 0;
        }
    }
    int countx=0, county=0;
    for(auto &xpair: convx) xpair.second = countx++;
    for(auto &ypair: convy) ypair.second = county++;
    for(int d=0; d<4; d++){
        for(int i=0; i<n; i++){
            s[d][i] = pii(convx[s[d][i].X], convy[s[d][i].Y]);
            t[d][i] = pii(convx[t[d][i].X], convy[t[d][i].Y]);
        }
    }
}

int main(){
    int n;
    cin >> n;
    //左下->右下が0, 反時計回り
    vector<vector<pii> > s(4, vector<pii>(n));
    vector<vector<pii> > t(4, vector<pii>(n));
    for(int i=0; i<n; i++){
        int xs,ys,xt,yt;
        cin >> xs >> ys >> xt >> yt;
        s[0][i] = t[3][i] = pii(xs, ys);
        s[1][i] = t[0][i] = pii(xt, ys);
        s[2][i] = t[1][i] = pii(xt, yt);
        s[3][i] = t[2][i] = pii(xs, yt);
    }
    compress(s, t);
    
    //線分情報をセグ木に格納
    segmentTree tree[2] = {segmentTree(2*n), segmentTree(2*n)};
    for(int d=0; d<4; d++){
        for(int i=0; i<n; i++){
            if(d%2 == 0){
                int pos = s[d][i].Y;
                int rmin = min(s[d][i].X, t[d][i].X);
                int rmax = max(s[d][i].X, t[d][i].X);
                tree[0].Insert(pii(pos, i), rmin, rmax);
            }else{
                int pos = s[d][i].X;
                int rmin = min(s[d][i].Y, t[d][i].Y);
                int rmax = max(s[d][i].Y, t[d][i].Y);
                tree[1].Insert(pii(pos, i), rmin, rmax);
            }
        }
    }
    tree[0].Sort();
    tree[1].Sort();

    //閉路ができた場合、ぶつかる壁のリストをansに突っ込む
    set<pii> ans; //pii(d, id)
    vector<vector<bool> > used(4, vector<bool>(n, false));
    for(int i=0; i<n; i++){
        pii curr = pii(0, i);
        set<pii> cycle;
        vector<pii> cyclevec;
        bool success = false;
        while(1){
            cycle.insert(curr);
            cyclevec.push_back(curr);
            //更新
            int d = curr.first;
            int id = curr.second;
            if(d%2 == 0){
                id = tree[1].IntersectID(s[d][id].Y, s[d][id].X, d/2!=0);
            }else{
                id = tree[0].IntersectID(s[d][id].X, s[d][id].Y, d/2!=0);
            }
            d = (d+1)%4;
            curr = pii(d, id);

            if(id == -1) break;
            if(cycle.find(curr) != cycle.end()){
                success = true;
                break;
            }
            if(used[d][id]) break;
            used[d][id] = true;
        }
        if(success){
            bool incycle = false;
            for(pii p: cyclevec){
                if(p == curr) incycle = true;
                if(incycle) ans.insert(p);
            }
        }
    }
    cout << ans.size() << endl;
    return 0;
}

