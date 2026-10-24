#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
#include "cmath"

using namespace std;

long long root3(long long x){
    return round(pow(x, 1.0/3));
}

void mainAlgorithm(){

    long long x;
    cin >> x;

    bool isWin = false;

    long long endNum = root3(x);
    for (long long num = 1; num <= endNum; ++num) {
        long long kek = root3(x - pow(num, 3));
        if (pow(kek, 3) + pow(num, 3) == x and kek > 0){
            isWin = true;
            break;
        }
    }

    if (isWin){
        cout << "YES";
    }else{
        cout << "NO";
    }

    cout << endl;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

//    freopen("C_in.txt", "r", stdin);
//    freopen("C_out.txt", "w", stdout);

//    freopen("main_in.txt", "r", stdin);
//    freopen("main_out.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--){

        mainAlgorithm();

    }

}