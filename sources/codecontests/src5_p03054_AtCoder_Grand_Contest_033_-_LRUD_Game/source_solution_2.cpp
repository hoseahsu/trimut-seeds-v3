#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W,N;
  cin>>H>>W>>N;
  int Sr,Sc;
  cin>>Sr>>Sc;
  string S,T;
  cin>>S>>T;
  
  int R=Sr,C=Sc;
  bool j=false;
  for(int i=0;i<N;i++){
    if(S[i]=='L'){
      C--;
    }
    if(C==0){
      j=true;
      break;
    }
    if(T[i]=='R'&&C<W){
      C++;
    }
  }
  R=Sr,C=Sc;
  for(int i=0;i<N;i++){
    if(S[i]=='R'){
      C++;
    }
    if(C==W+1){
      j=true;
      break;
    }
    if(T[i]=='L'&&C>1){
      C--;
    }
  }
  R=Sr,C=Sc;
  for(int i=0;i<N;i++){
    if(S[i]=='U'){
      R--;
    }
    if(R==0){
      j=true;
      break;
    }
    if(T[i]=='D'&&R<H){
      R++;
    }
  }
  R=Sr,C=Sc;
  for(int i=0;i<N;i++){
    if(S[i]=='D'){
      R++;
    }
    if(R==H+1){
      j=true;
      break;
    }
    if(T[i]=='U'&&R>1){
      R--;
    }
  }
  if(j)
    cout<<"NO"<<endl;
  else
    cout<<"YES"<<endl;
}