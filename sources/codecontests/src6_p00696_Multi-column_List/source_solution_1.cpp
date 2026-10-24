#include<string>
#include<vector>
#include<iostream>

#define	pb	push_back

using namespace std;

int main(){
	for(int plen;cin>>plen,plen;){
		int cnum,w,cspace;
		cin>>cnum>>w>>cspace;
		cin.ignore();

		vector<string> mul;
		for(string s;getline(cin,s),s!="?";){
			int len=s.length();
			if(len==0)	mul.pb("");
			for(int i=0;i<len;i+=w){
				if(w<len-i)	mul.pb(s.substr(i,w));
				else		mul.pb(s.substr(i));
			}
		}
//for(int i=0;i<mul.size();i++)	cout<<mul[i]<<endl;
		int m=mul.size();
		int pages=(m+(plen*cnum-1))/(plen*cnum);	// ceiling
		for(int i=0;i<pages;i++){
			int offset=i*plen*cnum;
			vector<string> pg(plen);
			if(i==pages-1){	// last page
				for(int j=offset;j<m;j++){
					pg[j%plen]+=mul[j];
					int padding=w-mul[j].length();
					pg[j%plen]+=string(padding,'.');
				}
				for(int j=m;j<offset+plen*cnum;j++){
					pg[j%plen]+=string(w,'.');
				}
			}
			else{
				for(int j=offset;j<offset+plen*cnum;j++){
					pg[j%plen]+=mul[j];
					int padding=w-mul[j].length();
					pg[j%plen]+=string(padding,'.');
				}
			}

			for(int i=0;i<plen;i++){
				for(int j=0;j<cnum;j++){
					if(j>0)	cout<<string(cspace,'.');
					cout<<pg[i].substr(w*j,w);
				}
				cout<<endl;
			}
			cout<<'#'<<endl;
		}

		cout<<'?'<<endl;
	}

	return 0;
}