// Because You look Gorgeous in Black
// ChandyShot
// 276C
#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define sz 200010
#define szz 30
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define MX 1000000000
#define MN -MX
#define hello cout << "hello" << endl;
#define tc int t; cin>>t; while(t--)
#define clr(x) memset(x, 0, sizeof(x))
#define fill(x) memset(x, -1, sizeof(x))
#define min3(a, b, c) min(a, min(b, c))
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
 
std::istream &operator>>(istream &in, std::vector<ll> &v)
{
for (unsigned int i = 0; i < v.size(); i++)
    cin >> v[i];
return in;
}
 
std::istream &operator>>(istream &in, std::vector<int> &v)
{
for (unsigned int i = 0; i < v.size(); i++)
    cin >> v[i];
return in;
}

int main(){
  // freopen("input.in", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q;
 
  cin>>n>>q;

  vector <ll> v(n);
  for(int i=0; i<n; i++)
    cin>>v[i];

  ll a[sz];
  clr(a);
  while(q--){
    int l, r;
    cin>>l>>r;
    a[l] += 1;
    a[r+1] -= 1;
  }

  for(int i=1; i<sz; i++){
    a[i] += a[i-1];
  }

  vector <ll> multiples;

  for(int i=0; i<sz; i++){
    if(a[i])
      multiples.pb(a[i]);
  }

  sort(multiples.rbegin(), multiples.rend());
  sort(v.rbegin(), v.rend());

  ll ans = 0;
  for(int i=0; i<multiples.size(); i++){
    ans += (multiples[i] * v[i]);
  }

  cout<<ans<<endl;

  return 0;
}
