// Because You Look Gorgeous in Black...
// ChandyShot...
// Average
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define sz 100005
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

vi v;
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.in", "r", stdin);
    // #endif
    cin >> n;
    v.resize(n);
    cin >> v;
    sort(v.begin(), v.end());

    int l, r, ans = 0;
    for(int i=0; i<n; i++){
        int val = 2 * v[i];
        l = 0;
        r = n-1;
        while(l < r){
            if(val == v[l] + v[r]){
                ans++;
                break;
            }
            if(v[l] + v[r] < val)
                l++;
            else
                r--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
