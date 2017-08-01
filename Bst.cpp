// Because You Look Gorgeous in Black...
// ChandyShot...

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define sz 4005
#define szz 30
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define MX 1000000000
#define MN -MX
#define hello cout << "hello" << endl;
#define clr(x) memset(x, 0, sizeof(x))
#define fill(x) memset(x, -1, sizeof(x))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define f(i, j, k, l) for (int(i) = (j); (i) < (k); (i) += (l))
#define ff(i, j, k, l) for (int(i) = (j); (i) <= (k); (i) += (l))
#define fin f(i, 0, n, 1)
#define fjn f(j, 0, n, 1)
#define fiin ff(i, 1, n, 1)
#define fjjn f(j, 1, n, 1)
#define vi vector<int>
#define pii pair<int, int>
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
};

void insertBST(struct Node **head_ref, ll &c, ll data){
  if(*head_ref == NULL){
    c = 0;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    *head_ref = newNode;
    return;
  }
  // hello
  c++;
  if(data < (*head_ref) -> data){
    if((*head_ref)->left == NULL){
      struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
      newNode->data = data;
      newNode->left = NULL;
      newNode->right = NULL;
      (*head_ref)->left = newNode;
      return;
    }
    else{
      insertBST(&((*head_ref)->left), c, data);
    }
  }
  else if(data > ((*head_ref)->data)){
    if((*head_ref)->right == NULL){
      struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
      newNode->data = data;
      newNode->left = NULL;
      newNode->right = NULL;
      (*head_ref)->right = newNode;
    }
    else{
      insertBST(&((*head_ref)->right), c, data);
    }
  }
}

int main(){
  // io;
  // freopen("input.in", "r", stdin);
  struct Node *head = NULL;
  int n;
  scanf("%d", &n);
  ll c = 0;
  for(int i=0; i<n; i++){
    ll x;
    // cin>>x;
    scanf("%lld", &x);
    insertBST(&head, c, x);
    // deb(head)
    // cout<<c<<endl;
    printf("%lld\n", c);
  }
  return 0;
}
