// Because You Look Gorgeous in Black...
// ChandyShot...
// PYRAMID
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

vi v;

int partition(vector<int> &v, int start, int end)
{
    int st = start;
    int nd = end;
    int pivot = v[start];
    while (start < end)
    {
        while (v[start] <= pivot and start <= end)
            start++;
        while (v[end] > pivot)
            end--;
        if (start < end and end >= 0)
            swap(v[start], v[end]);
    }

    v[st] = v[end];
    v[end] = pivot;
    return end;
}

void quickkSort(vector<int> &v, int start, int end)
{
    if (start < end)
    {
        int pivot = partition(v, start, end);
        quickkSort(v, start, pivot - 1);
        quickkSort(v, pivot + 1, end);
    }
}

void quick(vector<int> &v)
{
    int start = 0;
    int end = v.size() - 1;
    quickkSort(v, start, end);
}

int solve(vector<int> v){
    int reqd = 1;
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] >= reqd)
        {
            reqd++;
            ans++;
        }
    }

    return ans;
}

int main()
{
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    fin
    {
        int a, b;
        cin >> a >> b;
        v.pb(min(a, b));
    }

    quick(v);

    if (v[0] > 1)
    {
        cout << 0 << endl;
        return 0;
    }

    int ans = solve(v);

    cout << ans << endl;
    return 0;
}
