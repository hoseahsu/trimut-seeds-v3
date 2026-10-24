#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <cctype>
using namespace std;

int main(){
	int n, m;
	for(cin >> n; n--; ){
		string cmd, msgstr;
		cin >> cmd >> msgstr;
		
		deque<char> msg(msgstr.begin(), msgstr.end());
		deque<char>::iterator it1, it2;
		
		for(int i = cmd.size() - 1; i >= 0; --i){
			switch(cmd[i]){
				case 'J':
					msg.push_front( msg.back() );
					msg.pop_back();
					break;
				case 'C':
					msg.push_back( msg.front() );
					msg.pop_front();
					break;
				case 'E':
					m = msg.size() / 2;
					it1 = msg.begin();
					it2 = msg.end() - m;
					while( m-- ){
						swap( *it1++, *it2++ );
					}
					break;
				case 'A':
					reverse(msg.begin(), msg.end());
					break;
				case 'P':
					for(it1 = msg.begin(); it1 != msg.end(); ++it1){
						if( isdigit(*it1) ){
							*it1 = (*it1 == '0' ? '9' : *it1 - 1);
						}
					}
					break;
				case 'M':
					for(it1 = msg.begin(); it1 != msg.end(); ++it1){
						if( isdigit(*it1) ){
							*it1 = (*it1 == '9' ? '0' : *it1 + 1);
						}
					}
					break;
			}
		}
		
		cout << string(msg.begin(), msg.end()) << '\n';
	}
}