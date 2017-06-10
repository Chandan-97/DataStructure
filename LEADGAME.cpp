// ChandyShot... 
// LEADGAME

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout<<#x<<" = "<<x<<endl;
#define deb2(x, y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl;
#define sz 100010
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
using namespace std;
 
int gcd(int a, int b){return b?gcd(b, a%b):a;}
ll pw(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

ll pww(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.in", "r", stdin);
    int n;
    cin>>n;
    int p = -1;
    int lead = 0;
    int a = 0, b = 0;
    fin{
        int x, y;
        cin>>x>>y;
        a += x;
        b += y;
        if(a > b){
            if(a - b > lead){
                p = 1;
                lead = a - b;
            }
        }
        else if(b - a > lead){
            if(b - a > lead){
                p = 2;
                lead = b - a;
            }
        }
    }
    cout<<p<<" "<<lead<<endl;
    return 0;
}
