#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int sz = 200005;

struct nodetype {
public:
    int l;
    void init(int node1, int node2, int length) {
        n1 = node1;
        n2 = node2;
        l = length;
    }
    int othernode(int node) {
        if (node == n1) return n2;
        else if (node == n2) return(n1);
        else return(-1);
    }
private:
    int n1, n2;
} nodearr[sz];

vector<int> adj[sz], revadj[sz];

int visited[sz] = {}, nodestk[sz] = {}, congrp[sz] = {};
ll mydist[sz] = {}, gcdarr[sz] = {};

int visit(int node, int& marker, ll dist) {
    if (visited[node]) return(-1);
    visited[node] = 1;
    mydist[node] = dist;
    for (auto& i: adj[node]) {
        visit(nodearr[i].othernode(node), marker, dist + nodearr[i].l);
    }
    marker++;
    nodestk[marker] = node;
    return(0);
}

int group(int node, int root) {
    if (congrp[node] != 0) return(-1);
    congrp[node] = root;
    for (auto& i: revadj[node]) {
        group(nodearr[i].othernode(node), root);
    }
    return(0);
}

ll findgcd(ll n, ll m) {
    while (m != 0) {
        ll t = n;
        n = m;
        m = t % m;
    }
    return(abs(n));
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);//cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int t1, t2, t3;
        //cin >> t1 >> t2 >> t3;
        scanf("%d %d %d", &t1, &t2, &t3);
        nodearr[i].init(t1, t2, t3);
        adj[t1].push_back(i);
        revadj[t2].push_back(i);
    }
    int marker = 0;
    for (int i = 1; i <= n; i++) visit(i, marker, 0);
    for (int i = n; i >= 1; i--) {
        if (congrp[nodestk[i]] == 0) {
            group(nodestk[i], nodestk[i]);
        }
    }
    for (int i = 1; i <= n; i++) {
        int groupid = congrp[i];
        int node1 = i;
        for (auto& j: adj[node1]) {
            int node2 = nodearr[j].othernode(i);
            if (congrp[node2] == groupid) {
                gcdarr[groupid] = findgcd(gcdarr[groupid], mydist[node1] - mydist[node2] + nodearr[j].l);
            }
        }
    }

    //for (int i = 1; i <= n; i++) cout << nodestk[i];
    //for (int i = 1; i <= n; i++) cout << congrp[i];

    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int v, s, t;
        //cin >> v >> s >> t;
        scanf("%d %d %d", &v, &s, &t);
        ll g = findgcd(gcdarr[congrp[v]], t);
        if ((g == 0 && s == 0) || (g != 0 && s % g == 0))
            printf("YES\n");
        else
            printf("NO\n");
            //cout << "YES\n"; else cout << "NO\n";
    }
    return(0);
}
