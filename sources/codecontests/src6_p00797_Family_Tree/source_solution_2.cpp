#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

constexpr long double EPS = 1e-15;
const long double PI = acos(-1);
constexpr int inf = 2e9;
constexpr ll INF = 2e18;
constexpr ll MOD = 1e9+7;
constexpr ll MOD1 = 998244353;
typedef pair<ll,ll> P;

//#define all(v) (v).begin(), (v).end()
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second
//#define mp make_pair

class Person{
public:
    int id;
    string name;
    vector<Person> child;
    int pid = -1;

    Person(){}
    Person(string _name, int _id, int p = -1) {
        id = _id;
        name = _name;
        pid = p;
    }
    void addchild(Person c) {
        child.push_back(c);
    }
    bool issibling(string s) {
        REP(i,sz(child)) {
            if (s == child[i].name) return 1;
        }
        return 0;
    }
    void showchild() {
        for (int i = 0; i < child.size(); i++) {
            cout << child[i].name << endl;
        }
    }
};

void solve() {

while (1) {
    string s;
    getline(cin,s);
    stringstream ss;
    ss << s;
    int n, m;
    ss >> n >> m;
    // cout << n << " " << m << endl;
    if (n == 0 && m == 0) break;


    map<string,int> id;
    vector<Person> people;
    stack<pair<string,int>> parents;

    REP(i,n) {
        getline(cin,s);
        int indent = 0;
        while (s[indent] == ' ') {
            indent++;
        }
        string name = s.substr(indent, s.size() - indent);
        // cout << name << endl;

        if (indent == 0) {
            parents.push({name,0});
            people.push_back(Person(name,i));
            id[name] = i;
        } else {
            pair<string,int> tp = parents.top();
            while (indent <= tp.se) {
                parents.pop();
                tp = parents.top();
            }
            parents.push({name,indent});
            people.push_back(Person(name,i,id[tp.fi]));
            people[id[tp.fi]].addchild(people.back());
            id[name] = i;
        }
    }

    REP(i,m) {
        stringstream tmp;
        getline(cin,s);
        tmp << s;
        string n1,is,the,relation,of,n2;
        tmp >> n1 >> is >> the >> relation >> of >> n2;
        // cout << n1 << " " << is << " " << the << " " << relation << " " << of << " " << n2 << endl;
        n2 = n2.substr(0,sz(n2)-1);
        bool f = 0;
        if (relation == "child") {
            f = (people[id[n1]].pid == id[n2]);
        } else if (relation == "ancestor") {
            f = 0;
            int tid = people[id[n2]].pid;
            while (tid != -1) {
                if (people[tid].name == n1) {
                    f = 1;
                    break;
                }
                tid = people[tid].pid;
            }
        } else if (relation == "sibling") {
            f = 0;
            int tid = people[id[n1]].pid;
            if (tid == -1) f = 0;
            else f = people[tid].issibling(n2);
        } else if (relation == "parent") {
            f = (people[id[n2]].pid == id[n1]);
        } else if (relation == "descendant") {
            f = 0;
            int tid = people[id[n1]].pid;
            while (tid != -1) {
                if (people[tid].name == n2) {
                    f = 1;
                    break;
                }
                tid = people[tid].pid;
            }
        }
        cout << (f?"True":"False") << endl;
    }

    cout << endl;
}
}


int main(int argc, char *argv[]){

    // /* Regular */
    // int case_num = 1;
    // if (argc > 1 && stoi(argv[1])) cin >> case_num;
    // REP(case_no, case_num) {
    //   cerr << endl << "case " << case_no + 1 << endl;
    //   solve();
    // }

    /* AOJ */
    solve();

    return 0;
}
