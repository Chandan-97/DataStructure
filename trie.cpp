// ChandyShot

#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
#define deb(x) cout<<#x<<" = "<<x<<endl;
#define deb2(x, y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl;
#define sz 26
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define MX 1000000000
#define MN -MX
#define tc int t; cin>>t; while(t--)
#define hello cout<<"hello"<<endl;

using namespace std;

struct Node{
	struct Node *child[26];
	bool isLeaf;
};

int getIdx(char ch){
	return ch - 'a';
}

void insert(struct Node *root, string str){

	struct Node *current = root;
	
	for(int i=0; i<str.length(); i++){
		char ch = str[i];
		int idx = getIdx(ch);

		if(current->child[idx] == NULL){
			current->child[idx] = (struct Node *)malloc(sizeof(struct Node));
			current->child[idx]->isLeaf = false;
			for(int i=0; i<sz; i++)
				current->child[idx]->child[i] = NULL;
		}

		current = current->child[idx];
	}

	current->isLeaf = true;
}

bool search(struct Node *root, string str){

	struct Node *current = root;

	for(int i=0; i<str.length(); i++){
		char ch = str[i];
		int idx = getIdx(ch);

		if(current->child[idx] == NULL)
			return false;

		current = current->child[idx];
	}

	return(current != NULL && current->isLeaf);
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.in", "r", stdin);
	#endif

	struct Node *root = (struct Node *)malloc(sizeof(struct Node));
	root->isLeaf = false;
	for(int i=0; i<sz; i++){
		root->child[i] = NULL;
	}

}
