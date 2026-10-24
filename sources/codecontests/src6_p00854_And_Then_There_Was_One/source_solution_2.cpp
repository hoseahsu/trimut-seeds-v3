#include<bits/stdc++.h>
using namespace std;
struct node {
  struct node* left;
  int idx;
  struct node* right;
};

int main(){
  int n, k, m;
  node list[10000], *root;

  while(cin >> n >> k >> m, n){
    for(int i = 0; i < n; i++){
      list[i].left = &list[(i + n - 1) % n];
      list[i].idx = i + 1;
      list[i].right = &list[(i + 1) % n];
      if(list[i].idx == m) root = &list[i];
    }
    while(root != root -> right){
      root -> left -> right = root -> right;
      root -> right -> left = root -> left;
      for(int i = 0; i < k; i++) root = root -> right;
    }
    cout << root -> idx << endl;
  } 
}