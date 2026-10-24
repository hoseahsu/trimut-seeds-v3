#include <iostream>
#include <complex>
#include <vector>
#include <stack>

using namespace std;

template<class T> bool operator<(const complex<T> &a, const complex<T> &b){
    return a.real() == b.real() ? a.imag() < b.imag() : a.real() < b.real();
}

typedef complex<double> P;
#define X real()
#define Y imag()

double dot(P a, P b){
    return (a * conj(b)).X;
}
double cross(P a, P b){
    return (a * conj(b)).Y;
}

vector<P> points;
deque<P> selected;
int max_count;

void search(int index) {
    if(index > points.size()) return;
    int selected_size = selected.size();

    bool is_all_overlap = true;
    if(selected_size >= 2 && selected_size > max_count) {
        // calc is all overlaps
        vector<P> copied_selected;
        copy(selected.begin(), selected.end(), back_inserter(copied_selected));

        for (int i = 0; i < selected_size ; ++i) {
            for (int j = 0; j < selected_size; ++j) {
                if(i == j) continue;
                // two point check
                double d12 = abs(copied_selected[i] - copied_selected[j]);
                if(d12 > 2.0 + 1e-10) {
                    is_all_overlap = false;
                    break;
                }

                for (int k = 0; k < selected_size; ++k) {
                    if(i == k || j == k) continue;
                    // three point check
                    P p1 = copied_selected[i];
                    P p2 = copied_selected[j];
                    P p3 = copied_selected[k];

                    P center12 = P((p1.X + p2.X) / 2, (p1.Y + p2.Y) / 2);
                    double allow_distance = 1 + sqrt(1 - ((d12 * d12) / 4));
                    if(abs(center12 - p3)  > allow_distance + 1e-10) {
                        is_all_overlap = false;
                        break;
                    }
                }

            }
            if(!is_all_overlap) {
                break;
            }
        }

        copied_selected.clear();
        copied_selected.shrink_to_fit();
    }

    if (is_all_overlap) {
        // update max count
        if(selected_size > max_count) {
            max_count = selected_size;
        }

        P p = points[index];
        // remove bad situation
        if(selected.empty() || abs(p - selected.front()) <= 2.0 + 1e-10) {
            // take
            selected.push_front(p);
            search(index + 1);
            selected.pop_front();
        }

        // for next dispatch
        // not take
        search(index + 1);
    }
}

int main() {
    int n;
    while (cin >> n) {
        if(n == 0) break;
        points.clear();
        points.shrink_to_fit();
        selected.clear();
        selected.shrink_to_fit();
        max_count = 0;

        // load points
        for (char i = 0; i < n; ++i) {
            double x;
            double y;
            scanf("%lf,%lf", &x, &y);
            P p = P(x, y);
            points.push_back(p);
        }

        search(0);
        cout << max_count << endl;
    }
    return 0;
}