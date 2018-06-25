// BST Implementation

#include <bits/stdc++.h>
#define ll long long int
#define sz 10005
using namespace std;

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
};

struct Node* GetNode(int data){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;

	return (newNode);
}

struct Node* findAppropriateParent(struct Node **root, int data){
	struct Node *current = *root;
	struct Node *prev = NULL;

	while(current){
		prev = current;
		if(data <= current->data)
			current = current->left;
		else
			current = current->right;
	}

	return prev;
}

void Insert(struct Node **root, int data){
	struct Node *newNode = GetNode(data);
	
	if(*root == NULL){	// insert at head;
		*root = newNode;
		newNode->parent = NULL;
		return;
	}

	// compare and find position
	struct Node *parent = findAppropriateParent(root, data);
	newNode->parent = parent;
	
	if(data <= parent->data)
		parent->left = newNode;
	else
		parent->right = newNode;

	return;
}

void preOrder(struct Node *current){
	if(current){
		cout<<current->data<<" ";
		preOrder(current->left);
		preOrder(current->right);
	}
}

void inOrder(struct Node *current){
	if(current){
		inOrder(current->left);
		cout<<current->data<<" ";
		inOrder(current->right);
	}
}

void postOrder(struct Node *current){
	if(current){
		postOrder(current->left);
		postOrder(current->right);
		cout<<current->data<<" ";
	}
}

bool search(struct Node *current, int data){

	while(current){
		if(current->data == data)
			return true;

		if(data <= current->data)
			current = current->left;
		else
			current = current->right;
	}

	return false;
}

int main(){
	struct Node *root = NULL;
	int n, m;
	cin>>n>>m;
	for(int i=0; i<n; i++){
		int data;
		cin>>data;
		Insert(&root, data);
	}

	cout<<"PreOrder : ";
	preOrder(root);
	cout<<endl;

	cout<<"InOrder : ";
	inOrder(root);
	cout<<endl;

	cout<<"PostOrder : ";
	postOrder(root);
	cout<<endl;

	for(int i=0; i<m; i++){
		int data;
		cin>>data;
		if(search(root, data))
			cout<<"Found"<<endl;
		else
			cout<<"Not Found"<<endl;
	}

	return 0;
}
