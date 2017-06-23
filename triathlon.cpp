// Because You Look Gorgeous in Black...
// ChandyShot...
// INOI1201 : Triathlon
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define sz 7
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

vector <pair<int, int> > v;
int n;
int ans = INT_MAX;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
    #endif

    cin>>n;
    v.resize(n);
    fin{
        int a, b, c;
        cin>>a>>b>>c;
        v[i].first = b + c;
        v[i].second = a;
    }

    sort(v.rbegin(), v.rend());

    for(int i=1; i<n; i++){
        v[i].second += v[i-1].second;
    }

    for(int i=0; i<n; i++){
        v[i].first += v[i].second;
    }

    sort(v.rbegin(), v.rend());

    cout<<v[0].first<<endl;

    return 0;
}
