// VOTERS
// ChandyShot...

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

int n1, n2, n3;
unsigned int p1, p2, p3;
vector <int> v1, v2, v3, ans;

istream& operator >> (istream &in, vector<int> &v){
    for(unsigned int i=0; i<v.size(); i++)
        cin>>v[i];
    return in;
}

int main(){
    // freopen("input.in", "r", stdin);
    cin>>n1>>n2>>n3;
    v1.resize(n1), v2.resize(n2), v3.resize(n3);
    cin>>v1>>v2>>v3;
    p1 = p2 = p3 = 0;

    while(p1 < v1.size() or p2 < v2.size() or p3 < v3.size()){
        int minm = 1000000000;
        if(p1 < v1.size())
            minm = min(v1[p1], minm);
        if(p2 < v2.size())
            minm = min(v2[p2], minm);
        if(p3 < v3.size())
            minm = min(v3[p3], minm);

        int cnt = 0;
        // deb(minm)
        // if(p1 < v1.size()) deb(v1[p1])
        // if(p2 < v2.size()) deb(v2[p2])
        // if(p3 < v3.size()) deb(v3[p3])
        // cout<<endl;

        if(p1 < v1.size() and v1[p1] == minm){
            p1++;
            cnt++;
        }
        if(p2 < v2.size() and v2[p2] == minm){
            p2++;
            cnt++;
        }
        if(p3 < v3.size() and v3[p3] == minm){
            p3++;
            cnt++;
        }

        if(cnt >= 2){
            ans.pb(minm);
        }
    }

    cout<<ans.size()<<endl;
    for(unsigned int i = 0; i<ans.size(); i++)
        cout<<ans[i]<<endl;

    return 0;
}
