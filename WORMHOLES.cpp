// Because You Look Gorgeous in Black...
// ChandyShot...
// ZCO12002 : Wormholes
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

vector <pair<int, int> > t;
vi V;
vi W;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    int n, x, y;
    cin >> n >> x >> y;
    fin{
        int a, b;
        cin >> a >> b;
        t.pb(mp(a, b));
    }

    V.resize(x);
    cin >> V;

    W.resize(y);
    cin >> W;

    sort(V.begin(), V.end());
    sort(W.begin(), W.end());

    int ans = INT_MAX;
    int p = 0, q = 0;
    for (int i = 0; i < n; i++)
    {
        int curr_start = t[i].first;
        int curr_end = t[i].second;

        auto it = lower_bound(V.begin(), V.end(), curr_start) - V.begin();

        if(V[it] == curr_start)
            p = it;
        else
            p = it - 1;

        auto itt = lower_bound(W.begin(), W.end(), curr_end);
        if(itt == W.end())
            q = -1;
        else
            q = itt - W.begin();

        if(p < 0 or q < 0)
            continue;
        ans = min(ans, W[q] - V[p] + 1);
    }
    cout << ans << endl;
    return 0;
}
// Just one run needed for a Century... :p 
