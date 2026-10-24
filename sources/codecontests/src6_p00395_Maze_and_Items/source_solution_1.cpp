#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

using lint = long long;
using P = pair<int, int>;
using LLP = pair<long long, long long>;

const long long LLINF = 1LL << 61;
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};

template<typename T>
bool chmax(T &a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

template<typename T>
bool chmin(T &a, T b){
    if(b < a){
        a = b;
        return true;
    }
    return false;
}

struct node{
    int id;
    lint cost;

    bool operator<(const node& rhs) const {
        return cost > rhs.cost;
    }
};

int w, h;
string row[1000];
lint s[10][10];

int px[32], py[32];
lint dis[32][32];
lint cost[1 << 10][32][32];

bool check(int y, int x){
    return 0 <= y && y < h && 0 <= x && x < w && row[y][x] != '#';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> w >> h;

    fill(px, px + 32, -1);
    fill(py, py + 32, -1);
    fill(dis[0], dis[32], LLINF);
    for(int i = 0 ; i < (1 << 10) ; ++i){
        fill(cost[i][0], cost[i][32], LLINF);
    }

    for(int i = 0 ; i < h ; ++i){
        cin >> row[i];
        for(int j = 0 ; j < w ; ++j){
            if('0' <= row[i][j] && row[i][j] <= '9'){
                px[row[i][j] - '0'] = j;
                py[row[i][j] - '0'] = i;
            }else if('A' <= row[i][j] && row[i][j] <= 'J'){
                px[row[i][j] - 'A' + 10] = j;
                py[row[i][j] - 'A' + 10] = i;
            }else if('a' <= row[i][j] && row[i][j] <= 'j'){
                px[row[i][j] - 'a' + 20] = j;
                py[row[i][j] - 'a' + 20] = i;
            }else if(row[i][j] == 'S'){
                px[30] = j;
                py[30] = i;
            }else if(row[i][j] == 'T'){
                px[31] = j;
                py[31] = i;
            }
        }
    }

    for(int i = 0 ; i < 10 ; ++i){
        for(int j = 0 ; j < 10 ; ++j){
            cin >> s[i][j];
        }
    }

    for(int i = 0 ; i < 32 ; ++i){
        if(px[i] < 0){
            continue;
        }
        lint tmpDis[1000][1000];
        fill(tmpDis[0], tmpDis[h], LLINF);
        queue< pair<P, lint> > que;
        que.push({{py[i], px[i]}, 0LL});
        tmpDis[py[i]][px[i]] = 0LL;
        while(!que.empty()){
            auto now = que.front();
            que.pop();
            if(tmpDis[now.first.first][now.first.second] < now.second){
                continue;
            }
            for(int j = 0 ; j < 4 ; ++j){
                int ny = now.first.first + dy4[j], nx = now.first.second + dx4[j];
                if(!check(ny, nx)){
                    continue;
                }else if(chmin(tmpDis[ny][nx], now.second + 1LL) && (row[ny][nx] == '.' || row[ny][nx] == 'S' || row[ny][nx] == 'T' || ('0' <= row[ny][nx] && row[ny][nx] <= '9'))){
                    que.push({{ny, nx}, now.second + 1LL});
                }
            }
        }
        for(int j = 0 ; j < 32 ; ++j){
            if(px[j] < 0){
                continue;
            }
            chmin(dis[i][j], tmpDis[py[j]][px[j]]);
        }
    }

    for(int i = 0 ; i < (1 << 10) ; ++i){
        for(int j = 0 ; j < 32 ; ++j){
            if(px[j] < 0 || (j < 10 && !(i >> j & 1))){
                continue;
            }
            priority_queue<node> que;
            que.push({j, 0LL});
            cost[i][j][j] = 0LL;
            while(!que.empty()){
                node now = que.top();
                que.pop();
                if(cost[i][j][now.id] < now.cost){
                    continue;
                }
                for(int k = 0 ; k < 10 ; ++k){
                    if(dis[now.id][k] >= LLINF || now.id == k){
                        continue;
                    }
                    if(chmin(cost[i][j][k], now.cost + dis[now.id][k])){
                        que.push({k, now.cost + dis[now.id][k]});
                    }
                }
                for(int k = 10 ; k < 20 ; ++k){
                    if(dis[now.id][k] >= LLINF || now.id == k || i >> (k - 10) & 1){
                        continue;
                    }
                    if(chmin(cost[i][j][k], now.cost + dis[now.id][k])){
                        que.push({k, now.cost + dis[now.id][k]});
                    }
                }
                for(int k = 20 ; k < 30 ; ++k){
                    if(dis[now.id][k] >= LLINF || now.id == k || !(i >> (k - 20) & 1)){
                        continue;
                    }
                    if(chmin(cost[i][j][k], now.cost + dis[now.id][k])){
                        que.push({k, now.cost + dis[now.id][k]});
                    }
                }
                for(int k = 30 ; k < 32 ; ++k){
                    if(dis[now.id][k] >= LLINF || now.id == k){
                        continue;
                    }
                    if(chmin(cost[i][j][k], now.cost + dis[now.id][k])){
                        que.push({k, now.cost + dis[now.id][k]});
                    }
                }
            }
        }
    }

    LLP ans = {LLINF, LLINF};
    vector<int> v;
    for(int i = 0 ; i < 10 ; ++i){
        v.emplace_back(i);
    }
    do{
        if(cost[0][30][v[0]] >= LLINF || cost[(1 << 10) - 1][v[9]][31] >= LLINF){
            continue;
        }
        LLP tmp = {cost[0][30][v[0]] + cost[(1 << 10) - 1][v[9]][31], 0LL};
        bool flag = true;
        int state = 1 << v[0];
        for(int i = 0 ; i < 9 ; ++i){
            if(cost[state][v[i]][v[i + 1]] >= LLINF){
                flag = false;
                break;
            }
            tmp.first += cost[state][v[i]][v[i + 1]];
            tmp.second -= s[v[i]][v[i + 1]];
            state |= (1 << v[i + 1]);
        }

        if(flag){
            chmin(ans, tmp);
        }
    }while(next_permutation(v.begin(), v.end()));

    if(ans.first < LLINF){
        cout << ans.first << " " << -ans.second << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}
