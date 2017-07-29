// Because You Look Gorgeous in Black...
// ChandyShot...
// 189A
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
using namespace std;

istream &operator>>(istream &in, vector<ll> &v)
{
  for (unsigned int i = 0; i < v.size(); i++)
    cin >> v[i];
  return in;
}

istream &operator>>(istream &in, vector<int> &v)
{
  for (unsigned int i = 0; i < v.size(); i++)
    cin >> v[i];
  return in;
}

int mat[3][sz];
int ans[sz];

void print(int n){
  for(int i=0; i<3; i++){
    for(int j=0; j<=n; j++)
      cout<<mat[i][j]<<" ";
    cout<<endl;
  }
  cout<<endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  int a[3];
  cin>>n>>a[0]>>a[1]>>a[2];
  for(int i=1; i<=n; i++){
    for(int j=0; j<3; j++){
      int remain = i - a[j];
      // cout<<"remain = "<<remain<<endl;
      if(remain < 0 or ans[remain] == -1)
        mat[j][i] = -1;
      else
        mat[j][i] = ans[remain] + 1;
      // print(n);
    }
    // cout<<endl;

    int curr = max(mat[0][i] , max(mat[1][i] , mat[2][i]));
    ans[i] = curr;
  }
  cout<<ans[n]<<endl;
  // print(n);
  return 0;
}
