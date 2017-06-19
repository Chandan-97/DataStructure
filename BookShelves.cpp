// Because You Look Gorgeous in Black...
// ChandyShot...
// ZCO16001 : Bookshelves
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout<<#x<<" = "<<x<<endl;
#define deb2(x, y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl;
#define sz 7
#define szz 30
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define MX 1000000000
#define MN -MX
#define tc int t; cin>>t; while(t--)
#define hello cout<<"hello"<<endl;
#define clr(x) memset(x, 0, sizeof (x))
#define fill(x) memset(x, -1, sizeof(x))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define f(i, j, k, l) for(int (i)=(j); (i)<(k); (i)+=(l))
#define ff(i, j, k, l) for(int (i)=(j); (i)<=(k); (i)+=(l))
#define fin f(i, 0, n, 1)
#define fjn f(j, 0, n, 1)
#define fiin ff(i, 1, n, 1)
#define fjjn f(j, 1, n, 1)
#define vi vector<int>
#define pii pair<int, int>
using namespace std;

istream& operator >> (istream &in, vector<ll> &v){
    for(unsigned int i=0; i<v.size(); i++)
        cin>>v[i];
    return in;
}

int makeswap(vector <ll> v1, vector <ll> v2, int k){
    int opt = INT_MAX;
    int n = v1.size();
    priority_queue<int> p1;
    priority_queue<int, vector<int>, greater<int> > p2;
    for (int i = 0; i < n; i++){
        p1.push(v1[i]);
        p2.push(v2[i]);
    }

    for (int i = 0; i < k; i++){
        int a = p1.top();
        int b = p2.top();

        p1.pop();
        p2.pop();

        p1.push(b);
        p2.push(a);
    }
    opt = p1.top();
    int a = p2.top();
    while(!p2.empty()){
        a = p2.top();
        p2.pop();
    }
    opt += a;
    return opt;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<ll> v1, v2;
    v1.resize(n), v2.resize(n);
    cin >> v1 >> v2;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int ans = min(makeswap(v1, v2, k), makeswap(v2, v1, k));
    cout << ans << endl;
    return 0;
}
