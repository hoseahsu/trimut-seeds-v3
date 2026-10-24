#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)

class Tree
{
public:
	string name;
	Tree* parent;
	vector<Tree*> child;
	
	Tree()
	:parent(NULL)
	{}
	
	~Tree()
	{
		REP(i,child.size()) delete child[i];
	}
};

Tree* tree;

Tree* find(Tree* t, string name)
{
	if(name==t->name) return t;
	
	REP(i, t->child.size())
	{
		Tree* ret=find(t->child[i], name);
		if(ret!=NULL) return ret;
	}
	return NULL;
}

bool isChild(Tree* t, string name)
{
	REP(i, t->child.size())
	{
		if(t->child[i]->name==name) return true;
	}
	
	return false;
}

bool isParent(Tree* t, string name)
{
	if(t->parent->name == name) return true;
	return false;
}

bool isSibling(Tree* t, string name)
{
	Tree* p=t->parent;
	
	return isChild(p, name);
}

bool isDescendant(Tree* t, string name)
{
	Tree* ret=find(t, name);
	if(ret==NULL) return false;
	
	return true;
}

bool isAncestor(Tree* t, string name)
{
	if(t->name==name) return true;
	if(t->parent==NULL) return false;
	
	return isAncestor(t->parent, name);
}

int main()
{
	int n,q;
	while(cin >> n >> q, (n||q))
	{
		tree = new Tree;
		Tree* now = tree;
		Tree* prev = tree;
		int sp=-1;
		cin.ignore();
		
		REP(i,n)
		{
			string str;
			getline(cin,str);
			
			int cnt=0;
			REP(j,str.size()) if(str[j]==' ') ++cnt;
			string name(str.begin()+cnt, str.end());
			
			REP(j, (sp-cnt)+1)
				now=now->parent;

			Tree* nw= new Tree;
			nw->parent=now;
			nw->name=name;
			
			now->child.push_back(nw);
			now = nw;
			sp=cnt;
		}
		
		REP(i,q)
		{
			bool ret;
			string a,b,c;
			cin >> a >> b >> b >> b >> c >> c;
			
			c=c.substr(0,c.size()-1);
			
			Tree* s=find(tree, c);
			if(s==NULL) cout << "False" << endl;
			else
			{
				if(b[0]=='c') ret=isChild(s,a);
				if(b[0]=='p') ret=isParent(s,a);
				if(b[0]=='s') ret=isSibling(s,a);
				if(b[0]=='d') ret=isDescendant(s,a);
				if(b[0]=='a') ret=isAncestor(s,a);
				
				cout << (ret?"True":"False") << endl;
			}
		}
		
		cout << endl;
		
		delete tree;
	}
}