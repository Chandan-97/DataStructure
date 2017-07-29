// Because You Look Gorgeous in Black...
// ChandyShot...
// 431C

/*  
  Problem : find number of ways of creating number i from numbers 1, 2, ... k, having atleast one number >= d;


  number i can be formed by i-1, i-2, i-3, ... i-k by adding 1, 2, 3, ..., k respectively

  if(number i is formed by something >= d){
    add it to ans;
  }
*/

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

int main(){
  // freopen("input.in", "r", stdin);
  ios_base::sync_with_stdio(false);
  int n, k, d;
  cin>>n>>k>>d;
  int a[n+1];
  int ans[n+1];
  clr(a);
  clr(ans);
  a[0] = 1;
  // if(d<=1) ans[1] = a[1];

  for(int i=1; i<=n; i++){
    // deb(i)
    for(int j=max(0, i-k); j<min(n, i); j++){
      // deb(i-j)
      // deb(j)
      if(i-j>= d){
        ans[i] += a[j];
        ans[i] += ans[j];
      }
      else{
        a[i] += a[j];
        ans[i] += ans[j];
      }
    }
  }

  // {
  //   for(int i=1; i<=n; i++)
  //     cout<<a[i]<<" ";
  //   cout<<endl;

  //   for(int i=1; i<=n; i++)
  //     cout<<ans[i]<<" ";
  //   cout<<endl;
  // }

  cout<<ans[n]<<endl;
  return 0;
}
