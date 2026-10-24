/*
 * 2535.cc: Texas hold 'em
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>
 
using namespace std;

/* constant */

const string HN[] = {
  "HC", "OP", "TP", "TOK", "S", "F", "FH", "FOK", "SF", "RSF"
};

const char ST[] = {'S', 'H', 'D', 'C'};
const char RK[] = {
  '_', 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'
};

/* typedef */

typedef vector<int> vi;
typedef queue<int> qi;
typedef pair<int,int> pii;

enum { H_HC, H_OP, H_TP, H_TOK, H_S, H_F, H_FH, H_FOK, H_SF, H_RSF };

struct Card {
  int s, r;
  Card() {}
  Card(int _s, int _r): s(_s), r(_r) {}
  Card(string cs) {
    switch (cs[0]) {
    case 'S': s = 0; break;
    case 'H': s = 1; break;
    case 'D': s = 2; break;
    case 'C': s = 3; break;
    }
    switch (cs[1]) {
    case 'A': r = 14; break;
    case 'K': r = 13; break;
    case 'Q': r = 12; break;
    case 'J': r = 11; break;
    case 'T': r = 10; break;
    default: r = cs[1] - '0';
    }
  }

  bool operator==(const Card& c) { return r == c.r; }
  bool operator<(const Card& c) { return r < c.r; }
  bool operator>(const Card& c) { return r > c.r; }
  string to_s() { string t; t += ST[s]; t += RK[r]; return t; }
};

/* global variables */

bool used[4][15];

/* subroutines */

int check_hand(Card (&cs)[5], vi &tb) {
  int sns[4] = {}, rns[15] = {};
  int maxsn = 0, maxrn0 = 0, maxrn1 = 0;
  tb.clear();

  for (int i = 0; i < 5; i++) sns[cs[i].s]++, rns[cs[i].r]++;
  for (int i = 0; i < 4; i++)
    if (maxsn < sns[i]) maxsn = sns[i];
  for (int i = 2; i <= 14; i++) {
    if (maxrn0 < rns[i]) maxrn1 = maxrn0, maxrn0 = rns[i];
    else if (maxrn1 < rns[i]) maxrn1 = rns[i];
  }
  //printf("maxsn=%d, maxrn0=%d, maxrn1=%d\n", maxsn, maxrn0, maxrn1);
  
  bool flush = (maxsn == 5);

  bool strt = false;
  if (maxrn0 == 1) {
    int cnt = 0;
    for (int i = 14; i >= 2; i--) {
      if (rns[i]) {
	if (++cnt == 5) {
	  strt = true;
	  tb.push_back(i + 4);
	  break;
	}
      }
      else cnt = 0;
    }
    if (cnt == 4 && rns[14]) {
      strt = true;
      tb.push_back(5);
    }
  }

  if (strt) {
    // Royal straight flush
    if (flush && tb[0] == 14) return H_RSF;
    // Straight flush
    if (flush) return H_SF;
    // Straight
    return H_S;
  }

  vi tbs[5];
  for (int i = 14; i >= 2; i--)
    if (rns[i] > 0) tbs[rns[i]].push_back(i);

  // Four of a kind
  if (maxrn0 == 4) {
    tb.push_back(tbs[4][0]);
    tb.push_back(tbs[1][0]);
    return H_FOK;
  }

  // Full house
  if (maxrn0 == 3 && maxrn1 == 2) {
    tb.push_back(tbs[3][0]);
    tb.push_back(tbs[2][0]);
    return H_FH;
  }

  // Flush
  if (flush) {
    for (int i = 14; i >= 2; i--)
      for (int j = 0; j < rns[i]; j++) tb.push_back(i);
    return H_F;
  }

  // Straight (already done)

  // Three of a kind
  if (maxrn0 == 3) {
    tb.push_back(tbs[3][0]);
    tb.push_back(tbs[1][0]);
    tb.push_back(tbs[1][1]);
    return H_TOK;
  }

  // Two Pair
  if (maxrn0 == 2 && maxrn1 == 2) {
    tb.push_back(tbs[2][0]);
    tb.push_back(tbs[2][1]);
    tb.push_back(tbs[1][0]);
    return H_TP;
  }

  // One Pair
  if (maxrn0 == 2) {
    tb.push_back(tbs[2][0]);
    tb.push_back(tbs[1][0]);
    tb.push_back(tbs[1][1]);
    tb.push_back(tbs[1][2]);
    return H_OP;
  }

  // High card
  tb = tbs[1];
  return H_HC;
}

bool win_hand(int h0, vi &tb0, int h1, vi &tb1) {
  if (h0 != h1) return (h0 > h1);
  for (int i = 0; i < tb0.size(); i++)
    if (tb0[i] != tb1[i]) return (tb0[i] > tb1[i]);
  return false;
}

int rec(Card (&cs)[7], Card (&cs0)[5], vi &tb, int k, int n) {
  //printf("rec(%d,%d)\n", k, n);
  if (k >= 5) {
    //for (int i = 0; i < 5; i++) cout << ' ' << cs0[i].to_s();
    //cout << endl;
    return check_hand(cs0, tb);
  }
  if (n >= 7) return -1;

  int maxh = -1, maxi = min(6, 2 + k);
  vi tb0;

  for (int i = n; i <= maxi; i++) {
    cs0[k] = cs[i];
    int h = rec(cs, cs0, tb0, k + 1, i + 1);
    if (h >= 0 && win_hand(h, tb0, maxh, tb)) {
      maxh = h;
      tb = tb0;
    }
  }

  return maxh;
}

int strongest(Card (&cs)[7], vi &tb) {
  Card cs0[5];
  tb.clear();

  //cout << "strongest:";
  //for (int i = 0; i < 7; i++) cout << ' ' << cs[i].to_s();
  //cout << endl;
  return rec(cs, cs0, tb, 0, 0);
}

/* main */

int main() {
  /*
  //Card c5[5] = {Card("SA"), Card("SK"), Card("SQ"), Card("SJ"), Card("ST")};
  //Card c5[5] = {Card("S9"), Card("SK"), Card("SQ"), Card("SJ"), Card("ST")};
  //Card c5[5] = {Card("HA"), Card("S2"), Card("S3"), Card("S4"), Card("S5")};
  //Card c5[5] = {Card("S9"), Card("H9"), Card("D9"), Card("CK"), Card("SK")};
  Card c5[5] = {Card("S3"), Card("S3"), Card("S3"), Card("SJ"), Card("SQ")};
  //Card c5[5] = {Card("S9"), Card("H9"), Card("D9"), Card("CK"), Card("HA")};
  //Card c5[5] = {Card("S9"), Card("H9"), Card("DQ"), Card("CQ"), Card("HK")};
  //Card c5[5] = {Card("S3"), Card("H3"), Card("D4"), Card("C5"), Card("HA")};
  //Card c5[5] = {Card("S3"), Card("H6"), Card("D4"), Card("C5"), Card("HA")};
  vi tbb;
  int h = check_hand(c5, tbb);
  cout << HN[h];
  for (int i = 0; i < tbb.size(); i++) printf(" %d", tbb[i]); putchar('\n');
  return 0;
  */
  
  string cs00, cs01, cs10, cs11;
  for (;;) {
    cin >> cs00;
    if (cs00 == "#") break;

    memset(used, false, sizeof(used));
    
    cin >> cs01 >> cs10 >> cs11;
    Card h00 = Card(cs00); used[h00.s][h00.r] = true;
    Card h01 = Card(cs01); used[h01.s][h01.r] = true;
    Card h10 = Card(cs10); used[h10.s][h10.r] = true;
    Card h11 = Card(cs11); used[h11.s][h11.r] = true;

    string ccs0, ccs1, ccs2;
    cin >> ccs0 >> ccs1 >> ccs2;
    Card f0 = Card(ccs0); used[f0.s][f0.r] = true;
    Card f1 = Card(ccs1); used[f1.s][f1.r] = true;
    Card f2 = Card(ccs2); used[f2.s][f2.r] = true;

    int win = 0, total = 0;
    Card cs0[7] = {h00, h01, f0, f1, f2};
    Card cs1[7] = {h10, h11, f0, f1, f2};
    
    for (int s0 = 0; s0 < 4; s0++)
      for (int r0 = 2; r0 <= 14; r0++)
	if (! used[s0][r0]) {
	  used[s0][r0] = true;
	  Card tc(s0, r0);
	  cs0[5] = cs1[5] = tc;
	  for (int s1 = 0; s1 < 4; s1++)
	    for (int r1 = 2; r1 <= 14; r1++)
	      if (! used[s1][r1]) {
		used[s1][r1] = true;
		Card rc(s1, r1);
		cs0[6] = cs1[6] = rc;

		vi tb0, tb1;
		int h0 = strongest(cs0, tb0);
		/*
		cout << HN[h0];
		for (int i = 0; i < tb0.size(); i++) printf(" %d", tb0[i]);
		putchar('\n');
		*/
		int h1 = strongest(cs1, tb1);
		/*
		cout << HN[h1];
		for (int i = 0; i < tb1.size(); i++) printf(" %d", tb1[i]);
		putchar('\n');
		*/
		if (win_hand(h0, tb0, h1, tb1)) win++;
		total++;
		
		used[s1][r1] = false;
	      }
	  used[s0][r0] = false;
	}

    //printf("%d/%d\n", win, total);
    printf("%.10lf\n", (double)win / total);
  }  
  return 0;
}